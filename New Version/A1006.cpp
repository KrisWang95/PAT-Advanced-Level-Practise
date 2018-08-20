#include<iostream>
#include<string>
#include<Nector>

using namespace std;

int main(){
	int num,minI=-1,minO=-1;
	string minIn ="99:99:99",minOut = "00:00:00",in,out,id;
	
	Nector<string> N;
	cin >> num;
	
	for(int i = 0 ; i  < num; i++){
		cin >> id >> in >> out ;
		if(minIn > in ){
			minIn = in;
			minI = i;
		}
		if(minOut < out ){
			minOut = out;
			minO = i;
		}
		N.push_back(id);
	}
	
	cout << N[minI]  << " "<< N[minO];
	
	return  0;
} 
