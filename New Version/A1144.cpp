#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 10000010;
int n;
LL a[MAXN];
vector<int> vec;

int getFirstMissingPositiveInteger() {
	for (int i = 1; i <= n; i++) {   // ������������
		while (a[i] > 0 && a[i] <= n && a[i] != a[a[i]]) {   // ֻҪa[i]�ڷ�Χ�ڣ�����a[i]Ϊ�±����������a[i]
			swap(a[i], a[a[i]]);    // ��������a[i]�ع鱾λ
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) {     // ���a[i]������i��˵��i����ȱʧ����
			return i;
		}
	}
	return n + 1;   // ��������a[i]������i����ô˵��n+1��ȱʧ����
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	printf("%d\n", getFirstMissingPositiveInteger());

	// ����Ľⷨ
	// for(int i = 0; i < n; i++) {
	//     LL x;
	//     scanf("%lld", &x);
	//     if(x > 0 && x <= n) {
	//         vec.push_back(x);    // ֻ��1��n֮������ӵ�vector��
	//     }
	// }
	// sort(vec.begin(), vec.end());    // ����
	// int k = 0;
	// while(k < (int)vec.size() - 1 && vec[k] + 1 >= vec[k + 1]) {     // д>=�ǿ����ظ�����
	//     k++;
	// }
	// printf("%lld\n", vec.size() == 0 ? 1 : ((LL)vec[k] + 1));
	return 0;
}