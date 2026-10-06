class Solution {
private:
    int lower, upper, count = 0;
    vector<long> prefixSum;
    
    void mergeSort(int low, int high){
        if(low >= high) return;
        
        int mid = (low + high) / 2;
        mergeSort(low, mid);      // Count in left half
        mergeSort(mid+1, high);   // Count in right half
        
        // Count cross-boundary subarrays
        int i, j;
        i = j = mid+1;
        
        for(int k = low; k <= mid; k++) {
            // Find first position where sum >= lower
            while(i <= high && prefixSum[i] - prefixSum[k] < lower) i++;
            // Find first position where sum > upper  
            while(j <= high && prefixSum[j] - prefixSum[k] <= upper) j++;
            
            count += j - i;  // All positions in [i, j) are valid
        }
        
        merge(low, mid, high);  // Keep array sorted for parent calls
    }
    
    void merge(int low, int mid, int high){
        vector<long> helper(high-low+1);
        for(int i = low; i <= high; i++){
            helper[i-low] = prefixSum[i];
        }
        
        int i = low, j = mid+1, idx = low;
        while(i <= mid && j <= high){
            if(helper[i-low] < helper[j-low]){
                prefixSum[idx] = helper[i-low];
                i++;
            } else {
                prefixSum[idx] = helper[j-low];
                j++;
            }
            idx++;
        }
        
        while(i <= mid){
            prefixSum[idx++] = helper[i-low];
            i++;
        }
    }
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        this->lower = lower;
        this->upper = upper;
        
        // Build prefix sum array
        prefixSum.resize(n+1);
        prefixSum[0] = 0;
        for(int i = 0; i < n; i++){
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        
        mergeSort(0, n);
        return count;
    }
};