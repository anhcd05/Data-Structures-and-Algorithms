// BIẾN ĐỔI TIỀN TỐ - TRUNG TỐ

// Best solutions
// Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng tiền tố về dạng trung tố.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ràng buộc:

// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤106.
// Ví dụ:

// Input

// Output

// 2

// *+AB-CD

// *-A/BC-/AKL

// ((A+B)*(C-D))

// ((A-(B/C))*((A/K)-L)

#include<bits/stdc++.h>
using namespace std;

void solve(string s, stack<string>& st) {
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') { 
            string tmp1 = st.top();
            st.pop();
            string tmp2 = st.top();
            st.pop();
            string super = "(" + tmp1 + s[i] + tmp2 + ")";
            st.push(super);
        } 
		
		else {
            st.push(string(1, s[i])); 
        }
    }
}

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string s;
        getline(cin, s);
        stack<string> st; 
        solve(s, st); 
        while (!st.empty()) {  
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;  
    }
}

