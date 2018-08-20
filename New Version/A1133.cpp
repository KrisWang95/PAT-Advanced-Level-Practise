#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cctype>
#include<climits>
#include<algorithm>
#include<cmath>
#define _CRT_SECURE_NO_WARNINGS
#define inf INT_MAX
using namespace std;

struct node{

	int address, key, next;

};



int main() {

	int head, n, k;

	scanf("%d %d %d", &head, &n, &k);

	vector<node> v(100000);

	vector<node> nege, less, great;


	for(int i = 0; i < n; i++){
	
		int add, key, ne;

		scanf("%d %d %d", &add, &key, &ne);

		v[add].address = add;

		v[add].key = key;

		v[add].next = ne;

	}

	while (head != -1){

		if (v[head].key < 0) {

			nege.push_back(v[head]);

		}
		else if (v[head].key <= k) {

			less.push_back(v[head]);

		}
		else {
			great.push_back(v[head]);

		}

		head = v[head].next;

	}

	v.clear();

	for (auto it : nege) {

		v.push_back(it);

	}

	for (auto it : less) {

		v.push_back(it);

	}

	for (auto it : great) {

		v.push_back(it);

	}

	
	if (v.size() > 0) {

		for (int i = 0; i < v.size(); i++) {

			if (i < v.size() - 1) printf("%05d %d %05d\n", v[i].address, v[i].key, v[i + 1].address);

		}

		printf("%05d %d -1\n", v[v.size() - 1].address, v[v.size() - 1].key);

	}

	system("pause");

	return 0;
}