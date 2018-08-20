#include<iostream>
#include<vector>
using namespace std;
int main() {
	int upCnt = 0, downCnt = 0, sum;
	cin >> sum;
	vector<int> v;
	v.push_back(0);
	for (int i = 1; i <= sum; i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
		if (v[i] > v[i - 1]) {
			upCnt += (v[i] - v[i - 1]);
		}
		else if(v[i] < v[i - 1]){
			downCnt += (v[i - 1] - v[i]);
		}
	}
	cout << upCnt * 6 + downCnt * 4 + sum * 5;
	system("pause");
	return 0;
}