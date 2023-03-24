#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<float> tmp, avg;
    vector<int> answer;
    for(int i = 0; i < score.size(); i++){
        tmp.push_back((score[i][0] + score[i][1]) / 2.0);
        avg.push_back((score[i][0] + score[i][1]) / 2.0);
        answer.push_back(score[i][0]);
    }
    sort(tmp.begin(), tmp.end(),greater<float>());
    for(int i = 0; i < tmp.size(); i++){
        for(int j = 0; j < tmp.size(); j++){
            if(i > 0 && tmp[i - 1] == tmp[i]) continue;
            else if(tmp[i] == avg[j]) {
                answer[j] = i + 1;
            }
        }
    }
    return answer;
}