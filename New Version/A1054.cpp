#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

int main(){

	ios::sync_with_stdio(false);

	map<int, int> mm;

	int n, m, maxn;

	cin >> n >> m;

	for (int i = 0; i < n * m; i++) {

		int temp = 0;

		cin >> temp;

		if (mm.find(temp) == mm.end()) mm[temp] = 1;

		else mm[temp]++;

		maxn = max(maxn, mm[temp]);

	}

	for (auto it : mm) {
		if (it.second == maxn) {
			cout << it.first; 
			break;
		}
	}


	
	
	system("pause");

	return 0;
}


