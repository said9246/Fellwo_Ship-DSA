class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2);

        unordered_set <int> set1, set2;

        for(int i=0;i<nums1.size();i++){
            set1.insert(nums1[i]);
        };
         for(int i=0;i<nums2.size();i++){
            set2.insert(nums2[i]);
        }

        for (auto value : set1) {
    if (set2.find(value) == set2.end()) {
        answer[0].push_back(value);
    }
}

          for(auto value:set2){
            if(!set1.count(value)){ answer[1].push_back(value);}
        }
    return answer;

    }
};