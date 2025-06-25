#include<bits/stdc++.h>
using namespace std;

int n, x[10000];

void PrintRes(){
    for (int i = 1; i <= n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void Init(){
    for (int i = 1; i <= n; i++){
        x[i] = i;
    }
}

void Sinh(){
    PrintRes();
    int i = n - 1;
    while (i > 0){
        if (x[i] < x[i+1]) break;
        i--;
    }
    if (i == 0) return;
    int k = n;
    while (x[k] < x[i]) k--;
    swap(x[k], x[i]);
    int left = i + 1, right = n;
    while (left < right){
        swap(x[left], x[right]);
        left++;
        right--;
    }
    Sinh();
}

int main(){
    cin >> n;
    Init();
    Sinh();
}