#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include<string>
#include<climits>
using namespace std;

struct node {

	vector<int> grade;

	int total;

	bool isShow = false;

	int id;

	int rank;

	int per = 0;

};

int n, k, m;

vector<int> fullGrade;

vector<node> t;

bool cmp(node a, node b) {

	return (a.total != b.total ? a.total > b.total :( a.per != b.per ? a.per > b.per : a.id < b.id));

}





int main() {

	cin >> n >> k >> m;

	fullGrade.resize(k);

	t.resize(n);

	for (auto &it : fullGrade) {

		cin >> it;

	}

	for (auto &it : t) {

		it.grade.resize(k,-1);

	}

	for (int i = 0; i < m; i++) {

		int id, qid, g;

		cin >> id >> qid >> g;

		t[id - 1].id = id;

		if (g >= t[id - 1].grade[qid - 1]) {

			t[id - 1].grade[qid - 1] = (g > 0 ? g : 0) ;

		}

		if(g >= 0) t[id - 1].isShow = true;

		if (t[id - 1].grade[qid - 1] == fullGrade[qid - 1]) t[id - 1].per++;

	}

	for (auto &it : t) {

		int sum = 0;

		for (auto that : it.grade) {

			sum += (that == -1 ? 0 : that);

		}

		it.total = sum;

	}


	sort(t.begin(), t.end(), cmp);

	t[0].rank = 1;


	for (int i = 1; i < n; i++) {

		t[i].rank = i + 1;

		if (t[i - 1].total == t[i].total) {

			t[i].rank = t[i - 1].rank;
		}

	}

	for (auto it = t.begin(); it != t.end(); it++) {

		if (it->isShow) {

			printf("%d %05d %d", it->rank, it->id, it->total);

			for (auto that : it->grade) {

				if (that == -1) printf(" -");

				else printf(" %d", that);

			}

			printf("\n");

		}

	}
	


	system("pause");

	return 0;
}