#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
//vector<int> nums;
int val=2;
int main(){
    int n[1]={2};
    //n={1,3,4,2,2,2,3,3,3,6,6,1,1,1};
    vector<int> nums(n,n+sizeof(n)/sizeof(int));
    int i=0;
        int j=nums.size()-1;
        while(true){
            while(i<nums.size()&&nums[i]!=val)
                i++;
            while(j>=0&&nums[j]==val)
                j--;
            if(i<j){
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
            else if(i>=nums.size()){
                    cout<<nums.size();
                return nums.size();
            }
            else {
                    cout<<j;
                    return j;
            }
        }
}
