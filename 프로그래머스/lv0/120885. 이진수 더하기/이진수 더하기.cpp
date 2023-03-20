#include <string>
#include <vector>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "", tmp = "";
    int sum = 0, up = 1;
    for(int i = bin1.size() - 1; i >= 0; i--){
        sum += (bin1[i] - '0') * up;
        (up == 0) ? up = 2 : up *= 2; 
    }
    up = 1;
    for(int i = bin2.size() - 1; i >= 0; i--){
        sum += (bin2[i] - '0') * up;
        (up == 0) ? up = 2 : up *= 2; 
    }
    if(sum == 0) answer = "0";
    else{
        while(sum > 0) {
            tmp += (sum % 2) + '0';
            sum /= 2;
        }
        for(int i = tmp.size() - 1; i >= 0; i--) answer += tmp[i];
    }

    return answer;
}