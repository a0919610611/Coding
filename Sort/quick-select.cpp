int findKthSmall(vector<int>&nums,k){
        int index = quickSelect(nums,0,nums.size()-1,k);
        return nums[index];

}
int findKthLargest(vector<int>& nums, int k) {
        int index = quickSelect(nums,0,nums.size()-1,nums.size()-k+1);
        return nums[index];
}
int quickSelect(vector<int>&nums,int start,int end,int k){

        if(start==end) return start;
        int index = start + (end-start)/2;
        int pivot = nums[index];
        swap(nums[index],nums[end]);
        int left =start ;
        int right = end;
        while(left<right){
            if(nums[left++]>pivot){
                swap(nums[--left],nums[--right]);
            }
        }
        swap(nums[left],nums[end]);
        int m =  left-start+1;
        if(m==k) return left;
        else if(m>k){
            return quickSelect(nums,start,left-1,k);
        }else {
             return quickSelect(nums,left+1,end,k-m);
        }

    }

