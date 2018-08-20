#include<iostream>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

bool positiveTable[LONG_MAX],negetiveTable[LONG_MAX];

int maxBlock = 46340;

 int positiveBlock[46340], negetiveBlock[46340];

long findKth(int k) {

	int cnt = 0, temp;

	for (int i = 0; i < maxBlock; i++) {


		if (cnt + negetiveBlock[i] >= k) {

			temp = i;

			break;

		}

		cnt += negetiveBlock[i];
		

	}

	if (cnt >= k) {

		for (long i = temp * maxBlock; i < (temp + 1) * maxBlock; i++) {

			cnt += negetiveTable[i];

			if (cnt == k) return i;

		}

	}
	else {

		for (int i = 0; i < maxBlock; i++) {


			if (cnt + positiveBlock[i] >= k) {

				temp = i;

				break;

			}

			cnt += positiveBlock[i];


		}

		for (long i = temp * maxBlock; i < (temp + 1) * maxBlock; i++) {

			cnt += positiveTable[i];
			
			if (cnt == k) return i;
 
		}

	}

}

int main() {

	int m, n, cnt;

	cin >> m;
	for (int i = 0; i < m; i++) {
		long int temp;
		cin >> temp;
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		long int temp;
		cin >> temp;
		b.push_back(temp);
	}

	cout << findKth((m + n) / 2);
	
	
	system("pause");

	return 0;
}
