// D. Liệt kê tập con
// time limit per test1 second
// memory limit per test256 megabytes
// Cho dãy số a
//  gồm có n
//  phần tử là các số nguyên dương. Nhiệm vụ của bạn là với số nguyên dương k
//  bất kỳ, hãy tạo ra tất cả các dãy ký tự số khác nhau bằng việc ghép đúng k
//  số trong mảng a
//  lại với nhau và thoả mãn điều kiện: các số được ghép theo thứ tự xuất hiện trong mảng (số xuất hiện trước không được ghép vào phía sau số xuất hiện sau).

// Input
// Dòng 1
// : chứa 2
//  số nguyên dương n
//  và k
//  (2≤k<n≤16)
// .

// Dòng 2
// : chứa n
//  phần tử của dãy số a
//  (1≤ai≤109)
// .

// Output
// Liệt kê tất cả các dãy ký tự số khác nhau có thể tạo ra theo thứ tự từ điển tăng dần, mỗi dãy ký tự số trên một dòng.

// Example
// InputCopy
// 4 2
// 123 231 211 122
// OutputCopy
// 123122
// 123211
// 123231
// 211122
// 231122
// 231211


#include<bits/stdc++.h>
using namespace std;
 
long long n, k;
long long a[10001];
vector<string> value;
set<string> s;
 
void Print(){
	string tmp = "";
	for (long long i = 1; i <= k; i++){
		tmp += value[a[i] - 1];
	}
	s.insert(tmp);
}
 
void Try(long long i){
	for (long long j = a[i - 1] + 1; j <= n - k + i; j++){
		a[i] = j;
		if (i == k){
			Print();
		}
		else {
			Try(i + 1);
		}
	}
}
 
int main(){
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> k;
	for (long long i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		value.push_back(tmp);
	}
	a[0] = 0;
	Try(1);
	for (auto &x : s) cout << x << '\n';
}