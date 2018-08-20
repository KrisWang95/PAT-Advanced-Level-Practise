#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int main() {

	string s = "SHCDJ";

	int num;

	cin >> num;

	vector<int> cards(55), shuff(55), temp;

	for (int i = 1; i <= 54; i++) {

		cin >> shuff[i];

		cards[i] = i;

	}

	for (int i = 0; i < num; i++) {

		temp = cards;

		for (int j = 1; j <= 54; j++) {

			cards[shuff[j]] = temp[j];

		}


	}

	cout << s[(cards[1] - 1 )/ 13] << (cards[1] % 13 == 0 ? cards[1] % 14: cards[1] % 13);

	for(int i = 2; i <= 54; i++) {

		cout << " " << s[(cards[i] - 1 )/ 13] << (cards[i] % 13 == 0 ? 13 : cards[i] % 13); ;

	}
	
	system("pause");

	return 0;
}


