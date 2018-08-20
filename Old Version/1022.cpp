#include<iostream>
#include<string>
#include<map>
#include<set>

using namespace std;

map<string, set<int>> d[6];

void myprint(map<string, set<int>> &m, string &s) {
	
	if (m.find(s) != m.end()) {
		for (auto it = m[s].begin(); it != m[s].end(); it++)
			printf("%07d\n", *it);
	}
	else {
		cout << "Not Found\n";
	}

}
int main() {
	long num, id, qnum, qtype;
	cin >> num;
	string stitle, sauthor, skeyword, spub, syear;

	for (int i = 0; i < num; i++){
		scanf("%d\n", &id);
		getline(cin,stitle);
		d[1][stitle].insert(id);
		getline(cin, sauthor);
		d[2][sauthor].insert(id);
		while (cin >> skeyword) {
			d[3][skeyword].insert(id);
			char c = getchar();
			if (c == '\n') break;
		}
		getline(cin, spub);
		d[4][spub].insert(id);
		getline(cin, syear);
		d[5][syear].insert(id);
	}

	scanf("%d", &qnum);
	for(int i =0; i < qnum ; i++){
		scanf("%d: ", &qtype);
		string temp;
		getline(cin, temp);
		cout << qtype << ": " << temp << "\n";
		myprint(d[qtype], temp);
	}
	system("pause");
	return 0;
}
