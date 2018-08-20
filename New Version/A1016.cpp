#include <iostream>
#include <map>
#include <vector>
#include<string>
#include <algorithm>
using namespace std;
int rate[25], sum;
typedef struct node {
	string name;
	int month,date,hour,minute,total,type;
}_node;

bool cmp(_node a, _node b) {
	return a.name != b.name ? a.name < b.name : a.total < b.total;
}

double cost(_node a, _node b) {
	double total1 = rate[a.hour] * a.minute + rate[24] * 60 * a.date;
	for (int i = 0; i < a.hour; i++)
		total1 += rate[i] * 60;
	double total2 = rate[b.hour] * b.minute + rate[24] * 60 * b.date;
	for (int i = 0; i < b.hour; i++)
		total2 += rate[i] * 60;
	return (total2 - total1) / 100.0;
}

int main() {
	
	for (int i = 0; i < 24; i++){
		cin >> rate[i];
		rate[24] += rate[i];
	}
	
	cin >> sum;
	vector<_node> a(sum);
	for (int i = 0; i < sum; i++){
		cin >> a[i].name;
		scanf("%d:%d:%d:%d", &a[i].month, &a[i].date, &a[i].hour, &a[i].minute);
		a[i].total = a[i].date * 24 * 60 + a[i].hour * 60 + a[i].minute;
		string type; 
		cin >> type;
		a[i].type = type == "on-line" ? 1 : 0;
 	}
 	
	sort(a.begin(), a.end(), cmp);
	
	map<string, vector<node> > custom;
	for (int i = 1; i < sum; i++) {
		if (a[i].name == a[i - 1].name && a[i - 1].type == 1 && a[i].type == 0) {
			custom[a[i - 1].name].push_back(a[i - 1]);
			custom[a[i].name].push_back(a[i]);
		}
	}
	
	for (auto it : custom) {
		vector<node> temp = it.second;
		cout << it.first;
		printf(" %02d\n", temp[0].month);
		double total = 0.0;
		for (int i = 1; i < temp.size(); i += 2) {
			double t = cost(temp[i - 1],temp[i]);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].date, temp[i - 1].hour, temp[i - 1].minute, temp[i].date, temp[i].hour, temp[i].minute, temp[i].total - temp[i - 1].total, t);
			total += t;
		}
		printf("Total amount: $%.2f\n", total);
	}
	system("pause");
	return 0;
}
