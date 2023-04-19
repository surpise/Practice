#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int, string>> q;
bool v[10000];
void ans(string ans){
    cout << ans << '\n';
    while(!q.empty()) q.pop();
}

void bfs(int f){
    int x = q.front().first;
    string dslr = q.front().second;
    q.pop();

    int d, s, l, r;
    d = (x * 2) % 10000;
    s = (x == 0) ? 9999 : x - 1;
    l = ((x * 10) % 10000) + (x / 1000);
    r = ((x % 10) * 1000) + (x / 10);
    if(d == f) ans(dslr + 'D');
    else if(s == f) ans(dslr + 'S');
    else if(l == f) ans(dslr + 'L');
    else if(r == f) ans(dslr + 'R');
    else{
        if(!v[d]){
            q.push({d, dslr + 'D'});
            v[d] = 1;
        } 

        if(!v[s]) {
            q.push({s, dslr + 'S'});
            v[s] = 1;
        }

        if(!v[l]){
            q.push({l, dslr + 'L'});
            v[l] = 1;
        }

        if(!v[r]){
            q.push({r, dslr + 'R'});
            v[r] = 1;
        }
    }
}

int main(){
    int tc, a, b;
    cin >> tc;
    for(int t = 0; t < tc; t++){
        cin >> a >> b;
        memset(v, 0, sizeof(v));
        q.push({a, ""});
        v[a] = 1;
        while(!q.empty()) bfs(b);
    }
}