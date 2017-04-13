#include<iostream>
#include<string>
using namespace std;
bool ifequal(string k){
    if(k.size()==1) return true;
    int i=0;
    int j=k.size()-1;
    while(i<j){
        if(k[i]!=k[j]) return false;
    }
    return true;
}
int main(){
string s;
cin>>s;
unordered_set<string> uSet;
int sum=0;
for(int i=0;i<s.size();i++){
    for(int j=i;j<s.size();j++){
        string k=s.substr(i,j-i+1);
        if(ifeual(k)){
            if(uSet.find(k)!=uSet.end()) continue;
            else {
                sum++;
                uSet.insert(k);
            }
        }
        else continue;
    }
}
return sum;
}
