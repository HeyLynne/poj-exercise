#include<iostream>
#include<string>
using namespace std;

void permutation(string &s,int st,int e){
    if(st==e)
        cout<<s<<endl;
    else{
        for(int i=st;i<=e;i++){
            swap(s[st],s[i]);
            permutation(s,st+1,e);
            swap(s[st],s[i]);
        }
    }
}
int main(){
string s;
cin>>s;
permutation(s,0,s.size()-1);
return 0;
}
