// DÃY CON TĂNG DÀI NHẤT

// Best solutions
// Cho một dãy số nguyên gồm N phần tử A[1], A[2], ... A[N]. 

// Biết rằng dãy con tăng là 1 dãy A[i1],... A[ik]

// thỏa mãn i1 < i2 < ... < ik và A[i1] < A[i2] < .. < A[ik].

// Hãy cho biết dãy con tăng dài nhất của dãy này có bao nhiêu phần tử? 

// Input: Dòng 1 gồm 1 số nguyên là số N (1 ≤ N ≤ 1000). Dòng thứ 2 ghi N số nguyên A[1], A[2], .. A[N] (1 ≤ A[i] ≤ 1000). 

// Output: Ghi ra độ dài của dãy con tăng dài nhất.

// Ví dụ:

// Input

// Output

// 6

// 1 2 5 4 6 2

// 4

#include<bits/stdc++.h>
using namespace std;

int f[1001];

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	int res = -1;
	for (int i = 0; i < n; i++){
		f[i] = 1;
	}
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			if (a[i] > a[j]){
				f[i] = max(f[i], f[j] + 1);
				res = max(res, f[i]);
			}
		}
	}
	
//	for (int i = 0; i < n; i++) cout << f[i] << " ";
	
	cout << res << "\n";
}
