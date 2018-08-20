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
using namespace std;

struct frac {
	long long down, up;
};

long long gcd(long long a, long long b) {

	return b == 0 ? a : gcd(b, a%b);
}

frac simply(frac a) {

	long long c = gcd(abs(a.up), abs(a.down));

	a.up /= c;

	a.down /= c;

	return a;

}

frac cal(int i, frac a, frac b) {

	frac ans;

	switch (i){

	case 1:

		b.up = -b.up;

	case 0:

		ans.down = a.down * b.down / gcd(a.down, b.down);

		ans.up = a.up * ans.down / a.down + b.up * ans.down / b.down;

		ans = simply(ans);

		break;
	case 3:
		if (b.up < 0) {

			b.up = -b.up;

			b.down = -b.down;

		}
		swap(b.up, b.down);

	case 2:
		ans.down = a.down * b.down;

		ans.up = a.up * b.up;

		ans = simply(ans);

		break;
	}


	return ans;
}

void output(frac a) {

	bool isNeg = (a.up < 0 ? true : false);

	if (isNeg) printf("(");

	if(a.down == 1) printf("%lld", a.up);

	else {

		if (abs(a.up) < abs(a.down)) {

			printf("%lld/%lld", a.up, a.down);

		}
		else {


			printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % a.down, a.down);
		}
	}

	if (isNeg) printf(")");

}



int main() {

	frac a, b;

	string op = "+-*/";

	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);

	a = simply(a);

	b = simply(b);

	for (int i = 0; i < 4; i++) {

		output(a);

		printf(" %c ", op[i]);

		output(b);

		printf(" = ");

		if (i == 3 && b.up == 0) printf("Inf");

		else {

			frac ans = cal(i, a, b);

			output(ans);
		}

		printf("\n");
		
	}

	system("pause");

	return 0;
}