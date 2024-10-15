class Solution {
public:
    long long minimumSteps(string s) {
        int  n = s.size();
        long long total_count = 0;
        int left = 0;

        while(left < n && s[left] != '1')
            left++;
        for(int i = left+1;i<n;i++){
            if(s[i] == '0'){
                total_count += i-left;
                left++;
            }
        }
        return total_count;
    }
};