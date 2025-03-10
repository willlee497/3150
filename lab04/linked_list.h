#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <vector>
#include <stdexcept>

struct Node {
    int data;
    Node* next;

    // Constructor that initializes the node with a given value.
    Node(int val) : data(val), next(nullptr) {}

    // Copy Constructor: deep copies the node and its successors.
    Node(const Node& other);

    // Destructor: recursively deletes subsequent nodes.
    ~Node();

    // Move Constructor: takes ownership of the other node’s chain.
    Node(Node&& other) noexcept;

    // Move Assignment Operator: cleans up current resources then takes ownership.
    Node& operator=(Node&& other) noexcept;
};

// Utility functions:
Node* build_linked_list(const std::vector<int>& values);
void print_linked_list(Node* head);
void delete_entire_linked_list(Node*& head);
int get_linked_list_data_item_value(Node* head, int node_number);
void delete_list_element(Node*& head, int node_number);

#endif // LINKEDLIST_H
