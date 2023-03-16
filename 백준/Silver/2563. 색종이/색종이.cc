#include <iostream>

using namespace std;

bool arr[101][101];
int main(){
    int n, row, col, ans = 0;;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> row >> col;
        for(int r = row; r < row + 10; r++){
            for(int c = col; c < col + 10; c++){
                if(!arr[r][c]){
                    ans++;
                    arr[r][c] = 1;
                }
            }
        }
    }
    cout << ans;
}