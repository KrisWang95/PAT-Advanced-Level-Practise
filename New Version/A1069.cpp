#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {

	int n;

	scanf("%d", &n);

	vector<int> m;

	do{

		int first = 0, second = 0, base = 1;

		int cnt = 0;

		m.clear();

		m.resize(4);

		fill(m.begin(), m.end(), 0);

		while (n != 0) {

			m[cnt++] = n % 10;

			n /= 10;

		}

		sort(m.begin(), m.end());

		for (auto it : m) {

			first = first * 10 + it;

			second += it * base;

			base *= 10;

		}

		n = second - first;

		printf("%04d - %04d = %04d\n", second, first, n);

	}while(n != 0 && n != 6174);


	return 0;
}