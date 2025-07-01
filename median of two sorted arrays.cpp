class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int i = (low + high) / 2;
            int j = (m + n + 1) / 2 - i;

            int maxLeftX = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRightX = (i == m) ? INT_MAX : nums1[i];

            int maxLeftY = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRightY = (j == n) ? INT_MAX : nums2[j];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // Correct partition
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return double(max(maxLeftX, maxLeftY));
                }
            } else if (maxLeftX > minRightY) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }

        // If input arrays are not sorted or inputs are invalid
        return 0.0;
    }
};
