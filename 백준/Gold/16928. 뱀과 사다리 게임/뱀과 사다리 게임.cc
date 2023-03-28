#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> que;
int arr[101];

void bfs(int d, int c){
    if(d >= 100){
        cout << c << endl;
        while(!que.empty()) que.pop();
    }
    else{
        int tmp = 0;
        for(int i = 0; i < 7; i++){
            if(arr[d + i] != 0) que.push({arr[d + i], c + 1});
            else tmp = i;
        }
        if(tmp != 0) que.push({d + tmp, c + 1});
        que.pop();
    }
}

int main(){
    int n, m, x, y;
    cin >> n >> m;
    for(int i = 0; i < n + m; i++){
        cin >> x >> y;
        arr[x] = y;
    }
    que.push({1, 0});
    while(!que.empty()) bfs(que.front().first, que.front().second);
}
