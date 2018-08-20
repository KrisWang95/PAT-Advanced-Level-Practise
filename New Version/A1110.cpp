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

struct node {

	int left = -1, right = -1;

};



int main() {

	int n;

	cin >> n;

	vector<bool> isRoot(n, false);

	vector <node> v(n);

	for (int i = 0; i < n; i++) {

		string s, as;

		cin >> s >> as;

		if (s != "-") {

			int temp = stoi(s);

			v[i].left = temp;

			isRoot[temp] = true;

		}

		if (as != "-") {

			int temp = stoi(as);

			v[i].right = temp;

			isRoot[temp] = true;

		}

	}

	int root ,last;

	for (int i = 0; i < n; i++) {

		if (isRoot[i] == false) {

			root = i;
		}

	}

	bool res = true, isN = false;;

	queue<int> q;

	q.push(root);

	while (!q.empty()) {

		int k = q.front(); q.pop();

		if (k >= 0) last = k;

		if (k != -1) {

			q.push(v[k].left);

			q.push(v[k].right);

		}
		else{

			isN = true;

		}

		if( isN) {

			if (k >= 0) {

				res = false;

				break;

			}

		}


	}




	if (res) cout << "Yes " << last;

	else cout << "No " << root;


	system("pause");

	return 0;
}