class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(); // size of the vector
        int l = 0; // using two-pointer technique
        int r = n - 1;

        // Skip from the right to find the longest non-decreasing suffix
        while (r > 0 && arr[r] >= arr[r - 1]) {
            r--;
        }

        int shortest = r; // Remove all elements to the left of r
        while (l < r) {
            while (r < n && arr[l] > arr[r]) {
                r++;
            }
            shortest = min(shortest, r - l - 1); // r - l - 1 means removing elements between l and r

            l++;
            if (l > 0 && arr[l] < arr[l - 1]) {
                break;
            }
        }

        return shortest;
    }
};
