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
#define _CRT_SECURE_NO_WARNINGS
#define inf INT_MAX 
using namespace std;





int main() {

	int n;

	cin >> n;

	vector<int> u(n), v(n);

	for (auto &it : u) {

		cin >> it;

	}
	for (auto &it : v) {

		cin >> it;

	}

	int i = 0, j;

	for (; i < n  && v[i] <= v[i + 1]; i++);

	for (j = i + 1; j < n && u[j] == v[j]; j++);

	if (j == n) {

		cout << "Insertion Sort\n";

		sort(v.begin(), v.begin() + i + 2);

	}
	else {

		cout << "Heap Sort\n";

		i = n - 1;

		for (; i >= 0 && v[i] >= v[0]; i--);

		pop_heap(v.begin(), v.begin() + i + 1);

		/*i = n - 1;

		for (; i >= 0 && v[i] >= v[0]; i--);

		j = i;

		swap(v[0], v[j]);

		j--;

		int l = 0;

		for (int i = 0; i <= j / 2; i = l) {

			l = 2 * i + 1;

			if ( l != j && v[l] < v[l + 1]) l++;

			if (v[l] > v[i]) swap(v[l], v[i]);	

		}*/


	}

	for (int i = 0; i < n; i++) {

		if (i == 0) cout << v[i];

		else cout << " " << v[i];
	} 


	system("pause");

	return 0;
}