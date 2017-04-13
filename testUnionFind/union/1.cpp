#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int unionCnt = 0;
vector<int> union10;

void makeUnion() {
    for (int i = 1;i <= 10;i++) {
        union10.push_back(i);
    }
    unionCnt = 10;
}
// 普通解法，时间复杂度是O(n)
int findUnion(int index) {
    return union10[index];
}

void connect(int node1, int node2) {
    int uId1 = findUnion(node1);
    int uId2 = findUnion(node2);
    for (int i = 0;i < union10.size();i++) {
        if (union10[i] == uId1) {
            union10[i] = uId2;
        }
    }
    unionCnt--;
}

//quick union,时间复杂度是O(logn)
int findUnionQuick(int index) {
    while(index != union10[index - 1]) {
        index = union10[index - 1];
    }
    return index;
}

void connectQuick(int node1, int node2) {
    int uId1 = findUnionQuick(node1);
    int uId2 = findUnionQuick(node2);
    if (uId1 == uId2) {
        return;
    }
    union10[node1 - 1] = node2;
    unionCnt--;
    return;
}

int main() {
    makeUnion();
    connectQuick(1,3);
    connectQuick(2,3);
    connectQuick(5,8);
    cout << "union count is " << unionCnt << endl;
}
