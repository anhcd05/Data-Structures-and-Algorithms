#include<bits/stdc++.h>
using namespace std;

int n, k, x[10000];

void PrintRes(){
    for (int i = 1; i <= k; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void Init(){
    for (int i = 1; i <= k; i++){
        x[i] = i;
    }
}

void Sinh(){
    PrintRes();
    int i = k;
    while (i > 0){
        if (x[i] < n - k + i) break;
        i--;
    }
    if (i == 0) return;
    x[i]++;
    for (int j = i + 1; j <= k; j++){
        x[j] = x[j-1] + 1;
    }
    Sinh();
}

int main(){
    cin >> k >> n;
    Init();
    Sinh();
}