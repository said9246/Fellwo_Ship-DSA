class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector <string> result;
        unordered_map <int ,string > mp;

        for(int i=0;i<names.size();i++){
            mp[heights[i]]=names[i];
        }
        
        sort(heights.begin(), heights.end(), greater<int>());
        for(int h:heights){
            result.push_back(mp[h]);
        }

        return result ;
        
    }
};