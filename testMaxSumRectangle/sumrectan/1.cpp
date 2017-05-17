#include <iostream>
#include <vector>
using namespace std;

int findMaxSum(vector<int> &sum, int &k) {
    int maxSumTmp = sum[0], maxSum = sum[0];
    int res = INT_MIN;
    for (int i = 1;i < sum.size();i++) {
        maxSumTmp = max(sum[i], maxSumTmp + sum[i]);
        if (maxSumTmp <= k) {
            res = max(maxSumTmp, res);
        }
        maxSum = max(maxSumTmp, maxSum);
    }
    return res;
}

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }
    int rows = matrix.size(), cols = matrix[0].size();
    int currentMax = INT_MIN;
    int res = INT_MIN;
    for (int l = 0;l < cols;l++) {
        vector<int> rowSum(rows, 0);
        int sumMax = INT_MIN;
        for (int r = l;r < cols;r++) {
            for (int row = 0;row < rows;row++) {
                rowSum[row] += matrix[row][r];
            }
            currentMax = findMaxSum(rowSum, k);
            if (currentMax <= k) {
                res = max(res, currentMax);
            }
        }
    }
    return res;
}

int main() {
    int a[1][3] = {{2,2,-1}};
    vector<vector<int> > matrix(1);
    for (int i = 0;i < 1;i++) {
        for (int j = 0;j < 3;j++) {
            matrix[i].push_back(a[i][j]);
        }
    }
    int k = 10;
    int res = maxSumSubmatrix(matrix, k);
    cout << res;
}
