#include <iostream>
#include <deque>
using namespace std;

int main(){
    int sz, n, x, cnt, ans = 0;
    cin >> sz >> n;

    deque<int> dq;
    for(int i = 0; i < sz; i++) dq.push_back(i);
    for(int i = 0; i < n; i++){
        cin >> x;
        deque<int> t1 = dq, t2 = dq;
        int c1 = 0, c2 = 0;
        while(t1.front() != x - 1){
            t1.push_back(t1.front());
            t1.pop_front();
            c1++;
        }
        while(t2.front() != x - 1){
            t2.push_front(t2.back());
            t2.pop_back();
            c2++;
        }
        dq = (c1 <= c2) ? t1 : t2;
        ans += (c1 <= c2)? c1 : c2;
        dq.pop_front();
    }
    cout << ans;
}