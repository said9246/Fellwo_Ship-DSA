#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Build graph
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }
        
        // Answer queries
        vector<double> results;
        for (auto& q : queries) {
            string src = q[0], dst = q[1];
            if (!graph.count(src) || !graph.count(dst)) {
                results.push_back(-1.0);
                continue;
            }
            if (src == dst) {
                results.push_back(1.0);
                continue;
            }
            results.push_back(bfs(src, dst, graph));
        }
        return results;
    }

private:
    double bfs(string& src, string& dst, unordered_map<string, vector<pair<string, double>>>& graph) {
        queue<pair<string, double>> q;
        unordered_map<string, bool> visited;
        q.push({src, 1.0});
        visited[src] = true;
        
        while (!q.empty()) {
            auto [node, val] = q.front();
            q.pop();
            if (node == dst) return val;
            for (auto& [nei, w] : graph[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push({nei, val * w});
                }
            }
        }
        return -1.0;
    }
};
