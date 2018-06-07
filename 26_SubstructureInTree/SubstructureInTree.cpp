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

// 面试题26: 树的子结构
// 题目: 输入两棵二叉树A和B, 判断B是不是A的子结构.

#include <cstdio>

struct BinaryTreeNode {
  double value;
  BinaryTreeNode* left;
  BinaryTreeNode* right;
};

bool IsEqual(double a, double b) {
  if (((a - b) > -1e-7) && ((a - b) < 1e-7)) return true;
  return false;
}

bool IsSameTree(BinaryTreeNode const* root1, BinaryTreeNode const* root2) {
  if (root2 == nullptr) return true;
  if (root1 == nullptr) return false;

  if ((IsEqual(root1->value, root2->value) == true) &&
      (IsSameTree(root1->left, root2->left) == true) &&
      (IsSameTree(root1->right, root2->right) == true)) {
    return true;
  }
  return false;
}

bool HasSubTree(BinaryTreeNode const* root1, BinaryTreeNode const* root2) {
  if (root2 == nullptr) return true;
  if (root1 == nullptr) return false;

  if (IsSameTree(root1, root2) == true) return true;

  return (HasSubTree(root1->left, root2) || HasSubTree(root1->right, root2));
}

// ====================辅助测试代码====================
BinaryTreeNode* CreateBinaryTreeNode(double dbValue) {
  BinaryTreeNode* pNode = new BinaryTreeNode();
  pNode->value = dbValue;
  pNode->left = nullptr;
  pNode->right = nullptr;

  return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
  if (pParent != nullptr) {
    pParent->left = pLeft;
    pParent->right = pRight;
  }
}

void DestroyTree(BinaryTreeNode* pRoot) {
  if (pRoot != nullptr) {
    BinaryTreeNode* pLeft = pRoot->left;
    BinaryTreeNode* pRight = pRoot->right;

    delete pRoot;
    pRoot = nullptr;

    DestroyTree(pLeft);
    DestroyTree(pRight);
  }
}

// ====================测试代码====================
void Test(char const* testName, BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2, bool expected) {
  if (HasSubTree(pRoot1, pRoot2) == expected)
    printf("%s passed.\n", testName);
  else
    printf("%s failed.\n", testName);
}

// 树中结点含有分叉，树B是树A的子结构
//              8             8
//             / \           / \
//            8   7         9   2
//           / \
//          9   2
//             / \
//            4   7
void Test1() {
  BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
  BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

  ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
  ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
  ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

  BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

  ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

  Test("Test1", pNodeA1, pNodeB1, true);

  DestroyTree(pNodeA1);
  DestroyTree(pNodeB1);
}

// 树中结点含有分叉，树B不是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
void Test2() {
  BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
  BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

  ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
  ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
  ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

  BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

  ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

  Test("Test2", pNodeA1, pNodeB1, false);

  DestroyTree(pNodeA1);
  DestroyTree(pNodeB1);
}

// 树中结点只有左子结点，树B是树A的子结构
//                8                  8
//              /                   /
//             8                   9
//           /                    /
//          9                    2
//         /
//        2
//       /
//      5
void Test3() {
  BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

  ConnectTreeNodes(pNodeA1, pNodeA2, nullptr);
  ConnectTreeNodes(pNodeA2, pNodeA3, nullptr);
  ConnectTreeNodes(pNodeA3, pNodeA4, nullptr);
  ConnectTreeNodes(pNodeA4, pNodeA5, nullptr);

  BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

  ConnectTreeNodes(pNodeB1, pNodeB2, nullptr);
  ConnectTreeNodes(pNodeB2, pNodeB3, nullptr);

  Test("Test3", pNodeA1, pNodeB1, true);

  DestroyTree(pNodeA1);
  DestroyTree(pNodeB1);
}

// 树中结点只有左子结点，树B不是树A的子结构
//                8                  8
//              /                   /
//             8                   9
//           /                    /
//          9                    3
//         /
//        2
//       /
//      5
void Test4() {
  BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

  ConnectTreeNodes(pNodeA1, pNodeA2, nullptr);
  ConnectTreeNodes(pNodeA2, pNodeA3, nullptr);
  ConnectTreeNodes(pNodeA3, pNodeA4, nullptr);
  ConnectTreeNodes(pNodeA4, pNodeA5, nullptr);

  BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);

  ConnectTreeNodes(pNodeB1, pNodeB2, nullptr);
  ConnectTreeNodes(pNodeB2, pNodeB3, nullptr);

  Test("Test4", pNodeA1, pNodeB1, false);

  DestroyTree(pNodeA1);
  DestroyTree(pNodeB1);
}

// 树中结点只有右子结点，树B是树A的子结构
//       8                   8
//        \                   \
//         8                   9
//          \                   \
//           9                   2
//            \
//             2
//              \
//               5
void Test5() {
  BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

  ConnectTreeNodes(pNodeA1, nullptr, pNodeA2);
  ConnectTreeNodes(pNodeA2, nullptr, pNodeA3);
  ConnectTreeNodes(pNodeA3, nullptr, pNodeA4);
  ConnectTreeNodes(pNodeA4, nullptr, pNodeA5);

  BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

  ConnectTreeNodes(pNodeB1, nullptr, pNodeB2);
  ConnectTreeNodes(pNodeB2, nullptr, pNodeB3);

  Test("Test5", pNodeA1, pNodeB1, true);

  DestroyTree(pNodeA1);
  DestroyTree(pNodeB1);
}

// 树A中结点只有右子结点，树B不是树A的子结构
//       8                   8
//        \                   \
//         8                   9
//          \                 / \
//           9               3   2
//            \
//             2
//              \
//               5
void Test6() {
  BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

  ConnectTreeNodes(pNodeA1, nullptr, pNodeA2);
  ConnectTreeNodes(pNodeA2, nullptr, pNodeA3);
  ConnectTreeNodes(pNodeA3, nullptr, pNodeA4);
  ConnectTreeNodes(pNodeA4, nullptr, pNodeA5);

  BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNodeB4 = CreateBinaryTreeNode(2);

  ConnectTreeNodes(pNodeB1, nullptr, pNodeB2);
  ConnectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

  Test("Test6", pNodeA1, pNodeB1, false);

  DestroyTree(pNodeA1);
  DestroyTree(pNodeB1);
}

// 树A为空树
void Test7() {
  BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNodeB4 = CreateBinaryTreeNode(2);

  ConnectTreeNodes(pNodeB1, nullptr, pNodeB2);
  ConnectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

  Test("Test7", nullptr, pNodeB1, false);

  DestroyTree(pNodeB1);
}

// 树B为空树
void Test8() {
  BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);

  ConnectTreeNodes(pNodeA1, nullptr, pNodeA2);
  ConnectTreeNodes(pNodeA2, pNodeA3, pNodeA4);

  Test("Test8", pNodeA1, nullptr, true);

  DestroyTree(pNodeA1);
}

// 树A和树B都为空
void Test9() {
  Test("Test9", nullptr, nullptr, true);
}

int main(int argc, char* argv[]) {
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();
  Test6();
  Test7();
  Test8();
  Test9();

  return 0;
}
