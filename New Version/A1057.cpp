#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;

int table[100000] = { 0 }, block[316] = { 0 };

stack<int> s;


int getPeekMedian() {

	int k = (s.size() % 2 == 0 ? s.size() / 2 : s.size() / 2 + 1);

	int sum = 0, i = 0;
	while (sum + block[i] < k) {
		sum += block[i++];
	}

	int num = i * 316;

	while (sum + table[num] < k) {
		sum += table[num++];
	}

	return num;

}



int main(){

	int query;

	cin >> query;

	for (int i = 0; i < query; i++) {
		string c;

		int k;

		cin >> c;

		if (c == "Push") {

			getchar();

			cin >> k;

			table[k]++;

			block[k / 316]++;

			s.push(k);

		}
		else if (c == "Pop") {

			if (s.empty()) {

				cout << "Invalid\n";

				continue;
			}

			k = s.top();

			s.pop();

			table[k]--;

			block[k / 316]--;

			cout << k << endl;

		}
		else {

			if (s.empty()) {

				cout << "Invalid\n";

				continue;
			}

			cout << getPeekMedian() << endl;

		}
	}

	

	system("pause");

	return 0;
}


