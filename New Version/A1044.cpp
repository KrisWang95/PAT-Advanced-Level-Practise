#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int main(){

	int num, pay, near = 10000000;

	cin >> num >> pay;

	vector<int> v(num + 1,0);

	for (int i = 1; i <= num; i++) {

		cin >> v[i];

		v[i] += v[i - 1];

	}

	for (int i = 1; i <= num; i++) {

		int j = upper_bound(v.begin() + i, v.end(), v[i - 1] + pay) - v.begin();

		if (v[j - 1] == v[i - 1] + pay) {

			near = pay;

			break;
		}
		else if(j <= num && v[j] < v[i - 1] + near){ //find mini

			near = v[j] - v[i - 1];

		}

	}

	for (int i = 1; i <= num; i++) {

		int j = upper_bound(v.begin() + i, v.end(), v[i - 1] + near) - v.begin();

		if (v[j - 1] == v[i - 1] + near) {
			
			cout << i  << "-" << j - 1 << endl;


		}

	}
	
	system("pause");

	return 0;
}


