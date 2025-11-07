#include <iostream>
using namespace std;


// Node structure
struct ListNode {
    int data;
    ListNode next;

    ListNode(): data(0), next(nullptr) {}
    ListNode(int val): data(val), next(nullptr) {}
    ListNode(int val, Node n): data(val), next(n) {}
};



// Linked List class
class LinkedList {
private:
    ListNode head;

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
        ListNode newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next == nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }



    // Delete a node by value
    void deleteNode(int val) {
        if (head == nullptr) return;

        if (head->data == val) {
            ListNode temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) return; // Value not found

        prev->next = curr->next;
        delete curr;


    }




    // Delete a node by index
    int deleteNodebyIndex(int index){
        if (head == nullptr) return -1;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        if(index == 0){
            head = head->next;
            int val = curr->data;
            delete curr;
            return val;
        }

        int count = 0;
        while (curr != nullptr && count != index) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (curr == nullptr) return -1; // Index out of bounds

        prev->next = curr->next;
        int val = curr->data;
        delete curr;
        return val;

    }



    // Display list elements
    void display() {
        ListNode temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
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

    // Delete a node
    list.deleteNode(20);

    cout << "Linked List after deletion: ";
    list.display();

    return 0;
}
