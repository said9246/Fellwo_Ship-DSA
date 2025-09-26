class Solution {
public:
    vector<string> result;

    vector<string> restoreIpAddresses(string s) {
        string path;
        backtrack(s, 0, 0, path);
        return result;
    }

    void backtrack(string &s, int index, int part, string path) {
        // Agar 4 parts ban gaye aur string bhi khatam
        if (part == 4 && index == s.size()) {
            path.pop_back(); // last dot hatao
            result.push_back(path);
            return;
        }

        // Agar 4 parts ban gaye but string bachi hai
        if (part == 4 || index == s.size()) return;

        // Har part max 3 length ka ho sakta hai
        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string segment = s.substr(index, len);

            // Leading zero check
            if (segment.size() > 1 && segment[0] == '0') break;

            // Range check
            int val = stoi(segment);
            if (val > 255) break;

            // Recurse
            backtrack(s, index + len, part + 1, path + segment + ".");
        }
    }
};
