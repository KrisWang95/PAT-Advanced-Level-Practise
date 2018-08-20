#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	string n;

	cin >> n;

	int len = n.length() + 2;

	int n1, n2, n3;

	n1 = n3 = len / 3;

	n2 = len - n1 * 2;

	for (int i = 0; i < n1 - 1 ; i++) {

		cout << n[i];

		for (int j = 0; j < n2 - 2; j++) {

			cout << " ";

		}

		cout << n[len - i - 3] << endl;

	}

	for (int i = 0; i < n2; i++) {

		cout << n[n1 - 1 + i];

	}
	
	system("pause");

	return 0;
}


