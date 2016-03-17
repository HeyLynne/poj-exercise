#include<iostream>
#include<stdio.h>
using namespace std;
int rows;
int cols;

int path(int m,int n){
    if((m==cols-1&&n==rows-1)||(m==cols-1&&n==rows-2))
        return 1;
    return path(m+1,n)+path(m,n+1);
}

int main(){
    //int m,n;
    cin>>rows>>cols;
    cout<<path(0,0)<<endl;
    return 0;
}
