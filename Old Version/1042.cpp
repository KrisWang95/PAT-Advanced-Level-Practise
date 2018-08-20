#include<iostream>

using namespace std;

int main() {

	int k, s[55],ans[55],temp[55];

	cin >> k;

	for (int i = 1; i <= 54; i++) {
		cin >> s[i];
		ans[i] = i;
	}

	for (int i = 0; i < k; i++){
		for (int j = 1; j <= 54; j++) {
			temp[j] = ans[j];
		}
		for (int j = 1; j < 55; j++)
			ans[s[j]] = temp[j];
	}

	char str[6] = "SHCDJ";
	for (int j = 1; j < 55; j++) {
		ans[j] -= 1;
		printf("%c%d", str[ans[j] / 13], ans[j] % 13 + 1);
		if (j != 54) printf(" ");
	}

	system("pause");
	return 0;
		
}