void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(n==0) return;
    queue<int> q1;
    int i=0,j=0;
    while(i<m)
    {
        if(q1.empty()&&j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                i++;
             }
            else
            {
                q1.push(nums1[i]);
                nums1[i]=nums2[j];
                i++;j++;
            }
        }
        else if(j<n)
        {
            if(q1.front()<=nums2[j])
            {
                q1.push(nums1[i]);
                nums1[i]=q1.front();
                q1.pop();
                i++;
             }
            else
            {
                q1.push(nums1[i]);
                nums1[i]=nums2[j];
                i++;j++;
            }
        }
        else
        {
            q1.push(nums1[i]);
            nums1[i]=q1.front();
            q1.pop();
            i++;
        }
    }
    while(i<m+n)
    {
        if(q1.empty())
        {
            nums1[i]=nums2[j];
            i++;j++;
        }
        else
        {
            if(j==n)
            {
                nums1[i]=q1.front();
                q1.pop();
                i++;
            }
            else if(q1.front()<=nums2[j])
            {
                nums1[i]=q1.front();
                q1.pop();
                i++;
             }
            else
            {
                nums1[i]=nums2[j];
                i++;j++;
            }
        }
    }
    return ;
}
