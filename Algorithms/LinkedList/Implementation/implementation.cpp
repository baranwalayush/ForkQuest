#include <iostream>
using namespace std;


// Node structure
struct ListNode {
    int data;
    ListNode* next;

    ListNode(): data(0), next(nullptr) {}
    ListNode(int val): data(val), next(nullptr) {}
    ListNode(int val, ListNode* n): data(val), next(n) {}
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
        ListNode* newNode =new ListNode(val);
        newNode->next=head;
        head=newNode;
    }



    // Insert at tail
    void insertAtTail(int val) {
        ListNode* newNode = new ListNode(val);
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



    // Delete a node by value
    void deleteNode(int val) {
        if(head==nullptr) return ;
        if(head->data==val){
          ListNode* temp=head;
          head=head->next;
          delete temp;
          return ;
        }
        ListNode* temp=head;
        while(temp->next!=nullptr && temp->next->data!=val){
          temp=temp->next;
        }

        if(temp->next==nullptr) return;
        ListNode* nodetodelete=temp->next;
        temp->next=temp->next->next;
        delete nodetodelete;
    }




    // Delete a node by index
    int deleteNodebyIndex(int index){
        if(head==nullptr) return -1;
        if(index==0){
          ListNode* temp=head;
          head=head->next;
          int val=temp->data;
          delete temp;
          return val;
        }
        ListNode* temp=head;
        int count=0;
        while(temp->next!=nullptr && count<index-1){
          temp=temp->next;
          count++;
        }
        if(temp->next==nullptr) return -1;
        ListNode* nodetodelete=temp->next;
        temp->next=temp->next->next;
        int val=nodetodelete->data;
        delete nodetodelete;
        return val;
    }
  



    // Display list elements
    void display() {
        ListNode* temp = head;
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

    int a=list.deleteNodebyIndex(1);
    cout << "Deleted value: " << a << endl;
    cout << "Linked List after deletion by index: ";
    list.display();

    return 0;
}
