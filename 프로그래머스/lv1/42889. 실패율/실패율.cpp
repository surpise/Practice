#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<float, int> a, pair<float, int> b){
    if(a.first > b.first) return true;
    else if(a.first == b.first){
        if(a.second < b.second) return true;
    }
    return false;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float, int>> tmp;
    float noc, c, f;
    for(int i = 1; i <= N; i++){
        noc = 0;
        c = 0;
        for(int j = 0; j < stages.size(); j++){
            if(stages[j] == i) noc++;
            if(stages[j] >= i) c++;
        }
        f = (c == 0) ? 0 : noc / c;
        tmp.push_back({f, i});
    }
    sort(tmp.begin(), tmp.end(), cmp);
    for(int i = 0; i < N; i++) answer.push_back(tmp[i].second);
    return answer;
}