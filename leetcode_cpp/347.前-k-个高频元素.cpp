/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    void heapifyDown(vector<vector<int>>& nums, int parent, int end) {
        int largest = parent, left = 2 * parent + 1, right = 2 * parent + 2;
        if (left < end && nums[left][1] > nums[largest][1])
        {
            largest = left;
        }
        if (right < end && nums[right][1] > nums[largest][1])
        {
            largest = right;
        }
        if (largest != parent)
        {
            vector<int> tmp = nums[largest];
            nums[largest] = nums[parent];
            nums[parent] = tmp;
            heapifyDown(nums, largest, end);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        /**
         * 解法一: 堆排序 + 哈希表
         * 哈希表: 保存 元素-频率 的对应关系（用unordered_map直接击败95%，而普通map只击败15%）
         * 堆排序: 基于哈希表建立一个数组[[数字i，频率]， [数字i+1，频率], ...]，然后进行堆排序
        */
        vector<vector<int>> hq;
        unordered_map<int, int> hash;

        // 计数并保存到hashmap里面
        for (int i: nums) {
            hash[i]++;              // c++会默认不存在的key的value为0，所以可以直接++操作
            // if (hash.count(i) > 0) {
            //     hash[i]++;
            // }
            // else {
            //     hash[i] = 1;
            // }
        }

        // hashmap里面的key和value全部保存到将要做成大顶堆的vector里面
        for (auto m: hash) {
            hq.push_back({m.first, m.second});
        }

        // 建立大顶堆
        int length = hq.size();
        for (int i = (length - 2) / 2; i >= 0; i--) {
            heapifyDown(hq, i, length);
        }

        // 遍历大顶堆，依次取出最大的数字，直到k
        vector<int> res;
        for (int j = length - 1; j >= 0; j--) {
            vector<int> tmp = hq[0];
            hq[0] = hq[j];
            hq[j] = tmp;
            res.push_back(tmp[0]);
            k--;
            if (k <= 0) break;
            heapifyDown(hq, 0, j);
        }
        return res;
    }
};
// @lc code=end

