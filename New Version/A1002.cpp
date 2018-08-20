#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n,m,cnt = 0;
	float r[1002] = {0};
	
	cin >> n  ;
	for(int i = 0 ; i  < n ; i++ ){
		int temp;
		float ftemp ;
		cin >> temp >> ftemp;
		r[temp] += ftemp;
	}
	
	cin >> m  ;
	for(int i = 0 ; i  < m ; i++ ){
		int temp;
		float ftemp ;
		cin >> temp >> ftemp;
		r[temp] += ftemp;
	}
	
	for(int i = 0 ;  i < 1002; i++){
		if(r[i] != 0) cnt++;
	}
	
	cout << cnt ;
	
	for(int i = 1001 ;  i >= 0 ; i--){
		if(r[i] != 0)  cout << " " << i << " " << setiosflags(ios::fixed) << setprecision(1) << r[i];
	}
	
	return 0;
	
}

