#Kth Largest Element in an Array
##Worst case O(NlogN) solution with O(1) space
```C++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
```

##Worst case O(NlogK) solution with O(K) space (size-K max heap)
O(KlogN) is also possible by constructing a max heap in O(N) time, and pop the max element K times.
```C++
class Solution {
public:
    struct comp {
        bool operator() (int a, int b) {
            return a > b;
        }
    };
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;

        make_heap(nums.begin(), nums.begin() + k, comp());
        for (int i = k; i < nums.size(); i++) {
            if (nums.front() < nums[i]) {
                pop_heap(nums.begin(), nums.begin() + k, comp());
                nums[k - 1] = nums[i];
                push_heap(nums.begin(), nums.begin() + k, comp());
            }
        }

        return nums.front();
    }
};
```

##Average case O(N) solution with O(1) space (quick select with median of three)
```C++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, 0, nums.size() - 1, k);
    }
    int findKth(vector<int>& nums, int start, int end, int k) {
        if (start == end) 
            return nums[start];
        else if (start == end - 1) 
            return (k == 1)? max(nums[start], nums[end]) : min(nums[start], nums[end]);

        int median = rearrange(nums, start, end);
        int ptrStart = start + 1, ptrEnd = end - 2;
        while (ptrStart <= ptrEnd) {
            if (nums[ptrStart] <= median) swap(nums[ptrStart], nums[ptrEnd--]);
            else ptrStart++;
        }
        swap(nums[ptrStart], nums[end - 1]);
        
        if (k == ptrStart - start + 1) 
            return nums[ptrStart];
        else if (k > ptrStart - start + 1)
            return findKth(nums, ptrStart + 1, end, k - (ptrStart - start + 1));
        else // k < ptrStart - start + 1
            return findKth(nums, start, ptrStart - 1, k);
    }
    inline int rearrange(vector<int>& nums, int start, int end) {
        int mid = start + (end - start) / 2;
        if (nums[start] < nums[mid]) swap(nums[start], nums[mid]);
        if (nums[start] < nums[end]) swap(nums[start], nums[end]);
        if (nums[mid] < nums[end]) swap(nums[mid], nums[end]);
        swap(nums[mid], nums[end - 1]);
        return nums[end - 1];
    }
};
```

##Note
Theorectically there is an algorithm with linear time guaranteed. But that algorithm is impractical in the present scale of data.