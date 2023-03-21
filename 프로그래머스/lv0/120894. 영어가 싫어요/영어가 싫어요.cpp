#include <string>
#include <vector>

using namespace std;
string arr[10] = {"zer", "one", "two" , "thr", "fou", "fiv", "six", "sev", "eig", "nin"};
long long solution(string numbers) {
    long long answer = 0, cnt = 0;
    string tmp = "";
    for(int i = 0; i < numbers.size(); i++){
        cnt++;
        tmp += numbers[i];
        if(cnt == 3) {
            for(int j = 0; j < 10; j++){
                if (tmp == arr[j]){
                    answer *= 10;
                    answer += j;
                    tmp = "";
                    cnt = 0;
                    if(j == 0 || j == 4 || j == 5 || j == 9) i += 1;
                    if(j == 3 || j == 7 || j == 8) i += 2;
                }
            }
        }
    }
    return answer;
}