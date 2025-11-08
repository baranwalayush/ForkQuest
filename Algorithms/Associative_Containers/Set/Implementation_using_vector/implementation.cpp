#include<bits/stdc++.h>

using namespace std;


class MySet{
private:
    // private variables/functions
    vector<int> data;
public:

    // Constructor
    MySet(){
        data.clear();
    }


    // insert function
    void insert(int value){
        if(!contains(value)){
            data.push_back(value);
        }
    }
    // size function
    int size(){
        return (int)data.size();
    }


    // erase function
    void erase(int value){
        auto it = find_it(value);
        if(it != data.end()){
            data.erase(it);
        }
    }  


    // find iterator helper
    vector<int>::iterator find_it(int value){
        return std::find(data.begin(), data.end(), value);
    }

    // contains function
    bool contains(int value){
        return find_it(value) != data.end();
    }


    // (size() already defined above)



    // empty function
    bool empty(){
        return data.empty();

    }


    // clear function
    void clear(){
        data.clear();

    }



    // display function
    void display(){
        for(auto &val : data){
            cout << val << " ";
        }
        cout << endl;

    }
};


int main(){
    // Add some examples for every function mentioned in MySet class here
    MySet mySet;
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.display();  // Display elements
    cout << "Size: " << mySet.size() << endl;
    cout << "Find 20: " << (mySet.contains(20) ? "Found" : "Not Found") << endl;
    mySet.erase(20);
    cout << "Find 20: " << (mySet.contains(20) ? "Found" : "Not Found") << endl;
    mySet.clear();
    cout << "Empty: " << (mySet.empty() ? "Yes" : "No") << endl;
    return 0;
}