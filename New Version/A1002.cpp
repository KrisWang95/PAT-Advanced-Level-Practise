/*
1002 A+B for Polynomials (25)£¨25 ·Ö£©
This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 a~N1 N2 a~N2 ... NK a~NK, where K is the number of nonzero terms in the polynomial, Ni and a~Ni (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10£¬0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input

2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output

3 2 1.5 1 2.9 0 3.2


*/

#include<iostream>
#include<iomanip>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

map<int, float> poly;

void read_data(int n) {

	for (int i = 0; i < n; i++) {

		int e;

		float c;

		cin >> e >> c;

		if (poly.find(e) == poly.end()) poly[e] = c;

		else poly[e] += c;

	}

}

int main(){

	std::ios::sync_with_stdio(false);

	int n, m, cnt = 0;
	
	cin >> n  ;

	read_data(n);
	
	cin >> m  ;

	read_data(m);
	
	for (auto it : poly) {

		if (it.second == 0) cnt++;

	}
	
	cout << poly.size() - cnt ;

	for (auto it = poly.rbegin(); it != poly.rend(); it++) {

		if (it->second != 0) cout << setprecision(1) << setiosflags(ios::fixed) << " " << it->first << " " << it->second;

	}
	
	return 0;
	
}

