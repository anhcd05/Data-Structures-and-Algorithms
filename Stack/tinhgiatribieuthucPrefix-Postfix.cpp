// C. Tiền tố và Hậu tố
// time limit per test1 second
// memory limit per test256 megabytes
// Biểu thức dưới dạng tiền tố là phép biểu diễn biểu thức trong đó phép toán được đặt trước hai toán hạng.

// Ví dụ: + * A B / C D tương ứng với biểu thức trung tố (A * B) + (C / D).

// Biểu thức dưới dạng hậu tố là phép biểu diễn biểu thức trong đó phép toán được đặt sau hai toán hạng.

// Ví dụ: A B + C D - * tương ứng với biểu thức trung tố (A + B) * (C - D).

// Bạn được cho một xâu ký tự s
//  có thể biểu diễn cho 1
//  biểu thức tiền tố hoặc hậu tố. Nhiệm vụ của bạn là hãy tính toán giá trị biểu thức đó.

// Input
// Dòng đầu tiên chứa số lượng bộ test t
//  (1≤t≤103).
//  Mỗi bộ test có dạng:

// Dòng 1
// : chứa số nguyên dương n
//  là số lượng toán tử và toán hạng. (1≤n≤103).

// Dòng 2
// : chứa xâu ký tự s
//  mô tả biểu thức toán học. Các toán tử và toán hạng cách nhau 1
//  dấu cách.

// Input đảm bảo tổng n
//  của tất cả các test không vượt quá 104
// .

// Chú ý:

// Các toán hạng có thể có nhiều chữ số, có thể là số âm.
// Phép chia thực hiện trên số nguyên.
// Kết quả biểu thức có giá trị tuyệt đối không vượt quá 1018
// .
// Output
// Đưa ra kết quả mỗi biểu thức trên 1
//  dòng.

// Example
// InputCopy
// 3
// 7
// - + 2 * 3 1 9
// 7
// 8 7 5 * + 9 -
// 3
// + -10 -4
// OutputCopy
// -4
// 34
// -14

#include<bits/stdc++.h>
using namespace std;

vector<string> value;

long long solvePrefix(){
	stack<string> st;
	for (long long i = value.size() - 1; i >= 0; i--){
		if (value[i] == "+" || value[i] == "-" || value[i] == "*" || value[i] == "/"){
			long long tmp1 = stoll(st.top());
			st.pop();
			long long tmp2 = stoll(st.top());
			st.pop();
			long long tmpRes;
			if (value[i] == "+"){
				tmpRes = tmp1 + tmp2;
			}
			if (value[i] == "-"){
				tmpRes = tmp1 - tmp2;
			}
			if (value[i] == "*"){
				tmpRes = tmp1 * tmp2;
			}
			if (value[i] == "/"){
				tmpRes = tmp1 / tmp2;
			}	
			st.push(to_string(tmpRes));								
		}
		else {
			st.push(value[i]);
		}
	}
	return stoll(st.top());
}

long long solvePostfix(){
	stack<string> st;
	for (long long i = 0; i < value.size(); i++){
		if (value[i] == "+" || value[i] == "-" || value[i] == "*" || value[i] == "/"){
			long long tmp1 = stoll(st.top());
			st.pop();
			long long tmp2 = stoll(st.top());
			st.pop();
			long long tmpRes;
			if (value[i] == "+"){
				tmpRes = tmp1 + tmp2;
			}
			if (value[i] == "-"){
				tmpRes = tmp2 - tmp1;
			}
			if (value[i] == "*"){
				tmpRes = tmp1 * tmp2;
			}
			if (value[i] == "/"){
				tmpRes = tmp2 / tmp1;
			}	
			st.push(to_string(tmpRes));								
		}
		else {
			st.push(value[i]);
		}
	}
	return stoll(st.top());
}
int main(){
	cin.tie(0) -> sync_with_stdio(0);
	long long t;
	cin >> t;
	while (t--){
		long long n;
		cin >> n;
		while (n--){
			string s;
			cin >> s;
			value.push_back(s);
		}
		if (value[0] == "+" || value[0] == "-" || value[0] == "*" || value[0] == "/"){
			cout << solvePrefix() << "\n";
		}
		else cout << solvePostfix() << "\n";
		
		value.clear();
	}
}