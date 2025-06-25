#include <bits/stdc++.h>
using namespace std;

int n, x[10000];

void PrintRes(){
    for (int i = 1; i <= n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void Sinh(){
    PrintRes();
    int i = n;
    while (i > 0){
        if (x[i] == 0) break;
        i--;
    }
    if (i == 0) return;
    for (int j = i; j <= n; j++){
        x[j] = 1 - x[j];
    }
    Sinh();
}

int main(){
    cin >> n;
    Sinh();
}