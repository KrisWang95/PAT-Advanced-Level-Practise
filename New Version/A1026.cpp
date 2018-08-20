#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct customers {

	int arr_time, start_time = 21 * 3600, vip, serve_time;

};

vector<customers> v;

int isVip[101] = { 0 }, tableTime[101] = { 0 }, tableServe[101] = { 0 };

bool cmp(customers a, customers b) {

	return a.arr_time < b.arr_time;
}

bool cmp1(customers a, customers b) {

	return a.start_time < b.start_time;
}

int getNextVip(int current) {
	
	current++;

	while (current < v.size() && v[current].vip != 1) {
		
		current++;

	}

	return current;

}

void assignTable(int cus_index, int table_index ) {

	if (v[cus_index].arr_time <= tableTime[table_index]) {

		v[cus_index].start_time = tableTime[table_index];

	}

	else {

		v[cus_index].start_time = v[cus_index].arr_time;

	}

	tableTime[table_index] = v[cus_index].start_time + v[cus_index].serve_time;

	tableServe[table_index] ++;


}



int main() {


	int num;

	cin >> num;


	for (int i = 0; i < num; i++) {

		customers c;

		int h, m, s, st;

		scanf("%d:%d:%d %d %d", &h, &m, &s, &st, &c.vip);

		c.arr_time = h * 3600 + m * 60 + s;

		c.serve_time = (st > 120 ? 120 * 60 : st * 60);

		if (c.arr_time >= 21 * 3600)

			continue;

		v.push_back(c);

	}

	sort(v.begin(), v.end(), cmp);
	
	int tableNum,vipTableNum;

	cin >> tableNum >> vipTableNum;

	for (int i = 0; i < vipTableNum; i++) {

		int temp;

		cin >> temp;

		isVip[temp] = 1;

	}

	for (int i = 0; i <= 100; i++) {

		tableTime[i] = 8 * 3600;

	}

	int currentVip = -1, i = 0;;

	currentVip = getNextVip(currentVip);

	while (i < v.size()) {


		//找最早的桌子
		int min = 1;

		for (int j = 1; j <= tableNum; j++) {

			if (tableTime[min] > tableTime[j]) {

				min = j;

			}

		}

		//所有的桌子都到了21：00
		if (tableTime[min] >= 21 * 3600) break;

		//跳过插队的vip
		if (i < currentVip && v[i].vip == 1) {

			i++;

			continue;

		}

		if (isVip[min]) {

			if (v[i].vip == 1) {

				assignTable(i, min);

				if (currentVip == i)

					currentVip = getNextVip(currentVip);

				i++;

			}

			else {

				if (currentVip < v.size() && v[currentVip].arr_time <= tableTime[min]) {

					assignTable(currentVip, min);

					currentVip = getNextVip(currentVip);

				}

				else{

					assignTable(i, min);

					i++;

				}


			}

		}
		else {

			if (v[i].vip == 1) {

				//找最早VIP桌子
				int minVipIndex = -1, minTime = 24 * 3600;

				for (int j = 1; j <= tableNum; j++) {

					if ( isVip[j] == 1 && minTime > tableTime[j]) {

						minTime = tableTime[j];

						minVipIndex = j;

					}

				}

				//有VIP桌可用
				if(minVipIndex != -1 && v[i].arr_time >= tableTime[minVipIndex]){

					assignTable(i, minVipIndex);

				}
				else {
					
					assignTable(i, min);

				}

				if (currentVip == i)

					currentVip = getNextVip(currentVip);

				i++;

			}

			else {

				assignTable(i, min);

				i++;

			}

		}



	}

	sort(v.begin(), v.end(), cmp1);

	for (int i = 0; i < v.size() && v[i].start_time < 21 * 3600; i++) {

		printf("%02d:%02d:%02d ", v[i].arr_time / 3600, v[i].arr_time % 3600 / 60, v[i].arr_time % 60);

		printf("%02d:%02d:%02d ", v[i].start_time / 3600, v[i].start_time % 3600 / 60, v[i].start_time % 60);

		printf("%.0f\n", round((v[i].start_time - v[i].arr_time) / 60.0));

	}

	for (int i = 1; i <= tableNum; i++) {

		if (i != 1)

			printf(" ");

		printf("%d", tableServe[i]);
	}
	
	system("pause");

	return 0;
}
