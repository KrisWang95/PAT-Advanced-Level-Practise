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
	for (int i = 1; i <= n; i++) {   // 遍历整个数组
		while (a[i] > 0 && a[i] <= n && a[i] != a[a[i]]) {   // 只要a[i]在范围内，且以a[i]为下标的数不等于a[i]
			swap(a[i], a[a[i]]);    // 交换，让a[i]回归本位
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) {     // 如果a[i]不等于i，说明i就是缺失的数
			return i;
		}
	}
	return n + 1;   // 如果上面的a[i]都等于i，那么说明n+1是缺失的数
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	printf("%d\n", getFirstMissingPositiveInteger());

	// 排序的解法
	// for(int i = 0; i < n; i++) {
	//     LL x;
	//     scanf("%lld", &x);
	//     if(x > 0 && x <= n) {
	//         vec.push_back(x);    // 只把1到n之间的数加到vector中
	//     }
	// }
	// sort(vec.begin(), vec.end());    // 排序
	// int k = 0;
	// while(k < (int)vec.size() - 1 && vec[k] + 1 >= vec[k + 1]) {     // 写>=是考虑重复的数
	//     k++;
	// }
	// printf("%lld\n", vec.size() == 0 ? 1 : ((LL)vec[k] + 1));
	return 0;
}