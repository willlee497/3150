#include "linked_list.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>

// --- Node member function definitions ---

// Copy constructor: deep copy of this node and its successors.
Node::Node(const Node& other)
    : data(other.data),
      next(other.next ? new Node(*other.next) : nullptr)
{ }

// Destructor: recursively deletes successors.
Node::~Node() {
    delete next;
}

// Move constructor: steal resources from other.
Node::Node(Node&& other) noexcept
    : data(other.data),
      next(other.next)
{
    other.next = nullptr;  // leave other in a safe moved-from state
}

// Move assignment operator: free current chain then take ownership.
Node& Node::operator=(Node&& other) noexcept {
    if (this != &other) {
        delete next;          // free our existing chain
        data = other.data;
        next = other.next;
        other.next = nullptr; // leave other in a valid state
    }
    return *this;
}

// --- Linked list utility function definitions ---

// Build a linked list from a vector of integers.
Node* build_linked_list(const std::vector<int>& values) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int val : values) {
        Node* new_node = new Node(val);
        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    return head;
}

// Print the linked list in the format "value -> value -> ... -> nullptr".
void print_linked_list(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Delete the entire linked list and set the head pointer to nullptr.
void delete_entire_linked_list(Node*& head) {
    delete head;
    head = nullptr;
}

// Retrieve the data from the node at the specified index (0-indexed).
int get_linked_list_data_item_value(Node* head, int node_number) {
    Node* current = head;
    int index = 0;
    while (current) {
        if (index == node_number)
            return current->data;
        current = current->next;
        ++index;
    }
    throw std::out_of_range("Node number out of range");
}

// Delete the node at the specified index (0-indexed).
void delete_list_element(Node*& head, int node_number) {
    if (!head)
        throw std::out_of_range("List is empty");
    if (node_number == 0) {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr; // prevent recursive deletion
        delete temp;
        return;
    }
    Node* current = head;
    for (int i = 0; current && i < node_number - 1; i++) {
        current = current->next;
    }
    if (!current || !current->next)
        throw std::out_of_range("Node number out of range");
    Node* temp = current->next;
    current->next = temp->next;
    temp->next = nullptr;
    delete temp;
}
