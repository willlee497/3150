
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct Node {
    string name;
    shared_ptr<Node> next; // Initial implementation with shared_ptr
    weak_ptr<Node> weak_next; // Weak pointer for the cycle

    Node(string name) : name{name} {}
    ~Node() {
        cout << "Node [" << name << "] destructor" << endl;
    }
};

void createAndDisplayCircularList(shared_ptr<Node>& root, string names[], int numberOfNodes) {
    shared_ptr<Node> node = root;
    for (int i = 1; i < numberOfNodes; i++) {
        node->next = make_shared<Node>(names[i]);
        node = node->next;
    }
    node->next = root; // Creating a cycle with shared_ptr
}

void createAndDisplayWeakCircularList(shared_ptr<Node>& root, string names[], int numberOfNodes) {
    shared_ptr<Node> node = root;
    for (int i = 1; i < numberOfNodes; i++) {
        node->next = make_shared<Node>(names[i]);
        node = node->next;
    }
    node->weak_next = root; // Creating a cycle with weak_ptr
}

TEST_CASE("Testing circular linked list with shared_ptr") {
    string names[] = {"one", "two", "three", "four", "five"};
    int numberOfNodes = sizeof(names) / sizeof(names[0]);
    shared_ptr<Node> root = make_shared<Node>(names[0]);

    createAndDisplayCircularList(root, names, numberOfNodes);

    CHECK(root.use_count() == 2); // Root should have an extra count due to the cycle
}

TEST_CASE("Testing circular linked list with weak_ptr") {
    string names[] = {"one", "two", "three", "four", "five"};
    int numberOfNodes = sizeof(names) / sizeof(names[0]);
    shared_ptr<Node> root = make_shared<Node>(names[0]);

    createAndDisplayWeakCircularList(root, names, numberOfNodes);

    CHECK(root.use_count() == 1); // Root should not have an extra count due to weak_ptr
}

