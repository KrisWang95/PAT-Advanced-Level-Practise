#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> post,pre;

bool flag = true;;

void getPost(int preL, int preR) {

	if (preL > preR) return;

	int i = preL + 1 , j = preR;

	if (flag) {

		while (i <= preR && pre[preL] > pre[i]) i++;
		while (j > preL && pre[j] >= pre[preL]) j--;

	}
	else {

		while (i <= preR && pre[preL] <= pre[i]) i++;
		while (j > preL && pre[j] < pre[preL]) j--;

	}

	if (i - j != 1) return;

	getPost(preL + 1, j);

	getPost(i,preR);

	post.push_back(pre[preL]);

}


int main() {

	int num;

	cin >> num;

	for (int i = 0; i < num; i++) {

		int temp;

		cin >> temp;

		pre.push_back(temp);

	}

	getPost(0, num - 1);

	if (post.size() != num) {

		post.clear();

		flag = false;

		getPost(0, num - 1);

	}

	if (post.size() == num) {

		cout << "YES\n" << post[0];

		for (int i = 1; i < num; i++) {

			cout << " " << post[i];

		}

	}
	else {

		cout << "NO\n";

	}

	
	
	system("pause");

	return 0;
}


