#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int findKth(vector<int> arr1, vector<int> arr2, int start1, int start2, int len1, int len2, int k) {
	// 保证arr1是较短的数组
	if (len1 > len2) {
		return findKth(arr2, arr1, start2, start1, len2, len1, k);
	}
	if (len1 == 0) {
		return arr2[start2 + k - 1];
	}
	if (k == 1) {
		return min(arr1[start1], arr2[start2]);
	}
	int p1 = min(k / 2, len1);

	int p2 = k - p1;

	if (arr1[start1 + p1 - 1] < arr2[start2 + p2 - 1]) {
		return findKth(arr1, arr2, start1 + p1, start2, len1 - p1, len2, k - p1);
	}
	else if (arr1[start1 + p1 - 1]>arr2[start2 + p2 - 1]) {
		return findKth(arr1, arr2, start1, start2 + p2, len1, len2 - p2, k - p2);
	}
	else {
		return arr1[start1 + p1 - 1];
	}
}



int findMedianSortedArrays(vector<int> a, vector<int> b) {
	int m = a.size(), n = b.size();

	int k = (m + n) / 2;

	if ((m + n) % 2 == 0) {

		return findKth(a, b, 0, 0, m, n, k);
	}
	else {

		return findKth(a, b, 0, 0, m, n, k + 1);

	}

}



int main() {

	int m, n, cnt;
	vector<int> a, b;

	cin >> m;
	for (int i = 0; i < m; i++) {
		long int temp;
		cin >> temp;
		a.push_back(temp);
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		long int temp;
		cin >> temp;
		b.push_back(temp);
	}

	cout << findMedianSortedArrays(a, b);
	
	
	system("pause");

	return 0;
}
