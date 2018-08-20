#include <iostream>
using namespace std;
int a[1001];
int main() {
	int n, m, temp;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		a[temp]++;
	}
	//散列查找，还可以二分查找，双指针
	for (int i = 0; i < 1001; i++) {
		if (a[i]) {
			a[i]--;
			if (m > i && a[m - i]) {
				printf("%d %d", i, m - i);
				return 0;
			}
			a[i]++;
		}
	}
	printf("No Solution");
	return 0;
}