#include <bits/stdc++.h>
using namespace std;
int binary_search(vector<int>& nums, int x)
{
    int left = 0;
    int right = nums.size();
    while (left <= right) {
        int mid = (left) + (right - left) / 2;
        if (x > nums[mid]) {
            left = mid + 1;
        } else if (x < nums[mid]) {
            right = mid - 1;
        } else
            return mid;
    }
    return -1;
}
int upper_bound(vector<int>& nums, int x)
{
    int left = 0;
    int right = nums.size();
    while (left < right) {
        int mid = (left) + (right - left) / 2;
        if (x >= nums[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
int lower_bound(vector<int>& nums, int x)
{
    int left = 0;
    int right = nums.size();
    while (left < right) {
        int mid = (left) + (right - left) / 2;
        if (x > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
