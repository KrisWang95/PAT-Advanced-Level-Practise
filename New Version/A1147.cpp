#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int m, n;
vector<int> v;
void postOrder(int index) {
	if (index >= n) return;
	postOrder(index * 2 + 1);
	postOrder(index * 2 + 2);
	printf("%d%s", v[index], index == 0 ? "\n" : " ");

}

bool cmp(int a, int b) { return a > b; }
int main() {
	scanf("%d%d", &m, &n);
	v.resize(n);
	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) scanf("%d", &v[j]);

		int flag = v[0] > v[1] ? 1 : -1;

		if (flag == 1) {

			if (!is_heap(v.begin(), v.end())) flag = 0;

		}
		else {

			if (!is_heap(v.begin(), v.end(), cmp)) flag = 0;

		}

		if (flag == 0) printf("Not Heap\n");

		else printf("%s Heap\n", flag == 1 ? "Max" : "Min");

		postOrder(0);
	}

	return 0;
}