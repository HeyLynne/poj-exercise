#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
struct cow{
    int svote;
    int pos;
}Cow;
map<int,cow,greater<int> > mapcow;
map<int,int,greater<int> > mapcow1;

int main(){
    int n,k;
    int first,second,i;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>first>>second;
        Cow.svote=second;
        Cow.pos=i+1;
        mapcow.insert(pair<int,cow>(first,Cow));
    }
    map<int,cow>::iterator iter=mapcow.begin();
    for(i=0;i<k;i++){
        mapcow1.insert(pair<int,int>(iter->second.svote,iter->second.pos));
        iter++;
    }
    cout<<mapcow1.begin()->second<<endl;
}
