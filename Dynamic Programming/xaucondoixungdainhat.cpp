// XÂU CON ĐỐI XỨNG DÀI NHẤT

// Best solutions
// Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự.

// Hãy tìm xâu con đối xứng dài nhất của S.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
// Mỗi test gồm một xâu S có độ dài không vượt quá 1000, chỉ gồm các kí tự thường.
// Output:  Với mỗi test, in ra đáp án tìm được.

// Ví dụ:

// Input

// Output

// 2

// abcbadd

// aaaaa

 

// 5

// 5

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	cin.ignore();
	while (t--){
		string s;
		getline(cin, s);
		s = "x" + s;
		int n = s.length() - 1;
		vector<vector<bool>> f(n + 1, vector<bool>(n + 1, false));
		int ans = 1;
		for (int i = 1; i <= n; i++) f[i][i] = true;
		for (int len = 2; len <= n; len++){
			for (int i = 1; i <= n - len + 1; i++){
				int j = i + len - 1;
				if (len == 2 && s[i] == s[j]) f[i][j] = true;
				else {
					if (f[i + 1][j - 1] == true && s[i] == s[j])
						f[i][j] = true;
				}
				if (f[i][j])	ans = max(ans, j - i + 1);
			}
		}
//		for (int i = 1; i <= n; i++){
//			for (int j = 1; j <= n; j++){
//				cout << f[i][j] << " ";
//			}
//			cout << "\n";
//		}
		cout << ans << "\n";
	}
}
