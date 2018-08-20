#include<iostream> 
#include<string>
#include<iomanip>
using namespace std;

int main(){
	float max,result = 1;
	int r[3];
	string str = "WTL";
	
	for(int i = 0 ; i < 3; i ++){
		max = -1;
		for( int j = 0 ;j < 3 ; j ++){
			float a;
			cin >> a;
			if(a > max){
				max = a;
				r[i] = j;
			}
		}
		result *= max;
	}
	
	for(int i = 0 ; i < 3; i++){
		cout << str[r[i]] << " ";
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << (result*0.65 - 1)*2;
	return 0;
}
