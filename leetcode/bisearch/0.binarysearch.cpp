int binary_search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            return mid;
        }
    }
    return -1;
}


// # 若有重复元素 则返回重复元素左边界(左侧的第一个元素)的索引
// #     0  1  2  3
// # 如 [0, 2, 2, 4] 
// # target=2,   返回索引1
// # target= 1, 虽然不存在, 但返回索引1, 即大于等于target的最小的元素位置
// # target= 3, 虽然不存在, 但返回索引3, 即大于等于target的最小的元素位置
// # target=-1, 虽然不存在, 但返回索引0, 即大于等于target的最小的元素位置
// # target= 5, 虽然不存在, 但返回索引len(nums), 该索引越上界

int left_bound(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;
    while (left<=right) {
        int mid = left + (right - left)/2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            right = mid - 1;
        }
    }
    if (left >= nums.size() || nums[left] != target) {
        return -1;
    }
    return left;
}

// # 变种
int left_bound_(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();
    while (left < right) {
        int mid = left + (right - left)/2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        } else if (nums[mid] == target) {
            right = mid;
        }
    }
    if (left >= nums.size() || nums[left] != target) {
        return -1;
    }
    return left;
}



// # 若有重复元素 则返回重复元素右边界(右侧的最后一个元素)的索引
// #     0  1  2  3
// # 如 [0, 2, 2, 4] 
// # target=2,  返回索引2
// # target=3, 虽然不存在, 但返回索引2, 即小于等于target的最大的元素位置
// # target=1, 虽然不存在, 但返回索引0, 即小于等于target的最大的元素位置
// # target=-1, 虽然不存在, 但返回索引-1, 该索引越下界
// # target= 5, 虽然不存在, 但返回索引3, 即小于等于target的最大的元素位置
int right_bound(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        // 不返回 收缩左边界
        } else if (nums[mid] == target) {
            left = mid + 1;
        }
    }
    if (right < 0 || nums[right] != target) {
        return -1;
    }
    return right;
}
// # 变种
int right_bound_(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();
    while (left < right) {
        int mid = left + (right - left)/2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        // 不返回 收缩左边界
        } else if (nums[mid] == target) {
            left = mid + 1;
        }
    }
    if (right < 0 || nums[right-1] != target) {
        return -1;
    }
    return right-1;
}

    
    