#include<iostream>
using namespace std;



struct ListNode{
    int val;
    ListNode* next;

    ListNode(): val(0), next(NULL) {}
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode* ptr): val(x), next(ptr) {}
};



class List{
    ListNode* head = NULL;

public:


    // Creates a linked list
    void insert(int x){
        if(head == NULL){
            head = new ListNode(x);
        }
        else{
            ListNode* temp = head;
            while(temp->next != NULL) temp = temp->next;

            temp->next = new ListNode(x);
        }
    }


    // reverse a linked list
    void reverse(){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(curr != NULL){
            next = curr->next;   
            curr->next = prev;   
            prev = curr;         
            curr = next;  
        }
        head = prev;
    }


    // displays the linked list
    void display(){
        ListNode* temp = head;

        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};


int main(){
    List l;
    

    // Example
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);

    cout << "Original Linked List ->";
    l.display();

    // reverse the linked list
    l.reverse();
    cout << "Reversed Linked List ->";
    l.display();

    return 0;
}