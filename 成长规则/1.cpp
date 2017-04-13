#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int main(){
vector<vector<int> > k;
vector<int> single;
unordered_map<int,int> rec;
int last=0;
int val=0;
int start=0;
int end=0;
int sum=0;
while(cin){
    vector<int>().swap(single);
    int m;
    cin>>m;
    if(m==1){
        single.push_back(1);
        for(int i=0;i<3;i++){
            cin>>m;
            if(i==2&&m>last) last=m;
            single.push_back(m);
        }
    }
    if(m==2){
        single.push_back(2);
        for(int i=0;i<2;i++){
            cin>>m;
            single.push_back(m);
        }
    }
    k.push_back(single);
}
for(int i=0;i<k.size();i++){
    if(k[i][0]==1){
        for(int j=k[i][1];j<=k[i][2];j++){
            if(rec.find(j)!=rec.end()&&rec[j]<k[i][3]) rec[j]=k[i][3];
            else rec[j]=k[i][3];
        }
    }
    if(k[i][0]==2){
        if(k[i][1]<=last-1)
            sum+=k[i][2];
    }
}
for(auto& x:rec){
    sum+=x.second;
}
cout<<sum;
return sum;
}
