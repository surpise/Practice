#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    int r = M - 1, c = (N - 1) * (r + 1);
    int answer = (M == 1 && N == 1) ? 0 : r + c;
    return answer;
}