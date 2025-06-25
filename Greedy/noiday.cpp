#include<bits/stdc++.h>
using namespace std;

int main(){
	long long t;
	cin >> t;
	while (t--){
		long long n;
		cin >> n;
		priority_queue<long long, vector<long long>, greater<long long>> Q;
		for (long long i = 0; i < n; i++){
			long long x; cin >> x;
			Q.push(x);
		}
		long long sum = 0;
		while (Q.size() > 1){
			long long tmp1 = Q.top(); Q.pop();
			long long tmp2 = Q.top(); Q.pop();
			sum += tmp1 + tmp2;
			Q.push(tmp1 + tmp2);	
		}
		cout << sum << endl;
	}
}
