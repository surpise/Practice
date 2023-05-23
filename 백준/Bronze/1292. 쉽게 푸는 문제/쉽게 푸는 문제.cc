#include <iostream>

using namespace std;

int main(){
    int arr[1001];
    int cnt = 0, t = 1;
    for(int i = 1; i <= 1000; i++){
        arr[i] = t;
        cnt++;
        if(cnt == t){
            cnt = 0;
            t++;
        }
    }
    int a, b, sum = 0;
    cin >> a >> b;
    for(int i = a; i <= b; i++) sum += arr[i];
    
    cout << sum;
}