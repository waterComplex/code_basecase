#include<iostream>
#include<vector>
#include<string>
#include<list>

using namespace std;
class HashTable {
    private:
        static const int hashGroups = 10;
        list <pair<int, string> > table[hashGroups];
    public:
        bool isEmpty() ;
        int hashFunction(int key) ;
        void insertItem(int key,string value);
        void removeItem(int key );
        string searchTable(int key);
        void printTable();
};

bool HashTable:: isEmpty(){
    int sum{};
    for(int i{} ; i< hashGroups;i++) {
        sum += table[i].size();
    }
    if(!sum) {
        return true;
    } else {
        return false;
    }
}

int HashTable:: hashFunction(int key) {
    return key% hashGroups;
}

void HashTable:: insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto & cell = table[hashValue]; // cell = list
    bool keyExists = false;
    for(auto bitr = begin(cell); bitr != end(cell) ; bitr++) {
        if(bitr->first == key ) {
            keyExists = true;
            bitr->second = value;
            cout<<"[Warning] key exists value replaced."<<endl;
            break;
        }
    } 
    if(!keyExists) {
        cell.emplace_back(key,value);
    }

    return ;
}

void HashTable:: removeItem(int key) {
    int hashValue = hashFunction(key);
    auto & cell = table[hashValue];
    bool keyExists = false;
    for(auto bitr = begin(cell); bitr != end(cell) ; bitr++) {
        if(bitr->first == key ) {
            keyExists = true;
            bitr = cell.erase(bitr);//return itr to next otherwise you may have bug(segmentation bug)
            cout<<"[some Info] Item removed."<<endl;
            break;
        }
    } 
    if(!keyExists) {
        cout<<"[Warning] Key not found , didn't remove anything"<<endl;
    }
}

void HashTable:: printTable() {
    for(int i{}; i< hashGroups ;i++) {
        if(table[i].size() == 0) {
            continue;
        }

        for(auto bitr = begin(table[i]); bitr != end(table[i]) ; bitr++) {
            cout<<"[INFO] Key: "<<bitr->first<<" Value: "<<bitr->second<<endl;
        }
    }
    return ;
}
 int main() {
     HashTable HT;
     if(HT.isEmpty()){
         cout<<"HT is empty ,Good job "<<endl;
     }else{
         cout<<"check code"<<endl;
     }
     HT.insertItem(78, "rak");
     HT.insertItem(98, "makk");
     HT.insertItem(28, "tap");
     HT.insertItem(56, "cook");
     HT.insertItem(343, "math");
     HT.insertItem(34, "raptile");
     HT.insertItem(58, "lag");

     HT.printTable();

     HT.removeItem(343);
     HT.removeItem(843);

    if(HT.isEmpty()){
         cout<<"check code"<<endl;
     }else{
         cout<<"correct answer,Good job "<<endl;
     }



    return 0;
 }














// #include<iostream>
// #include<vector>
// #include<string>
// #include<list>
// using namespace std;
// template<typename K,typename V>
// class HashMap{
//     public:
//     class HMNode{
//         public:
//         K key;
//         V value;
//         HMNode(K key, V value) {
//             this-> key = key;
//             this-> value = value;
//         }
//     };


//     private:
//     vector <list <HMNode >* > buckets;
//     int sz {}; //size
//     void initbuckets(int N) {
//         for(int i{}; i< N ;i++) {
//             buckets[i] = new list <HMNode >();
//         }
//     }
//     public:
//      HashMap() {
//          initbuckets(4);
//          sz = 0;
//      }

//     private:
    
//     void insert(K key , V val){
//         int bi = hashfn(key);
//         int di = getIndexWithinBucket(key,bi);
//     }

//     int get(K key) {

//     }
//     bool find(K key) {

//     }

//     int erase(K key) {

//     }
//     vector<K> keySet(){

//     }
//     int size() {
//         return sz;
//     }


//     void display() {
//         cout<<"Display Begins"<<endl;
//         for(int i{}; i< buckets.size();i++) {
//             cout<<"bucket"<<i<<" ";
//             for(HMNode n : buckets[i]){
//                 cout<<n.key<<" @ "<<n.value<<" ";
//             }
//             cout<<"."<<endl;
//         }
//         cout << "Display Ends"<<endl;
//     }

// };

// int main (){
//     HashMap<string, int> um;
//     string cm;
//     cin>> cm;
//     while(cm != "quit") {
//         if(cm == "put"){
//             string key{};
//             cin >> key;
//             int val{};
//             cin>> val;
//             um.insert(key,val);
//         }else if( cm == "remove"){
//             string key{};
//             cin>> key;
//             cout<<um.erase(key)<<endl;;
//         }else if(cm == "get"){
//             string key{};
//             cin>> key;
//             int a = um.get(key);
//             cout<<a<<endl;
//         }else if(cm == "containsKey") {
//             string key{};
//             cin>> key;
//             cout<<std::boolalpha<<um.find(key)<<endl;;
//         }else if(cm == "keyset") {
//             vector<string > a = um.keySet();
//             for(string s: a){
//                 cout<< s<<", ";
//             }
//             cout<<endl;

//         }else if(cm == "size") {
//             cout<<um.size()<<endl;
//         }else if(cm == "display"){
//             um.display();
//         }
//     }

//     return 0;
// }