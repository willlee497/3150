#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"
#include <sstream>
#include <vector>

// Helper: capture the output from print_linked_list
std::string capture_print(Node* head) {
    std::stringstream buffer;
    std::streambuf* old_buf = std::cout.rdbuf(buffer.rdbuf());
    print_linked_list(head);
    std::cout.rdbuf(old_buf);
    return buffer.str();
}

TEST_CASE("Basic Linked List Operations") {
    std::vector<int> values = {10, 20, 30, 40};
    Node* head = build_linked_list(values);

    CHECK(capture_print(head) == "10 -> 20 -> 30 -> 40 -> nullptr\n");
    CHECK(get_linked_list_data_item_value(head, 2) == 30);

    delete_list_element(head, 1); // Delete node with value 20.
    CHECK(capture_print(head) == "10 -> 30 -> 40 -> nullptr\n");

    delete_entire_linked_list(head);
    CHECK(head == nullptr);
}

TEST_CASE("Move Constructor") {
    std::vector<int> values = {1, 2, 3, 4, 5};
    Node* original = build_linked_list(values);

    // Use move constructor: move the contents of *original into 'moved'
    Node moved(std::move(*original));

    // 'moved' should now have the full chain.
    CHECK(capture_print(&moved) == "1 -> 2 -> 3 -> 4 -> 5 -> nullptr\n");

    // The original node should be left in a moved-from state (its next pointer is nullptr)
    CHECK(capture_print(original) == "1 -> nullptr\n");

    // Clean up the original node (moved-from) separately.
    delete original;
}

TEST_CASE("Move Assignment Operator") {
    std::vector<int> values1 = {100, 200, 300};
    std::vector<int> values2 = {10, 20, 30, 40};

    Node* list1 = build_linked_list(values1);
    Node* list2 = build_linked_list(values2);

    // Create Node objects using move construction.
    Node node1(std::move(*list1));
    Node node2(std::move(*list2));

    // Use move assignment: move node2 into node1.
    node1 = std::move(node2);

    // node1 should now hold the list originally from list2.
    CHECK(capture_print(&node1) == "10 -> 20 -> 30 -> 40 -> nullptr\n");

    // node2 should be left with only its own data (moved-from state).
    CHECK(capture_print(&node2) == "10 -> nullptr\n");

    delete list1;
    delete list2;
}
