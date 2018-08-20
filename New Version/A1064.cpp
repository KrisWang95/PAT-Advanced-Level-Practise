#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> in,level;

int num, cnt = 0;

void getLevel(int l, int r, int index) {

	if (l > r) return;

	int len = r - l + 1;

	int num = pow(2, (int)log2(len));

	int left = (len - num + 1 > num / 2 ? num / 2 : len - num + 1) + (num - 1) / 2;

	//int right = (len - num + 1 > num / 2 ? len - num + 1 - num / 2 : 0) + (num - 1) / 2;

	getLevel(l, l + left - 1, index * 2 + 1);

	level[index] = in[l + left];

	getLevel(l + left + 1,r, index * 2 + 2);
	
}


int main() {

	cin >> num;

	in.resize(num);

	level.resize(num);

	for (auto &it : in) {

		cin >> it;

	}

	sort(in.begin(), in.end());

	getLevel(0,num-1,0);

	for (auto it = level.begin(); it != level.end(); it++) {

		if (it == level.begin()) cout << *it;
		else cout << " " << *it;

	}

	system("pause");

	return 0;

}