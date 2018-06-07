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

// 面试题27: 二叉树的镜像
// 题目: 请完成一个函数, 输入一个二叉树, 该函数输出它的镜像.

#include <cstdio>
#include <stack>
#include "../Utilities/BinaryTree.h"

void MirrorRecursively(BinaryTreeNode* root) {
  if ((root == nullptr) || ((root->m_pLeft == nullptr) && (root->m_pRight == nullptr))) return;
  BinaryTreeNode* tmp = root->m_pLeft;
  root->m_pLeft = root->m_pRight;
  root->m_pRight = tmp;
  if ((root->m_pLeft != nullptr) &&
      ((root->m_pLeft->m_pLeft != nullptr) || (root->m_pLeft->m_pRight != nullptr))) {
    MirrorRecursively(root->m_pLeft);
  }
  if ((root->m_pRight != nullptr) &&
      ((root->m_pRight->m_pLeft != nullptr) || (root->m_pRight->m_pRight != nullptr))) {
    MirrorRecursively(root->m_pRight);
  }
  return;
}

void MirrorIteratively(BinaryTreeNode* root) {
  if ((root == nullptr) || ((root->m_pLeft == nullptr) && (root->m_pRight == nullptr))) return;
  std::stack<BinaryTreeNode*> nodes;
  nodes.push(root);
  while (nodes.empty() == false) {
    BinaryTreeNode* node = nodes.top();
    nodes.pop();
    BinaryTreeNode* tmp = node->m_pLeft;
    node->m_pLeft = node->m_pRight;
    node->m_pRight = tmp;
    if ((node->m_pLeft != nullptr) &&
        ((node->m_pLeft->m_pLeft != nullptr) || (node->m_pLeft->m_pRight != nullptr))) {
      nodes.push(node->m_pLeft);
    }
    if ((node->m_pRight != nullptr) &&
        ((node->m_pRight->m_pLeft != nullptr) || (node->m_pRight->m_pRight != nullptr))) {
      nodes.push(node->m_pRight);
    }
  }
  return;
}

// ====================测试代码====================
// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      10
//       5 7    9  11
void Test1() {
  printf("=====Test1 starts:=====\n");
  BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
  BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
  BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
  BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
  BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

  ConnectTreeNodes(pNode8, pNode6, pNode10);
  ConnectTreeNodes(pNode6, pNode5, pNode7);
  ConnectTreeNodes(pNode10, pNode9, pNode11);

  PrintTree(pNode8);

  printf("=====Test1: MirrorRecursively=====\n");
  MirrorRecursively(pNode8);
  PrintTree(pNode8);

  printf("=====Test1: MirrorIteratively=====\n");
  MirrorIteratively(pNode8);
  PrintTree(pNode8);

  DestroyTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个左子结点
//            8
//          7
//        6
//      5
//    4
void Test2() {
  printf("=====Test2 starts:=====\n");
  BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
  BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

  ConnectTreeNodes(pNode8, pNode7, nullptr);
  ConnectTreeNodes(pNode7, pNode6, nullptr);
  ConnectTreeNodes(pNode6, pNode5, nullptr);
  ConnectTreeNodes(pNode5, pNode4, nullptr);

  PrintTree(pNode8);

  printf("=====Test2: MirrorRecursively=====\n");
  MirrorRecursively(pNode8);
  PrintTree(pNode8);

  printf("=====Test2: MirrorIteratively=====\n");
  MirrorIteratively(pNode8);
  PrintTree(pNode8);

  DestroyTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个右子结点
//            8
//             7
//              6
//               5
//                4
void Test3() {
  printf("=====Test3 starts:=====\n");
  BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
  BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
  BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

  ConnectTreeNodes(pNode8, nullptr, pNode7);
  ConnectTreeNodes(pNode7, nullptr, pNode6);
  ConnectTreeNodes(pNode6, nullptr, pNode5);
  ConnectTreeNodes(pNode5, nullptr, pNode4);

  PrintTree(pNode8);

  printf("=====Test3: MirrorRecursively=====\n");
  MirrorRecursively(pNode8);
  PrintTree(pNode8);

  printf("=====Test3: MirrorIteratively=====\n");
  MirrorIteratively(pNode8);
  PrintTree(pNode8);

  DestroyTree(pNode8);
}

// 测试空二叉树：根结点为空指针
void Test4() {
  printf("=====Test4 starts:=====\n");
  BinaryTreeNode* pNode = nullptr;

  PrintTree(pNode);

  printf("=====Test4: MirrorRecursively=====\n");
  MirrorRecursively(pNode);
  PrintTree(pNode);

  printf("=====Test4: MirrorIteratively=====\n");
  MirrorIteratively(pNode);
  PrintTree(pNode);
}

// 测试只有一个结点的二叉树
void Test5() {
  printf("=====Test5 starts:=====\n");
  BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

  PrintTree(pNode8);

  printf("=====Test4: MirrorRecursively=====\n");
  MirrorRecursively(pNode8);
  PrintTree(pNode8);

  printf("=====Test4: MirrorIteratively=====\n");
  MirrorIteratively(pNode8);
  PrintTree(pNode8);
}

int main(int argc, char* argv[]) {
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();

  return 0;
}
