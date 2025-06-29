// E. Đánh số cặp ngoặc
// time limit per test1 second
// memory limit per test256 megabytes
// Cho một xâu ký tự s
//  là một biểu thức ngoặc đúng (tức là các dấu ngoặc đơn đều đầy đủ mở và đóng, đảm bảo đúng thứ tự), s
//  có thể chứa thêm cả các toán tử, toán hạng hoặc dấu cách. Nhiệm vụ của bạn là viết chương trình đánh số các cặp dấu ngoặc theo thứ tự xuất hiện, chỉ số được bắt đầu tính từ 1
// .

// Ví dụ: với biểu thức (a + (b * c) ) + (d / e), ta có kết quả là: 1 2 2 1 3 3.

// Input
// Dòng đầu tiên chứa số bộ test t
//  (1≤t≤104)
// . Mỗi bộ test có dạng:

// 1
//  dòng duy nhất chứa xâu ký tự s
//  là một biểu thức ngoặc đúng (2≤|s|≤2.105)
// .

// Input đảm bảo tổng |s|
//  của tất cả các test không vượt quá 2.105

// Output
// Đưa ra kết quả mỗi test trên một dòng.

// Example
// InputCopy
// 2
// (a + (b * c) ) + (d/e)
// ( ( () ) ( () ) )
// OutputCopy
// 1 2 2 1 3 3 
// 1 2 3 3 2 4 5 5 4 1 


#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	cin.ignore();
	while (t--){
		string s;
		getline(cin, s);
		stack<int> st;
		int cnt = 0;
		vector<int> solve(s.length(), -1);
		for (int i = 0; i < s.length(); i++){
			if (s[i] == '('){
				cnt++;
				st.push(cnt); // push 1 push 2 push 3
				solve[i] = cnt;
				
			}
			else if (s[i] == ')'){
				int tmp = st.top(); // tmp = 3
				st.pop();
				solve[i] = tmp; // solve 
			}
		}
		
		for (auto &x : solve){
			if (x != -1) cout << x << " ";
		}
		cout << "\n";
	}
}