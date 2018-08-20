#include<iostream>
#include<string>
using namespace std;
int main() {

	string num;

	cin >> num;

	int digit[10],flag = 0;

	for (int i = 0; i < 10; i++) 
		digit[i] = 0;

	bool tag = true;

	for (int i = num.length()-1; i >= 0; i--){
		int temp = num[i] - '0';
		digit[temp]++;
		temp = temp * 2 + flag;
		flag = 0;
		if (temp >= 10) {
			temp = temp - 10;
			flag = 1;
		}
		num[i] = temp + '0';
		digit[temp]--;
	}

	for (int i = 0; i < 10; i++) {
		if (digit[i] != 0) {
			tag = false;
		}
			
	}
	cout << ((tag && flag != 1 )? "Yes" : "No") << endl;
	if (flag == 1) cout << "1";
	cout << num;
	system("pause");
	return 0;
}
