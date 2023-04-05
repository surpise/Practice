#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int t;
bool cmp(string a, string b){
    if(a[t] < b[t]) return true;
    else if (a[t] == b[t]){
        if(a < b) return true;
    }
    return false;
}
vector<string> solution(vector<string> strings, int n) {
    t = n;
    vector<string> answer;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}