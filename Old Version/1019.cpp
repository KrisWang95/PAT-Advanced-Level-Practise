#include<iostream>
#include<vector>
using namespace std;
int main() {
	long long num, base;
	bool flag = true;
	cin >> num >> base;
	vector<int> v;
	do{
		int temp;
		temp = num % base;
		num = num / base;
		v.push_back(temp);
	} while (num != 0);
	for (int i = 0; i < v.size() / 2; i++) {
		if (v[i] != v[v.size() - i - 1])
			flag = false;
	}
	cout << (flag ? "Yes" : "No") << endl;
	for (int i = v.size() - 1; i > 0 ;  i--) {
		cout << v[i] << " ";
	}
	cout << v[0];
	system("pause");
	return 0;
}