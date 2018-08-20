#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int num, non_leaf, target;

vector<int> weight,e[100],temp;

bool cmp(int a, int b) {

	return weight[a] > weight[b];

}

void myprint() {

	cout << temp[0];

	for (int i = 1; i < temp.size(); i++) {

		cout << " " << temp[i] ;

	}
	cout << endl;

}

void dfs( int root) {

	temp.push_back(weight[root]);

	if (e[root].size() == 0) {

		int sum = 0;

		for (auto &it : temp) {

			sum += it;
		}

		if (sum == target) myprint();

	}


	for (auto &it : e[root]) {
		
		dfs(it);

	}

	temp.pop_back();

}


int main(){

	cin >> num >> non_leaf >> target;

	for (int i = 0; i < num; i++) {
		int temp;

		cin >> temp;

		weight.push_back(temp);
	}

	for (int i = 0; i < non_leaf; i++) {

		int id, n, temp;

		cin >> id >> n;
		
		for (int j = 0; j < n; j++) {

			cin >> temp;

			e[id].push_back(temp);


		}

		sort(e[id].begin(), e[id].end(),cmp);

	}

	dfs(0);
	
	system("pause");

	return 0;
}


