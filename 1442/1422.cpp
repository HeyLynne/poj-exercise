#include<iostream>
#include<stdio.h>
const int MAX_N=1000001;

int n,k;
int a[MAX_N],qup[MAX_N],index[MSX_N],ans[MAX_N];

void getmin(){
    int head=1,tail=0;
    int i;
    for(i=1;i<=k;i++){
        while(tail>=head&&qu[tail]>=a[i])
            tail--;
        qu[++tail]=a[i];
        index[tail]=i;
    }
    for(i=k;i<=n;i++){
        while(tail>=head&&qu[tail]>=a[i])
            tail--;
        qu[++tail]=a[i];
        if(index[head]<=i-k)head++;
        ans[i-k]=qu[head];
    }
}

void getmax(){
    int head=1,tail=0;
    int i;
    for(i=1;i<=k;i++){
        while(tail>=head&&qu[tail]<=a[i])
            tail--;
        qu[++tail]=a[i];
        index[tail]=i;
    }
    for(i=k;i<=n;i++){
        while(tail>=head&&qu[tail]<=a[i])
            tail--;
        qu[++tail]=a[i];
        if(index[head]<=i-k)
            head++;
        ans[i-k]=qu[head];
    }
}

int main(){
    cin>>n>>k;
    int i;
    for(i=1;i<=n;i++)
        cin>>a[i];
    getmin();
    for(i=0;i<=n-k;i++)
        cout<<ans[i];
    cout<<endl;
    getmax();
    for(i=0;i<=n-k;i++)
        cout<<ans[i];
    cout<<endl;
    return 0;
}
