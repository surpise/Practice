#include <iostream>
using namespace std;

int main(){
    int n, m;
    int arr[101], tmp[101];
    cin >> n >> m;
    for(int i = 1; i <= n; i++) arr[i] = i;

    int begin, end, mid;
    for(int i = 0; i < m; i++){
        cin >> begin >> end >> mid;
        int t = 0;
        for(int j = mid; j <= end; j++) tmp[t++] = arr[j];
        for(int j = 0; j < mid - begin; j++) tmp[t++] = arr[begin + j];
        for(int j = 0; j < t; j++) arr[begin + j] = tmp[j];
    }
    for(int i = 1; i <= n; i++) cout << arr[i] << " ";
}