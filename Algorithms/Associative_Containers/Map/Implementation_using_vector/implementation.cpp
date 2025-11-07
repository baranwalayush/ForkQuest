#include<bits/stdc++.h>
using namespace std;


class MyMap{
private:
    // private variables/functions
    vector<pair<int, int>> data;

public:

    // Constructor
    MyMap(){
        data.clear();
    }


    // insert function
    void insert(int key, int value){
        for(auto &kv : data){
            if(kv.first == key){
                kv.second = value;
                return;
            }
        }
        data.push_back({key, value});

    }


    // erase function
    void erase(int key){
        for(auto it = data.begin(); it != data.end(); ++it){
            if(it->first == key){
                data.erase(it);
                return;
            }
        }

    }


    // find function
    bool find(int key){
        for(auto &kv : data){
            if(kv.first == key){
                return true;
            }
        }
        return false;

    }


    // get function
    int get(int key){
        for(auto &kv : data){
            if(kv.first == key){
                return kv.second;
            }
        }
        throw runtime_error("Key not found");

    }


    // size function
    int size(){
        return data.size();

    }


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
        for(auto &kv : data){
            cout << "Key: " << kv.first << ", Value: " << kv.second << endl;
        }
    }
};


int main(){
    // Add some examples for every function mentioned in MyMap class here
    MyMap myMap;    
    return 0;
}