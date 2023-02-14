// #include<bits/stdc++.h>
// using namespace std;
#include<iostream>
#include<string>
#include<vector>
using namespace std;

    vector<int> data;

    int _size() {
        //write your code here
        return ::data.size();//-----------------------------------------
    }

    void swap(int a , int b){
        int temp = ::data[a];
        ::data[a] = ::data[b];
        ::data[b] = temp;
    }

  

    void upheapify(int index) {
        if(index == 0 ) {
            return ;
        }
        int pi = (index - 1) / 2;
        if(::data[index] < ::data[pi]){
            //swap
            swap(index, pi);
            //upheapify
            upheapify(pi);
        }

    }
    void add(int val) {
       // write your code here
       ::data.push_back(val);
       upheapify(::data.size() - 1);

    }

   
    void down_heapify(int p_index) {
        int min = p_index;
        int li = (2 * p_index) +1;
        if(li < ::data.size() && ::data[li] < ::data[min]){
            min = li;
        }
        int ri = (2 * p_index) +2;
        if(ri < ::data.size() && ::data[ri] < ::data[min]) {
            min = ri;
        }
        if(min != p_index){
            swap(p_index, min);
            down_heapify(min);
        }
    }

    int _remove() {
     //write your code here
        if(::data.size() == 0){
            cout<<"Underflow"<<endl;
            return -1;
        }

        //swap 1st and last
        swap(0,::data.size() -1);
        //remove last
        int ans = ::data[::data.size() -1];
        ::data.pop_back();

        //down_heapify
        down_heapify(0);

        return ans;
        
    }

    

    int peek() {
     //write your code here
        if(::data.size() == 0){
            cout<<"Underflow"<<endl;
            return -1;
        }
        return ::data[0];
    }

    



int main(){
   

  while(1){
      string str;
        getline(cin,str);
      if(str[0]=='a'){
          string num=str.substr(4,str.length());
          int val=stoi(num);
          add(val);
      }else if(str[0]=='r'){
          int val=_remove();
          if(val!=-1){
              cout<<val<<endl;
          }
      }else if(str[0]=='p'){
          int val=peek();
          if(val!=-1){
              cout<<val<<endl;
          }
      }else break;
  }


   
}