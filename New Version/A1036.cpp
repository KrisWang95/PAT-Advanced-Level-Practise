#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct node {
	char gender;
	int grade;
	string name,subject;
};

bool cmp(node a, node b) {

	return (a.gender != b.gender ? a.gender < b.gender : a.grade > b.grade);

}



int main() {

	int num;

	vector<node> v;

	cin >> num;

	for (int i = 0; i < num; i++) {

		node a;

		cin >> a.name >> a.gender >> a.subject >> a.grade;

		v.push_back(a);
	}

	sort(v.begin(), v.end(),cmp);

	if (num == 0) cout << "Absent\n" << "Absent\n" << "NA";

	else{

		if (v.front().gender != 'F') cout << "Absent\n";
		else cout << v.front().name << " " << v.front().subject << endl;

		if (v.back().gender != 'M') cout << "Absent\n";
		else cout << v.back().name << " " << v.back().subject << endl;

		if(v.front().gender != 'F' || v.back().gender != 'M') cout  << "NA";
		else cout << v.front().grade - v.back().grade;


	}

	
	system("pause");

	return 0;
}


