#include<iostream>
using namespace std;
int num, b[100010];

int getMinMissingInter(int a[]) {

	for (int i = 0; i < num; i++) {
		while (a[i] >= 0 && a[i] < num - 1 && a[i] != a[a[i]]) {
			swap(a[i], a[a[i]]);
		}
	}

	for (int j = 0; j < num; j++) {
		if (a[j] != j) {
			return j;
		}
	}

	return num;
}


int main() {
	
	std::ios::sync_with_stdio(false);

	cin >> num;

	for (int j = 0; j < num; j++) {
		scanf("%d", &b[j]);
	}

	int ans = getMinMissingInter(b);

	printf("%d\n", ans);

	return 0;
}