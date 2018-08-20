#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long f(string a,long long radix) {
	long long temp = 1,real = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		if (a[i] >= '0'&&a[i] <= '9') {
			real += (a[i] - '0')*temp;
		}
		else if (a[i] >= 'a'&&a[i] <= 'z') {
			real += (a[i] - 'a' + 10)*temp;
		}
		temp *= radix;
	}
	return real;
}
int findMinRiadix(string a) {
	int b = -1;
	for (int i = a.length() - 1; i >= 0; i--) {
		if (b < a[i])
			b = a[i];
	}
	return (b > '9' ? b - 'a' + 10 : b - '0')+1;
}
int main() {
	string a[3];
	long tag, radix, real = 0, flag = 1, low, high, mid;
	cin >> a[1] >> a[2] >> tag >> radix;
	real = f(a[tag], radix);
	low = findMinRiadix(a[tag == 1 ? 2 : 1]);
	high = max(low, real) + 1;
	while (low <= high) {
		long long re = 0;
		mid = (low + high) / 2;
		re = f(a[tag == 1 ? 2 : 1], mid);

		if (re > real||re < 0) { // a cheat
			high = mid - 1;
		}
		else if (re == real) {
			flag = 0;
			break;
		}
		else 
			low = mid + 1;	
	}
	
	if (flag)
		cout << "Impossible";
	else
		cout << mid;
	system("pause");
	return 0;

}