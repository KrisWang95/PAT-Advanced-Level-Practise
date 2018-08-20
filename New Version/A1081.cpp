#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cctype>
#include<climits>
#include<algorithm>
#include<cmath>
#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX inf
using namespace std;

struct frac{

	int up;

	int down;

};

int gcd(int a, int b) {

	return b == 0 ? a : gcd(b, a%b);

}

frac add(frac a, frac b) {

	frac ans;

	ans.down = a.down * b.down / gcd(a.down, b.down);

	ans.up = a.up * (ans.down / a.down) + b.up * (ans.down / b.down);

	int c = gcd(abs(ans.down), abs(ans.up));

	ans.down /= c;
	
	ans.up /= c;

	return ans;
}



int main() {

	frac ans = { 0,1 };

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		frac temp;

		scanf("%d/%d", &temp.up, &temp.down);

		ans = add(temp, ans);

	}

	if (ans.down == 1 || ans.up == 0) 
		
		cout << ans.up;

	else if (abs(ans.up) > ans.down) 
		
		cout << ans.up / ans.down << " " << abs(ans.up) % ans.down << "/" << ans.down;
	
	else 
		cout << ans.up << "/" << ans.down;
	

	system("pause");

	return 0;
}