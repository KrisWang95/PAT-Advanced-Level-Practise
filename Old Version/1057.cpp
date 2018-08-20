#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

stack<int> s;
int table[100010], book[316];

int getPeekMedian() {

	int k = (s.size() % 2 == 0 ? s.size() / 2 : s.size() / 2 + 1);
	int sum = 0, i = 0;
	while (sum + book[i] < k) {
		sum += book[i++];
	}

	int num = i * 316;

	while (sum + table[num] < k) {
		sum += table[num++];
	}

	return num;

}

int main() {

	int cnum;
	char cmd[20];
	cin >> cnum;
	for (int i = 0; i < cnum; i++){
		bool flag = true;
		int temp;
		scanf("%s", cmd);
		if (strcmp(cmd, "Push")==0) {
			scanf("%d", &temp);
			s.push(temp);
			table[temp]++;
			book[temp / 316]++;
		}
		else if (strcmp(cmd, "Pop") == 0) {
			if (s.empty()) flag = false;
			else {
				temp = s.top();
				s.pop();
				table[temp]--;
				book[temp / 316]--;
				printf("%d\n", temp);
			}
		}
		else if (strcmp(cmd, "PeekMedian") == 0) {
			if (s.empty()) flag = false;
			else {
				temp = getPeekMedian();
				printf("%d\n", temp);
			}
		}
		else {
			flag = false;
		}
		if (flag == false) printf("Invalid\n");;
	}
	system("pause");
	return 0;
}