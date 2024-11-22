class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> relative_freq;
        for(auto& row : matrix){
            int first = row[0];
            string curr;

            for(int ele : row){
                if(ele == first) curr.push_back('0');
                else             curr.push_back('1'); 
            }
            relative_freq[curr]++;
        }
        int max_freq = 0;
        for(auto& [string,freq] : relative_freq){
            max_freq = max(max_freq,freq);
        }
        return max_freq;
    }
};