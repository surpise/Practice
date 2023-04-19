#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int idx = 0;
    sort(&X[0], &X[X.size()], greater<char>());
    sort(&Y[0], &Y[Y.size()], greater<char>());
    for(int i = 0; i < X.size(); i++){
        while(X[i] < Y[idx]) idx++;
        if(X[i] == Y[idx]) {
            answer += X[i];
            idx++;
        }
        
    } 
    if(answer.size() == 0) answer = "-1";
    else if(answer[0] == '0') answer = "0";
    return answer;
}