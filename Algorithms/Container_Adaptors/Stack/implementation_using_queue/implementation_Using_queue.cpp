#include<bits/stdc++.h>
using namespace std;

class MyStack {
private:
    // Private variables
    // queue<int> q1;
    // queue<int> q2;
public:
    // Constructor
    queue<int> q1;
    queue<int> q2;
    MyStack(){
        
    }

    // 1 2 3 4
    // 4 3 2 1 
    // push function
    void push(int value) {
        q1.push(value);
        // int top = q1.front();
        // q1.pop();
        // q2.push(top);
    }


    // pop function
    void pop() {
        while(!q1.empty()){
            int top = q1.front();
            q1.pop();
            q2.push(top);
        }
        // cout << q2.front();
        q2.pop();
    }


    // top function
    int top() {
        if(q1.empty()){
            return q2.front();
        }else{
            while(!q1.empty()){
            int top = q1.front();
            q1.pop();
            q2.push(top);
            }
            return q2.front();
        }
    }


    // empty function
    bool empty() {
        return q1.empty() && q2.empty();
    }


    // size function
    int size() {
        if(q1.empty()) return q2.size();
        else{
            return q1.size() + q2.size();
        }
    }


    // display function
    void display() {
        if(q1.empty()){
            while(!q2.empty()){
                int top = q2.front();
                q2.pop();
                cout << top << " ";
            }
        }else{
            while(!q1.empty()){
                int top = q1.front();
                q1.pop();
                q2.push(top);
            }
            while(!q2.empty()){
                int top = q2.front();
                q2.pop();
                cout << top << " ";
            }
        }
    }
};




int main() {
    // Add some examples for every function mentioned in MyStack class here
    MyStack st =  MyStack();
    st.push(3);
    st.push(5);
    st.push(8);
    st.push(1);
    st.pop();
    st.display();
    return 0;
}
