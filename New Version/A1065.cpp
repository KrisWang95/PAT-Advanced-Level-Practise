#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;



int main() {

	int num;

	cin >> num;

	for (int i = 1; i <= num; i++) {

		long long a, b, c;

		cin >> a >> b >> c;

		long long sum = a + b;

		if (a > 0 && b > 0 && sum < 0) {

			printf("Case #%d: true\n", i);
		}
		else if (a < 0 && b < 0 && sum >= 0) {
			printf("Case #%d: false\n", i);

		}
		else if (sum > c) {
			printf("Case #%d: true\n", i);
		}
		else{
			printf("Case #%d: false\n", i);
		}

	}



	system("pause");

	return 0;

}