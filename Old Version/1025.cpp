#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef struct stu {
	string id;
	int marks, location, local_rank;
}stu;

vector<stu> v;

bool cmp(stu a, stu b) {
	return (a.marks != b.marks ? a.marks > b.marks:a.id < b.id);
}
int main() {
	int n, k, s = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			stu n;
			cin >> n.id >> n.marks;
			n.location = i;
			v.push_back(n);
		}
		sort(v.begin() + s, v.end(), cmp);
		v[s].local_rank = 1;
		for (int j = s + 1; j < s + k; j++) {
			if (v[j].marks == v[j - 1].marks) {
				v[j].local_rank = v[j - 1].local_rank;
			}
			else {
				v[j].local_rank = j - s + 1;
			}
		}
		s += k;
	}
	cout << v.size() << endl;
	sort(v.begin(), v.end(), cmp);
	int rank = 1;
	for(int i = 0; i < v.size();i++){
		if (i > 0 && v[i].marks != v[i - 1].marks) {
			rank = i + 1;
		}
		cout << v[i].id << " ";
		cout << rank << " " << v[i].location << " " << v[i].local_rank << endl;
	}
	system("pause");
}