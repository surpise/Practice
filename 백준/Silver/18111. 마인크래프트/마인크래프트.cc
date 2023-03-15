#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m, b, h = 0, l = 257;
    int arr[500][500];
    int res[257] = {0, };
    bool c[257] = {0, };
    cin >> n >> m >> b;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] > h) h = arr[i][j];
            if(arr[i][j] < l) l = arr[i][j];
        }
    }
    int height = h, t;
    while(height >= l){
        t = b;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] - height < 0) {
                    res[height] += height - arr[i][j];
                    t-= height - arr[i][j];       
                }
                else {
                    res[height] += (arr[i][j] - height) * 2;
                    t+= arr[i][j] - height;
                }
            }
        }
        if(t < 0) c[height] = 1;
        height--;
    }

    int ans = -1, anst;
    for(int i = h; i >= l; i--){
        if(c[i]) continue;
        if(anst > res[i] || ans == -1) {
            ans = i;
            anst = res[i];
        }
    }
    cout << anst << " " << ans << endl;
}