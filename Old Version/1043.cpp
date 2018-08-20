#include<iostream>
#include<vector>
using namespace std;
vector<int> pre, post;
bool flag = false;

void getPost(int root,int tail) {

	if (tail < root) return;

	int i = root + 1, j = tail;

	if (!flag) {
		while (i <= tail && pre[root] > pre[i]) i++;
		while (j > root && pre[root] <= pre[j]) j--;
	}
	else {
		while (i <= tail && pre[root] <= pre[i]) i++;
		while (j > root && pre[root] > pre[j]) j--;
	}

	if (i - j != 1) return;//²»ÊÇ¶þ²æËÑË÷Ê÷
	
	getPost(root + 1, j);
	getPost(i, tail);

	post.push_back(pre[root]);
}
int main() {

	int num;

	cin >> num;

	pre.resize(num);

	for (int i = 0; i < num; i++){
		cin >> pre[i];
	}

	getPost(0, num - 1);
	if (post.size() != num) {
		flag = true;
		post.clear();
		getPost(0, num - 1);
	}

	if (post.size() == num) {
		printf("YES\n%d", post[0]);
		for (int i = 1; i < num; i++)
			printf(" %d", post[i]);
	}
	else {
		printf("NO");
	}
	system("pause");
	return 0;

}