#include <iostream>

using namespace std;

int node[26][2];

void preorder(int x){
    char ans = x + 'A';
    cout << ans;
    if(node[x][0] != 0) preorder(node[x][0]);
    if(node[x][1] != 0) preorder(node[x][1]);
}

void inorder(int x){
    if(node[x][0] != 0) inorder(node[x][0]);
    char ans = x + 'A';
    cout << ans;
    if(node[x][1] != 0) inorder(node[x][1]);
}

void postorder(int x){
    char ans = x + 'A';
    if(node[x][0] != 0) postorder(node[x][0]);
    if(node[x][1] != 0) postorder(node[x][1]);
    cout << ans;
}

int main(){
    int n;
    cin >> n;
    char a, b, c;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        if(b != '.') node[a - 'A'][0] = b - 'A';
        if(c != '.') node[a - 'A'][1] = c - 'A';
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
}