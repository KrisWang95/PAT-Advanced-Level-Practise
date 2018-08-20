#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

bool isPrime(int n) {
	if (n == 1) return false;

	int k = sqrt(n);

	for (int i = 2; i <= k; i++) {

		if (n % i == 0) return false;

	}
	return true;
}

int main() {

	int tableSize, n, m;

	cin >> tableSize >> n >> m;

	while (!isPrime(tableSize)) tableSize++;

	vector<int> v(tableSize);

	for (int i = 0; i < n; i++) {

		int temp;

		cin >> temp;

		bool flag = false;

		for (int j = 0; j < tableSize; j++) {

			int pos = (temp + j * j) % tableSize;

			if (v[pos] == 0) {

				v[pos] = temp;

				flag = true;

				break;

			}

		}

		if (flag == false) cout << temp << " cannot be inserted.\n";

	}

	int ans = 0;

	for (int i = 0; i < m; i++) {

		int temp;

		cin >> temp;

		int cnt = 1;

		for (int j = 0; j < tableSize; j++) {

			int pos = (temp + j * j) % tableSize;

			if (v[pos] == temp || v[pos] == 0) break;

			cnt++;

		}

		ans += cnt;

	}

	cout << setiosflags(ios::fixed) << setprecision(1) << ans * 1.0 / m;

	return 0;

}