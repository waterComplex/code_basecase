#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
    //max heap
    cout<<"MAX heap----------------"<<endl;
    priority_queue<int, vector<int>> pq;
    pq.push(4);
    pq.push(45);
    pq.push(2);
    pq.push(124);
    pq.push(867);
    cout<<"top-> "<<pq.top()<<endl; //867
    pq.pop();

    while(pq.size() >0){
        cout<<pq.top()<<endl;
        pq.pop();
    }

    //min heap
    cout<<"MIN heap----------------"<<endl;

    priority_queue<int, vector<int>,greater<int>> minpq;
    minpq.push(4);
    minpq.push(45);
    minpq.push(2);
    minpq.push(124);
    minpq.push(867);

    cout<<"top-> "<<minpq.top()<<endl; //867
    minpq.pop();

    while(minpq.size() >0){
        cout<<minpq.top()<<endl;
        minpq.pop();
    }

    return 0;
}