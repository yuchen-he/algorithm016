/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
class Solution {
public:
    int find(vector<int>& parent, int i) {
        int root = i;

        // 找到i的根(while结束之后会赋值到root上)
        while (parent[root] != root) {
            root = parent[root];
        }

        // 剪枝优化
        while (parent[i] != i) {
            int tmp = parent[i];
            parent[i] = root;
            i = tmp;
        }

        return root;
    }

    void unionSet(vector<int>& parent, int& res, int i, int j) {
        int p_i = find(parent, i);
        int p_j = find(parent, j);
        if (p_i == p_j) return;
        parent[p_i] = p_j;
        res--;
    }

    int findCircleNum(vector<vector<int>>& M) {
        /**
        * 并查集（不需要完全建立一个并查集的class，只要实现里面的方法就行了）
        */
        int num = M.size();
        int res = num;

        // 初始化并查集
        vector<int> parent(num, 0);
        for (int i=1; i<num; i++) parent[i] = i;

        for (int i=0; i<num-1; i++) {
            for (int j=i+1; j<num; j++) {
                // 只需要遍历二维数组的半边
                if (M[i][j] == 1) {
                    unionSet(parent, res, i, j);
                }
            }
        }

        return res;
    }
};
// @lc code=end

