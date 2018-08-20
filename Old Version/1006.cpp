#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool cmp(string a, string b) {
	int timeA = (a[0] * 10 + a[1] - '0') * 3600 + (a[3] * 10 + a[4] - '0') * 60 + (a[6] * 10 + a[7] - '0');
	int timeB = (b[0] * 10 + b[1] - '0') * 3600 + (b[3] * 10 + b[4] - '0') * 60 + (b[6] * 10 + b[7] - '0');
	if (timeA < timeB) {
		return true;
	}
	else
	{
		return false;
	}
}
int main() {
	int N,maxI,minI;
	string minTime = "99:99:99", maxTime = "00:00:00",inTime,outTime,ID;
	vector<string> id;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ID >> inTime >> outTime;
		if (cmp(inTime, minTime)) {
			minTime = inTime;
			minI = i;
		}
		if (!cmp(outTime, maxTime)) {
			maxTime = outTime;
			maxI = i;
		}
		id.push_back(ID);
	}
	cout << id[minI] << " " << id[maxI];
	system("pause");
}

