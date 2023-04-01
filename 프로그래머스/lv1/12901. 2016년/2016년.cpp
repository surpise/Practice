#include <string>
#include <vector>
using namespace std;

string solution(int a, int b) {
    string day[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    int month[12] = {0, 1, 0, 1, 1, 2, 2, 3, 4, 4, 5, 5};
    b += (a - 1) * 30 + month[a - 1];
    string answer = day[b % 7];
    return answer;
}