#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    unsigned long long n, num, a, b, sum = 0;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++){
        cin >> num;
        pq.push(num);
    }

    while(pq.size() > 1){
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        sum += a + b;
        pq.push(a + b);
    }

    cout << sum;
}
