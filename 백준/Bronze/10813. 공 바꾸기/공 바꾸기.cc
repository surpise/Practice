#include <iostream>
using namespace std;

int arr[101];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) arr[i] = i;
    
    int a, b, tmp;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
    for(int i = 1; i <= n; i++) cout << arr[i] << " ";
}