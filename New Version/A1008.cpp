#include<iostream>
using namespace std;

int main(){
	int num,up =0 ,down = 0,last = 0;
	cin >> num;
	
	for(int i = 0 ;i < num; i++){
		int temp;
		cin >> temp; 
		if(temp< last){
			down += (last -temp);
		}else{
			up += (temp - last);
		}
		last = temp;
	}
	
	cout << up*6 +4*down+5*num;
	
	return 0;
}
