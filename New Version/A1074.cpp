#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include<string>
#include<climits>
using namespace std;

struct node {

	int address;

	int next;

	int data;

}listnode[100000];



int main() {

	ios::sync_with_stdio(false);

	int root, n, k;

	cin >> root >> n >> k;

	for (int i = 0; i < n; i++) {

		int temp;

		cin >> temp;

		listnode[temp].address = temp;

		cin >> listnode[temp].data >> listnode[temp].next;

	}

	vector<node> v(100010);

	int j = 0;

	for (int i = root; i != -1; i = listnode[i].next) {

		v[j / k * k + k - 1 - (j % k)] = listnode[i];

		j++;

	}

	reverse(v.begin() + j - j % k, v.begin() + j - j % k + k);

	for (int i = 0; i < j; i++) {

		if (i < j - 1)printf("%05d %d %05d\n", v[i].address, v[i].data, v[i + 1].address);

		else printf("%05d %d -1", v[i].address, v[i].data);

	}

	system("pause");

	return 0;
}