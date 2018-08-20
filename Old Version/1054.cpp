#include<iostream>
#include<map>
using namespace std;

int main() {
	map<int, int> mm;
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			int temp;
			cin >> temp;
			if (mm.find(temp) != mm.end()) mm[temp]++;
			else mm[temp] = 1;
		}
	}
	int ans, max = -1;

	for (auto it = mm.begin(); it != mm.end(); it++ ) {
		if ( it->second > max) {
			max = it->second;
			ans = it->first;
		}
	}
	cout << ans;
	system("pause");
	return 0;
}