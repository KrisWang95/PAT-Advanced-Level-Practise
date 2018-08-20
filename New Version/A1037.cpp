#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int n, m, res  = 0 ;

	int coupon[100001], product[100001];

	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> coupon[i];
	}

	sort(coupon, coupon + n);

	cin >> m;

	for (int i = 0; i < m; i++) {

		cin >> product[i];
	}

	sort(product, product + m);

	for (int i = 0; i < n && i < m; i++) {

		if (coupon[i] < 0 && product[i] < 0) res += (coupon[i] * product[i]);

		if (coupon[n - 1 - i] > 0 && product[m - 1 - i] > 0) res += (coupon[n - 1 - i] * product[m - 1 - i]);

	}
	cout << res;

	system("pause");

	return 0;
}


