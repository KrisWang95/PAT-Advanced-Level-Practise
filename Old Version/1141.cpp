#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

struct node {
	string name;
	int ns,r,twss;
	double tws;
}Node[100010];
map<string, int> m;
int num,cnt =0;

void toLowerCase(string &s) {
	for (int i = 0; i < s.length(); i++) {
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
	}
}

int getId(string s) {
	if (m.find(s) == m.end()) {

		m[s] = cnt;

		return cnt++;
	}
	else {
		return m[s];
	}
}

double getMarks(string s, int marks) {
	switch (s[0]) {
		case 'T':
			return marks*1.5;
		case 'A':
			return marks;
		case 'B':
			return marks/1.5;
	}
}

bool cmp(node a, node b) {
	return a.twss != b.twss ? a.twss > b.twss : (a.ns != b.ns ? a.ns < b.ns : a.name < b.name);
}

int main() {

	std::ios::sync_with_stdio(false);
	cin >> num;

	for (int i = 0; i < num; i++) {
		string id, school;
		int marks;
		cin >> id >> marks >> school;
		toLowerCase(school);
		int iid = getId(school);
		Node[iid].name = school;
		Node[iid].ns++;
		Node[iid].tws += getMarks(id,marks);
	}

	for (int i = 0; i < cnt; i++) {
		Node[i].twss = (int)Node[i].tws;
	}
	sort(Node, Node + cnt, cmp);

	Node[0].r = 1;
	for (int i = 1; i < cnt; i++) {
		if (Node[i].twss == Node[i - 1].twss) {
			Node[i].r = Node[i - 1].r;
		}
		else {
			Node[i].r = i + 1;
		}
	}

	cout << cnt << endl;

	for (int i = 0; i < cnt; i++) {
		cout << Node[i].r << " " << Node[i].name << " " << Node[i].twss << " " << Node[i].ns << endl;
	}


	return 0;
}