#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct stu {
	char name[15], id[15],sex;
	int grade;
};

bool cmp(stu a, stu b){
	return a.grade < b.grade;
}

int main() {

	vector<stu> m, f;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++){
		stu s;
		cin >> s.name >> s.sex >> s.id >> s.grade;
		if (s.sex == 'M') {
			m.push_back(s);
		}
		else {
			f.push_back(s);
		}
	}

	sort(m.begin(), m.end(), cmp);

	sort(f.begin(), f.end(), cmp);

	if (f.size() != 0) {
		cout << f[f.size() - 1].name << " " << f[f.size() - 1].id << endl;
	}
	else {
		cout << "Absent" << endl;
	}
	if (m.size() != 0) {
		cout << m[0].name << " " << m[0].id << endl;
	}
	else {
		cout << "Absent" << endl;
	}
	if (f.size() != 0 && m.size() != 0) {
		cout << f[f.size() - 1].grade - m[0].grade << endl;
	}
	else {
		cout << "NA" << endl;
	}
	

	system("pause");

	return 0;
}