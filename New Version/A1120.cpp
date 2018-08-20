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

int intToDigitSum(int x) {

	int sum = 0;

	do {

		sum += (x % 10);

		x /= 10;

	} while (x != 0);

	return sum;

}

int main() {

	int n;

	cin >> n;

	set<int> s;

	for (int i = 0; i < n; i++) {

		int temp; 

		cin >> temp;

		s.insert(intToDigitSum(temp));

	}

	cout << s.size() << endl;

	for (auto it = s.begin(); it != s.end(); it++) {

		if (it == s.begin()) cout << *it;

		else cout << " " << *it;
		
	}



	system("pause");

	return 0;
}