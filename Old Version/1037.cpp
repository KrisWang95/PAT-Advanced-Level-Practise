#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a < b;
}
int main() {
	int cnum, pnum, i = 0, j = 0,ans=0;
	vector<int> c, p;
	cin >> cnum;
	for (int i = 0; i < cnum; i++){
		int temp;
		cin >> temp;
		c.push_back(temp);
	}
	cin >> pnum;
	for (int i = 0; i < pnum; i++) {
		int temp;
		cin >> temp;
		p.push_back(temp);
	}
	sort(c.begin(), c.end(), cmp);
	sort(p.begin(), p.end(), cmp);
	/*ºÜ°ô°ô*/
	while (i < cnum&&j < pnum&&c[i] < 0 && p[j] < 0) {
		ans += c[i++] * p[j++];
	}
	i = cnum - 1; j = pnum - 1;
	while (i >=0 &&j >= 0&&c[i] > 0 && p[j] > 0) {
		ans += c[i--] * p[j--];
	}
	cout << ans;
	system("pause");
	return 0;
}