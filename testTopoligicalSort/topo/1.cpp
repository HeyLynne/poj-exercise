#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
unordered_set<int> zeroDegree;

int findZeroIndegree(vector<int> &degrees) {
    for (int i = 0;i < degrees.size();i++) {
        if (degrees[i] == 0 && zeroDegree.find(i) == zeroDegree.end()) {
            return i;
        }
    }
    return -1;
}

void make_graph(vector<pair<int, int>>& prerequisites, vector<unordered_set<int> > &graph, vector<int> &degrees) {
    for (int i = 0;i < prerequisites.size();i++) {
        int start = prerequisites[i].second;
        int end = prerequisites[i].first;
        graph[start].insert(end);
        degrees[end]++;
    }
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    if (prerequisites.size() == 0) {
        return true;
    }
    vector<unordered_set<int> > graph(numCourses);
    vector<int> degrees(numCourses, 0);
    make_graph(prerequisites, graph, degrees);
    int start = findZeroIndegree(degrees);
    while (zeroDegree.size() != numCourses) {
        if (start == -1) {
            return false;
        }
        zeroDegree.insert(start);
        for (auto vertex : graph[start]) {
            degrees[vertex]--;
        }
        start = findZeroIndegree(degrees);
    }
    return true;
}

int main() {
    int numcourses;
    cin >> numcourses;
    int nums;
    cin >> nums;
    vector<pair<int, int>> prerequisites;
    for (int i = 0;i < nums;i++) {
        int m,n;
        cin >> m >>n;
        prerequisites.push_back(make_pair(m,n));
    }
    bool ifcan = canFinish(numcourses, prerequisites);
    cout << ifcan << endl;
}
