#include <bits/stdc++.h> 

bool isNum(char c){
    if(c>='0' && c<='9'){ return true; }
    return false;
}

int atoi(string str) {
    long long ans=0; bool isNeg=false; int i=0;
    if(str[i]=='-'){ isNeg=true; i++; }
    string temp="";
    for(; i<str.size(); i++){
        if(isNum(str[i])==true){ temp+=str[i]; }
    }
    if(temp.size()<str.size() && str[0]!='-'){ isNeg=false; }
    for(int i=0; i<temp.size(); i++){
        ans+=(int)(temp[i]-'0');
        ans*=10;
    }
    if(isNeg==true){ ans*=-1; }
    return (int)ans/10;
}