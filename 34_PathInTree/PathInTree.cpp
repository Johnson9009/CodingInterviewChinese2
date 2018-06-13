/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者: 何海涛
//==================================================================

// 面试题34: 二叉树中和为某一值的路径
// 题目: 输入一棵二叉树和一个整数, 打印出二叉树中结点值的和为输入整数的所有路径. 从树的根结点开始往
// 下一直到叶结点所经过的结点形成一条路径.

#include <cstdio>
#include <stdexcept>
#include <vector>
#include "../Utilities/BinaryTree.h"

void FindPathCore(BinaryTreeNode const* root, int target, std::vector<int>* node_path) {
  if ((root == nullptr) || (node_path == nullptr)) throw std::invalid_argument("");
  node_path->push_back(root->m_nValue);
  if ((root->m_pLeft == nullptr) && (root->m_pRight == nullptr)) {
    int sum = 0;
    for (auto const& value : *node_path) sum += value;
    if (sum == target) {
      for (auto const& value : *node_path) printf("%d ", value);
      printf("\n");
    }
  }
  if (root->m_pLeft != nullptr) FindPathCore(root->m_pLeft, target, node_path);
  if (root->m_pRight != nullptr) FindPathCore(root->m_pRight, target, node_path);
  node_path->pop_back();
}

void FindPath(BinaryTreeNode const* root, int target) {
  if (root == nullptr) throw std::invalid_argument("");
  std::vector<int> node_path;
  FindPathCore(root, target, &node_path);
  return;
}

// ====================测试代码====================
void Test(char const* testName, BinaryTreeNode* pRoot, int expectedSum) {
  if (testName != nullptr) printf("%s begins:\n", testName);
  try {
    FindPath(pRoot, expectedSum);
  } catch (std::invalid_argument const& ia) {
    if (expectedSum == 0) {
      printf("Passed!\n");
    } else {
      printf("Failed!\n");
    }
  }
  printf("\n");
}

//          10
//         /  \
//        5   12
//       / \
//      4   7
// 有两条路径上的结点和为22
void Test1() {
  BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
  BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

  ConnectTreeNodes(pNode10, pNode5, pNode12);
  ConnectTreeNodes(pNode5, pNode4, pNode7);

  printf("Two paths should be found in Test1.\n");
  Test("Test1", pNode10, 22);

  DestroyTree(pNode10);
}

//          10
//         /  \
//        5   12
//       / \
//      4   7
// 没有路径上的结点和为15
void Test2() {
  BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
  BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

  ConnectTreeNodes(pNode10, pNode5, pNode12);
  ConnectTreeNodes(pNode5, pNode4, pNode7);

  printf("No paths should be found in Test2.\n");
  Test("Test2", pNode10, 15);

  DestroyTree(pNode10);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
// 有一条路径上面的结点和为15
void Test3() {
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

  ConnectTreeNodes(pNode5, pNode4, nullptr);
  ConnectTreeNodes(pNode4, pNode3, nullptr);
  ConnectTreeNodes(pNode3, pNode2, nullptr);
  ConnectTreeNodes(pNode2, pNode1, nullptr);

  printf("One path should be found in Test3.\n");
  Test("Test3", pNode5, 15);

  DestroyTree(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
// 没有路径上面的结点和为16
void Test4() {
  BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
  BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

  ConnectTreeNodes(pNode1, nullptr, pNode2);
  ConnectTreeNodes(pNode2, nullptr, pNode3);
  ConnectTreeNodes(pNode3, nullptr, pNode4);
  ConnectTreeNodes(pNode4, nullptr, pNode5);

  printf("No paths should be found in Test4.\n");
  Test("Test4", pNode1, 16);

  DestroyTree(pNode1);
}

// 树中只有1个结点
void Test5() {
  BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

  printf("One path should be found in Test5.\n");
  Test("Test5", pNode1, 1);

  DestroyTree(pNode1);
}

// 树中没有结点
void Test6() {
  printf("No paths should be found in Test6.\n");
  Test("Test6", nullptr, 0);
}

int main(int argc, char* argv[]) {
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();
  Test6();

  return 0;
}
