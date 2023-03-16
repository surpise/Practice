#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> dogam;
string ndogam[100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        cin >> ndogam[i];
        dogam.insert({ndogam[i], i});
    }

    string ans;
    for(int i = 0; i < M; i++){
        cin >> ans;
        if(dogam.find(ans) != dogam.end()){
            cout << dogam.find(ans)->second << '\n';
        }
        else cout << ndogam[stoi(ans)] << '\n';
    }
}