// CÁI TÚI

// Best solutions
// Một người có cái túi thể tích V (V<1000). Anh ta có N đồ vật cần mang theo (N≤1000), mỗi đồ vật có thể tích là A[i] (A[i]≤100) và giá trị là C[i] (C[i]≤100). Hãy xác định tổng giá trị lớn nhất của các đồ vật mà người đó có thể mang theo, sao cho tổng thể tích không vượt quá V.

// Input

// Dòng đầu ghi số bộ test T (T<10)
// Mỗi bộ test gồm ba dòng. Dòng đầu ghi 2 số N và V. Dòng tiếp theo ghi N số của mảng A. Sau đó là một dòng ghi N số của mảng C.
// Dữ liệu vào luôn đảm bảo không có đồ vật nào có thể tích lớn hơn V.
// Output

// Với mỗi bộ test, ghi trên một dòng giá trị lớn nhất có thể đạt được.
// Ví dụ

// Input

// Output

// 1

// 15 10

// 5 2 1 3 5 2 5 8 9 6 3 1 4 7 8

// 1 2 3 5 1 2 5 8 7 4 1 2 3 2 1

// 15

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, V;
		cin >> n >> V;
		vector<int> w(n + 1), v(n + 1);
		for (int i = 1; i <= n; i++){
			cin >> w[i];
		}
		for (int i = 1; i <= n; i++){
			cin >> v[i];
		}
		
		int f[n + 1][V + 1];
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= V; j++){
				if (j >= w[i]){
					f[i][j] = max(f[i-1][j], v[i] + f[i - 1][j - w[i]]);
				}
				else {
					f[i][j] = f[i - 1][j];
				}
			}
		}
		cout << f[n][V] << "\n";
	}
}
