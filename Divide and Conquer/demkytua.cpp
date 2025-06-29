// J. Đếm ký tự a
// time limit per test1 second
// memory limit per test256 megabytes
// Xét dãy xâu ký tự f1,f2,...,fn
//  được xây dựng theo công thức sau:

// f0=a
// f1=b
// fn=fn−1+fn−2
//  với n≥2
// Cho 2
//  số nguyên n
//  và k
// , nhiệm vụ của bạn là hãy xác định số lượng ký tự a
//  trong k
//  ký tự đầu tiên của xâu fn
// .

// Input
// Dòng đầu tiên chứa số bộ test t
//  (1≤t≤104)
// . Mỗi bộ test có dạng:

// Một dòng duy nhất chứa 2
//  số nguyên n
//  và k
//  (0≤n≤45,1≤k≤|fn|)
// .

// Output
// Đưa ra đáp số mỗi test trên một dòng.

// Example
// InputCopy
// 5
// 0 1
// 1 1
// 3 2
// 7 7
// 8 16
// OutputCopy
// 1
// 0
// 1
// 3
// 6
// Note
// Ta có xâu f2=ba→f3=bab
// . Như vậy 2
//  ký tự đầu của xâu f3
//  chỉ có đúng 1
//  ký tự a
// .


#include<bits/stdc++.h>
using namespace std;

unsigned long long fibo[93], cnt[93];

void init(){
	fibo[0] = 1, fibo[1] = 1;
	cnt[0] = 1, cnt[1] = 0;
	for (int i = 2; i <= 92; i++){
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		cnt[i] = cnt[i - 1] + cnt[i - 2];
	}
}

unsigned long long solve(unsigned long long n, unsigned long long i){
	if (n == 0) return 1;
	if (n == 1) return 0;
	if (i <= fibo[n - 1]) return solve(n - 1, i);
	else return cnt[n - 1] + solve(n - 2, i - fibo[n - 1]);
}


int main(){
	cin.tie(0) -> sync_with_stdio(0);
	init();
	int t;
	cin >> t;
	while (t--){
		unsigned long long n, k;
		cin >> n >> k;
		cout << solve(n, k) << "\n";
	}
}