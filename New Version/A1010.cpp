#include<iostream>
#include<string>
#include<algorithm> 

using namespace std;

long long getReal(string a, int r){
	long long sum = 0,t = 1;
	for(int i = a.length() - 1; i >= 0 ;i --){
		sum += (a[i] >= '0' && a[i] <= '9'? (a[i]- '0')*t : (a[i]-'a'+10)*t);
		t *= r;
	}
	return sum;
}
int getMin(string a){
	int b = -1;
	for(int i = 0 ; i  < a.size(); i++){
		if (b < a[i])
			b = a[i];
	}
	return (b > '9' ? b - 'a' + 10 : b - '0')+1;
}

int main(){
	string a[2];
	long long c, d, low, high, mid, real,flag = 0;
	cin >> a[0] >> a[1] >> c >> d; 
	
	real = getReal(a[c == 1 ? 0: 1],d);
	
	low = getMin(a[c != 1 ? 0 : 1]);
	high = max(real,low)+1;
	
	while(low <= high){
		
		mid = (low+high)/2;
		
		long long g = getReal(a[c != 1 ? 0 : 1],mid);
		
		if(g > real ||g <0){
			
			high = mid - 1;
			
		}else if (g == real){
			flag = 1;
			break;
		}else{
			low = mid  + 1;
		}
		
	}
	
	if(flag){
		cout << mid;
	}else{
		cout << "Impossible";
	}
	return 0;
}
