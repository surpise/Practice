#include <iostream>

using namespace std;

int arr[128][128];
int b = 0, w = 0;
char cut(int l, int r, int c){
    if(l == 2){
        int cnt = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++) cnt += arr[r - i][c - j];
        }
        if(cnt == 4) return 'b';
        else if(cnt == 0) return 'w';
        else {
            b += cnt;
            w += 4 - cnt;
            return 'c';
        }
    }
    else{
        int bt = 0, wt = 0;
        char tmp;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                tmp = cut(l / 2, r - ((l / 2) * i), c - ((l / 2) * j));
                if(tmp == 'b') bt++;
                else if(tmp == 'w') wt++;
            }
        }
        if(bt == 4) return 'b';
        else if(wt == 4) return 'w';
        else{
            b += bt;
            w += wt;
            return 'c';
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> arr[i][j];
    }

    char ans = cut(n, n - 1, n - 1);
    if(ans == 'b') cout << 0 << '\n' << 1;
    else if(ans == 'w') cout << 1 << '\n' << 0;
    else cout << w << '\n' << b;
}