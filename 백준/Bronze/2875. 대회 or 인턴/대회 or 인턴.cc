#include <iostream>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    int team = 0;
    while(n >= 2 && m >= 1){
        n -= 2;
        m--;
        team++;
    }

    if(n > 0) k -= n;
    if(m > 0) k -= m;

    while(k > 0){
        k -= 3;
        team--;
    }
    cout << team;
}