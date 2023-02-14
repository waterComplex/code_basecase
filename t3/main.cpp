#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int nw = words.size();
        int np = puzzles.size();
        // vector<int> wMask;
        vector<int> pMask(np);
        //using the fact that strings in puzzles have max lenght of 7
        // unordered_map <char,bool> wc;//word charcter
        int ndc{};
        int wmi{};
        bool flag {false};
        unordered_map<char, vector<int>> aaa;
        for(int i {}; i< nw; i++) {
            ndc = 0;
            wmi = 0;
            flag = false;
            for(char c: words[i]){
                if(wmi != ( wmi|(1<<(c-'a')) )){
                    // wc.insert(c);
                    // wc[c] = true;
                    ndc++;
                    if(ndc >7){
                        flag = true;
                        break;
                    }
                    wmi = ( wmi|(1<<(c-'a')) );
                }
            }
            // wc.clear();
            if(flag){
                continue;
            }
            // wMask.push_back(wmi);
            for(char c: words[i]){
                aaa[c].push_back(wmi);
            }
        }

        for(int i {}; i< np; i++) {
            for(char c: puzzles[i]){
                pMask[i] = ( pMask[i]|(1<<(c-'a')) );
            }
        }

        vector<int> ans(np);
        for(int i{}; i< np ; i++){
            char fc = puzzles[i][0];
            for( int j{}; j< aaa[fc].size();j++) {
                if( (pMask[i] | aaa[fc][j]) == pMask[i]){
                    ans[i]++;
                }
            }
        }

        return ans;
    }

int main() {
    vector<string> a;
    vector<string> b;
    findNumOfValidWords(a,b);
}