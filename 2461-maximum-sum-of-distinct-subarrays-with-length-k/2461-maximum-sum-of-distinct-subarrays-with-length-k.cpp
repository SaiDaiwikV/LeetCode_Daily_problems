class Solution {
    #define ll long long
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll max_sum = 0;
        unordered_map<int,int> freq;

        ll win_sum = 0;
        for(int i = 0;i<n;i++){
            freq[nums[i]]++;
            win_sum += nums[i];

            if(i>=k){
                win_sum -= nums[i-k];
                freq[nums[i-k]]--;
                if(freq[nums[i-k]] == 0){
                    freq.erase(nums[i-k]);
                }
            }
            if(i>=k-1 and freq.size()==k){
                max_sum = max(max_sum,win_sum);
            }
        }
        return max_sum;
    }
};