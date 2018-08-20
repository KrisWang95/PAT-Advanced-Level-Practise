#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
//优先权的问题 
using namespace std;

int flag = 0;
int m[1000000],result[1000000];

struct stu{
	int id;
	int marks[4],ranks[4];
};


bool cmp(stu a,stu b){
	return a.marks[flag] > b.marks[flag];
}

int main(){
	int num,cnum;
	cin >> num >> cnum;
	vector<stu> v;
	string str = "-ACME";
	
	for(int i = 0 ; i < num; i++){
		stu a;
		cin >> a.id >> a.marks[1] >> a.marks[2] >> a.marks[3]; 
		a.marks[0] = ( a.marks[1] + a.marks[2] + a.marks[3])/3.0+0.5; 
		v.push_back(a); 
		m[a.id] = 5;
	}
	
	for(int i = 0 ; i < 4; i++){
		flag = i;
		sort(v.begin(),v.end(),cmp);
		v[0].ranks[i] = 1;
		for(int j = 1; j < num ; j ++){
			v[j].ranks[i] = j + 1;
			if(v[j].marks[i] == v[j-1].marks[i]){
				v[j].ranks[i] = v[j-1].ranks[i];
			}
		}
	}
	
	for(int i = 0; i < num; i++){
		
		for(int j = 0 ; j <= 3; j++){
			if(m[v[i].id] > v[i].ranks[j]){
				m[v[i].id] = v[i].ranks[j];
				result[v[i].id] = j + 1;
			}
		}
		
	}
	
	for(int i = 0;i  < cnum; i++){
		int temp;
		cin >> temp;
		if(result[temp]){
			cout << m[temp] << " " << str[result[temp]] << endl;
		}else{
			cout << "N/A" <<endl;
		}
	}
	return 0;
	
}
