// BIẾN ĐỔI HẬU TỐ - TRUNG TỐ

// Best solutions
// Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng hậu tố về dạng trung tố.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp.
// T, exp thỏa màng ràng buộc: 1≤T≤100; 2≤length(exp)≤106.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ràng buộc:

// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤106.
// Ví dụ:

// Input

// Output

// 2

// ABC++

// AB*C+

// (A+(B+C)

// ((A*B)+C)

#include<bits/stdc++.h>
using namespace std;

void solve(string &s, stack<string> &st){
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
			string tmp1 = st.top();
			st.pop();
			string tmp2 = st.top();
			st.pop();
			string superTmp = "(" + tmp2 + string(1, s[i]) + tmp1 + ")";
//			cout << superTmp << "DEBUG WAS HJERE" << endl;
			st.push(superTmp);
		}
		
		
		else {
			st.push(string(1, s[i]));
		}
		
	}
}



int main(){
	int t;
	cin >> t;
	cin.ignore();
	while (t--){
		string s;
		getline(cin, s);
		stack<string> st;
		solve(s, st);
		cout << st.top() << endl;
	}	
	
}
