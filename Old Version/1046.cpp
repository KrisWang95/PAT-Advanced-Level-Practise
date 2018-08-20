#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n,m,sum = 0;
	vector<int> dis; // 表示从1到i+1的距离
	cin >> n;
	dis.resize(n + 1);
	for (int i = 1; i <= n; i++){
		int temp;
		cin >> temp;
		sum += temp;
		dis[i] = sum;
	}
	cin >> m;

	for (int i = 0; i < m; i++){
	
		int temp1, temp2;

		cin >> temp1 >> temp2;
		if (temp1 > temp2)
			swap(temp1, temp2);
		int temp = dis[temp2 - 1] - dis[temp1 - 1];
		cout << min(temp, sum - temp) << endl;
	}

	system("pause");
	return 0;

}