#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {
    unordered_map <string, int> umap;
    umap["little price"] = 120;
    umap["a thousand splended son"] = 80;
    umap["theory of everything"] = 90;
    umap["brief history of time"] = 100;
    umap["Maus"] = 40;


    //insert
    umap.insert({"school of life",20});
    // umap.insert(("the rudest book ever",5));//error
    umap.insert(pair("the rudest book ever",5));// me worked
    umap.insert(make_pair("jungle book", 65));


    //loops
    //range base for loop
    for(pair <string, int> p : umap){
        cout<<p.first<<" "<<p.second<<" million."<<endl;
    }
    cout<<"---------------------------------"<<endl;
    // itr = iteretor works like pointer
    for(auto itr = umap.begin(); itr != umap.end();itr++){
        cout<<itr->first<<" "<<itr->second<<" million."<<endl;
    }



    //updating
    // umap.insert({"school of life",80}); // didn't change
    // umap["school of life"] = 80; // changed
    // for(pair <string, int> p : umap){
    //     cout<<p.first<<" "<<p.second<<" million."<<endl;
    // }

    // cout<<"---------------------------------"<<endl;


    //find
    // string key = "harry potter";
    // if(umap.find(key) != umap.end()){
    //     cout<<"found "<<endl;
    // }else{
    //     cout<<"not found "<<endl;
    // }

    // cout<<"---------------------------------"<<endl;

    //erase
    // umap.erase("school of life");
    // for(pair <string, int> p : umap){
    //     cout<<p.first<<" "<<p.second<<" million."<<endl;
    // }



    // count the occurence and stored in a map
    vector<int> vec {7,3,4,7,2,3,4,5,4,3,2,2,3,4,5,6,7,8,89,8,7,65,5,6,7};
    unordered_map<int, int> acc;
    for(int i{} ;i<vec.size(); i++){
        // int key = vec[i];
        acc[vec[i]]++;
    }
    cout<<"---------------------------------"<<endl;
    for(pair <int, int> p : acc){
        cout<<p.first<<" occured "<<p.second<<" times."<<endl;
    }


}