#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n;
int a[100000];
int k;

int main(){
   int i;
   int t;
   string s;
   scanf("%d",&n);
   for(i=0;i<n;i++)
        scanf("%d",&a[i]);
   sort(a,a+n);
   scanf("%s",&s);
   scanf("%d",&k);
   for(i=0;i<k;i++){
        scanf("%d",&t);
        printf("%d\n",a[t-1]);
   }
}
