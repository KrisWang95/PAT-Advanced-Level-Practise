#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include<string>
#include<climits>
#include<stack>

using namespace std;

vector<int> in, pre,post;

void getPost(int root,int inL, int inR) {

	if (inL > inR) return;

	int k = 0;

	while (k < inR && pre[root] != in[k]) k++;

	int num = k - inL;

	getPost(root + 1, inL, k - 1);

	getPost(root + num + 1, k + 1, inR);

	post.push_back(pre[root]);
}

int main() {

	stack<int> st;

	int n;

	cin >> n;

	for (int i = 0; i < n * 2; i++) {

		string s;

		cin >> s;

		if (s == "Push") {
			int t;

			cin >> t;

			st.push(t);

			pre.push_back(t);
		}
		else {

			in.push_back(st.top());

			st.pop();

		}
	}

	getPost(0, 0, n - 1);

	for (int i = 0; i < n; i++) {

		if (i == 0) cout << post[0];

		else cout << " " << post[i];

	}

	

	system("pause");

	return 0;
}