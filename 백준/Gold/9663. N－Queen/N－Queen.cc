#include <iostream>

using namespace std;

int n, cnt;
int queen[15];

bool check(int x){
    bool c = true;
    for(int i = 0; i < x; i++){
        if(queen[x] == queen[i]) c = false;
        else if(abs(x - i) == abs(queen[x] - queen[i])) c = false;
    }
    return c;
}

void dfs(int x){
    if(x == n) cnt++;
    else{
        for(int i = 0; i < n; i++){
            queen[x] = i;
            if(check(x)){
                dfs(x + 1);
            }
        }
    }
}

int main(){
    cin >> n;

    dfs(0);
    
    cout << cnt;
}