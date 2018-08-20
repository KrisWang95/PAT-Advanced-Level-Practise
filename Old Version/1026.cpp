#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct _node {
	int arr_time, serve_time,start, vip, h, m, s;
}node;

vector<node> v;
vector<node> table[100];
int num, tablesNum, vip_tablesNum, NumVip[100], tableTime[100];

bool cmp1(node a, node b) {
	return a.arr_time < b.arr_time;
}

bool cmp2(node a, node b) {
	return a.start < b.start;
}

void assignTable(int id , int  index) {

	if (v[id].arr_time <= tableTime[index]) {
		v[id].start = tableTime[index];
	}
	else {
		v[id].start = v[id].arr_time;
	}
	tableTime[index] = v[id].start + v[id].serve_time;
	table[index].push_back(v[id]);
}

int getCurrentVip(int id) {

	//防止上一次id重现
	id++;

	while (id < v.size() && v[id].vip == 0) {
		id++;
	}
	return id;
}


int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		node n;
		int temp;
		scanf("%d:%d:%d %d %d", &n.h, &n.m, &n.s,&temp,&n.vip);
		n.serve_time = (temp <= 120 ? temp * 60 : 7200);
		n.arr_time = n.h * 3600 + n.m * 60 + n.s;
		n.start = 21 * 3600;
		if (n.arr_time >= 21 * 3600)
			continue;
		v.push_back(n);
	}

	sort(v.begin(), v.end(), cmp1);

	cin >> tablesNum >> vip_tablesNum;
	for (int i = 0; i < vip_tablesNum; i++) {
		int temp;
		cin >> temp;
		NumVip[temp] = 1;
	}

	for (int i = 1; i <= tablesNum; i++) {
		tableTime[i] = 8 * 3600;
	}

	int currentVip = -1 , i = 0;
	currentVip = getCurrentVip(currentVip);

	while ( i < v.size()) {

		


		//寻找最早的可以用的桌子
		int index = -1,min = 9965535;
		for (int j = 1; j <= tablesNum; j++) {
			if (min > tableTime[j]) {
				min = tableTime[j];
				index = j;
			}
		}

		//判断是否关门
		if (tableTime[index] >= 21 * 3600) {
			break;
		}

		//跳过已服务的vip
		if (v[i].vip == true && i < currentVip) {
			i++;
			continue;
		}

		//核心逻辑--分类讨论
		//当前是VIP桌
		if (NumVip[index] == 1) {
			//当前玩家是VIP
			if (v[i].vip == 1) {
				assignTable(i, index);
				if(currentVip == i)
					currentVip = getCurrentVip(currentVip);
				i++;
			}
			//当前玩家不是VIP
			else {
				//看是否有VIP玩家在等待
				if (currentVip < v.size() && v[currentVip].arr_time <= tableTime[index]) {
					assignTable(currentVip, index);
					currentVip = getCurrentVip(currentVip);
				}
				else {
					assignTable(i, index);
					i++;
				}

			}
		}
		//当前不是VIP桌
		else {
			//当前玩家不是VIP
			if (v[i].vip == 0) {
				assignTable(i, index);
				i++;
			}
			//当前玩家是VIP
			else {
				int vipindex = -1 ,minVip = 99999999;
				for (int j = 1; j <= tablesNum; j++) {
					if (NumVip[j] == 1 && minVip > tableTime[j]) {
						minVip = tableTime[j];
						vipindex = j;
					}
				}
				//看是否有VIP桌
				if (vipindex != -1 && v[i].arr_time >= tableTime[vipindex]) {
					assignTable(i, vipindex);
				}
				else {
					assignTable(i, index);
				}

				if (currentVip == i)
					currentVip = getCurrentVip(currentVip);
				i++;
			}
		}

	}
	sort(v.begin(), v.end(), cmp2);
	for (i = 0; i < v.size() && v[i].start < 21 * 3600; i++) {
		printf("%02d:%02d:%02d ", v[i].arr_time / 3600, v[i].arr_time % 3600 / 60, v[i].arr_time % 60);
		printf("%02d:%02d:%02d ", v[i].start / 3600, v[i].start % 3600 / 60, v[i].start % 60);
		printf("%.0f\n", round((v[i].start - v[i].arr_time) / 60.0));
	}
	for (int i = 1; i <= tablesNum; i++) {
		if (i != 1)
			printf(" ");
		printf("%d", table[i].size());
	}
	system("pause");
	return 0;
	
}