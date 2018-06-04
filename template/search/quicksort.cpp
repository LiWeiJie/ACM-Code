void msort(vector<int>& nums, vector<int>& numsno, int st, int ed)
{
    if (st<ed)
    {
        int p = partition(nums, numsno, st, ed);
        msort(nums, numsno, st, p-1);
        msort(nums, numsno, p+1, ed);
    }
}

int partition(vector<int>& nums, vector<int>& numsno, int st, int ed)
{
    int pivot = nums[ed];
    int i = st;
    for (int j = st; j<ed; j++)
    {
        if (nums[j] <= pivot)
        {
            swap(nums[i], nums[j]);
            swap(numsno[i], numsno[j]);
            i = i+1;
        }
    }
    swap(nums[i], nums[ed]);
    swap(numsno[i], numsno[ed]);
    return i;
}
