#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<deque>
#include<cctype>
#include<climits>
#include<algorithm>
#include<cmath>
#define _CRT_SECURE_NO_WARNINGS
#define inf INT_MAX 
using namespace std;

vector<int> post, in;

map<int, int> level;

void getLevel(int inL, int inR, int postL, int postR,int index) {

	if (inL > inR || postL > postR) return;

	level[index] = post[postR];

	int k;

	for (k = inL; k < inR && in[k] != post[postR]; k++);

	int num = k - inL;

	getLevel(inL, k - 1, postL, postL + num - 1, 2 * index + 1);

	getLevel(k + 1, inR, postL + num, postR - 1, 2 * index + 2);

}



int main() {

	int n;

	cin >> n;

	post.resize(n);

	in.resize(n);

	for (auto & it : in) {

		cin >> it;
	}

	for (auto & it : post) {

		cin >> it;
	}

	getLevel(0, n - 1, 0, n - 1, 0);

	int last = 0 ,depth = 0, cnt = 0;

	vector<int> v;

	for (auto it = level.begin(); it != level.end(); it++) {

		if (last < it->first){

			last = 2 * last + 2;

			depth++;

			cnt = 0;

		}

		if (depth % 2 != 0) { 

			v.push_back(it->second);

		}

		else {

			v.insert(v.end() - cnt, it->second);

			cnt++;

		}

	}

	for (int i = 0; i < v.size(); i++) {

		if (i == 0) cout << v[i];

		else cout << " " << v[i]; 

	}


	system("pause");

	return 0;
}