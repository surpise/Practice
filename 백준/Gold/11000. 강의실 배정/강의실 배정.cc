#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Tt{
    int s, e;
};
bool cmp(Tt a, Tt b){
    if(a.s < b.s) return true;
    else if(a.s == b.s){
        if(a.e < b.e) return true;
    }
    return false;
}
int n;

int main(){
    cin >> n;
    vector<Tt> v;
    Tt x;
    for(int i = 0; i < n; i++){
        cin >> x.s >> x.e;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(v[0].e);
    for(int i = 1; i < v.size(); i++){
        if(pq.top() > v[i].s){
            pq.push(v[i].e);
        }
        else{
            pq.pop();
            pq.push(v[i].e);
        }
    }
    cout << pq.size();
}