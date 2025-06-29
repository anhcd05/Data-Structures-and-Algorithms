// BẬC THANG

// Best solutions
// Một chiếc cầu thang có N bậc. Mỗi bước, bạn được phép bước lên trên tối đa K bước. Hỏi có tất cả bao nhiêu cách bước để đi hết cầu thang? (Tổng số bước đúng bằng N).

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
// Mỗi test gồm hai số nguyên dương N và K(1 ≤ N ≤ 100000, 1 ≤ K ≤ 100).
// Output: 

// Với mỗi test, in ra đáp án tìm được trên một dòng theo modulo 109+7.
// Ví dụ:

// Input

// Output

// 2

// 2 2

// 4 2

 

// 2

// 5

 

// Giải thích test 1: Có 2 cách đó là (1, 1) và (2).

// Giải thích test 2: 5 cách đó là: (1, 1, 1, 1), (1, 1, 2), (1, 2, 1), (2, 1, 1), (2, 2).

#include <bits/stdc++.h>
using namespace std;
static const long long MOD = 1e9 + 7;

long long solve_one(int N, int K) {
    vector<long long> dp(N + 1, 0);
    dp[0] = 1;
    long long window = 1;
    for (int i = 1; i <= N; i++){
    	
    	dp[i] = window % MOD;
    	window = ((dp[i] + window) + MOD) % MOD;
    	
    	if (i >= K){
    		window = ((window - dp[i - K]) + MOD) % MOD ;
		}
	}
	return dp[N];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        cout << solve_one(N, K) << "\n";
    }
    return 0;
}

