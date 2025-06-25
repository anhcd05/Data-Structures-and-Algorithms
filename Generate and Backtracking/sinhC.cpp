// C. Chênh lệch hoán vị
// time limit per test1 second
// memory limit per test256 megabytes
// Cho một số nguyên dương n
// , ta xét tất cả các hoán vị của các số từ 1
//  đến n
// , với mỗi cấu hình thì độ chênh lệch được định nghĩa là tổng khoảng cách của các số cạnh nhau, trong đó khoảng cách được tính bằng hiệu của số đứng trước trừ đi số đứng ngay sau nó.

// Ví dụ: với n=4
//  và hoán vị p=[2,4,3,1]
//  thì độ chênh lệch là (2−4)+(4−3)+(3−1)=1
// .

// Nhiệm vụ của bạn là hãy in ra tất cả các cấu hình thoả mãn có độ chênh lệch lớn hơn 0
// .

// Input
// Một số nguyên dương n
//  duy nhất (2≤n≤9)
// .

// Output
// Đưa ra các hoán vị thoả mãn theo thứ tự từ điển tăng dần, mỗi hoán vị trên một dòng.

// Example
// InputCopy
// 4
// OutputCopy
// 2 3 4 1 
// 2 4 3 1 
// 3 1 4 2 
// 3 2 4 1 
// 3 4 1 2 
// 3 4 2 1 
// 4 1 2 3 
// 4 1 3 2 
// 4 2 1 3 
// 4 2 3 1 
// 4 3 1 2 
// 4 3 2 1 




#include<bits/stdc++.h>
using namespace std;
 
int n, a[101];
bool visited[101];
 
void Print(){
	int diff = 0;
	for (int i = 1; i <= n - 1; i++){
		diff += a[i] - a[i + 1];
	}
	if (diff > 0){
//		cout << "DEBUG WAS HERE " << diff << endl;
		for (int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << '\n';
	}
}
 
void Try(int i){
	for (int j = 1; j <= n; j++){
		if (!visited[j]){
			a[i] = j;
			visited[j] = true;
			if (i == n){
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
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n;
	Try(1);
}