#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int cnt = 0;

int getA(int a, int b) {

	do {

		v.push_back(a % b);
		cnt++;

		a /= b;

	} while (a != 0);

	int res = 0 ,t = 1;

	for (int i = cnt - 1; i >= 0; i--) {
		res += t * v[i];
		t *= b;
	}
	return res;
}

int main() {
	int num, r;
	cin >> num >> r;

	if (getA(num, r) == num) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

	for (int i = cnt - 1; i > 0; i--) {
		cout << v[i] << " ";
	}
	cout << v[0];
	
	system("pause");
	return 0;
	
}

