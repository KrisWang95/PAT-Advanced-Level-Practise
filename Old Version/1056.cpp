//1.every NG programmers are grouped in a match
//2.All the losers in this turn are ranked the same. 
//3.If there are less than NG mice at the end of the player's list, then all the mice left will be put into the last group. 
#include<iostream>
#include<queue>
using namespace std;

struct node {
	int weight;
	int rank;
}mice[1010];

queue<int> q;

int main() {
	int np, ng;
	cin >> np >> ng;
	for (int i = 0; i < np; i++){
		cin >> mice[i].weight;
	}
	for (int i = 0; i < np; i++) {
		int temp;
		cin >> temp;
		q.push(temp);
	}
	int temp = np, groups;

	while (q.size() != 1) {//当队列剩下1时不退出会死循环
		groups = (temp % ng == 0 ? temp / ng : temp / ng + 1);
		for (int i = 0; i < groups; i++) {
			int max = q.front();
			for (int j = 0; j < ng; j++){
				if (i * ng + j >= temp) break;//处理最后一组不足ng
				int cur = q.front();
				if (mice[cur].weight > mice[max].weight) {
					max = cur;
				}
				mice[cur].rank = groups + 1;
				q.pop();
			}

			q.push(max);
		}
		temp = groups;
	}

	mice[q.front()].rank = 1;
	
	for (int i = 0; i < np; i++) {
		cout << mice[i].rank << (i < np - 1 ? " ":"");
	}

	system("pause");
	return 0;

}