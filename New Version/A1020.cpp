#include <iostream>
#include <map>
#include <vector>
#include<string>
#include <algorithm>
using namespace std;

vector<int> post, in;
map<int,int> level;

void postT(int pl, int pr, int il, int ir,int index) {

	if (pl > pr || il > ir) return;

	int root = post[pr];

	level[index] = root;

	int k = 0;
	

	for (int i = il; i <= ir; i++) {
		if (in[i] == post[pr]) {
			k = i;
			break;
		}
	}
	int numLeft = k - il;

	postT(pl, pl + numLeft - 1, il, k - 1, index * 2 + 1);

	postT(pl + numLeft, pr - 1, k + 1, ir, index * 2 + 2);

}

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;
		post.push_back(temp);
	}

	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;
		in.push_back(temp);
	}
	postT(0, num - 1, 0, num - 1, 0);

	int cnt = 0;
	for (auto  it : level) {
		cout << it.second;
		cnt++;
		if (cnt < num) cout << " ";
	}
		

	system("pause");
	return 0;
}
