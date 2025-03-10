Lab Week 4: Linked Lists with Move Semantics

Overview
This lab builds upon Lab Week 3 by extending the Node structure to support move semantics. In Lab Week 3, the linked list implementation included:

Copy Constructor: Performs a deep copy of the node and its successors.
Destructor: Recursively deletes subsequent nodes.
build_linked_list: Creates a linked list from a vector of integers.
print_linked_list: Outputs the list in a formatted string ("value -> value -> ... -> nullptr").
delete_entire_linked_list: Deletes the entire list and resets the head pointer to nullptr.
get_linked_list_data_item_value: Retrieves the data value at a specified index (0-indexed).
delete_list_element: Deletes a specific node by its index (0-indexed).
In this lab, we add two new operations:

Move Constructor: Transfers ownership of a node’s entire chain to a new node without performing a deep copy.
Move Assignment Operator: First frees any already–allocated successors, then transfers ownership from the source node.
These enhancements improve efficiency by avoiding unnecessary deep copies when temporary objects are used.

File Structure
The repository contains the following files:

linked_list.h: Contains the declarations for the Node structure (including the new move operations) and linked list functions.
linked_list.cpp: Contains the definitions for the Node member functions (copy constructor, destructor, move constructor, and move assignment operator) as well as the linked list utility functions.
linked_list_test.cpp: Contains unit tests (using the doctest framework) that validate all linked list operations, including the new move semantics.
doctest.h: (Download this file as described below; it is required for running the tests.)
README.md: This file, which includes instructions on how to compile and run the tests.
How to Set Up
If you do not already have the latest doctest.h file, download it by running:
  wget https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h

Ensure that doctest.h is in the same directory as linked_list_test.cpp, or update the include path accordingly.

Compiling the Code

Open your terminal and navigate to the lab folder. For example:
  cd CSE3150/Labs/lab03
Compile the code using g++ with C++17 support:
  g++ -std=c++17 -o linkedlist linked_list_test.cpp linked_list.cpp
This command compiles both the linked list implementation and the test suite into an executable named "linkedlist".
Running the Tests
After compiling, run the executable:
  ./linkedlist
The tests will execute automatically using the doctest framework and display the results in your terminal.

Additional Information

0-Indexed Numbering: All functions (e.g., retrieving or deleting nodes) use 0-indexed numbering—the first node is at index 0.
Recursive Deletion: The Node destructor recursively deletes the successor nodes. When deleting a single node using delete_list_element, the node’s next pointer is set to nullptr to prevent unintended deletion of the rest of the list.

Deep Copy: The copy constructor performs a deep copy, ensuring that copying a node creates a complete new copy of the entire list starting from that node.
Move Semantics:

• Move Constructor: Instead of deep copying, this constructor “steals” the internal pointer (next) from the source node, transferring ownership of the entire chain. The source node is left in a valid but “empty” (moved-from) state (its next pointer is set to nullptr).
• Move Assignment Operator: This operator first deletes any existing successors in the destination node to avoid memory leaks, then takes ownership of the source node’s chain and resets the source’s next pointer to nullptr.

These move operations enhance performance by eliminating the overhead of deep copying when nodes are moved (for example, when passing temporary objects).