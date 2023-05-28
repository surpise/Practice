#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, t;
bool knowp[51], v[51];
int meet[51][51];
queue<int> q;
vector<int> party[51];

void bfs(){
    while(!q.empty()){
        int _v = q.front();
        q.pop();
        v[_v] = 1;
        knowp[_v] = 1;

        for(int i = 1; i <= n; i++){
            if(!v[i] && meet[_v][i] == 1){
                knowp[i] = 1;
                q.push(i);
            }
        }
    }
}

int main(){
    cin >> n >> m >> t;

    int tp;
    for(int i = 0; i < t; i++){
        cin >> tp;
        knowp[tp] = 1;
        q.push(tp);
    }

    int many, num;
    for(int i = 0; i < m; i++){
        cin >> many;
        for(int j = 0; j < many; j++){
            cin >> num;
            party[i].push_back(num);
        }
        for(int j = 0; j < many; j++){
            for(int k = 0; k < many; k++){
                if(j != k) meet[party[i][j]][party[i][k]] = 1;
            }
        }
    }

    bfs();
    int ans = m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < party[i].size(); j++){
            if(knowp[party[i][j]] == 1){
                ans--;
                break;
            }
        }
    }
    cout << ans;
}