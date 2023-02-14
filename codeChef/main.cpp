#include <iostream>
#include <string>
using namespace std;
bool is_palindrome(string s){
    int a {};
    int b = s.length();
    while(a<b){
        if( s[a] != s[b]){
            return false;
        }
        a++;
        b--;
    }
    return true;
}
// int fun(string s, int i){
//     if(i == s.length()) {
//         return -1;
//     }
//     if(is_palindrome(s)){
//         return ;
//     }
//     fun(s,i+1,ans);
//     string left = s.substr(0,i);
//     string right = s.substr(i+1,s.length()-i-1);
//     fun((left + right),i+1,ans);
// }

int main() {
	// your code goes here
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    // int t{};
    // cin>> t;
    // int num{};
    // string s{};
    // while(t--){
    //     cin >> num>> s;
    //     if(is_palindrome(s)){
    //         cout<<0<<endl;
    //         continue;
    //     }
    //     int ans{-1};
    //     ans = fun(s,0,ans);
    //     cout<<ans<<endl;
    // }
	return 0;
}




