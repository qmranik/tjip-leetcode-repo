Problem Link: https://leetcode.com/problems/valid-anagram/

TC: O(n);
mc: O(1);

bool isAnagram(string s, string t) {
    if(s.size()!=t.size()) return false;
    vector<int> flag(30,0);

    for(int i=0 ; i<s.size() ; i++){
        flag[s[i]-'a']++;
        flag[t[i]-'a']--;
    }

    for(int i=0 ; i<28 ; i++){
        if(flag[i]!=0){
            return false;
        }
    }
    return true;
}