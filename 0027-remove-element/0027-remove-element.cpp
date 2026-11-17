class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int r = nums.size() - 1;
        int l = 0;
        int cnt = 0;

        while (l <= r) {
            if (nums[l] == val && nums[r] != val) {
                nums[l] = nums[r];
                nums[r] = 0;
                r--;
                l++;
                cnt++;
            }
            else if (nums[l] != val) {
                cnt++;
                l++;
            }
            else if (nums[r] == val) {
                r--;
            }
        }
        return cnt;
    }
};