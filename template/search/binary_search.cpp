int binary_search(vector<int>& nums, int stm, int edm, int target)
{
    int st=stm, ed = edm;
    while (st<ed) {
        int mid = (st+ed)/2;
        if (nums[mid]==target)
        {
            return mid;
        } else {
            if (nums[mid]<target)
            {
                st = mid+1;
            } else {
                ed = mid-1;
            }
        }
    }
    return st;
}
