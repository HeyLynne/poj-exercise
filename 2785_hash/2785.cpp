#include<stdio.h>
#include<iostream>
using namespace std;
#define MAXNUM 4000
#define MAX 1000000000
#define size 20345677
#define key 745
int a[4][MAXNUM];
int n,ans;
int hash[size],sum[size];

void insert(int a){
    int tmp=(a+MAX)%size;
    while(hash[tmp]!=MAX&&hash[tmp]!=a)
        tmp=(tmp+key)%size;
    hash[tmp]=a;
    sum[tmp]++;
}

int find(int a){
    int tmp=(a+MAX)%size;
    while(hash[tmp]!=MAX&hash[tmp]!=a)
        tmp=(tmp+key)%size;
    if(hash[tmp]==MAX)
        return 0;
    else
        return sum[tmp];
}

int main(){
    int i,j;
    ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d %d %d",&a[0][i],&a[1][i],&a[2][i],&a[3][i]);
    for(i=0;i<size;i++)
        hash[i]=MAX;
    for(i=0;i<size;i++)
        sum[i]=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            insert(a[0][i]+a[1][j]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            ans+=find(-(a[2][i]+a[3][j]));
    printf("%d\n",ans);
}
