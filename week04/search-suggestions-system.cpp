Problem Link: https://leetcode.com/problems/search-suggestions-system/

TC :- 

class TrieNode{
public:
    bool isWord;
    TrieNode* link[26];
    
    TrieNode(){
        isWord=false;
        for(int i=0 ; i<26 ; i++)
            link[i]=NULL;
    }
};

class Solution {
public:
    
    void findAllWordsDFS(TrieNode* node,vector<string> &words,string &baseStr){
        
        if(words.size()==3) return;
        
        if(node->isWord){    
            words.push_back(baseStr);
        }
        
        for(int i=0 ; i<26 ; i++){
            if(node->link[i]==NULL) continue;
            
            char temp = i+'a';
            baseStr.push_back(temp);
            findAllWordsDFS(node->link[i],words,baseStr);
            baseStr.pop_back();
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>> finalResult;
        
        TrieNode* root = new TrieNode();
        TrieNode* currNode;
        for(auto &product : products){
            
            currNode = root;
            for(int i=0 ; i<product.size() ; i++){
                if(currNode->link[product[i]-'a']==NULL)
                    currNode->link[product[i]-'a'] = new TrieNode();
                currNode=currNode->link[product[i]-'a'];
            }
            currNode->isWord=true;
        }
        
        currNode=root;
        for(int i=0 ; i<searchWord.size() ; i++){
            vector<string> words;
            
            if(currNode->link[searchWord[i]-'a']){       
                currNode=currNode->link[searchWord[i]-'a'];
                string baseStr = searchWord.substr(0,i+1);
                findAllWordsDFS(currNode,words,baseStr);
                
            }else{
                while(i<searchWord.size()){
                    finalResult.push_back(words);
                    i++;
                }
                return finalResult;
            }
            finalResult.push_back(words);
        }
        
        return finalResult;
    }
    
};