#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(string a, string b) {

	return a < b;
}

int main() {

	int num;

	cin >> num;

	vector<int> v(num);

	
	int n[10001] = { 0 };

	for (int i = 0; i < num; i++) {

		cin >> v[i] ;

		n[v[i]] ++;

	}
	int res = -1;

	for (int i = 0; i < v.size(); i++) {

		if (n[v[i]] == 1) { 

			res = v[i];

			break; 

		}

	}

	

	if(res != -1) cout << res;

	else cout << "None";

	system("pause");

	return 0;
}


