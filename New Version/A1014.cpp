//���Ƚ��N*M���˵��Ŷ����⣬�ٽ��������˵��Ŷ� 
//1. N*M�Ŷ�
//	ֱ����ÿ������ ˳����� 
//2. ��������Ŷ�
//	����ÿ�����ڵ�ʱ�����У�ÿ��Ѱ���������ҵ��Ĵ��ڣ�
//���ù˿ʹӸô����޳�����Ѱ�Ҵ����������ٵĴ��ڽ��в��롣 
#include<iostream>
#include<queue>
using namespace std; 

struct customers{
	int index;
	int st;
	int beginTime = 999; 
	int endtime = 999;
};

struct windowInfo{
	queue <customers> windows;
	int lastEndTime = 0;
};

int main(){
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	
	customers  c[1001];
	windowInfo w[20];
	
	//��k���˲��뵽������ 
	for(int i = 0; i < k; i++){
		
		c[i].index = i;
		
		cin >> c[i].st;
		
		if(i < n * m){
		
			w[i % n].windows.push(c[i]);
			
			if(i / n == 0){
				c[i].beginTime = 0;
				w[i].lastEndTime = c[i].st;
			} 
				
		}
		else{
				
			int min = 0;
			
			for(int j = 0; j < n; j++){
				
				if(w[min].lastEndTime > w[j].lastEndTime){
					min = j;
				}
				
			} 
			
			//��������޳� 
			int temp = w[min].windows.front().index;
			c[temp].endtime = w[min].lastEndTime;
			w[min].windows.pop();
			
			w[min].windows.push(c[i]);
			w[min].lastEndTime +=  w[min].windows.front().st;
			c[w[min].windows.front().index].beginTime = c[temp].endtime;
			
		}
		
	}
	
	for(int j = 0; j < n; j++){
		
		while(! w[j].windows.empty()){

			int temp = w[j].windows.front().index;
			c[temp].endtime = w[j].lastEndTime;
			w[j].windows.pop();
			
			if(!w[j].windows.empty()){
				w[j].lastEndTime += w[j].windows.front().st;
				c[w[j].windows.front().index].beginTime = c[temp].endtime;
			}
		}
		
	} 
	
	

	for(int i = 0; i < q; i++){
		
		int query;
		cin >> query;
		if(c[query-1].beginTime < 540)
			printf("%02d:%02d\n", c[query - 1].endtime/ 60 + 8, c[query - 1].endtime % 60);
		else
			cout << "Sorry" << endl;
	}
	
	return 0;
} 
