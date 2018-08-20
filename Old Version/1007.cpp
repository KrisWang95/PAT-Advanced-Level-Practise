#include<iostream>
using namespace std;
int main() {

	int k;

	cin >> k;

	int N[20000], maxSum = -1, s = 0, e = k - 1, s1 = 0, sum = 0;

	bool tag = false;

	for (int i = 0; i < k; i++) {

		cin >> N[i];

		sum += N[i];

		if (maxSum < sum) {

			maxSum = sum;

			s = s1;

			e = i;

		}
		else if (sum < 0) {

			sum = 0;

			s1 = i + 1;

		}

	}

	if (maxSum < 0) maxSum = 0;

	cout << maxSum << " " << N[s] << " " << N[e];

	system("pause");
}