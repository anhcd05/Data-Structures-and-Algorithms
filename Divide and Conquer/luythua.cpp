// L2. Luỹ thừa (Ver. 2)
// time limit per test1 second
// memory limit per test256 megabytes
// Cho 3
//  số nguyên dương a,b,c
//  và nhiệm vụ của bạn là tính toán và đưa ra kết quả của phép tính ab
//  sau khi chia dư cho c
// .

// Input
// Dòng đầu chứa số lượng bộ test t
//  (1≤t≤103)
// .

// Mỗi bộ test gồm 2
//  số nguyên a,b
//  trên một dòng (1≤a,b,c≤1018)
// .

// Output
// Đưa ra đáp số mỗi test trên 1
//  dòng.

// Example
// InputCopy
// 3
// 3 6 5
// 7 15 33
// 16 25 48
// OutputCopy
// 4
// 10
// 16

#include<bits/stdc++.h>
using namespace std;

long long mulRus(long long a, long long b, long long c){
	long long res = 0;
	a %= c;
	while (b > 0){
		if (b & 1)
			res = (res + a) % c;
		a = (a + a) % c;
		b = b / 2;
	}
	return res;
}

long long solve (long long a, long long b, long long c){
	long long res = 1;
	a %= c;
	while (b > 0){
		if (b & 1)
			res = mulRus(res, a, c);
		a = mulRus(a, a, c);
		b = b / 2;
	}
	return res;
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--){
		long long a, b, c;
		cin >> a >> b >> c;
		cout << solve(a, b, c) << "\n";
	}
}