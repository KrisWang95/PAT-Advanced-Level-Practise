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
#define INT_MAX inf
using namespace std;

string b[] = { "ling", "yi","er","san","si","wu","liu","qi","ba","jiu" };

string base[] = { "Qian","","Shi","Bai" };

int main() {

	int n ,temp;

	scanf("%d", &n);

	vector<string> res;

	if (n < 0) res.push_back("fu");

	n = temp = abs(n);

	if (n == 0) res.push_back("ling");

	vector<int> v;

	do {

		v.push_back(n % 10);

		n /= 10;


	} while (n != 0);

	bool isZero = false;

	for (int j = v.size(); j > 0; j--) {

		if (v[j - 1] != 0) {

			if (isZero) {

				res.push_back("ling");

				isZero = false;

			}

			res.push_back(b[v[j - 1]]);

			if(j % 4 != 1)res.push_back(base[j % 4]);


		}
		else{

			if (isZero == false && (j - 1) % 4 != 0) { //»¹ÓÐbug

				isZero = true;

			}


		}

		if (j == 9) {

			res.push_back("Yi");

		}
		else if (j == 5 && (temp / 10000) % 10000 > 0) {

			res.push_back("Wan");

		}

	}

	for (auto it = res.begin(); it != res.end(); it++) {

		if (it == res.begin()) cout << *it;

		else cout << " " << *it;

	}

	system("pause");

	return 0;
}