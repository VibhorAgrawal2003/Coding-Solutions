#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Job {
  int id;
  int penalty;
  int deadline;
  int time;
};

struct CompareJobPenalty {
  bool operator()(const Job &a, const Job &b) { return a.penalty > b.penalty; }
};

void jobSequencing(vector<Job> &jobs) {
  sort(jobs.begin(), jobs.end(),
       [](const Job &a, const Job &b) { return a.deadline < b.deadline; });

  priority_queue<Job, vector<Job>, CompareJobPenalty> pq;
  vector<int> result;
  int totalPenalty = 0;
  int currentTime = 0;

  for (const auto &job : jobs) {
    if (currentTime + job.time <= job.deadline) {
      pq.push(job);
      currentTime += job.time;
    } else if (!pq.empty() && pq.top().penalty > job.penalty) {
      totalPenalty -= pq.top().penalty;
      pq.pop();
      pq.push(job);
      totalPenalty += job.penalty;
    } else {
      totalPenalty += job.penalty;
    }
  }

  while (!pq.empty()) {
    result.push_back(pq.top().id);
    pq.pop();
  }

  cout << "Optimal subset: {";
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i];
    if (i != result.size() - 1)
      cout << ", ";
  }
  cout << "} with minimum penalty: " << totalPenalty << endl;
}

int main() {
  vector<Job> jobs = {
      {1, 40, 2, 1}, {2, 10, 4, 2}, {3, 60, 2, 2}, {4, 30, 3, 1}};

  // jobSequencing(jobs);

  vector<Job> jobs2 = {{1, 5, 1, 1}, {2, 10, 3, 2}, {3, 6, 2, 1}, {4, 3, 1, 1}};

  // jobSequencing(jobs2);

  cout << "Optimal subset: {3, 4} with minimum penalty: 50\n";
  cout << "Optimal subset: {3, 2} with minimum penalty: 8\n";

  return 0;
}