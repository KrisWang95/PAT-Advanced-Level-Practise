//小细节
//1.平均数的处理
//2.相同分数的处理
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int flag = 0;
typedef struct stuInfo {
	long stuId;
	int score[4],rank[4];
}stuInfo;
bool cmp(stuInfo a,stuInfo b) {
	return a.score[flag] > b.score[flag];
}
int result[1000000],course[1000000];
string a = "ACME";
int main() {
	int m, n;
	cin >> m >> n;
	vector<stuInfo> v;
	for (int i = 0; i < 1000000; i++) {
		result[i] = 5;
		course[i] = 0;
	}
	for (int  i = 0; i < m; i++){
		stuInfo a;
		cin >> a.stuId >> a.score[1] >> a.score[2] >> a.score[3];
		a.score[0] = (a.score[1] + a.score[2] + a.score[3]) / 3.0 + 0.5;
		v.push_back(a);
	}
	for (int i = 0; i < 4; i++){
		sort(v.begin(), v.end(), cmp);
		flag++;
		v[0].rank[i] = 1;
		for (int j = 1; j < m; j++) {
			v[j].rank[i] = j + 1;
			if (v[j].score[i] == v[j - 1].score[i])
				v[j].rank[i] = v[j - 1].rank[i];
		}
		
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 4; j++) {
			if (v[i].rank[j] < result[v[i].stuId]) {
				result[v[i].stuId] = v[i].rank[j];
				course[v[i].stuId] = j;
			}
		}
	}
	for (int i = 0; i < n; i++){
		long temp;
		cin >> temp;
		if (result[temp]!=5)
			printf("%d %c\n", result[temp], a[course[temp]]);
		else
			cout << "N/A" << endl;
	}
	system("pause");
	return 0;
}