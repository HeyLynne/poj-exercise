#include <iostream>
#include <vector>
using namespace std;

int getIndex(int x) {
    return x & (x ^ (x - 1));
}
//构建树状数组
void buildTree(vector<int> &nums, vector<int> &tree){
    for(int i = 0;i < nums.size();i++) {
        int pos = i + 1;
        int index = getIndex(pos);
        for(int j = pos - index; j < pos;j++) {
            tree[i] += nums[j];
        }
    }
}
//求前n项的和
int getSum (vector<int> &trees, int pos) {
    int sum = 0;
    while(pos >= 0) {
        sum += trees[pos];
        pos -= (getIndex(pos + 1));
    }
    return sum;
}
//某个位置的数值发生变化，val是差值
void update(vector<int> &trees, int pos, int val) {
    while (pos < trees.size()) {
        trees[pos] += val;
        pos += getIndex(pos + 1);
    }
}
//获取特定位置的值
int getPosNum(vector<int> &trees, int pos) {
    if (pos == 0) {
        return trees[pos];
    }
    int sum = trees[pos];
    int z = pos - getIndex(pos + 1);
    pos -= 1;
    while (pos != z) {
        sum -= trees[pos];
        pos -= getIndex(pos + 1);
    }
    return sum;
}
int main(){
    int a[10] = {5,12,-3,13,4,1,5,9,2,7};
    vector<int> nums(a, a + 10);
    vector<int> tree(10, 0);
    buildTree(nums,tree);
//    int c = getSum(tree,3);
//    cout << c << endl;

//    update(tree,2,2);
//    for (int i = 0;i < 10;i++) {
//        cout << tree[i] << endl;
//    }

    int c = getPosNum(tree,2);
    cout << c << endl;
}
