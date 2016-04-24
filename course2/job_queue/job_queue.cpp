#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::make_pair;
using std::priority_queue;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;
  
  struct orderProcessingPQ {  
    bool operator()(const pair<int, long long> &l, const pair<int, long long> &r)  {  
        if (l.second == r.second)
            return l.first > r.first;
        else
            return l.second > r.second;  
    }  
  }; 
  priority_queue<pair<int, long long>, vector<pair<int, long long > >, orderProcessingPQ > pq;
  

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for (int i = 0; i < m; ++i) {
      cin >> jobs_[i];
    }
    for (int i = 0; i < num_workers_; ++i) {
        pq.push(make_pair(i, 0));
    }
  }

  void AssignJobs() {
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      assigned_workers_[i] = pq.top().first;
      start_times_[i] = pq.top().second;
      pq.pop();
      pq.push(make_pair(assigned_workers_[i], start_times_[i] + duration)); 
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
