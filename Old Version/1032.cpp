#include<iostream>
using namespace std;
struct node {
	char key;
	int  next;
	bool flag;
}node[1000000];
int main() {

	int h1, h2, n;

	cin >> h1 >> h2 >> n;
	for (int i = 0; i < n; i++){
		int a, next;

		char key;

		cin >> a >> key >> next;

		node[a] = { key,next,false };

	}

	for (int i = h1; i != -1; i = node[i].next) {
		node[i].flag = true;
	}

	for (int i = h2; i != -1; i = node[i].next){

		if (node[i].flag) {
			printf("%05d", i);
			return 0;
		}
	}

	printf("-1");
	
	system("pause");

	return 0;

}