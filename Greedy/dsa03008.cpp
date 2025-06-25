#include<bits/stdc++.h>
using namespace std;

struct Job{
	int id, start, end;
};

bool compare(Job A, Job B){
	return A.end < B.end;
}

vector<int> Greedy( vector<Job> &jobs, int n ){
	vector<int> solve;
	solve.push_back(jobs[0].id);
	int tmp = jobs[0].end;
	for (int i = 1; i < n; i++){
		if (jobs[i].start >= tmp){
			solve.push_back(jobs[i].id);
			tmp = jobs[i].end;
		}
	}
	return solve;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<Job> jobs(n);
		for (int i = 0; i < n; i++){
			jobs[i].id = i;
			cin >> jobs[i].start;
		}
		
		for (int i = 0; i < n ; i++){
			cin >> jobs[i].end;
		}
		
		sort(jobs.begin(), jobs.end(), compare);
		Greedy(jobs, n);
//		for (auto &x : jobs){
//			cout << x.id << " " << x.start << " " << x.end << endl;
//		}
		vector<int> solve = Greedy(jobs, n);
		cout << solve.size() << endl;
		for (auto &x : solve) {
			cout << x << " ";
		}
		jobs.clear();
	}
}
