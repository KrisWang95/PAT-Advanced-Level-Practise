#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
typedef struct poly{
	int e;
	float t;
}poly; 
int main(){
	int num,cnt = 0;
	vector<poly> v;
	float result[2001] = {0};
	cin >> num;
	
	for(int i = 0 ; i < num ; i++ ){
		poly a;
		cin >> a.e >> a.t;
		v.push_back(a);
	}
	
	cin >> num;
	
	for(int i = 0 ; i < num ; i++ ){
		poly a;
		cin >> a.e >> a.t;
		for(int j = 0; j < v.size(); j ++){
			result[v[j].e+a.e] += a.t * v[j].t;
		}
	}
	
	for(int i = 0; i < 2001; i++){
		if(result[i])
			cnt++;
	}
	cout << cnt;
	
	for(int i = 2000; i >= 0; i--){
		if(result[i]){
			cout << " " << i << " " << setiosflags(ios::fixed) << setprecision(1) << result[i];
		}
			
	}
	
} 
