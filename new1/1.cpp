#include<iostream>
#include<string>
using namespace std;
int main(){
string s;
int sum=0;
cin>>s;
int i=0;
int j=1;
sum=1;
while(i<s.size()&&j<s.size()){
    if(s[i]==s[j]){
        sum++;
        j++;
    }
    else{
        i=j;
        sum++;
        j++;
    }
}
return sum;
}
