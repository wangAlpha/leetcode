
# 哈希表
 - [x]  1\. Two Sum (Easy)
 - [x]  217\. Contains Duplicate (Easy)
 - [x]  128\. Longest Consecutive Sequence (Hard)
 - [ ]  149\. Max Points on a Line (Hard)
 - [ ]  332\. Reconstruct Itinerary (Medium)
 - [ ]  304\. Range Sum Query 2D - Immutable (Medium)
 - [ ]  560\. Subarray Sum Equals K (Medium)
 - [ ]  503\. Next Greater Element II (Medium) Daily Temperature 的变种题。
 - [x]  697\. **Degree of an Array (Easy) 如何对数组进行预处理才能正确并快速地计算子数组的长度？**
 - [x]  594\. Longest Harmonious Subsequence (Easy) 最长连续序列的变种题。
 - [x]  287\. Find the Duplicate Number (Medium) 寻找丢失数字的变种题。除了标负位置，你还有没有其它算法可以解决这个问题？
 - [ ]  313\. Super Ugly Number (Medium) 尝试使用优先队列解决这一问题。
 - [ ]  870\. Advantage Shuffle (Medium) 如果我们需要比较大小关系，而且同一数字可能出现多次，那么应该用什么数据结构呢？
 - [ ]  307\. Range Sum Query - Mutable (Medium) 前缀和的变种题。好吧我承认，这道题可能有些超纲，你或许需要搜索一下什么是线段树。
# 链表
 - [x]  160\. Intersection of Two Linked Lists (Easy) Goolge
 - [x]  206\. Reverse Linked List (Easy)
 - [x]  21\. Merge Two Sorted Lists (Easy)
 - [x]  83\. Remove Duplicates from Sorted List (Easy)
 - [x]  19\. Remove Nth Node From End of List (Medium)
 - [x]  24\. Swap Nodes in Pairs (Medium)
 - [x]  445\. Add Two Numbers II (Medium)
 - [x]  234**\. Palindrome Linked List (Easy)**
 - [x]  725\. Split Linked List in Parts(Medium)
 - [x]  328\. Odd Even Linked List (Medium)
 - [x]  **215\. Kth Largest Element in an Array (Medium)**
 - [x]  148\. **Sort List (Medium) 利用快慢指针找到链表中点后，可以对链表进行归并排序**
# 栈和队列
 - [x]  232\. Implement Queue using Stacks (Easy)
 - [x]  **225\. Implement Stack using Queues (Easy)**
 - [x]  155\. Min Stack (Easy)
 - [x]  20\. Valid Parentheses (Easy)
 - [x]  739 **\. Daily Temperatures (Medium)**
 - [x]  23 \.Merge k Sorted Lists (Hard)
 - [ ]  218\. The Skyline Problem (Hard)
 - [x]  **239**\. Sliding Window Maximum (Hard)
# 树
## 递归
 - [xx]  104\. Maximum Depth of Binary Tree (Easy)
 - [x]  **110\. Balanced Binary Tree (Easy)**
 - [x]  543\. **Diameter of Binary Tree (Easy)**
 - [xx]  617\. Merge Two Binary Trees (Easy)
 - [x]  560\. **Subarray Sum Equals K** 前缀法
 - [x]  437\. **Path Sum III (Easy)**
 - [xx]  572\. Subtree of Another Tree (Easy)
 - [x]  111\. **Minimum Depth of Binary Tree (Easy)**
 - [x]  687\. **Longest Univalue Path (Easy)**
 - [ ]  337\. House Robber III (Medium)
 - [x]  671\. **Second Minimum Node In a Binary Tree (Easy)**
 - [ ]  1110\. Delete Nodes And Return Forest (Medium)
 - [x] 222
 - [x] 257
 - [x] 112
## 层次遍历
 - [x]  637\. Average of Levels in Binary Tree (Easy)
 - [x]  513\. Find Bottom Left Tree Value (Easy)
## 前中后序遍历
 - [x]  144\. Binary Tree Preorder Traversal (Medium)
 - [x]  145\. Binary Tree Postorder Traversal (Medium)
 - [x]  94\. Binary Tree Inorder Traversal (Medium)
 - [ ]  105\. Construct Binary Tree from Preorder and Inorder Traversal (Medium)
 - [x]  99\. **Recover Binary Search Tree (Hard)**
## BST
 - [x]  !669\. **Trim a Binary Search Tree (Easy)** 搜索树的定义
 - [x]  230\. **Kth Smallest Element in a BST (Medium)** 迭代遍历
 - [x]  235\. **Lowest Common Ancestor of a Binary Search Tree (Easy)** 搜索树
 - [x]  236\. **Lowest Common Ancestor of a Binary Tree (Medium)**
 <!-- - [x]  108\. **Convert Sorted Array to Binary Search Tree (Easy)** 递归 -->
 - [x]  109\. **Convert Sorted List to Binary Search Tree (Medium)** 找中位数
 - [x]  653\. Two Sum IV - Input is a BST (Easy)
 - [x]  530\. M**inimum Absolute Difference in BST (Easy)**
 - [x]  501\. Find Mode in Binary Search Tree (Easy)
## Trie
 - [x]  208\. **Implement Trie (Prefix Tree) (Medium)**
 - [x]  677\. **Map Sum Pairs (Medium)**
## STL
 - [x]  146\. LRU Cache (Medium)
 - [x]  404\. Sum of Left Leaves (Easy) 怎么判断一个节点是不是左节点呢？一种可行的方法是，在辅函数里多传一个参数，表示当前节点是不是父节点的左节点。
 <!-- - [x]  538\. Convert BST to Greater Tree (Easy) 尝试利用某种遍历方式来解决此题，每个节点只需遍历一次。 -->
 - [ ]  889\. Construct Binary Tree from Preorder and Postorder Traversal (Medium) 给定任意两种遍历结果，我们都可以重建树的结构。
 - [x]  106\. **Construct Binary Tree from Inorder and Postorder Traversal (Medium) 给定任意两种遍历结果，我们都可以重建树的结构。**
 - [x]  **897\. Increasing Order Search Tree (Easy) 把 BST 压成一个链表，务必考虑清楚指针操作的顺序，否则可能会出现环路。**
 - [x]  !450\. Delete Node in a BST (Medium) 当寻找到待删节点时，你可以分情况考虑——当前节点是叶节点、只有一个子节点和有两个子节点。建议同时回收内存。
 - [x]  380\. Insert Delete GetRandom O(1) (Medium) 设计一个插入、删除和随机取值均为 O(1) 时间复杂度的数据结构。
 - []  432\. All O‘one Data Structure (Hard) 设计一个 increaseKey，decreaseKey，getMaxKey，getMinKey 均为 O(1) 时间复杂度的数据结构。
# 双指针
 - [x]  167\. Two Sum II - Input array is sorted (Easy)
 - [x]  633\. **Sum of Square Numbers (Easy)**
 - [x]  345\. Reverse Vowels of a String (Easy)
 - [x]  680\. Valid Palindrome II (Easy)
 - [x]  141\. Linked List Cycle (Easy)
 - [x]  524\. **Longest Word in Dictionary through Deleting (Medium) 归并两个有序数组的变形题** （双指针）
 - [x]  88\. Merge Sorted Array (Easy)
 - [x]  142\. **Linked List Cycle II (Medium)** 算术题
 - [ ]  76\. **Minimum Window Substring (Hard)**
 - [ ]  4\.   Longest Substring with At Most K Distinct Characters (Hard) 需要利用其它数据结构方便统计当前的字符状态。
# 搜索
## BFS
 - [ ]  1091\. Shortest Path in Binary Matrix(Medium)
 - [ ]  279\. Perfect Squares (Medium)
 - [ ]  127\. Word Ladder (Medium)
 - [ ]  547\. Friend Circles (Medium)
## DFS
 - [ ]  695\. Max Area of Island (Medium)
 - [ ]  200\. Number of Islands (Medium)
 - [ ]  547\. Friend Circles (Medium)
 - [ ]  130\. Surrounded Regions (Medium)
 - [ ]  417\. Pacific Atlantic Water Flow (Medium)
## Backtracking
 - [x]  17\. **Letter Combinations of a Phone Number (Medium)**
 - [ ]  93\. Restore IP Addresses(Medium)
 - [ ]  79\. Word Search (Medium)
 - [x]  46\. Permutations (Medium)
 - [x]  47\. Permutations II (Medium)
 - [ ]  77\. Combinations (Medium)
 - [ ]  39\. Combination Sum (Medium)
 - [x]  40\. Combination Sum II (Medium)
 - [x]  216\. **Combination Sum III (Medium)**
 - [x]  78\. Subsets (Medium)
 - [x]  90\. **Subsets II (Medium)**
 - [ ]  131\. Palindrome Partitioning (Medium)
 - [x]  37\. Sudoku Solver (Hard)
 - [x]  51\. N-Queens (Hard)
 - [ ]  934\. Shortest Bridge (Medium)
 - [ ]  126\. Word Ladder II (Hard)
 - [ ]  2\.   Binary Tree Paths (Easy) 输出二叉树中所有从根到叶子的路径，回溯法使用与否有什么区别？进阶难度
 - [ ]  3\.  Permutations II (Medium) 排列题的 follow-up，如何处理重复元素？
 - [ ]  4\.  Combination Sum II (Medium) 组合题的 follow-up，如何处理重复元素？
 - [ ]  6\.   Minimum Height Trees (Medium)如何将这道题转为搜索类型题？是使用深度优先还是广度优先呢？

# 贪心思想
 - [x]  455\. Assign Cookies (Easy) (Google)
 - [x]  435\. Non-overlapping Intervals (Medium) (Google)
 - [x]  452\. Minimum Number of Arrows to Burst Balloons (Medium)
 - [x]  406\. **Queue Reconstruction by Height(Medium)**
 - [x]  121\. **Best Time to Buy and Sell Stock (Easy)** 历史最低点
 - [x]  122\. **Best Time to Buy and Sell Stock II (Easy)**
 - [x]  392\. Is Subsequence (Medium)
 - [x]  665\. Non-decreasing Array (Easy)
 - [x]  53\. Maximum Subarray (Easy)
 - [x]  135\. Candy (Hard)
 - [x]  605\. Can Place Flowers (Easy)
 - [x]  763\. Partition Labels (Medium)

# 字符串
 - [x]  242\. Valid Anagram (Easy)
 - [x]  409\. Longest Palindrome (Easy)
 - [x]  205\. Isomorphic Strings (Easy)
 - [x]  647\. Palindromic Substrings (Medium)
 - [x]  9\. Palindrome Number (Easy)
 - [x]  696\. **Count Binary Substrings (Easy)**
 - [ ]  1\.   Basic Calculator II (Medium)
 - [ ]  2\.  Implement strStr() (Easy)
 - [ ]  3\. Longest Substring Without Repeating Characters (Medium) 计算最长无重复子字符串，同样的，可以利用其它数据结构进行辅助统计。
 - [ ]  4\.   Basic Calculator III (Hard) 题目 227 的 follow-up，十分推荐练习。
 - [ ]  5\. Longest Palindromic Substring (Medium) Manacher’s Algorithm，它可以在 O(n)

# 图
## 二分图
 - [ ]  785\. Is Graph Bipartite? (Medium)
 - [ ]  1059\. All Paths from Source Lead to Destination (Medium) 虽然使用深度优先搜索可以解决大部分的图遍历问题，但是注意判断是否陷入了环路。
 - [ ]  1135\. Connecting Cities With Minimum Cost (Medium)
 - [ ]  882\. Reachable Nodes In Subdivided Graph (Hard)
## 拓扑排序
 - [ ]  207\. Course Schedule (Medium)
 - [ ]  210\. Course Schedule II (Medium)
## 并查集
 - [x]  684\. **Redundant Connection (Medium)**

# 二分查找
 - [x]  69\. **Sqrt(x) (Easy)**
 - [x]  744\. **Find Smallest Letter Greater Than Target (Easy)**
 - [x]  278\. First Bad Version (Easy)
 - [x]  153\. **Find Minimum in Rotated Sorted Array (Medium)**
 - [x]  34\. **Find First and Last Position of Element in Sorted Array**
 - [x]  81\. **Search in Rotated Sorted Array II (Medium)**
 - [x]  154\. **Find Minimum in Rotated Sorted Array II (Medium) 旋转数组的变形题之一。**
 - [ ]  540\. Single Element in a Sorted Array (Medium) 在出现独立数之前和之后，奇偶位数的值发生了什么变化？
 - [ ]  4\. Median of Two Sorted Arrays (Hard) 需要对两个数组同时进行二分搜索。
# 分治
 - [ ]  241\. Different Ways to Add Parentheses (Medium)
 - [ ]  95\. Unique Binary Search Trees II (Medium)

# 数学
 - [x]  204\. **Count Primes (Easy)**
## 进制转换
 - [x]  504\. **Base 7 (Easy)**
 - [x]  405\. **Convert a Number to Hexadecimal (Easy)**
 - [x]  168\. **Excel Sheet Column Title (Easy)**
## 阶乘
 - [x]  172\. **Factorial Trailing Zeroes (Easy)**
## 字符串加法减法
 - [x]  67\. **Add Binary (Easy)**
 - [x]  415\. Add Strings (Easy)
## 相遇问题
 - [ ]  462\. Minimum Moves to Equal Array Elements II (Medium) 这道题是笔者最喜欢的 LeetCode 题目之一，需要先推理出怎么样移动是最优的，再考虑如何进行移动。你或许需要一些前些章节讲过的算法。
## 多数投票问题
 - [ ]  169\. Majority Element (Easy) 如果想不出简单的解决方法，搜索一下 Boyer-Moore Majority Vote 算法吧。
## 其它
 - [ ]  367\. Valid Perfect Square (Easy)
 - [ ]  326\. Power of Three (Easy)
 - [ ]  238\. Product of Array Except Self (Medium)
 - [ ]  628\. Maximum Product of Three Numbers (Easy)
 - [ ]  384\. Shuffle an Array (Medium)
 - [ ]  528\. Random Pick with Weight (Medium)
 - [ ]  382\. Linked List Random Node (Medium)
 - [ ]  5\.   Implement Rand10() Using Rand7() (Medium) 如何用一个随机数生成器生成另一个随机数生成器？你可能需要利用原来的生成器多次。
 - [ ]  6\.   Happy Number (Easy) 你可以简单的用一个 while 循环解决这道题，但是有没有更好的解决办法？如果我们把每个数字想象成一个节点，是否可以转化为环路检测？
# 位运算
 - [x]  1\.   **Hamming Distance (Easy)**
 - [x]  136\. Single Number (Easy)
 - [x]  268\. Missing Number (Easy)
 - [x]  260\. Single Number III (Medium)
 - [x]  190\. Reverse Bits (Easy)
 - [x]  231\. Power of Two (Easy)
 - [x]  342\. Power of Four (Easy)
 - [x]  693\. **Binary Number with Alternating Bits (Easy)**
 - [x]  476\. **Number Complement (Easy)**
 - [x]  371\. **Sum of Two Integers (Easy)**
 - [x]  318\. **Maximum Product of Word Lengths (Medium)**
 - [x]  338\. **Counting Bits (Medium)**
# 数组与矩阵
 - [x]  283\. **Move Zeroes (Easy)**
 - [x]  566\. Reshape the Matrix (Easy)
 - [x]  485\. Max Consecutive Ones (Easy)
 - [x]  240\. **Search a 2D Matrix II (Medium)**
 - [ ]  378\. Kth Smallest Element in a Sorted Matrix ((Medium))
 - [x]  645\. **Set Mismatch (Easy)**
 - [ ]  667\. Beautiful Arrangement II (Medium)
 - [x]  766\. **Toeplitz Matrix (Easy)**
 - [ ]  565\. Array Nesting (Medium)
 - [ ]  769\. Max Chunks To Make Sorted (Medium)
 - [x]  448\. **Find All Numbers Disappeared in an Array (Easy)**
 - [x]  48\. Rotate Image (Medium)
## 桶排序
 - [x]  215\. **Kth Largest Element in an Array**
## 荷兰国旗问题
 - [x]  75\. **Sort Colors (Medium)**
## 快速选择
 - [x]  347\.**Top K Frequent Elements (Medium)**
 - [x]  451\. **Sort Characters By Frequency (Medium)**
# 动态规划
## 斐波那契数列
 - [x]  70\. **Climbing Stairs (Easy)**
 - [x]  198\. **House Robber (Easy)**
 - [x] 213\. **House Robber II (Medium)**
 - [ ]  542\. 01 Matrix (Medium)
 - [x]  221\. **Maximal Square (Medium)**
 - [x]  53\. **Maximum Subarray (Easy) 经典的一维动态规划题目，试着把一维空间优化为常量吧。**
 - [x]  343\. **Integer Break (Medium) 分割类型题，先尝试用动态规划求解，再思考是否有更简单的解法。**
 - [ ]  583\. Delete Operation for Two Strings (Medium) 最长公共子序列的变种题。
 - [x]  646\. Maximum Length of Pair Chain (Medium) 最长递增子序列的变种题，同样的，尝试用二分进行加速。
 - [ ]  376\. Wiggle Subsequence (Medium) 最长摆动子序列，通项公式比较特殊，需要仔细思考。
## 矩阵路径
 - [ ]  64\. Minimum Path Sum (Medium)
 - [x]  62\. **Unique Paths (Medium)**
## 数组区间
 - [ ]  303\. Range Sum Query - Immutable (Easy)
 - [ ]  413\. Arithmetic Slices (Medium)
## 分割整数
 - [ ]  279\. Perfect Squares(Medium)
 - [ ]  91\. Decode Ways (Medium)
## 最长递增子序列
 - [ ]  300\. Longest Increasing Subsequence (Medium)
 - [ ]  376\. Wiggle Subsequence (Medium)
## 最长公共子序列
 - [x]  1143\. **Longest Common Subsequence**
 - [ ]  416\. Partition Equal Subset Sum (Medium)
 - [ ]  494\. Target Sum (Medium)
 - [ ]  474\. Ones and Zeroes (Medium)
 - [ ]  322\. Coin Change (Medium)
 - [ ]  518\. Coin Change 2 (Medium)
 - [ ]  139\. Word Break (Medium)
 - [ ]  377\. Combination Sum IV (Medium)
## 股票交易
 - [ ]  309\. Best Time to Buy and Sell Stock with Cooldown(Medium)
 - [ ]  714\. Best Time to Buy and Sell Stock with Transaction Fee (Medium)
 - [ ]  123\. Best Time to Buy and Sell Stock III (Hard)
 - [ ]  188\. Best Time to Buy and Sell Stock IV (Hard) Goolge
## 字符串编辑
 - [ ]  72\. Edit Distance (Hard)
 - [ ]  650\. 2 Keys Keyboard (Medium)
 - [ ]  10\. Regular Expression Matching (Hard)
