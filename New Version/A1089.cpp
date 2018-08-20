#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cctype>
#include<climits>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {

	int n;

	cin >> n;

	vector<int> v(n), u(n);

	for (auto &it : v) {

		cin >> it;

	}
	for (auto &it : u) {

		cin >> it;

	}

	int i, j;

	for (i = 0; i < n - 1 && u[i + 1] >= u[i]; i++);

	for (j = i + 1; v[j] == u[j] && j < n; j++);

	if (j == n) {

		cout << "Insertion Sort\n";

		sort(v.begin(), v.begin() + i + 2);

	}
	else {

		cout << "Merge Sort\n";

		int k = 2;

		for (; v != u; k = k * 2) {

			int len = n / k;

			for (int j = 0; j < len; j++) {

				sort(v.begin() + j * k, v.begin() + j * k + k);

			}

			sort(v.begin() + n / k * k, v.end());

		}

		for (int j = 0; j < n / k; j++) {

			sort(v.begin() + j * k, v.begin() + j * k + k);

		}

		sort(v.begin() + n / k * k, v.end());

	}

	for (int i = 0; i < n; i++) {

		if (i == 0) cout << v[0];

		else cout << " " << v[i];

	}


	system("pause");

	return 0;
}