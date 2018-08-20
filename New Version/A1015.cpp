#include<iostream> 
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<cmath>
using namespace std;

bool isPrime(int a){
	if(a == 1){
		return false;
	}else{
		for(int i = 2; i <= sqrt(a);i ++){
			if(a % i == 0) return false;
		}
	}
	return true;
}

int getR(int a, int b){
	vector<int> v;
	int t = 1,result = 0;
	
	while(a != 0){
		v.push_back(a % b) ;
		a /= b;
	}
	
	for(int j = v.size()- 1; j >= 0; j--){
		result += v[j] * t;
		t *= b; 
	}
	return result;
}



int main(){
	
	ios::sync_with_stdio(false);
	
	while(1){
		int n, d;
		cin >> n;
		if(n < 0) break;
		cin >> d;
		if( isPrime(n)){
			if(isPrime(getR(n,d))) cout << "Yes\n"; 
			else cout << "No\n";
			
		}else{
			cout << "No\n";
		}
	}
	
	return 0;
}
