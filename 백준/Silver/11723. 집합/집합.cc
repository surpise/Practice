#include <stdio.h>
#include <string.h>

using namespace std;

bool S[21];

void add(int x){
    S[x] = true;
}

void remove(int x){
    S[x] = false;
}

void check(int x){
    if(S[x]) printf("1\n");
    else printf("0\n");
}

void toggle(int x){
    if(S[x]) S[x] = false;
    else S[x] = true;
}

void all(){
    for(int i = 1; i <= 20; i++) S[i] = true;
}
void empty(){
    for(int i = 1; i <= 20; i++) S[i] = false;
}

int main(){  
    int M, n;
    char order[10];
    scanf(" %d", &M);

    for(int i = 0; i < M; i++){
        scanf(" %s", order);
        if(!strcmp(order, "add")){
            scanf(" %d", &n);
            add(n);
        }
        else if(!strcmp(order, "remove")){
            scanf(" %d", &n);
            remove(n);
        }
        else if(!strcmp(order, "check")){
            scanf(" %d", &n);
            check(n);
        }
        else if(!strcmp(order, "toggle")){
            scanf(" %d", &n);
            toggle(n);
        }
        else if(!strcmp(order, "all")) all();
        else if(!strcmp(order, "empty")) empty();
    }
}