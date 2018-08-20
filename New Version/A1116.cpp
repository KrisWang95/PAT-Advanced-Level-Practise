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

map<int, int> r;

map<int, bool> v;

bool isPrime(int a) {

	if (a == 1) return false;

	for (int i = 2; i <= sqrt(a); i++) {

		if (a%i == 0)return false;

	}

	return true;

}

int main() {

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {

		int temp;

		cin >> temp;

		r[temp] = i + 1;

	}

	int queryN;

	cin >> queryN;

	for (int i = 0; i < queryN; i++) {

		int temp;

		cin >> temp;

		if (r.find(temp) == r.end()) {

			printf("%04d: Are you kidding?\n",temp);

		}
		else {


			if (v.find(temp) != v.end()) {

				printf("%04d: Checked\n",temp);

			}
			else {

				v[temp] = true;

				if (r[temp] == 1) {

					printf("%04d: Mystery Award\n", temp);

				}
				else if (isPrime(r[temp])) {

					printf("%04d: Minion\n", temp);

				}
				else {

					printf("%04d: Chocolate\n", temp);

				}

			}



		}

	}



	system("pause");

	return 0;
}