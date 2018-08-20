#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct node {
	char name[10];
	unsigned char age;//0 -256
	int worth;
};

bool cmp(node a, node b) {

	return a.worth != b.worth ? a.worth > b.worth : strcmp(a.name,b.name) < 0;

}


int main(){

	int num, query;

	scanf("%d %d", &num, &query);

	vector<node> v(num);

	vector<vector<node> > q(201),temp(201);

	for (int i = 0; i < num; i++) {

		node a;

		scanf("%s %d %d", a.name, &a.age, &a.worth);

		v.push_back(a);

	}

	sort(v.begin(), v.end(), cmp);

	for (auto &it : v) {

		q[it.age].push_back(it);

	}

	temp = q;

	for (int i = 0; i < query; i++) {

		 q = temp;

		int n, ageMin, ageMax;

		scanf("%d %d %d", &n, &ageMin,&ageMax);

		vector<node> res;

		for (int j = 0; j < n; j++) {

			int maxWorth = INT_MIN , index = -1;

			for (int k = ageMin; k <= ageMax; k++) {

				if (!q[k].empty() && q[k].front().worth > maxWorth) {

					maxWorth = q[k].front().worth;

					index = k;

				}

			}

			if (index != -1) {

				res.push_back(q[index].front());

				q[index].erase(q[index].begin());

			}

		}

		printf("Case #%d:\n", i + 1);

		for (int j = 0; j < res.size(); j++) {

			printf("%s %d %d\n",res[j].name,res[j].age,res[j].worth);
			
		}

		if(res.size() == 0) printf("None\n");

	}


	
	system("pause");

	return 0;
}


