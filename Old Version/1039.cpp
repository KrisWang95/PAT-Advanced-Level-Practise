#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int getid(char *name) {
	int id = 0;
	for (int i = 0; i < 3; i++)
		id = 26 * id + (name[i] - 'A');
	id = id * 10 + (name[3] - '0');
	return id;
}
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> v[maxn];

int main() {
	int qnum, cnum;
	cin >> qnum >> cnum;
	for (int i = 0; i < cnum; i++){
		int cid, temp;
		cin >> cid >> temp;
		for (int i = 0; i < temp; i++){
			char name[5];
			scanf("%s", name);
			int id = getid(name);
			v[id].push_back(cid);
		}
	}

	for (int i = 0; i < qnum; i++) {
		char name[5];
		scanf("%s", name);
		int id = getid(name);
		printf("%s %d",name, v[id].size());
		sort(v[id].begin(), v[id].end());
		for (int i = 0; i < v[id].size(); i++){
			printf(" %d",v[id][i]); 
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

//map¹ý²»È¥
