#include <iostream>
using namespace std;

// Node structure
struct ListNode {
    int data;
    ListNode* next;

    ListNode() : data(0), next(nullptr) {}
    ListNode(int val) : data(val), next(nullptr) {}
    ListNode(int val, ListNode* n) : data(val), next(n) {}
};

// Linked List class
class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at head
    void insertAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at tail
    void insertAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next != nullptr) {   // fixed: should be != nullptr
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete a node by value
    void deleteNode(int val) {
        if (head == nullptr) return;

        // If head node itself holds the value
        if (head->data == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;

        // Search for the node to be deleted
        while (curr != nullptr && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }

        // Value not found
        if (curr == nullptr) return;

        // Unlink and delete
        prev->next = curr->next;
        delete curr;
    }

    // Delete a node by index (0-based)
    void deleteNodeByIndex(int index) {
        if (head == nullptr || index < 0) return;

        if (index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* curr = head;
        for (int i = 0; curr != nullptr && i < index - 1; i++) {
            curr = curr->next;
        }

        // If position is out of range
        if (curr == nullptr || curr->next == nullptr) return;

        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    // Display list elements
    void display() {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;   // fixed: missing increment
        }
        cout << endl;
    }
};

// Main Function
int main() {
    LinkedList list;

    // Insert elements
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtHead(5);

    cout << "Linked List after insertions: ";
    list.display();

    // Delete a node by value
    list.deleteNode(20);

    cout << "Linked List after deleting value 20: ";
    list.display();

    // Delete a node by index
    list.deleteNodeByIndex(1);

    cout << "Linked List after deleting index 1: ";
    list.display();

    return 0;
}