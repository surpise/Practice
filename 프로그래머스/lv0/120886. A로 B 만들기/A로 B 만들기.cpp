#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string before, string after) {
    int answer = 1;
    vector<char> a, b;
    for(int i = 0; i < before.size(); i++){
        a.push_back(after[i]);
        b.push_back(before[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < before.size(); i++){
        if(a[i] != b[i]) answer = 0;
    }
    return answer;
}