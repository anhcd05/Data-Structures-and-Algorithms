// K. Xâu LV
// time limit per test1 second
// memory limit per test256 megabytes
// Bạn được cho một dãy xâu với 2
//  trạng thái đầu và công thức như sau:

// f1=
//  L, f2=
//  V. Với mọi i≥3
//  thì:

// Nếu i
//  là số lẻ, fi=fi−1
//  + L + fi−2.

// Nếu i
//  là số chẵn, fi=fi−1
//  + V + fi−2.
// Nhiệm vụ của bạn là hãy tìm chữ cái ở vị trí thứ k
//  của xâu fn
//  (quy ước vị trí trong xâu được bắt đầu từ 1
// ).

// Input
// Dòng đầu tiên chứa số lượng bộ test t
//  (1≤t≤103)
// . Mỗi bộ test có dạng:

// Một dòng duy nhất chứa 2
//  số nguyên dương n
//  và k
//  (1≤n≤88,1≤k≤|fn|)
// .

// Output
// Đưa ra đáp án mỗi test trên 1
//  dòng.

// Example
// InputCopy
// 3
// 3 2
// 4 5
// 5 8
// OutputCopy
// L
// V
// L
// Note
// 4
//  xâu đầu tiên sẽ là: L, V, VLL, VLLVV.

// Như vậy, ký tự thứ 2
//  trong xâu VLL là L và ký tự thứ 5
//  trong xâu VLLVV là V.

#include<bits/stdc++.h>
using namespace std;

unsigned long long fibo[93];

void init(){
	fibo[1] = 1;
	fibo[2] = 1;
	for (unsigned long long i = 3; i <= 92; i++){
		fibo[i] = fibo[i - 1] + fibo[i - 2] + 1;
	}
}

char solve(unsigned long long n, unsigned long long k){
	if (n == 1) return 'L';
	if (n == 2) return 'V';
	if (k <= fibo[n - 1]) return solve(n - 1, k);
	else if (k == fibo[n - 1] + 1){
		if (n % 2 == 0) return 'V';
		else return 'L';
	}
	else return solve(n - 2, k - fibo[n - 1] - 1);
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	unsigned long long t;
	cin >> t;
	init();
	while (t--){
		unsigned long long n, k;
		cin >> n >> k;
		cout << solve(n, k) << "\n";
	}
}