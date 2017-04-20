#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 7;
    vector<int> res;
    res.push_back(1);
    int i2=0,i3=0,i5=0;
    while(res.size()<n){
        int m2=res[i2]*2;
        int m3=res[i3]*3;
        int m5=res[i5]*5;
        int mn=min(m2,min(m3,m5));
        if(mn==m2) i2++;
        if(mn==m3) i3++;
        if(mn==m5) i5++;
        res.push_back(mn);
    }
    cout <<  res[n - 1];
}
