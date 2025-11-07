#include <iostream>
using namespace std;


// Node structure
typedef struct ListNode {
    int data;
    ListNode* next;

    ListNode(): data(0), next(nullptr) {}
    ListNode(int val): data(val), next(nullptr) {}
    ListNode(int val, ListNode* n): data(val), next(n) {}
} ListNode;



// Linked List class
class LinkedList {
private:
    ListNode *head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        ListNode* cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    // Insert at head
    void insertAtHead(int val) {
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at tail
    void insertAtTail(int val) {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete a node by value (first occurrence)
    void deleteNode(int val) {
        if (head == nullptr) return;
        if (head->data == val) {
            ListNode* toDel = head;
            head = head->next;
            delete toDel;
            return;
        }
        ListNode* prev = head;
        ListNode* cur = head->next;
        while (cur != nullptr && cur->data != val) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr) return; // not found
        prev->next = cur->next;
        delete cur;
    }

    // Delete a node by index, returns deleted value or -1 if invalid
    int deleteNodebyIndex(int index){
        if (index < 0 || head == nullptr) return -1;
        if (index == 0) {
            int val = head->data;
            ListNode* toDel = head;
            head = head->next;
            delete toDel;
            return val;
        }
        ListNode* prev = head;
        for (int i = 0; i < index - 1 && prev != nullptr; ++i) {
            prev = prev->next;
        }
        if (prev == nullptr || prev->next == nullptr) return -1; // out of range
        ListNode* toDel = prev->next;
        int val = toDel->data;
        prev->next = toDel->next;
        delete toDel;
        return val;
    }

    // Display list elements
    void display() {
        ListNode *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
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

    // Delete by index
    int removed = list.deleteNodebyIndex(1);
    cout << "Removed by index (1): " << removed << "\n";
    cout << "List now: ";
    list.display();

    return 0;
}
