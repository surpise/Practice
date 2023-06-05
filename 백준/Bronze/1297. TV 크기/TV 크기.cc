#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double d, h, w;
    cin >> d >> h >> w;
    int _h = floor(sqrt((d * d * h * h / (h * h + w * w))));
    int _w = floor(sqrt((d * d * w * w / (h * h + w * w))));
    cout << _h << " " << _w;
}