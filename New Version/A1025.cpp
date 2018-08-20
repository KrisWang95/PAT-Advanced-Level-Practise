#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

struct node {
	string id;
	int grade;
	int rank;
	int location;
	int local_rank;
};
map<string, int> local_rank;

bool cmp(node a, node b) {
	return (a.grade != b.grade) ? a.grade > b.grade : a.id < b.id;
}

int main() {
	int n, k;
	cin >> n;
	vector<node> v[101],total;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			node temp;
			temp.location = i;
			cin >> temp.id >> temp.grade;
			v[i].push_back(temp);
			total.push_back(temp);
		}
		sort(v[i].begin(), v[i].end(), cmp);

		local_rank[v[i][0].id] = 1;

		for (int j = 1; j < v[i].size(); j++) {
			local_rank[v[i][j].id] = j + 1;
			if (v[i][j].grade == v[i][j - 1].grade) {
				local_rank[v[i][j].id] = local_rank[v[i][j - 1].id];
			}
		}
		
	}

	sort(total.begin(), total.end(), cmp);
	total[0].rank = 1;
	for (int j = 1; j < total.size(); j++) {
		total[j].rank = j + 1;
		if (total[j].grade == total[j - 1].grade) {
			total[j].rank = total[j - 1].rank;
		}
	}
	cout << total.size() << endl;
	for (int j = 0; j < total.size(); j++) {
		cout << total[j].id << " " << total[j].rank << " " << total[j].location << " " << local_rank[total[j].id] << endl;
	}



	system("pause");
	return 0;
}
