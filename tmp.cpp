#include<iostream>

using namespace std;


string superReducedString(string s) {
    string ans="";
    int n= s.size();
    char tmp='.';
    int ct=0;
    for(int i=0; i<n+1; i++){
        if(i< n && tmp=='.') {tmp= s[i]; ct=1;}
        else if(i<n && s[i]==tmp){ct++;}
        else{
            if(ct%2) ans+= tmp;
            tmp=s[i];
            ct=1;
        }
    }
    
    return ans;
}


int main(){
    cout << superReducedString("aaabccddd");
    return 0;
}