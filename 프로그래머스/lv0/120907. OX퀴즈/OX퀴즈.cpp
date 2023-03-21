#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer, vec;
    for(int i = 0; i < quiz.size(); i++){
        int tmp = 0;
        for(int j = 0; j < quiz[i].size(); j++){
            if(quiz[i][j] == ' '){
                vec.push_back(quiz[i].substr(tmp, j - tmp));
                tmp = j + 1;
            }
        }

        vec.push_back(quiz[i].substr(tmp));
        int sum = 0, up;
        for(int n = 0; n < vec.size(); n++){
            if (n == 1) {
                sum = tmp;
                continue;
            }
            else if(n == 3){
                if(vec[1] == "-") sum -= tmp;
                else sum += tmp;
                continue;
            }
            up = 1;
            tmp = 0;
            for(int m = vec[n].size() - 1; m >= 0; m--){
                if(vec[n][m] == '-') tmp *= -1;
                else{
                    tmp += (vec[n][m] - '0') * up;
                    up *= 10;
                }
            }
        }
        if(sum == tmp) answer.push_back("O");
        else answer.push_back("X");
        vec.clear();
    }
    return answer;
}