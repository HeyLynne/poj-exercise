#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > res;
vector<int> subres;
void permutate(vector<int> &nums, int start, int k){
	if (k == nums.size()){
		res.push_back(subres);
		return;
	}
	for (int i = start; i < nums.size(); i++){
		subres.push_back(nums[start]);
		//这里的递归下一步条件是错的，
		permutate(nums, start+ 1, k + 1);
		subres.pop_back();
	}
}
int main(){
	vector<int> nums = { 1, 2, 3 };
	permutate(nums, 0, 0);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[0].size(); j++){
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
}