#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
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



int main() {

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {

		int t, temp;

		cin >> t;

		temp = t;

		vector<int> v;

		do {

			v.push_back(t % 10);

			t /= 10;

		} while (t != 0);

		int r = 0, l = 0, base = 1, b = 1;

		for(int i = 0; i <v.size(); i++){
		
			if (i < v.size() / 2) {

				r += v[i] * base;

				base *= 10;

			}
			else {

				l += v[i] * b;

				b *= 10;



			}

		}

		if( r != 0 && temp % (r * l) == 0)  cout << "Yes\n";

		else cout << "No\n";



	}



	system("pause");

	return 0;
}