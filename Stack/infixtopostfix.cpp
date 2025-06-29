// BIẾN ĐỔI TRUNG TỐ - HẬU TỐ

// Best solutions
// Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng trung tố về dạng hậu tố.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T;
// Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ràng buộc:

// T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤10.
// Các phép toán bao gồm +, -, *, /, ^. Phép lũy thừa có ưu tiên cao hơn nhân chia và cộng trừ.
// Ví dụ:

// Input

// Output

// 2

// (A+(B+C)

// ((A*B)+C)

// ABC++

// AB*C+

#include<bits/stdc++.h>
using namespace std;

vector<char> output;
stack<char> st;

int getPriority(char x){
	if (x == '+' || x == '-') return 1;
	if (x == '*' || x == '/') return 2;
	if (x == '^') return 3;
	return 0;
}

void solve(string s){
	for (int i = 0; i < s.length(); i++){
		
		if (s[i] == '('){
			st.push(s[i]);
		}
		
		else if (s[i] == ')'){
			while (true){
				char y = st.top();
				st.pop();
				if (y == '(') break;
				output.push_back(y);
			}
		}
		
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
			char c = s[i];
			while (!st.empty() && st.top()!='(') {
			    char y = st.top();
			    int pY = getPriority(y), pC = getPriority(c);
			    if (pY > pC || (pY == pC && c != '^')) {
			        output.push_back(y);
			        st.pop();
			        continue;
			    }
			    break;
			}
			st.push(c);
		}
		
		else {
			output.push_back(s[i]);
		}
		
	}
	
	while (!st.empty()){
		output.push_back(st.top());
		st.pop();
	}
	
}


int main(){
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		
		solve(s);
		for (auto &x : output){
			cout << x;
		}            
		cout << endl;
		output.clear();
		st = stack<char> ();
	}
	
}
