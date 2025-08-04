class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events; // {x, height}
        for (auto& b : buildings) {
            events.emplace_back(b[0], -b[2]); // building enters
            events.emplace_back(b[1], b[2]);  // building exits
        }

        sort(events.begin(), events.end()); // sort by x, then height

        multiset<int> heights = {0}; // current active heights
        int prevHeight = 0;
        vector<vector<int>> result;

        for (auto& [x, h] : events) {
            if (h < 0) {
                // entering building, add height
                heights.insert(-h);
            } else {
                // exiting building, remove height
                heights.erase(heights.find(h));
            }

            int currHeight = *heights.rbegin(); // max height
            if (currHeight != prevHeight) {
                result.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }

        return result;
    }
};
