#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = -1;
    if(A == B) answer = 0;
    else{
        for(int i = 1; i < A.size(); i++){
            string tmp = A[A.size() - 1] + A.substr(0, A.size() - 1);
            if(tmp == B) {
                answer = i;
                break;
            }
            else A = tmp;
        }
    }
    return answer;
}