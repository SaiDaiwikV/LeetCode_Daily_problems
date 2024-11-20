class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int freq[3] = {0};

        int left = 0;
        while(left < n and (freq[0]<k or freq[1]<k or freq[2]<k)){
            freq[s[left]-'a']++;
            left++;
        }
        if(freq[0]<k or freq[1]<k or freq[2]<k){
            return -1;
        }
        int shortest = left;
        left -= 1;
        int right = n-1;
        while(left>=0){
            freq[s[left]-'a']--;
            left--;

            while(left <= right and (freq[0]<k or freq[1]<k or freq[2]<k)){
                freq[s[right]-'a']++;
                right--;
            }
            shortest = min(shortest,n-(right-left));
        }
        return shortest;
    }
};