#include<iostream>
#include<vector>

std::vector<int> quickSort(std::vector<int>& nums){
    sortCore(nums, 0, nums.size()-1);
}

void sortCore(std::vector<int> &myNums, int lo, int hi){
    if(lo>hi) return;
    int mi = partition(myNums, lo, mi-1)
    sortCore(myNums, lo, mi-1);
    sortCore(myNums, mi+1, hi);
}

void partition(std::vector<int>& nums, int lo, int hi){
    swap(nums[lo],nums[lo+rand()%(hi-lo+1]));
    int pivot = nums[lo];
    while(lo<hi){
        while(lo<hi){
            if(pivot < nums[hi]) hi--;
            else{
            nums[lo] = nums[hi];
            ++lo;
            break;
            }
        }
        while(lo<hi){
            if(pivot>nums[lo]) lo++;
            else{
                nums[hi] == nums[lo];
                --hi;
                break;
            }
        }
    }
    nums[lo] = pivot;
    return lo;
}