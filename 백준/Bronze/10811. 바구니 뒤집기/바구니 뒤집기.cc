#include <iostream>
#include <stack>
using namespace std;

int main(){
    int arr[101];
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) arr[i] = i;

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        stack<int> s;
        for(int i = a; i <= b; i++) s.push(arr[i]);
        for(int i = a; i <= b; i++){
            arr[i] = s.top();
            if(!s.empty()) s.pop();
        }
    }
    for(int i = 1; i <= n; i++) cout << arr[i] << " ";
}