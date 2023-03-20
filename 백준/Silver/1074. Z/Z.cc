#include <iostream>

using namespace std;

int row, col, cnt = -1;
int z(int l, int r, int c){
    if(l == 2){
        if(row > r || col > c){
            cnt += 4;
            return -1;
        }
        for(int i = 1; i >= 0; i--){
            for(int j = 1; j >= 0; j--){
                cnt++;
                if((r - i == row) && (c - j == col)) return cnt;
            }
        }
        return -1;
    }
    else{
        int ans, tr, tc;
        for(int i = 1; i >= 0; i--){
            for(int j = 1; j >= 0; j--){
                tr = r - ((l / 2) * i);
                tc = c - ((l / 2) * j);
                if(row > tr || col > tc) cnt += (l / 2) * (l / 2);
                else{
                    ans = z(l / 2, tr, tc);
                    if(ans != -1) return ans;
                }
            }
        }
        return -1;
    }
}

int main(){
    int N, n = 1;
    cin >> N >> row >> col;
    for(int i = 0; i < N; i++) n *= 2;
    cout << z(n, n - 1, n - 1);
}