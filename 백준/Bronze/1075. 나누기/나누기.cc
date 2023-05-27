#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, f;
    cin >> n >> f;
    int tmp = n - (n % 100);
    for(int i = 0; i < 100; i++){
        if (tmp % f == 0){
            int t = tmp % 100;
            if(t == 0) cout << "00";
            else if(t < 10) cout << "0" << t;
            else cout << t;
            break;
        }
        tmp++;
    }
}