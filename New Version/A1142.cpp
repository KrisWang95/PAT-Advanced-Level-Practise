#include<iostream>
#include<vector>
using namespace std;

int g[210][210];
vector<int> v;
int num, num1, k, visited[210] = { 0 };

bool isC(int k) {
	for (int i = 0; i < v.size(); i++) {
		if (g[k][v[i]] != 1) {
			return false;
		}
	}
	return true;
}

bool isMax() {
	for (int i = 1; i <= num; i++) {

		if (isC(i) == true && visited[i] == 0) return false;
	}
	return true;
}



int main() {

	std::ios::sync_with_stdio(false);
	cin >> num >> num1;



	for (int i = 0; i < num1; i++) {
		int t, r;
		cin >> t >> r;
		g[t][r] = 1;
		g[r][t] = 1;
	}
	cin >> k;

	for (int i = 0; i < k; i++) {
		int n, temp;
		cin >> n;
		v.clear();
		fill(visited, visited + 210, 0);
		for (int j = 0; j < n; j++) {
			cin >> temp;
			visited[temp] = 1;;
			if (isC(temp)) {
				v.push_back(temp);
			}

		}
		if (v.size() != n) {
			cout << "Not a Clique\n";
		}
		else {
			if (isMax()) cout << "Yes\n";
			else cout << "Not Maximal\n";
		}
	}

	system("pause");

	return 0;

}