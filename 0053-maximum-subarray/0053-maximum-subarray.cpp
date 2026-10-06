class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       vector<int> t = fun(nums,0,nums.size()-1);
        return t[2];
    }
    vector<int> cross_fun(vector<int> &a,int lo,int mid,int hi)
    {
        int l_sum = INT_MIN;
        int sum = 0;
        int m_left = mid;
        for(int i = mid; i>= lo ; i--)
        {
            sum += a[i];
            if(sum > l_sum)
            {
                l_sum = sum;
                m_left = i;
            }
        }
        int r_sum = INT_MIN;
        sum = 0;
        int m_right = mid;
        for(int i = mid + 1 ; i<= hi ; i++)
        {
            sum += a[i];
            if(sum > r_sum)
            {
                r_sum = sum;
                m_right = i;
            }
        }
        return {m_left,m_right,l_sum + r_sum};
    }
    vector<int> fun(vector<int> &a,int lo, int hi)
    {
        if(hi == lo) return {lo,hi,a[lo]};
        int mid = lo + (hi - lo)/2 ;
        vector<int> left = fun(a,lo,mid);
        vector<int> right = fun(a,mid+1,hi);
        vector<int> cross = cross_fun(a,lo,mid,hi);
        if(left[2] >= right[2] && left[2] >= cross[2]) return left;
        if(right[2] >= left[2] && right[2] >= cross[2]) return right;
        return cross; 
    }
};