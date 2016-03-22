#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::sort;

bool ps_srt_compare(pair<int, char> i, pair<int, char> j) { return (i < j); }

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());

  vector<pair<int, char>> ps_pairs;
  vector<pair<int, int>> tmp;

  for (auto i = starts.begin(); i != starts.end(); ++i) {
    ps_pairs.emplace_back(*i, 'l');
  }

  for (auto i = ends.begin(); i != ends.end(); ++i) {
    ps_pairs.emplace_back(*i, 'r');
  }

  for (auto i = points.begin(); i != points.end(); ++i) {
    ps_pairs.emplace_back(*i, 'p');
  }

  sort(ps_pairs.begin(), ps_pairs.end(), ps_srt_compare);
  int segments = 0;

  for (auto &i : ps_pairs) {
    //cout << "[" << i.first << ", " << i.second << "]\n";

    if (i.second == 'l') {
      segments++;
    } else if (i.second == 'p') {
      for (int j = 0; j < points.size(); j++) {
        if (points[j] == i.first) {
          cnt[j] = segments;
        }
      }
    } else if (i.second == 'r') {
      segments--;
    }
  }

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

void ps_stress() {
  while (true) {
    int n = 5000;
    int m = 5000;

    vector<int> starts(n), ends(n);
    for (size_t i = 0; i < n; i++) {
      int start = rand() % 10;
      int end = (rand() % 10) + start;
      starts[i] = start;
      ends[i] = end;
    }
    vector<int> points(m);
    for (size_t i = 0; i < points.size(); i++) {
      int point = rand() % 10;
      points[i] = point;
    }

    vector<int> cntNaive = naive_count_segments(starts, ends, points);
    vector<int> cntFast = fast_count_segments(starts, ends, points);

    bool success = true;
    for (size_t i = 0; i < cntFast.size(); i++) {
      if (cntFast[i] != cntNaive[i]) {
        success = false;

        cout << "Wrong answer!!!\n";
        cout << "Fast count result: ";
        for (int i = 0; i < cntFast.size(); ++i) {
          cout << cntFast[i] << " ";
        }
        cout << "\n";

        cout << "Naive count result: ";
        for (int i = 0; i < cntNaive.size(); ++i) {
          cout << cntNaive[i] << " ";
        }
        cout << "\n";

        cout << "Original starts input: ";
        for (int i = 0; i < starts.size(); ++i) {
          cout << starts[i] << " ";
        }
        cout << "\n";

        cout << "Original ends input: ";
        for (int i = 0; i < ends.size(); ++i) {
          cout << ends[i] << " ";
        }
        cout << "\n";

        cout << "Original points input: ";
        for (int i = 0; i < points.size(); ++i) {
          cout << points[i] << " ";
        }
        cout << "\n\n";

        break;
      }
    }

    if (success) {
      cout << "OK!\n";
    }
  }
}

int main() {
  ps_stress();

  int n, m;
  cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    cin >> points[i];
  }

  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    cout << cnt[i] << ' ';
  }
}
