#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    sort(&s[0], &s[s.size()], greater<int>());
    return s;
}