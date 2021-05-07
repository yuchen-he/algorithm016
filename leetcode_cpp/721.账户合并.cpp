/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */

// @lc code=start
class Solution {
private:
    void unionElem(vector<int>& parent, int i, int j) {
        int p_i = findP(parent, i);
        int p_j = findP(parent, j);
        if (p_i != p_j) {
            parent[p_i] = p_j;
        }
    }

    int findP(vector<int>& parent, int x) {
        int root = x;
        while (parent[root] != root) {
            root = parent[root];
        }

        while (parent[x] != x) {
            int tmp = parent[x];
            parent[x] = root;
            x = tmp;
        }

        return root;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int size = accounts.size();
        vector<int> parent(size, 0);
        for (int k = 0; k < size; k++) {
            parent[k] = k;
        }

        unordered_map<string, int> mail2index;
        for (int i = 0; i < size; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mail2index.count(accounts[i][j]) > 0) {
                    unionElem(parent, mail2index[accounts[i][j]], i);
                }
                else {
                    mail2index[accounts[i][j]] = i;
                }
            }
        }

        unordered_map<int, vector<string>> index2mail;
        for (auto &p : mail2index) {
            int parent_idx = findP(parent, p.second);
            if (index2mail.count(parent_idx) > 0) {
                index2mail[parent_idx].push_back(p.first);
            }
            else {
                index2mail[parent_idx] = {p.first};
            }
        }

        vector<vector<string>> res;
        for (auto &p : index2mail) {
            sort(p.second.begin(), p.second.end());
            vector<string> tmp;
            tmp.push_back(accounts[p.first][0]);
            for (string s : p.second) {
                tmp.push_back(s);
            }
            res.push_back(tmp);
        }

        return res;
    }
};
// @lc code=end

