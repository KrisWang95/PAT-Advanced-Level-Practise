#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct node {
	int next;
	char data;
};

node n[1000000];

int getLenth(int s) {

	int res = 0;

	while (s != -1) {

		s = n[s].next;

		res++;
	}

	return res ;


}



int main() {

	int nodeStart1, nodeStart2, num;

	cin >> nodeStart1 >> nodeStart2 >> num;

	for (int i = 0; i < num; i++) {
		int temp, next;

		char d;

		cin >> temp >> d >> next;

		n[temp].data = d;

		n[temp].next = next;

	}

	int len1 = getLenth(nodeStart1), len2 = getLenth(nodeStart2);

	if (len1 < len2) {
		
		swap(nodeStart1, nodeStart2);

		swap(len1,len2);

	} 

	for (int i = 0; i < len1 - len2; i++) nodeStart1 = n[nodeStart1].next;

	for (int i = 0; i < len2; i++) {

		if (nodeStart1 == nodeStart2) break;

		nodeStart1 = n[nodeStart1].next;

		nodeStart2 = n[nodeStart2].next;

	}

	if (nodeStart1 != -1)	printf("%05d", nodeStart1);
	else printf("-1");
	
	system("pause");

	return 0;
}


