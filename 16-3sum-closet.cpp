class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        arr = nums;
        sort(arr.begin(),arr.end());
        int ans = 1e9;
        int size = nums.size();
        for(int i=0;i+2<size;i++){
            int j = i +1;
            int k = size-1;
            while(j<k){
                int sum = getSum(i,j,k);
                if(abs(sum-target) < abs(ans-target)) ans = sum;
                if(sum>target){
                    k--;
                }else {
                    j++;
                }
            }
        }
        return ans;
    }
    int getSum(int x,int y,int z){
        return arr[x]+arr[y]+arr[z];
    }
private:
    vector<int>arr;
};
