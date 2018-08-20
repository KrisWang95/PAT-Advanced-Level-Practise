#include<iostream>
using namespace std;
int main() {
	double result = 1;
	int a;
	string r = "WTL";
	for (int i = 0; i < 3; i++){
		double temp = 0, max = -1;
		for (int j = 0; j < 3; j++){
			cin >> temp;
			if (temp > max) {
				max = temp;
				a = j;
			}
		}
		result *= max;
		cout << r[a] << " ";
	}
	printf("%.2lf", (result*0.65 - 1) * 2);
	system("pause");
	return 0;
}