class Solution {
public:

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0 , end = n-1;
        while(start<end){
            int mid = (start+end)/2;
            if(nums[mid] < nums[end]){
                end = mid;
            }else{
                start = mid+1;
            }
        }
        int pivot = end;
        if(target > nums[n-1]){
            start = 0;
            end = pivot-1;
        }else{
            start = pivot;
            end = n-1;
        }
        while(start<=end){
            int m = (start+end)/2;
            if(nums[m] == target) return m;
            if(nums[m]<target){
                start = m+1;
            }else{
                end= m-1;
            }
        }
        return -1;
    }
};
