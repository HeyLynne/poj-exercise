#include<iostream>
#include<vector>
using namespace std;
vector<int> nums;

void merge(int s,int m,int e){
    vector<int> tnum;
    int ss=s;
    int ms=m+1;
    int k=0;
    while(ss<=m&&ms<=e){
        if(nums[ss]<nums[ms])
            tnum.push_back(nums[ss++]);
        else
            tnum.push_back(nums[ms++]);
    }
    while(ss<=m)
        tnum.push_back(nums[ss++]);
    while(ms<=e)
        tnum.push_back(nums[ms++]);
    for(k=0;k<tnum.size();k++){
        nums[s+k]=tnum[k];
    }
}

void mergesort(int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        mergesort(start,mid);
        mergesort(mid+1,end);
        merge(start,mid,end);
    }
}

int main(){
    int m,i,n;
    cin>>m;
    for(i=0;i<m;i++){
        cin>>n;
        nums.push_back(n);
    }
    mergesort(0,m-1);
    for(i=0;i<m;i++)
        cout<<nums[i]<<' ';
}
