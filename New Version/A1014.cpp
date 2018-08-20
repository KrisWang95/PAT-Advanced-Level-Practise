//首先解决N*M个人的排队问题，再解决多余的人的排队 
//1. N*M排队
//	直接往每个窗口 顺序插入 
//2. 多余的人排队
//	建立每个窗口的时间序列，每次寻找最早完成业务的窗口，
//将该顾客从该窗口剔除，再寻找窗口人数最少的窗口进行插入。 
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
	
	//将k个人插入到队伍中 
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
			
			//最早完成剔除 
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
