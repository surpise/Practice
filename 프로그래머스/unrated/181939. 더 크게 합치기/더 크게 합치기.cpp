#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string A = to_string(a) + to_string(b);
    string B = to_string(b) + to_string(a);
    
    int ab = 0, ba = 0;
    for(int i = 0; i < A.size(); i++){
        ab *= 10;
        ba *= 10;
        ab += A[i] - '0';
        ba += B[i] - '0';
    }
    
    int answer = (ab > ba) ? ab : ba;
    return answer;
}