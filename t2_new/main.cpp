#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int t{};
    cin>> t;
    int n {};
    int a{};
    while(t--) {
        cin>>n;
        unordered_map<int,int> map;
        while(n--){
            cin>>a;
            map[a]++;
        }
        
        bool flag {false};
        for(auto p: map){
            if(p.second % 2 != 0){
                cout<<"Marichka"<<endl;
                flag = true;
                break;
            }
        }
        if(flag){
            continue;
        }
        cout<<"Zenky"<<endl;
    }
    return 0;
}

