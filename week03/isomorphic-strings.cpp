Problem Link: https://leetcode.com/problems/isomorphic-strings/

TC: O(N)
MC: O(N)

 bool isIsomorphic(string s, string t,int firstTime=0) {
        
    unordered_map<char,char> mappedChar;
    
    for(int i=0 ; i<s.size() ; i++){
        if(mappedChar.count(s[i])){
            if(mappedChar[s[i]]==t[i]) continue;
            else return false;
        }else{
            mappedChar[s[i]]=t[i];
        }
    }
    
    if(firstTime==0) return isIsomorphic(t,s,1);
    
    return true;
}
