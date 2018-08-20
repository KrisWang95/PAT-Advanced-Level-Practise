#include<iostream>
#include<vector>
using namespace std;

int main(){
	int v[20000],num;
	cin >> num;
	int sum = 0,s = 0 ,e = num -1,s1 = 0,maxsum = -1;
	for(int i = 0; i < num; i++){
		
		cin >> v[i];
		
		sum += v[i];
		if(maxsum < sum){
			maxsum = sum;
			s = s1;
			e = i;
		}
		else if(sum < 0){
			sum = 0;
			s1 = i + 1;
		}
	}
	if(maxsum < 0) maxsum = 0;
	cout << maxsum << " "<< v[s] << " " << v[e];
	return 0;
} 

