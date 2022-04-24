Problem Link: https://leetcode.com/problems/design-hashmap/

TC: (1);
MC: (1^3);

class MyHashMap {
public:
    
    int hashSize=1000;
    vector<pair<int,int>> myHashMap[1000];
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        vector<pair<int,int>> &temp=myHashMap[key%hashSize];
        for(int i=0 ; i<temp.size() ; i++){
            if(temp[i].first==key){
                temp[i].second=value;
                return;
            }
        }
        temp.push_back({key,value});
    }
    
    int get(int key) {
        vector<pair<int,int>> &temp=myHashMap[key%hashSize];
        for(int i=0 ; i<temp.size() ; i++){
            if(temp[i].first==key){
                return temp[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        vector<pair<int,int>> &temp=myHashMap[key%hashSize];
        for(int i=0 ; i<temp.size() ; i++){
            if(temp[i].first==key){
                temp.erase(temp.begin()+i);
                return;
            }
        }
    }
};