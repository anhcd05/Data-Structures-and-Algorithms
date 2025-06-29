// BIẾN ĐỔI HẬU TỐ - TIỀN TỐ

// Best solutions
// Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng hậu tố về dạng tiền tố.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ràng buộc:

// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤106.
// Ví  dụ:

// Input

// Output

// 2

// AB+CD-*

// ABC/-AK/L-*

// *+AB-CD

// *-A/BC-/AKL

#include <bits/stdc++.h>
using namespace std;

void solve(string &s, stack<string> &st) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            string tmp1 = st.top(); st.pop();
            string tmp2 = st.top(); st.pop();

            string superTmp;
            if (s[i] == '+') superTmp = "+" + tmp2 + tmp1;
            if (s[i] == '-') superTmp = "-" + tmp2 + tmp1;
            if (s[i] == '*') superTmp = "*" + tmp2 + tmp1;
            if (s[i] == '/') superTmp = "/" + tmp2 + tmp1;

            st.push(superTmp);
        } 
		
		
		else {
            st.push(string(1, s[i]));
        }
    }

    if (!st.empty()) cout << st.top() << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    
    while (t--) {
        string s;
        getline(cin, s);
        stack<string> st;
        solve(s, st);
    }

    return 0;
}

