#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n[10]={1,2,2,2,2,0,0,0,1,1};
    vector<int> nums(n,n+sizeof(n)/sizeof(int));
    int r=0;
        int b=nums.size()-1;
        int p;
        while(nums[r]==0)
            r++;
        while(nums[b]==2)
            b--;
        p=r+1;
        while(r<b){
            if(nums[p]==0&&p>r){
                swap(nums[r],nums[p]);
                p++;
                r++;
            }
            else if(nums[p]==2&&p<b){
                swap(nums[b],nums[p]);
                p++;
                b--;
            }
            else
                p++;
        }
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<' ';
}
