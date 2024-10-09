class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlength = 0;
        vector<int> charindex(128,-1);
        int left = 0;

        for(int right = 0;right < n;right++){
            if(charindex[s[right]] >= left){
                left = charindex[s[right]] + 1;
            }
            charindex[s[right]] = right;
            maxlength = max(maxlength,right - left + 1);
        }
        return maxlength;
    }
};