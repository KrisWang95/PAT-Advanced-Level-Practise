#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
long reverse_my(long a, int b) {
	vector<int> v;
	long result = 0 ,radix = 1;
	while (a!=0){
		v.push_back(a%b);
		a = a / b;
	}
	//for(int i = 0; i < v.size();i++){
	//	result = result * b + v[i];
	//}
	for (int i = v.size() - 1; i >= 0; i--){
		result += radix * v[i];
		radix *= b;
	}
	return result;
}
bool IsPrime(long a) {
	if (a <= 1) return false;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a%i == 0)
			return false;
	}
	return true;
}
int main() {
	long temp, radix, result;
	while (true){
		cin >> temp;
		if (temp > 0) {
			cin >> radix;
			result = reverse_my(temp, radix);
			if (IsPrime(result)&&IsPrime(temp)) {
				cout << "Yes\n";
			}
			else {
				cout << "No\n";
			}
		}
		else {
			break;
		}
	}
	system("pause");
	return 0;
}