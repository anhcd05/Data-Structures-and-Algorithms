// BIỂU THỨC TĂNG GIẢM

// Best solutions
// Cho dãy ký tự S chỉ bao gồm các ký tự I hoặc D. Ký tự I được hiểu là tăng (Increasing) ký tự D được hiểu là giảm (Decreasing). Sử dụng các số từ 1 đến 9, hãy đưa ra số nhỏ nhất được đoán nhận từ S. Chú ý, các số không được phép lặp lại. Dưới đây là một số ví dụ mẫu:

// A[] = “I”              : số tăng nhỏ nhất là 12.
// A[] = “D”            : số giảm nhỏ nhất là 21
// A[] =”DD”           : số giảm nhỏ nhất là 321
// A[] = “DDIDDIID”: số thỏa mãn 321654798
// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu S
// T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ length(S) ≤8; .
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input:

// Output:

// 4

// I

// D

// DD
// DDIDDIID

// 12

// 21

// 321

// 321654798

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		stack<int> st;
		st.push(1);
		int num = 2;
		for (int i = 0; i < s.length(); i++){
			if (s[i] == 'I'){
				while (!st.empty()){
					cout << st.top();
					st.pop();
				}
				st.push(num++);
			}
			else {
				st.push(num++);
			}
		}
		
		while (!st.empty()){
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}
