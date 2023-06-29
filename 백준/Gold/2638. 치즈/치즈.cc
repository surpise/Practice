#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans, cnt;
int arr[100][100];
int v[100][100];
int d[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

queue<pair<int, int>> q;
vector<pair<int, int>> ch;

void bfs(){
    int r, c, tr, tc;
    while(!q.empty()){
        r = q.front().first, c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            tr = r + d[0][i], tc = c + d[1][i];
            if(tr < 0 || tr >= n || tc < 0 || tc >= m) continue;

            if(arr[tr][tc] > 0) arr[tr][tc]++;
            else if(!v[tr][tc] && arr[tr][tc] == 0){
                q.push({tr, tc});
                v[tr][tc] = 1;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                ch.push_back({i, j});
            }
        }
    }

    while(ch.size() != 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) v[i][j] = 0;
        }

        q.push({0, 0});
        v[0][0] = 1;
        bfs();

        for(int i = 0; i < ch.size(); i++){
            if(arr[ch[i].first][ch[i].second] > 2){
                arr[ch[i].first][ch[i].second] = 0;
                ch.erase(ch.begin() + i);
                i--;
            }
            else arr[ch[i].first][ch[i].second] = 1;
        }

        ans++;
    }
    cout << ans;
}