#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
#define MAXSIZE 1000005
#define SIZE 2000001
#define MAXNUM 1000000000
#define KEY 645

int a[MAXSIZE],hash[SIZE];
int m,num;

void insert(int k){
    int tmp=(k+MAXNUM)%SIZE;
    if(hash[tmp]==MAXNUM)
        ;
    else {
        if(hash[tmp]==k)
            return;
        while(hash[tmp]!=MAXNUM && hash[tmp]!=k){
            tmp=(tmp+KEY)%SIZE;
        }
    }
    hash[tmp]=k;
    num++;
}

int main(){
    int i,k;
    num=0;
    for(i=0;i<SIZE;i++)
        hash[i]=MAXNUM;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&k);
        insert(k);
    }
    printf("%d",num);
}
