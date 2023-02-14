#include <climits>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
void solution(vector<int> &arr){
 // write your code here
    int n = arr.size();
    vector<int> vec(n);
    vec[0] = arr[0];
    for(int i{1}; i< n; i++) {
        vec[i] = vec[i-1] ^ arr[i];
    }
    // vector<int> vec2(n);
    // vec2[arr.size()-1] = arr[arr.size()-1];
    // for(int i = arr.size()-1; i>=0; i--) {
    //     vec2[i] = vec1[i+1] ^ arr[i];
    // }
    int ans{};
    for(int i{1}; i< n;i++){
        if(vec[i] == 0){
            ans += i;
        }
        for(int j{i+1}; j<n;j++){
            if( vec[j] ^ vec[i-1] == 0){
                ans += j-i;
            }
        }
    }
    // for(int i{}; i<n-1;i++) {
    //     for(int j{i+1}; j<n;j++){
    //         for(int k{j}; k<n;k++){
    //             int first{};
    //             if(i == 0){
    //                 first  = vec[j-1];
    //             }else{
    //                 first = vec[j-1] ^ vec[i-1];
    //             }
    //             int second = vec[k] ^ vec[j-1];
    //             if(first == second){
    //                 ans++;
    //             }
    //         }
    //     }
    // }
    cout<<ans<<endl;
    return ;
}

int main() {
	int n = 0;
	cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < arr.size(); i++){
        cin>>arr[i];
    }
    solution(arr);
    return 0;
}