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

// 面试题68: 树中两个结点的最低公共祖先
// 题目: 输入两个树结点, 求它们的最低公共祖先.

#include <cstdio>
#include <list>
#include <stdexcept>
#include "../Utilities/Tree.h"

bool GetPath(TreeNode const* root, TreeNode const* node, std::vector<TreeNode const*>* path) {
  if ((root == nullptr) || (node == nullptr) || (path == nullptr)) {
    throw std::invalid_argument("");
  }
  // Don't push the target node in the path.
  if (root == node) return true;
  path->push_back(root);
  if (root->m_vChildren.empty() == false) {
    for (auto const& child : root->m_vChildren) {
      // If the node is found, just return, note that the path must not be pop out.
      if (GetPath(child, node, path) == true) return true;
    }
  }
  path->pop_back();
  return false;
}

TreeNode const* GetLastCommonParent(TreeNode const* root, TreeNode const* node1,
                                    TreeNode const* node2) {
  if ((root == nullptr) || (node1 == nullptr) || (node2 == nullptr)) {
    throw std::invalid_argument("");
  }
  std::vector<TreeNode const*> node1_path;
  std::vector<TreeNode const*> node2_path;
  if ((GetPath(root, node1, &node1_path) == false) ||
      (GetPath(root, node2, &node2_path) == false)) {
    throw std::invalid_argument("");
  }
  // Must have common parent, so just forward to the first different node and return the previous
  // one.
  auto node1_iter = node1_path.begin();
  auto node2_iter = node2_path.begin();
  while ((node1_iter != node1_path.end()) && (node2_iter != node2_path.end()) &&
         (*node1_iter == *node2_iter)) {
    ++node1_iter;
    ++node2_iter;
  }
  return *(node1_iter - 1);
}

// ====================测试代码====================
void Test(const char* testName, const TreeNode* pRoot, const TreeNode* pNode1,
          const TreeNode* pNode2, TreeNode* pExpected) {
  if (testName != nullptr) printf("%s begins: ", testName);
  try {
    const TreeNode* pResult = GetLastCommonParent(pRoot, pNode1, pNode2);
    if (pResult->m_nValue == pExpected->m_nValue) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
  } catch (std::invalid_argument const& ia) {
    if (pExpected == nullptr) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
  }
}

// 形状普通的树
//             1
//           /   \
//          2     3
//       /     \
//      4       5
//     / \    / | \
//    6   7  8  9  10
void Test1() {
  TreeNode* pNode1 = CreateTreeNode(1);
  TreeNode* pNode2 = CreateTreeNode(2);
  TreeNode* pNode3 = CreateTreeNode(3);
  TreeNode* pNode4 = CreateTreeNode(4);
  TreeNode* pNode5 = CreateTreeNode(5);
  TreeNode* pNode6 = CreateTreeNode(6);
  TreeNode* pNode7 = CreateTreeNode(7);
  TreeNode* pNode8 = CreateTreeNode(8);
  TreeNode* pNode9 = CreateTreeNode(9);
  TreeNode* pNode10 = CreateTreeNode(10);

  ConnectTreeNodes(pNode1, pNode2);
  ConnectTreeNodes(pNode1, pNode3);

  ConnectTreeNodes(pNode2, pNode4);
  ConnectTreeNodes(pNode2, pNode5);

  ConnectTreeNodes(pNode4, pNode6);
  ConnectTreeNodes(pNode4, pNode7);

  ConnectTreeNodes(pNode5, pNode8);
  ConnectTreeNodes(pNode5, pNode9);
  ConnectTreeNodes(pNode5, pNode10);

  Test("Test1", pNode1, pNode6, pNode8, pNode2);
}

// 树退化成一个链表
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test2() {
  TreeNode* pNode1 = CreateTreeNode(1);
  TreeNode* pNode2 = CreateTreeNode(2);
  TreeNode* pNode3 = CreateTreeNode(3);
  TreeNode* pNode4 = CreateTreeNode(4);
  TreeNode* pNode5 = CreateTreeNode(5);

  ConnectTreeNodes(pNode1, pNode2);
  ConnectTreeNodes(pNode2, pNode3);
  ConnectTreeNodes(pNode3, pNode4);
  ConnectTreeNodes(pNode4, pNode5);

  Test("Test2", pNode1, pNode5, pNode4, pNode3);
}

// 树退化成一个链表，一个结点不在树中
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test3() {
  TreeNode* pNode1 = CreateTreeNode(1);
  TreeNode* pNode2 = CreateTreeNode(2);
  TreeNode* pNode3 = CreateTreeNode(3);
  TreeNode* pNode4 = CreateTreeNode(4);
  TreeNode* pNode5 = CreateTreeNode(5);

  ConnectTreeNodes(pNode1, pNode2);
  ConnectTreeNodes(pNode2, pNode3);
  ConnectTreeNodes(pNode3, pNode4);
  ConnectTreeNodes(pNode4, pNode5);

  TreeNode* pNode6 = CreateTreeNode(6);

  Test("Test3", pNode1, pNode5, pNode6, nullptr);
}

// 输入nullptr
void Test4() {
  Test("Test4", nullptr, nullptr, nullptr, nullptr);
}

int main(int argc, char* argv[]) {
  Test1();
  Test2();
  Test3();
  Test4();

  return 0;
}
