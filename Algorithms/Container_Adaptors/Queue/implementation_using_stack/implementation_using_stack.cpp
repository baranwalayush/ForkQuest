#include<bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int>st;
    stack<int>s;
    int cnt=0;


public:
    // Constructor
    MyQueue() {}
    //    stack<int> queue=st; 

    // enqueue function
    void enqueue(int value) {
        if(s.empty()){
            s.push(value);
            cnt++;
        }else{
            while(!s.empty()){
                st.push(s.top());
                s.pop();
                cnt--;
            }
            st.push(value);
            while(!st.empty()){
                s.push(st.top());
                cnt++;
                st.pop();
            }
        }
    }


    // dequeue function
    void dequeue() {
        s.pop();
        cnt--;
    }


    // front function
    int front() {
        return s.top();
    }


    // empty function
    bool empty() {
        if(s.empty()){
            return true;
        }else{
            return false;
        }
    }


    // size function
    int size() {
        return cnt;
    }


    // display function
    void display() {
        stack<int>t=s;
        for(int i=0; i<cnt; i++){
            cout<<t.top()<<" ";
            t.pop();
        }
    }
};




int main() {
    // Add some examples for every function mentioned in MyQueue class here
    MyQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    q.display();
    



    return 0;
}