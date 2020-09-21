## 学习笔记

### 脑图（持续更新中）
本周更新内容：
- 二叉树遍历时，不同顺序的迭代关键代码，以及通用的代码模版
- "code易错点": 记录C++和python编程时出现的一些语法错误

![脑图](../image/数据结构和算法.png)


### 二叉树的遍历
1. Iterative solution using stack: O(n) time and O(n) space
2. Recursive solution: O(n) time and O(n) space (function call stack == 递归时系统会自动调用栈) 
3. Morris traversal: O(n) time and O(1) space

#### 递归模版（通用）
```
if (root != NULL) {
            results.push_back(root->val);
            helper(root->left, results);
            helper(root->right, results);
}  // 前序遍历
```

#### 迭代模版（不通用）
- 前序
  ```
  if (root != NULL) myStack.push(root);
  else {return ret;}
  while (myStack.empty() != true) {
        TreeNode* temp_root = myStack.top();
        myStack.pop();
        ret.push_back(temp_root->val);
        if (temp_root->right) myStack.push(temp_root->right);
        if (temp_root->left) myStack.push(temp_root->left);
   }
  ```

- 中序
  ```
  TreeNode* cur = root;
  if (root == NULL) return ret;
  while (!myStack.empty() || cur != NULL) {
        if (cur != NULL) {
            myStack.push(cur);
            cur = cur->left;
        }
        else {
            cur = myStack.top();
            myStack.pop();
            ret.push_back(cur->val);
            cur = cur->right; 
        }
   }
  ```

