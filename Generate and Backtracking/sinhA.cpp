// A. Liệt kê hoán vị
// time limit per test1 second
// memory limit per test256 megabytes
// Bạn được cho 2
//  số nguyên dương n
//  và m
// . Nhiệm vụ của bạn là liệt kê các hoán vị của n
//  số nguyên dương đầu tiên thoả mãn số m
//  luôn đứng đầu.

// Input
// 1
//  dòng duy nhất chứa 2
//  số nguyên dương n
//  và m
//  (1≤m≤n≤10).

// Output
// Liệt kê lần lượt các hoán vị thoả mãn theo thứ tự từ điển, mỗi hoán vị trên 1
//  dòng.

// Example
// InputCopy
// 4 2
// OutputCopy
// 2 1 3 4 
// 2 1 4 3 
// 2 3 1 4 
// 2 3 4 1 
// 2 4 1 3 
// 2 4 3 1 

#include<bits/stdc++.h>
using namespace std;
 
int n, m;
int a[101];
bool visited[101];
 
void Print(){
	for (int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	cout << '\n';
}
 
void Try(int i){
	for (int j = 1; j <= n; j++){
		if (!visited[j]){
			a[i] = j;
			visited[j] = true;
			if (i == n){
				Print();
			}
			else {
				Try(i +1);
			}
			visited[j] = false;
		}
	}
}
 
int main(){
    cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	a[1] = m;
	visited[m] = true;
	Try(2);
}