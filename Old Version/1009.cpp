#include<iostream>
#include<vector>
using namespace std;
typedef struct node {
	int ex;
	float co;
}poly;
int main() {
	int m = 0, n = 0, cnt = 0;
	float result[2001];
	vector<poly> v;
	cin >> m;
	for (int i = 0; i <= 2000; i++)
		result[i] = 0;
	for (int  i = 0; i < m; i++){
		poly a;
		cin >> a.ex >> a.co;
		v.push_back(a);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp1;
		float temp2;
		cin >> temp1 >> temp2;
		for (int i = 0; i < v.size(); i++)
			result[temp1 + v[i].ex] += temp2*v[i].co;
	}

	for (int i = 0; i <= 2000; i++)
		if (result[i])
			cnt++;
	cout << cnt ;
	for (int i = 2000; i >= 0; i--)
		if (result[i])
			printf(" %d %.1f", i, result[i]);
	return 0;
}
