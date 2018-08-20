#include<iostream>
#include<queue>
using namespace std;
typedef struct node {
	int order;
	int timecost;
} node;
queue < node > window[20];
// ÿ�����ڷ��������ʱ�� �˿ͽ��������ʱ�� �Ƿ��ܱ�����
int winEndTime[20], customEndTime[1000], status[1000];
int main() {

	int n, m, k, q, timemin;

	cin >> n >> m >> k >> q;

	for (int i = 0; i < k; i++) {
		node l;
		l.order = i;
		cin >> l.timecost;
		status[i] = 1;

		//�� i < n * m ֱ�Ӳ���ȴ�����
		if (i < n * m) {
			window[i % n].push(l);
			if (i / n == 0)
				winEndTime[i] = l.timecost;
		}
		//�� i > n * m ��ʱ�轫�������������˳��ӣ��ٽ�����һ�������
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

	//��ʣ�µĵȴ������е��˿��ٳ���
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