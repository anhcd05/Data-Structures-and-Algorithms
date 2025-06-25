// B. Xếp cuối hàng
// time limit per test1 second
// memory limit per test256 megabytes
// Có n
//  người xếp hàng với n
//  cái tên khác nhau từng đôi một, người ta muốn xếp một người duy nhất luôn đứng cuối hàng. Nhiệm vụ của bạn là hãy liệt kê tất cả các cách xếp hàng thoả mãn theo thứ tự từ điển tăng dần.

// Input
// Dòng 1
// : chứa số nguyên dương n
//  là số người xếp hàng (2≤n≤9)
// .

// Dòng 2
// : chứa n
//  xâu ký tự si
//  là tên của người đứng thứ i
//  trong hàng (1≤|si|≤20)
// .

// Dòng 3
// : chứa xâu ký tự t
//  là tên của người luôn đứng cuối hàng. Input đảm bảo xâu t
//  luôn xuất hiện ở dòng 2
// .

// Output
// Liệt kê tất cả các cách xếp hàng thoả mãn theo thứ tự từ điển tăng dần.

// Example
// InputCopy
// 4
// dong tay nam bac
// nam
// OutputCopy
// bac dong tay nam 
// bac tay dong nam 
// dong bac tay nam 
// dong tay bac nam 
// tay bac dong nam 
// tay dong bac nam 

#include<bits/stdc++.h>
using namespace std;
 
int n;
int a[101];
string wanted;
vector<string> v;
bool visited[101];
int pos = -1;
vector<string> res;
 
 
void Print(){
	string tmp = "";
	for (int i = 1; i <= n; i++){
		tmp += v[a[i] - 1] + " ";
	}
	tmp.pop_back();
	res.push_back(tmp);
}
 
void Try(int i){
	for (int j = 1; j <= n; j++){
		if (!visited[j]){
			a[i] = j;
			visited[j] = true;
			if (i == n && a[n] == pos){
				Print();
			}
			else {
				Try(i + 1);
			}
			visited[j] = false;
		}
	}
}
 
int main(){
//	cin.tie(0) -> sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	cin >> wanted;
	for (int i = 0; i < v.size(); i++){
		if (wanted == v[i]){
			pos = i + 1;
		}
	}
	Try(1);
	sort(res.begin(), res.end());
	for (auto &x : res){
		cout << x << endl;
	}
}