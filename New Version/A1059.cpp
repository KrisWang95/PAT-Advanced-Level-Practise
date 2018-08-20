#include<iostream>
#include<cmath>
#include<map>
using namespace std;

const int maxn = 10010;

int primeTable[maxn];

int n = 0;

bool isPrime(int k) {

	if (k == 1) return false;

	else {

		int temp = sqrt(k);

		for (int i = 2; i <= temp; i++)

			if (k % i == 0) return false;

	}

	return true;
}

void getPrimeTable() {

	for (int i = 2; i < maxn; i++) {

		if (isPrime(i)) primeTable[n++] = i;

	}

}


int main() {

	getPrimeTable();

	int num;

	scanf("%d", &num);

	map<int, int> m;

	if (num == 1) printf("1=1");

	else printf("%d=", num);

	int temp = sqrt(num), i = 0;

	while (i < n && primeTable[i] <= temp) {

		if (num % primeTable[i] == 0) {

			if (m.find(primeTable[i]) == m.end()) m[primeTable[i]] = 1;

			else m[primeTable[i]]++;

			num /= primeTable[i];

		}

		else  i++;

		if (num == 1) break;

	}

	if (num != 1) m[num] = 1;

	for (auto it = m.begin(); it != m.end(); it++) {

		if (it != m.begin()) printf("*");

		printf("%d", it->first);

		if (it->second > 1) printf("^%d", it->second);

	}

	system("pause");

	return 0;

}