#include<iostream>
#include<queue>
using namespace std;
typedef struct node {
	int order;
	int timecost;
} node;
queue < node > window[20];
// 每个窗口服务结束的时间 顾客结束服务的时间 是否能被服务
int winEndTime[20], customEndTime[1000], status[1000];
int main() {

	int n, m, k, q, timemin;

	cin >> n >> m >> k >> q;

	for (int i = 0; i < k; i++) {
		node l;
		l.order = i;
		cin >> l.timecost;
		status[i] = 1;

		//当 i < n * m 直接插入等待队列
		if (i < n * m) {
			window[i % n].push(l);
			if (i / n == 0)
				winEndTime[i] = l.timecost;
		}
		//当 i > n * m 此时需将最早结束服务的人出队，再将后面一个人入队
		else { 
			timemin = 0;
			for (int i = 0; i < n; i++) {
				if (winEndTime[timemin] > winEndTime[i])
					timemin = i;
			}

			node temp = window[timemin].front();
			customEndTime[temp.order] = winEndTime[timemin];
			window[timemin].pop();

			window[timemin].push(l);
			temp = window[timemin].front();

			if (winEndTime[timemin] >= 540)
				status[temp.order] = 0;
			else
				winEndTime[timemin] += temp.timecost;
		}
	}

	//对剩下的等待队列中的人快速出队
	for (int i = 0; i < n; i++) {
		while (!window[i].empty()) {
			node temp = window[i].front();
			customEndTime[temp.order] = winEndTime[i];
			window[i].pop();
			temp = window[i].front();
			if (winEndTime[i] >= 540 && !window[i].empty())
				status[temp.order] = 0;
			else
				winEndTime[i] += temp.timecost;
		}
	}


	for (int i = 0; i < q; i++) {
		int temp;
		cin >> temp;
		if (status[temp - 1])
			printf("%02d:%02d\n", customEndTime[temp - 1] / 60 + 8, customEndTime[temp - 1] % 60);
		else
			printf("Sorry\n");
	}

	return 0;
}