//SY1506124 周萱
#include<iostream>
#include<stdio.h>
#include <windows.h>
using namespace std;
#define MAXCOST 1500
#define MAXDIS 9999

int length[50][50];
int cost[50][50];
int path[50][50];
int minToEnd[50];
int minLength=9999;
int allfee=0;
struct pNode{
int node;//节点记录
int path;//路径长度
int cost;//花费
}sNode[50];
int minPath[50];
int cities;

//弗洛伊德算法获取每个点之间的最短路径
void floyd(){
int i,j,k;
for(i=0;i<50;i++){
    for(j=0;j<50;j++)
        for(k=0;k<50;k++){
            if(path[i][k]+path[k][j]<path[i][j]){
                path[i][j]=path[i][k]+path[k][j];
            }
    }
}
}

void getMinToEnd(){
int i;
for(i=0;i<50;i++)
    minToEnd[i]=path[i][49];
minToEnd[49]=0;
}

//剪枝判断
bool ifCutThisWay(int step){
int i;
for(i=0;i<step;i++)
    if(sNode[i].node==sNode[step].node)
        return true;
if(sNode[step].cost>MAXCOST||sNode[step].path+minToEnd[sNode[step].node]>=minLength)
        return true;
return false;
}

void branch(int step){
int i;
if(step>=50)
    return;
for(i=1;i<50;i++){
sNode[step].node=i;
sNode[step].cost=sNode[step-1].cost+cost[sNode[step-1].node][i];
sNode[step].path=sNode[step-1].path+length[sNode[step-1].node][i];
if(!ifCutThisWay(step)){
    if (i == 49){
        for (int j = 0; j <= step; j++)
            minPath[j] = sNode[j].node;
        minLength = sNode[step].path;
        allfee = sNode[step].cost;
        cities = step;
        return;
        }
   branch(step+1);
}
}
}

void printAnswer(){
cout<<"Min Path:"<<minLength<<endl;
cout<<"The Cost:"<<allfee<<endl;
int i;
cout<<"The cities we are going to go through are:"<<endl;
for(i=0;i<cities;i++)
    cout<<minPath[i]+1<<"->";
cout<<minPath[cities]+1<<endl;
}

int main(){
int i,j;
freopen("m1.txt","r",stdin);
for(i=0;i<50;i++){
    for(j=0;j<50;j++){
        cin>>length[i][j];
        path[i][j]=length[i][j];
    }
}
freopen("m2.txt","r",stdin);
for(i=0;i<50;i++){
    for(j=0;j<50;j++)
        cin>>cost[i][j];
}
floyd();
getMinToEnd();
branch(1);
printAnswer();
system("pause");
}
