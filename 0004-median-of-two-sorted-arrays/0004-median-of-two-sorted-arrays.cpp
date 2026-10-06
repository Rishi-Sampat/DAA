class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        int i = 0, j = 0;
        int prev = -1, curr = -1;

        for (int count = 0; count <= n / 2; count++) {
            prev = curr;
            if (i < n1 && (j >= n2 || nums1[i] <= nums2[j])) {
                curr = nums1[i++];
            } else {
                curr = nums2[j++];
            }
        }

        if (n % 2 == 1) return curr;
        return (prev + curr) / 2.0;
    }
};