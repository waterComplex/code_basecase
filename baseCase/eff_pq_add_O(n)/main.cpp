// #include<bits/stdc++.h>
// using namespace std;
#include<iostream>
#include<string>
#include<vector>
using namespace std;

    
class priority_queue {
    private:
    vector<int> data;

    public:
    
    int _size() {
        //write your code here
        return data.size();//-----------------------------------------
    }

    private:
    void swap(int a , int b){
        int temp = data[a];
        data[a] = data[b];
        data[b] = temp;
    }
  
    void upheapify(int index) {
        if(index == 0 ) {
            return ;
        }
        int pi = (index - 1) / 2;
        if(data[index] < data[pi]){
            //swap
            swap(index, pi);
            //upheapify
            upheapify(pi);
        }

    }

    public:
    void add(int val) {
       // write your code here
       data.push_back(val);
       upheapify(data.size() - 1);

    }

   private:
    void down_heapify(int p_index) {
        int min = p_index;
        int li = (2 * p_index) +1;
        if(li < data.size() && data[li] < data[min]){
            min = li;
        }
        int ri = (2 * p_index) +2;
        if(ri < data.size() && data[ri] < data[min]) {
            min = ri;
        }
        if(min != p_index){
            swap(p_index, min);
            down_heapify(min);
        }
    }
    public:
    int _remove() {
     //write your code here
        if(data.size() == 0){
            cout<<"Underflow"<<endl;
            return -1;
        }

        //swap 1st and last
        swap(0,data.size() -1);
        //remove last
        int ans = data[data.size() -1];
        data.pop_back();

        //down_heapify
        down_heapify(0);

        return ans;
        
    }

    
    public:
    int peek() {
     //write your code here
        if(data.size() == 0){
            cout<<"Underflow"<<endl;
            return -1;
        }
        return data[0];
    }
//-------------------------------------------------------------
    priority_queue() {
        
    }
    priority_queue (vector<int> arr) {
        //efficient way o(n)
        for(int a: arr){
            data.push_back(a);
        }
        unsigned long int a {data.size()/2 -1};
        for( int i{static_cast<int>(a)} ;i >=0 ;i--) {
            down_heapify(i);
        }
    }
};
    



int main(){
   vector<int> arr {2,3,62,54,35};
    priority_queue a (arr);
    
    while(a._size() > 0){
        cout<<"Peek: "<<a.peek()<<" ";
        cout<<"Remove: "<<a._remove()<<" ";
        cout<<"size: "<<a._size()<<endl;
                
    }


   
}