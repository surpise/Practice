#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, x;
    double d, w, h;
    cin >> n >> w >> h;
    d = sqrt(w * w + h * h);
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x <= d) cout << "DA\n";
        else cout << "NE\n";
    }
}