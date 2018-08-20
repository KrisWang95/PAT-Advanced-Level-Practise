#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {

	int mount;

	float worth;

	float av;

};

bool cmp(node a, node b) {

	return a.av > b.av;

}

int main() {

	int num, command ;

	cin >> num >> command;

	vector<node> mooncake(num);

	for (int i = 0; i < num; i++) {

		cin >> mooncake[i].mount;

	}

	for (int i = 0; i < num; i++) {

		cin >> mooncake[i].worth;

		mooncake[i].av = mooncake[i].worth * 1.0 /  mooncake[i].mount;

	}

	sort(mooncake.begin(), mooncake.end(), cmp);

	int j = 0;

	float ret = 0.00;

	while (command !=0 && j < num) {

		if (command >= mooncake[j].mount) {

			command -= mooncake[j].mount;

			ret += mooncake[j].worth;

			j++;

		}
		else {

			ret += (mooncake[j].worth * 1.0  * command / mooncake[j].mount);

			command = 0;

		}

	}

	ret += 0.005;

	printf("%.2f", ret);

	system("pause");

	return 0;
}