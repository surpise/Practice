#include <iostream>

using namespace std;

char ans[531442];
void canto(int idx, int l){
    if(l == 1) return;
    int start = idx - l + (l / 3), end = idx - (l / 3);
    for(int i = start + 1; i <= end; i++){
        ans[i] = ' ';
    }
    canto(idx - (l / 3) * 2, l / 3);
    canto(idx, l / 3);
}

int main(){
    int n, length;
    while(1){
        cin >> n;
        if(cin.eof()) break;
        length = 1;
        for(int i = 0; i < n; i++) length *= 3;
        for(int i = 1; i <= length; i++) ans[i] = '-';
        canto(length, length);
        for(int i = 1; i <= length; i++) cout << ans[i];
        cout << endl;
    }
}