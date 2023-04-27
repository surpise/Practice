#include <iostream>

using namespace std;

struct node{
    int n;
    struct node* left = 0;
    struct node* right = 0;
};
node *root = 0;

void add(int v){
    node* newNode = new node();
    newNode->n = v;
    if(root == 0) root = newNode;
    else{
        node *tmp = root;
        while(tmp != 0){
            if(v < tmp->n) {
                if(tmp->left == 0) {
                    tmp->left = newNode;
                    return;
                }
                tmp = tmp->left;
            }
            else if(v > tmp->n) {
                if(tmp->right == 0) {
                    tmp->right = newNode;
                    return;
                }
                tmp = tmp -> right;
            }
        }
    }
}

void postorder(node* N){
    if(N != 0){
        postorder(N->left);
        postorder(N->right);
        cout << N->n << '\n';
    }
}

int main(){
    int x;
    while(1){
        cin >> x;
        if(cin.eof()) break;
        add(x);
    }
    postorder(root);
}