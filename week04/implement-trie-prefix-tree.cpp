Problem Link: https://leetcode.com/problems/implement-trie-prefix-tree/

TC:- (n*len);

class TrieNode{
public:
    bool isWord;
    TrieNode* next[26];
    
    TrieNode(){
        isWord = false;
        for(int i=0 ; i<26 ; i++)
            next[i]=NULL;
    }
};

class Trie {
public:
    
    TrieNode* root;
    
    Trie() {        
        root = new TrieNode();        
    }
    
    void insert(string word) {
        
        TrieNode* currNode = root;
        for(int i=0 ; i<word.size() ; i++){
            if(currNode->next[word[i]-'a']==NULL){
                currNode->next[word[i]-'a'] = new TrieNode();
            }
            currNode = currNode->next[word[i]-'a'];
        }
        currNode->isWord = true;
        
    }
    
    bool search(string word,bool checkPrefix=false) {
        
        TrieNode* traverse = root;
        for(int i=0 ; i<word.size() ; i++){
            if(traverse->next[word[i]-'a']==NULL){
                return false;
            }
            traverse=traverse->next[word[i]-'a'];
        }
        
        return traverse && (traverse->isWord || checkPrefix);
    }
    
    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};