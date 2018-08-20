#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
struct node{
    int v;
    int layer;
};

vector<node> g[1005];
bool visited[1005];
int num , maxLev,qnum;

int bfs(int s){
    int ans = 0;
    queue<node> q;
    node start;
    start.v = s;
    start.layer = 0;
    q.push(start);
    visited[start.v] = true;
    while(!q.empty()){
        node temp = q.front();
        q.pop();
        for(int i = 0; i < g[temp.v].size();i++){
            node next = g[temp.v][i];
            next.layer = temp.layer+1;
            if(visited[next.v] != true && next.layer <= maxLev){
                q.push(next);
                visited[next.v] = true;
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    node n;
    cin >> num >> maxLev;
    for(int i = 1; i<=num;i++){
        n.v = i;
        int k,temp;
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> temp;
            g[temp].push_back(n);
        }
    }

    cin >> qnum;

    for(int i = 0; i<qnum;i++){
        memset(visited,false,sizeof(visited));
        int k;
        cin >> k;
        cout << bfs(k) << endl;
    }
    return 0;
}

