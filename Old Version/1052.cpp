#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node {
	int address, next, key;
	bool flag = false;
}n[100010];
int num, start;
bool cmp(node a, node b) {
	if (a.flag == false || b.flag == false) return a.flag > b.flag;
	else return  a.key < b.key;
}
int main() {
	int num, start, address;
	cin >> num >> start;
	for (int i = 0; i < num; i++) {
		cin >> address;
		cin >> n[address].key >> n[address].next;
		n[address].address = address;
	}
	int cnt = 0, temp = start;
	while (temp != -1) {
		n[temp].flag = true;
		cnt++;
		temp = n[temp].next;
	}
	if (cnt == 0) {
		cout << "0 -1";
	}
	else {
		sort(n, n+100010, cmp);
		printf("%d %05d\n", cnt, n[0].address);
		for (int i = 0; i < cnt - 1; i++) {
			printf("%05d %d %05d\n", n[i].address, n[i].key, n[i + 1].address);
		}
		printf("%05d %d -1\n", n[cnt - 1].address, n[cnt - 1].key);
	}
	system("pause");
	return 0;
}
