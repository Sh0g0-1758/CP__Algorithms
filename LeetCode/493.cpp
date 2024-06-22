class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sect(0,n-1,nums,ans);
	    return ans;
    }
    void sect(int i,int j,vector<int>&a,int &ans){
        if(i>=j) return;
        int m = i+(j-i)/2;
        sect(i,m,a,ans);
        sect(m+1,j,a,ans);
        countPairs(i,m,j,a,ans);
    }
    void countPairs(int i,int m,int j,vector<int>&a,int &ans){
        int l = i, r = m+1;
        while(l<=m && r<=j){
            if(a[l]>2LL*a[r]){
                ans += (m-l+1);
                r++;
            }
            else l++;
        }
        merge(i,m,j,a);
    }
    void merge(int left, int mid, int right, vector<int>& nums){
        vector<int> temp(right - left + 1);
        int i = left,j=mid+1,k=0;
        while(i<=mid && j<=right){
            if(nums[i]<=nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }
        while(i<=mid){
            temp[k++] = nums[i++];
        }
        while(j<=right){
            temp[k++] = nums[j++];
        }
        for (int l = left; l <= right; l++) {
            nums[l] = temp[l - left];
        }
    }
};