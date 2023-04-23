#include <iostream>
#include <queue>
#include <array>
using namespace std;

int n, sz = 2, eat, cnt, ans;
int sea[20][20], fish[7];
bool v[20][20];
pair<int, int> shark;
queue<array<int, 3>> q;

void bfs(){
    int t[3] = {q.front()[0], q.front()[1], q.front()[2]};
    v[t[0]][t[1]] = 1;
    q.pop();
    if(sea[t[0]][t[1]] && sea[t[0]][t[1]] < sz){
        ans += t[2];
        eat++;
        while(!q.empty()) {
            if(sea[q.front()[0]][q.front()[1]] && sea[q.front()[0]][q.front()[1]] < sz && q.front()[2] == t[2]){
                if(q.front()[0] == t[0]){
                    if(q.front()[1] < t[1]){
                        t[0] = q.front()[0];
                        t[1] = q.front()[1];
                    }
                }
                else if(q.front()[0] < t[0]){
                        t[0] = q.front()[0];
                        t[1] = q.front()[1];
                }
            }
            q.pop();
        }
        sea[t[0]][t[1]] = 0;
        shark = {t[0], t[1]};
        return;
    }
    if(!v[t[0] - 1][t[1]] && t[0] > 0 && sea[t[0] - 1][t[1]] <= sz) {
        q.push({t[0] - 1, t[1], t[2] + 1});
    }
    if(!v[t[0]][t[1] - 1] && t[1] > 0 && sea[t[0]][t[1] - 1] <= sz) {
        q.push({t[0], t[1] - 1, t[2] + 1});
    }
    if(!v[t[0] + 1][t[1]] && t[0] < n - 1  && sea[t[0] + 1][t[1]] <= sz){
        q.push({t[0] + 1, t[1], t[2] + 1});
    } 
    if(!v[t[0]][t[1] + 1] && t[1] < n - 1 && sea[t[0]][t[1] + 1] <= sz) {
        q.push({t[0], t[1] + 1, t[2] + 1});
    }
}

int main(){
    cin >> n;

    int x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> x;
            if(x == 9) shark = {i, j};
            else if(x > 0) {
                fish[x]++;
                sea[i][j] = x;
            }
        }
    }
    cnt = fish[1];
    q.push({shark.first, shark.second, 0});
    while(!q.empty() && cnt){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 20; j++) v[i][j] = 0;
        }
        while(!q.empty()) bfs();
        q.push({shark.first, shark.second, 0});
        cnt--;
        if(eat == sz){
            if(sz < 7) cnt += fish[sz];
            sz++;
            eat = 0;
        }
    }
    cout << ans;
}