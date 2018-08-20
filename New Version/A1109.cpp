#include<iostream> 
#include<algorithm> 
#include<vector>
#include<string>
using namespace std;
struct stu {
	string name;
	int height;
};
//height from max to min , name from min to max
bool cmp(stu a, stu b) {

	if (a.height != b.height)

		return a.height > b.height;

	else

		return a.name < b.name;
}
int main() {

	int count, row, max, j = 0;

	cin >> count >> row;

	vector<stu> st(count);

	for (int i = 0; i < count; i++) {

		cin >> st[i].name >> st[i].height;

	}

	sort(st.begin(),st.end(), cmp);

	for (int i = 0; i < row && j < count; i++) {

		if (i == 0)

			max = count / row + count%row;

		else

			max = count / row;

		vector<string> temp(max);

		int right = max / 2 + 1, left = max / 2 - 1;

		temp[max / 2] = st[j++].name;

		while (left >= 0 || right <= max - 1) {

			if (left >= 0)

				temp[left--] = st[j++].name;

			if (right <= max - 1)

				temp[right++] = st[j++].name;

		}
		cout << temp[0];

		for (int k = 1; k < max; k++) {

			cout << " " << temp[k];

		}
		
		cout << endl;
	}

	system("pause");

	return 0;
}