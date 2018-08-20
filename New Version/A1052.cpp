#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int getRes(int a, int b) {



}

int main(){

	int num;

	cin >> num;

	vector<int> dis(num);

	for (int i = 0; i < num; i++) {

		cin >> dis[i];

	}

	int query;

	cin >> query;

	for (int i = 0; i < query; i++) {

		int t, s;

		cin >> t >> s;

		if (t > s) swap(t, s);

	}





	
	
	system("pause");

	return 0;
}


