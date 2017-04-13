#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> di;
vector<bool> isdi;
int find(int i){
	//int tmp = 0;
	int cnt = 0;
	int last = i;
	for (int j = i; j < di.size(); j++){
		if (cnt >= 2) break;
		if (di[j] - di[last] <= 10 && isdi[j]){
			cnt++;
			isdi[j] = false;
			last = j;
		}
	}
	return (2 - cnt);
}

int main(){
	int n;
	int tmp;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		di.push_back(tmp);
		isdi.push_back(true);
	}
	sort(di.begin(), di.end());
	int tB = 0;
	int tE = 1;
	int res = 0;
	for (int i = 0; i < n; i++){
		if (isdi[i]){
			isdi[i] = false;
			res += find(i);
		}
	}
	for (int i = 0; i < isdi.size(); i++){
		if (isdi[i]) res++;
	}
	cout << res;
	return res;
}