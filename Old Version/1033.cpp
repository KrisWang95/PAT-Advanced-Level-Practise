#include<iostream>
#include<vector>
#include<algorithm>
#define inf 99999999
using namespace std;

struct sta {
	double price, dis;
};

bool cmp(sta a, sta b) {
	return a.dis < b.dis;
}
int main() {

	double cmax, dis, davg, n;

	cin >> cmax >> dis >> davg >> n;

	vector<sta> v(n+1);
	v[0] = { 0.0 , dis };

	for (int i = 1; i <= n; i++){
		cin >>v[i].price >>v[i].dis;
	}
	sort(v.begin(), v.end(), cmp);

	double curprice = 0,curdis = 0,tempMaxdis = 0 ,leftDis = 0,totalPrice = 0;
	
	
	if (v[0].dis != 0) {
		//����û�м��͵ĵط�
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	else {
		curprice = v[0].price;
	}

	while (curdis < dis){
		bool flag = false; 
		double minPrice = inf, minDis = 0;
		tempMaxdis = curdis + cmax*davg;
		for (int i = 1; i <= n && v[i].dis <= tempMaxdis; i++) {

			//�������߹���
			if (v[i].dis <= curdis) continue;

			//�ҵ��ȵ�ǰ���˵�,��ʱ���վ����ʱ�Ӹպõ���
			if (v[i].price < curprice) {
				totalPrice += (v[i].dis - curdis - leftDis) / davg*curprice;
				leftDis = 0;
				curdis = v[i].dis;
				curprice = v[i].price;
				flag = true;
				break;
			}
			//��¼�ڵ�ǰ�ܵ���ķ�Χ������˵ģ���ʱ���վ����ʱӦ���������
			if (v[i].price < minPrice) {		
				minPrice = v[i].price;
				minDis = v[i].dis;
			}
		}

		//���¼������˵�վ����
		if (flag == false && minPrice != inf) {
			totalPrice += (cmax - leftDis / davg)*curprice;
			leftDis = cmax * davg + curdis - minDis;
			curprice = minPrice;
			curdis = minDis;

		}

		//���ܵ���
		if (flag == false && minPrice == inf){
			curdis += cmax * davg;
			printf("The maximum travel distance = %.2f", curdis);
			return 0;
		}
		
	}

	printf("%.2f", totalPrice);
	system("pause");
	return 0;
}