
    int findPivot(int* nums, int n){
        int low=0; int high= n-1; int size= n;
        
        while(low<=high){
            if(nums[low] <= nums[high]){ // if array is already sorted
                return low;
            }
            
            int mid= low + (high-low)/2;
            
            int prev= (mid +size -1)% size;
            int nxt= (mid+1) % size;
            
            if(nums[prev] >= nums[mid] && nums[nxt] >= nums[mid]){ // then mid is the pivot itself
                return mid;
            }
            
            // Now notice that [start - mid] and [mid - end] are 2 sub-array
            // between these 2- sub-array, only one of them is sorted, other one is un-sorted.
            // Also notice that pivot is present in the un-sorted sub-array itself
            
            else if(nums[low] <= nums[mid]){ // left sub-array is sorted, go to right side (un-sorted)
                low= mid+1;
            }
            
            else if(nums[high] >= nums[mid]){ // right sub-array is sorted, go to left side (un-sorted)
                high= mid-1;
            }
        }
        
        return low;
    }
    
    int binarySearch(int* nums, int target, int low, int high){
        if(low>high){
            return -1;
        }
        int mid= low+ (high-low)/2;
        if(target < nums[mid]){ // go to left side 
            return binarySearch(nums,target,low, mid-1);
        }
        else if(target > nums[mid]){
            return binarySearch(nums, target, mid+1, high);
        }
        else if(target == nums[mid]){
            return mid;
        }
        return -1; // target not found
    }
    
    int search(int* nums, int n, int target) {
        // See, we first need to find pivot (smallest element in rotated sorted array)
        // You can observe that 1. every element in right side of pivot are non-decreasingly sorted
        //                      2. every element in left side of pivot are also non-deceasingly sorted
        
        // finding pivot:----->
        int pivot= findPivot(nums, n);
        
        if(nums[pivot]==target){ // target is the pivot element itself
            return pivot;
        }
        
        if(pivot==0){ // if array is not rotated, then we will only search in right side of pivot
            return binarySearch(nums, target, pivot+1, n-1);
        }
        
        else if(target>= nums[0]){ // target can be found on the left sorted sub-array
            return binarySearch(nums, target, 0, pivot-1);
        }
        
        else if(target<= nums[n-1]){ // target can be found on right sorted sub-array
            return binarySearch(nums, target, pivot+1, n-1);
        }
        return -1; // target not found
    }