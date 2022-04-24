Problem Link: https://leetcode.com/problems/roman-to-integer/

TC: O(N);
MC: O(1);

int romanToInt(string s) {
    unordered_map<string,int> mappedValues;
    
    mappedValues["I"]=1;
    mappedValues["IV"]=4;
    mappedValues["V"]=5;
    mappedValues["IX"]=9;
    mappedValues["X"]=10;
    mappedValues["XL"]=40;
    mappedValues["L"]=50;
    mappedValues["XC"]=90;
    mappedValues["C"]=100;
    mappedValues["CD"]=400;
    mappedValues["D"]=500;
    mappedValues["CM"]=900;
    mappedValues["M"]=1000;
    
    int value=0;
    for(int i=0 ; i<s.size() ; i++){
        
        string temp;
        if(i+1<s.size()){
            temp=s.substr(i,2);
        }
        if(mappedValues.count(temp)){
            value+= mappedValues[temp];
            i++;
        }else{
            temp=s.substr(i,1);
            value+=mappedValues[temp];
        }
    }
    return value;
}