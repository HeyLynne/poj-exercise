#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

#define MAXNUM 4000
#define MAXNUMQUT 16000000
int a[4][MAXNUM],n,num,c;
int num1[MAXNUMQUT],num2[MAXNUMQUT];

int div(int left,int right,int a){
    while(left<=right){
        int i;
        int mid=(left+right)/2;
        int nu=0;
        if(num2[mid]==a){
            nu=1;
            for(i=mid-1;i>=0&&num2[i]==a;i--)  nu++;
            for(i=mid+1;i<n*n&&num2[i]==a;i++)  nu++;
            return nu;
        }
        else if(num2[mid]>a)
            right=mid-1;
        else
            left=mid+1;
    }
    return 0;
}

int main(){
    int i,j;
    num=0;
    c=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&a[0][i],&a[1][i],&a[2][i],&a[3][i]);
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            num1[c]=a[0][i]+a[1][j];
            num2[c++]=-(a[2][i]+a[3][j]);
        }
    sort(num2,num2+c);
    for(i=0;i<c;i++){
        num+=div(0,c,num1[i]);
    }
    printf("%d\n",num);
}
