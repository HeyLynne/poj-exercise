#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,ord=0;
struct DNA{
    string dna;
    int order;
};

DNA aDAN[101];

void Merge(string dna,int strat,int mid,int end){
    int s=strat;
    int e=mid+1;
    while(s<=mid&&e<=end){
        if(dna[s]>dna[e]){
            s++;
            ord+=(mid-s+1);
        }
        else{
            e++;
        }
    }
}

void MergeSort(string dna,int start,int end){
 if(start<end){
    int mid=(start+end)/2;
    MergeSort(dna,start,mid);
    MergeSort(dna,mid+1,end);
    Merge(dna,start,mid,end);
 }
}

bool cmp(DNA a1,DNA a2){
    return a1.order<a2.order;
}

int main(){
    int i,j;
    string temp;
    cin>>n>>m;
    for(i=0;i<m;i++){
        ord=0;
        cin>>temp;
        MergeSort(temp,0,temp.length()-1);
        aDAN[i].dna=temp;
        aDAN[i].order=ord;
    }
    stable_sort(aDAN[0],aDAN[m-1],cmp);
    for(i=0;i<m;i++){
        cout<<aDAN[i].dna<<endl;
    }
}
