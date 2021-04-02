/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int partition(vector<int>& nums, int begin, int end) {
        int pivot = end, count = begin;
        for (int i = begin; i < end; i++) {
            if (nums[i] < nums[pivot]) {
                int tmp = nums[count];
                nums[count++] = nums[i];
                nums[i] = tmp;
            }
        }
        int tmp = nums[count];
        nums[count] = nums[pivot];
        nums[pivot] = tmp;
        return count;
    }

    // void heapifyDown(vector<int>& nums, int parent, int end) {
    //     // 不包含end
    //     int left = 2 * parent + 1, right = 2 * parent + 2;
    //     int largest = parent;
    //     if (left < end && nums[left] > nums[largest]) {
    //         largest = left;
    //     }
    //     if (right < end && nums[right] > nums[largest]) {
    //         largest = right;
    //     }
    //     if (largest != parent) {
    //         int tmp = nums[parent];
    //         nums[parent] = nums[largest];
    //         nums[largest] = tmp;
    //         heapifyDown(nums, largest, end);
    //     }
    // }

    int findKthLargest(vector<int>& nums, int k) {
        /**
         * 解法二: 基于快排解决TopK问题。（比解法一的堆排更慢）
         * 利用pivot的idx位置判断k在左边还是右边 -> 剪枝
        */
        int length = nums.size();
        int begin = 0, end = length - 1;
        while (begin < end) {
            int pivot = partition(nums, begin, end);
            if (length - pivot == k) {
                return nums[pivot];    // 正好
            }
            else if (length - pivot > k) {
                begin = pivot + 1;     // pivot右边存在k
            }
            else {
                end = pivot - 1;       // pivot左边存在k
            }
        }
        // 此时说明begin==end，而且对应位置是k
        return nums[begin];

        /**
         * 解法一: 堆排序，O(N*logN)。不是先排序再返回倒数第k的数，而是排序过程中直接返回。
         * 排序过程中直接判断是否达到了第k个不同元素，达到则跳出循环。
        */
        // int length = nums.size();
        
        // // 建立大顶堆: heapify_down
        // for (int i = (length - 2) / 2; i >= 0; i--) {
        //     heapifyDown(nums, i, length);
        // }

        // // 每次把堆顶元素放入应放的数组末尾位置j，然后把j之前的再排序一次
        // // 并且需要记录此时放到末尾的堆顶元素（是否与之前重合，补充和则k--，直到k==0说明找到了）
        // int maxVal = INT_MAX;
        // for (int j = length - 1; j > 0; j--) {
        //     int tmp = nums[j];
        //     nums[j] = nums[0];
        //     nums[0] = tmp;

        //     // 此时j位置是当前最大值
        //     k--;
        //     maxVal = nums[j];
        //     if (k == 0) return maxVal;

        //     // 把j之前的排序（因为只有0位置变动了，所以直接从0开始heapifyDown即可）
        //     heapifyDown(nums, 0, j);
        // }
        // return nums[0];
    }
};
// @lc code=end

