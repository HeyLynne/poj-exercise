#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAXVALUE 99999
int d[8][8]={{0,14,25,27,10,11,24,16},{14,0,18,15,27,28,16,14},{25,18,0,19,14,19,16,10},{27,15,19,0,22,23,15,14},{10,27,14,22,0,14,13,20},{11,28,19,23,14,0,15,18},
{24,16,16,15,13,15,0,27},{16,14,10,14,20,18,27,0}};
int t[8][8];
int s[8][8];
int p[6][3];
int st[6][2];
int m=0;

int getWeight(int i,int j,int k)
{
    return d[i][j]+d[j][k]+d[i][k];
}

void min_triangle_value(){
int i,j,d,k,p;
for(i=0;i<8;i++)
    t[i][i]=0;
for(d=1;d<8;d++){
    for(i=1;i<8-d;i++){
        j=i+d;
        t[i][j]=MAXVALUE;
        for(k=i;k<j;k++){
           p=t[i][k]+t[k+1][j]+getWeight(i-1,j,k);
           if(p<t[i][j]){
                t[i][j]=p;
                s[i][j]=k;
           }
        }
    }
}
}

void backTrace(int a,int b){
if(a==b)
    return;
backTrace(a,s[a][b]);
backTrace(s[a][b]+1,b);
p[m][0]=a;
p[m][1]=s[a][b]+1;
p[m++][2]=b+1;
cout<<"Best sub triangle: "<<a<<s[a][b]+1<<b+1<<endl;
}

bool ifNeighbor(int i,int j){
if((abs(i-j)==1)||(i==1&&j==8)||(i==8&&j==1))
    return true;
else return false;
}

void getString(){
int i,j;
int m=0;
//int flag=1;
for(i=0;i<6;i++){
    if(!ifNeighbor(p[i][0],p[i][1])){
        for(j=0;j<i;j++){
            if((p[i][0]==st[j][0]||p[i][0]==st[j][1])&&(p[i][1]==st[j][0]||p[i][1]==st[j][1]))
                break;
        }
        if(j==i){
            //flag=0;
            st[m][0]=p[i][0];
            st[m++][1]=p[i][1];
        }
    }
    if(!ifNeighbor(p[i][0],p[i][2])){
        for(j=0;j<i;j++){
            if((p[i][0]==st[j][0]||p[i][0]==st[j][1])&&(p[i][2]==st[j][0]||p[i][2]==st[j][1]))
                break;
        }
        if(j==i){
            st[m][0]=p[i][0];
            st[m++][1]=p[i][2];
        }
    }
    if(!ifNeighbor(p[i][1],p[i][2])){
        for(j=0;j<i;j++){
            if((p[i][1]==st[j][0]||p[i][1]==st[j][1])&&(p[i][2]==st[j][0]||p[i][2]==st[j][1]))
                break;
        }
        if(j==i){
            st[m][0]=p[i][1];
            st[m++][1]=p[i][2];
        }
    }
}
for(i=0;i<m;i++){
    cout<<"The dividing string: "<<st[i][0]<<st[i][1]<<endl;
}
}
int main(){
    min_triangle_value();
    cout<<"Min value:"<<t[1][7]<<endl;
    backTrace(1,7);
    getString();
}
