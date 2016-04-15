#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool srtCompare(Segment i, Segment j) { return (i.end < j.end); }

vector<int> optimal_points(vector<Segment> &segments) {
  sort(segments.begin(), segments.end(), srtCompare);

  vector<int> points;

  for (size_t i = 0; i < segments.size(); ++i) {
    int pointCandidate = segments[i].end;
    int previousPointIdx = points.size()-1;

    if (previousPointIdx < 0 || points[previousPointIdx] < segments[i].start || points[previousPointIdx] > segments[i].end) {
      points.push_back(pointCandidate);
    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
