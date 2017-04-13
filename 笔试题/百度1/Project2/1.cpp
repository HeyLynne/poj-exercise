#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
int main(){
	string s;
	int sum = 0;
	cin >> s;
	int i = 0;
	int j = 1;
	sum = 1;
	unordered_set<string> k;
	k.insert(s.substr(0, 1));
	while (i<s.size() && j<s.size()){
		if (s[i] == s[j]){
			string m = s.substr(i, j - i + 1);
			if (k.find(m) == k.end()){
				sum++;
				k.insert(m);
			}
			j++;
		}
		else{
			i = j;
			if (k.find(s.substr(i,1)) == k.end()){
				sum++;
				k.insert(s.substr(i, 1));
			}
			//sum++;
			j++;
		}
	}
	cout << sum;
	return sum;
}

