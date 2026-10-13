class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        int n = nums.size();
        
        // Total number of subsets is 2^n
        int total_subset = 1 << n;
        
        // Optimizing performance by reserving space beforehand
        v.reserve(total_subset);
        
        // Run a loop from 000...0 to 111...1
        for(int i = 0 ; i < total_subset ; i++)
        {
            vector<int> v1;
            for(int j = 0 ; j < n ; j++)
            {
                // Check if the j-th bit of i is set
                if((i & (1 << j)) != 0)
                {
                    v1.push_back(nums[j]);
                }
            }
            v.push_back(v1);
        }
        return v;
    }
};