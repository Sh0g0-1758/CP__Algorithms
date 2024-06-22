class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = (n1 + n2);

        if(n1>n2) return findMedianSortedArrays(nums2, nums1);

        if(n1 == 0) return n2%2?nums2[n2/2]:(nums2[n2/2]+nums2[n2/2-1])/2.0;
        if(n2 == 0) return n1%2?nums1[n1/2]:(nums1[n1/2]+nums1[n1/2-1])/2.0;

        int part = (n + 1) / 2;

        int low = 0;
        int high = n1;
        int cut1,cut2;
        int l1,r1,l2,r2;

        while(low <= high) {
            cut1 = (low+high)/2;
            cut2 = part - cut1;

            l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            r1 = cut1 >= n1 ? INT_MAX : nums1[cut1];
            r2 = cut2 >= n2 ? INT_MAX : nums2[cut2];

            if (l1 <= r2 and l2 <= r1) {
                return n%2 ? max(l1,l2) : (max(l1,l2) + min(r1,r2)) / 2.0;
            }

            if (l1 > r2) high = cut1 - 1;
            else low = cut1+1;
        }

        return 0.0;
    }
};
