#include <iostream>

using namespace std;

void hanoi(int d, int from, int to, int via){
    if(d == 1){
        cout << from << " " << to << '\n';
    }
    else{
        hanoi(d - 1, from, via, to);
        cout << from << " " << to << '\n';
        hanoi(d - 1, via, to, from);
    }
}

int main(){
    int n, cnt = 1;
    cin >> n;
    for(int i = 0; i < n; i++) cnt *= 2;
    cout << cnt - 1 << '\n';
    hanoi(n, 1, 3, 2);
}