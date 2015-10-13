#include<iostream>
using namespace std;
#define MAXSIZE 100010
int i,j,n,s;
int a[MAXSIZE];

int main(){
    int k,sum,minlen,m;
    cin>>m;
    while(m--){
        cin>>n>>s;
        for(k=0;k<n;k++)
            cin>>a[k];
        i=0;j=0;
        sum=0;
        minlen=n+1;
        while(1){
            while(j<n&&sum<s){
                sum+=a[j++];
            }
            if(sum<s) break;
            minlen=min(minlen,(j-i));
            sum-=a[i];
            i++;
        }
        if(minlen==n+1)
            cout<<0<<endl;
        else
            cout<<minlen<<endl;
    }
}


