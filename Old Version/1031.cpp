#include<iostream>
#include<string>
using namespace std;
int main(){
	string a;

	cin >> a;

	int n = a.length() + 2;

	int x, y, i;

	x = n / 3 ;
	y = x + n % 3;

	for (i = 0; i < x - 1; i++) {
		cout << a[i];
		for (int j = 0; j < y - 2; j++)
			cout << " ";
		cout << a[a.length() - i - 1] << endl;
	}

	for (int j = 0; j < y ; j++)
		cout << a[i++];
	system("pause");
	return 0;
}