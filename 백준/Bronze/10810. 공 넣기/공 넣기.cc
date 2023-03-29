#include <iostream>
using namespace std;

int arr[101];
int main(){
    int n, m;
    cin >> n >> m;

    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        for(int j = a; j <= b; j++) arr[j] = c;
    }
    for(int i = 1; i <= n; i++) cout << arr[i] << " ";
}