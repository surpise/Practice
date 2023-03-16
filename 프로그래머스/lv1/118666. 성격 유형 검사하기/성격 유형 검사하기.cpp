#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    int R = 0, T = 0, F = 0, C = 0, M = 0, J = 0, A = 0, N = 0;
    int tmp;
    for(int i = 0; i < survey.size(); i++){
        tmp = choices[i] - 4;
        if(tmp == 0) continue;
        else if(tmp < 0){
            tmp  = 4 - choices[i];
            if(survey[i] == "RT") R += tmp;
            else if(survey[i] == "TR") T += tmp;
            if(survey[i] == "CF") C += tmp;
            else if(survey[i] == "FC") F += tmp;
            if(survey[i] == "JM") J += tmp;
            else if(survey[i] == "MJ") M += tmp;
            if(survey[i] == "AN")  A+= tmp;
            else if(survey[i] == "NA") N += tmp;
        }
        else{
            if(survey[i] == "TR") R += tmp;
            else if(survey[i] == "RT") T += tmp;
            if(survey[i] == "FC") C += tmp;
            else if(survey[i] == "CF") F += tmp;
            if(survey[i] == "MJ") J += tmp;
            else if(survey[i] == "JM") M += tmp;
            if(survey[i] == "NA") A += tmp;
            else if(survey[i] == "AN") N += tmp;
        }
    }
    answer += (R >= T) ? "R" : "T";
    answer += (C >= F) ? "C" : "F";
    answer += (J >= M) ? "J" : "M";
    answer += (A >= N) ? "A" : "N";

    return answer;
}