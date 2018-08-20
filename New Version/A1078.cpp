#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include<string>
#include<cmath>
#include<queue>
using namespace std;

bool isPrime(int k) {

	if (k == 1)return false;

	int s = sqrt(k);

	for (int i = 2; i <= s; i++) {

		if (k %i == 0)	return false;

	}
	return true;
}





int main() {

	int table_size, num;

	cin >> table_size >> num;

	while (!isPrime(table_size)) table_size++;

	vector<int> table(table_size,0), n(num);

	for (auto &it : n) {

		cin >> it;

		bool isIn = false;

		for (int i = 0; i < table_size; i++) {

			int pos = (it + i * i) % table_size;

			if (table[pos] == 0) {

				isIn = true;

				table[pos] = it;

				it = pos;

				break;

			}

		}

		if (!isIn) it = -1;

	}

	for (int i = 0; i < num; i++) {

		if (i == 0) if (n[i] == -1) cout << '-'; else cout << n[i];

		else { cout << " "; if (n[i] == -1) cout << '-'; else cout << n[i]; }

	}
	

	
	
	system("pause");

	return 0;
}