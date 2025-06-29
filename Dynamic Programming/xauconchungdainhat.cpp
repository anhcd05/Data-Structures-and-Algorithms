// XÂU CON CHUNG DÀI NHẤT

// Best solutions
// Cho 2 xâu S1 và S2. Hãy tìm xâu con chung dài nhất của 2 xâu này (các phần tử không nhất thiết phải liên tiếp nhau).

// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm hai dòng, mô tả xâu S1 và S2, mỗi xâu có độ dài không quá 1000 và chỉ gồm các chữ cái in hoa.

// Output:  Với mỗi test, in ra độ dài dãy con chung dài nhất trên một dòng.

// Ví dụ:

// Input

// Output

// 2

// AGGTAB

// GXTXAYB

// AA

// BB

// 4

// 0

// Giải thích test 1: Dãy con chung là G, T, A, B.

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	cin.ignore();
	while (t--){
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		
		int n = s1.length(), m = s2.length();
		s1 = "0" + s1;
		s2 = "0" + s2;
		
		int f[n + 1][m + 1];
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (s1[i] == s2[j]){
					f[i][j] = f[i-1][j-1] + 1;
				}
				else {
					f[i][j] = max(f[i-1][j], f[i][j-1]);
				}
			}
		}
		
		cout << f[n][m] << "\n";
	}
}
