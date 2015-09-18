#include<iostream>
#include<stdio.h>
#include<memory.h>
using namespace std;
const int M=40000;
int c[M],ans[M];
int N;
int lowbit(int x){
    return (x&(-x));
}

int Sum(int pos){
    int sum=0;
    while(pos>0){
        sum+=c[pos];
        pos-=lowbit(pos);
    }
    return sum;
}

void update(int pos){
    while(pos<=M){
        c[pos]++;
        pos+=lowbit(pos);
    }
}

int main(){
    int x,y,i;
    cin>>N;
    memset(c,0,sizeof(c));
    memset(ans,0,sizeof(ans));
    for(i=1;i<=N;i++){
        cin>>x>>y;
        ans[Sum(x+1)]++;
        update(x+1);
    }
    for(i=0;i<N;i++)
        cout<<ans[i]<<endl;
}
