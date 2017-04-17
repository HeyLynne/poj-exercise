#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

bool hasPath(string &w1, string &w2) {
    if (w1.size() != w2.size()) {
        return false;
    }
    bool hasP = false;
    for (int i = 0;i < w1.size();i++) {
        if (w1[i] != w2[i]) {
            if (hasP) {
                return false;
            }
            hasP = true;
        }
    }
    return hasP;
}

int findMinVer(vector<vector<int> > &map, int last, unordered_set<int> &sfind) {
    int minNode = -1;
    int minDist = INT_MAX;
    for (int i = 0;i < map.size();i++) {
        if (sfind.find(i) != sfind.end()) {
            continue;
        }
        if (map[last][i] == -1) {
            continue;
        }
        if (map[last][i] == -1) {
            continue;
        }
        if (map[0][i] == -1) {
            map[0][i] = map[0][last] + map[last][i];
        }
        else {
            map[0][i] = (map[0][last] + map[last][i] < map[0][i]) ? map[0][last] + map[last][i] : map[0][i];
        }
        if (map[0][i] < minDist) {
            minDist = map[0][i];
            minNode = i;
        }
    }
    return minNode;
}

int main() {
    string a[8] = {"hit", "cog", "hot","dot","dog","lot","log"};
    vector<string> words(a, a + 8);
    vector<vector<int> > map(words.size(), vector<int>(words.size(), -1));
        for (int i = 0;i < words.size();i++) {
            for(int j = i + 1;j < words.size();j++) {
                if (i == j) {
                    map[i][j] = 0;
                }
                else if (hasPath(words[i], words[j])) {
                    map[i][j] = 1;
                    map[j][i] = 1;
                }
            }
        }
        unordered_set<int> sfind;
        unordered_set<int> snot;
        sfind.insert(0);
        for (int i = 1;i < words.size();i++) {
            snot.insert(i);
        }
        int lastin = 0;
        while(!snot.empty()) {
            if (lastin == 0) {
                for (int i = 1;i < words.size();i++) {
                    if (map[0][i] == 1) {
                        sfind.insert(i);
                        snot.erase(i);
                        lastin = i;
                        break;
                    }
                }
            }
            else {
                int minNode = findMinVer(map, lastin, sfind);
                if (minNode == -1) {
                    return 0;
                }
                else {
                    sfind.insert(minNode);
                    snot.erase(minNode);
                    lastin = minNode;
                }
                if (minNode == 1) {
                    break;
                }
            }
        }
        cout << map[0][1] << endl;
}
