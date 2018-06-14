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

// 面试题52: 两个链表的第一个公共结点
// 题目: 输入两个链表, 找出它们的第一个公共结点.

#include <cstdio>
#include <stdexcept>
#include "../Utilities/List.h"

int GetListLength(ListNode const* head) {
  ListNode const* node = head;
  int length = 0;
  while (node != nullptr) {
    ++length;
    node = node->m_pNext;
  }
  return length;
}

ListNode* FindFirstCommonNode(ListNode* head1, ListNode* head2) {
  if ((head1 == nullptr) || (head2 == nullptr)) throw std::invalid_argument("");

  int length1 = GetListLength(head1);
  int length2 = GetListLength(head2);
  ListNode* long_list_node = head1;
  ListNode* short_list_node = head2;
  if (length2 > length1) {
    long_list_node = head2;
    short_list_node = head1;
  }

  for (int i = 0; i < std::abs(length2 - length1); ++i) {
    long_list_node = long_list_node->m_pNext;
  }

  while (long_list_node != nullptr) {
    if (long_list_node == short_list_node) return long_list_node;
    long_list_node = long_list_node->m_pNext;
    short_list_node = short_list_node->m_pNext;
  }
  throw std::invalid_argument("");
}

// ====================测试代码====================
void DestroyNode(ListNode* pNode);

void Test(char const* testName, ListNode* pHead1, ListNode* pHead2, ListNode* pExpected) {
  if (testName != nullptr) printf("%s begins: ", testName);
  try {
    ListNode* pResult = FindFirstCommonNode(pHead1, pHead2);
    if (pResult == pExpected)
      printf("Passed.\n");
    else
      printf("Failed.\n");
  } catch (std::invalid_argument const& ia) {
    if (pExpected == nullptr) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
  }
}

// 第一个公共结点在链表中间
// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
void Test1() {
  ListNode* pNode1 = CreateListNode(1);
  ListNode* pNode2 = CreateListNode(2);
  ListNode* pNode3 = CreateListNode(3);
  ListNode* pNode4 = CreateListNode(4);
  ListNode* pNode5 = CreateListNode(5);
  ListNode* pNode6 = CreateListNode(6);
  ListNode* pNode7 = CreateListNode(7);

  ConnectListNodes(pNode1, pNode2);
  ConnectListNodes(pNode2, pNode3);
  ConnectListNodes(pNode3, pNode6);
  ConnectListNodes(pNode4, pNode5);
  ConnectListNodes(pNode5, pNode6);
  ConnectListNodes(pNode6, pNode7);

  Test("Test1", pNode1, pNode4, pNode6);

  DestroyNode(pNode1);
  DestroyNode(pNode2);
  DestroyNode(pNode3);
  DestroyNode(pNode4);
  DestroyNode(pNode5);
  DestroyNode(pNode6);
  DestroyNode(pNode7);
}

// 没有公共结点
// 1 - 2 - 3 - 4
//
// 5 - 6 - 7
void Test2() {
  ListNode* pNode1 = CreateListNode(1);
  ListNode* pNode2 = CreateListNode(2);
  ListNode* pNode3 = CreateListNode(3);
  ListNode* pNode4 = CreateListNode(4);
  ListNode* pNode5 = CreateListNode(5);
  ListNode* pNode6 = CreateListNode(6);
  ListNode* pNode7 = CreateListNode(7);

  ConnectListNodes(pNode1, pNode2);
  ConnectListNodes(pNode2, pNode3);
  ConnectListNodes(pNode3, pNode4);
  ConnectListNodes(pNode5, pNode6);
  ConnectListNodes(pNode6, pNode7);

  Test("Test2", pNode1, pNode5, nullptr);

  DestroyList(pNode1);
  DestroyList(pNode5);
}

// 公共结点是最后一个结点
// 1 - 2 - 3 - 4 \
//                7
//         5 - 6 /
void Test3() {
  ListNode* pNode1 = CreateListNode(1);
  ListNode* pNode2 = CreateListNode(2);
  ListNode* pNode3 = CreateListNode(3);
  ListNode* pNode4 = CreateListNode(4);
  ListNode* pNode5 = CreateListNode(5);
  ListNode* pNode6 = CreateListNode(6);
  ListNode* pNode7 = CreateListNode(7);

  ConnectListNodes(pNode1, pNode2);
  ConnectListNodes(pNode2, pNode3);
  ConnectListNodes(pNode3, pNode4);
  ConnectListNodes(pNode4, pNode7);
  ConnectListNodes(pNode5, pNode6);
  ConnectListNodes(pNode6, pNode7);

  Test("Test3", pNode1, pNode5, pNode7);

  DestroyNode(pNode1);
  DestroyNode(pNode2);
  DestroyNode(pNode3);
  DestroyNode(pNode4);
  DestroyNode(pNode5);
  DestroyNode(pNode6);
  DestroyNode(pNode7);
}

// 公共结点是第一个结点
// 1 - 2 - 3 - 4 - 5
// 两个链表完全重合
void Test4() {
  ListNode* pNode1 = CreateListNode(1);
  ListNode* pNode2 = CreateListNode(2);
  ListNode* pNode3 = CreateListNode(3);
  ListNode* pNode4 = CreateListNode(4);
  ListNode* pNode5 = CreateListNode(5);

  ConnectListNodes(pNode1, pNode2);
  ConnectListNodes(pNode2, pNode3);
  ConnectListNodes(pNode3, pNode4);
  ConnectListNodes(pNode4, pNode5);

  Test("Test4", pNode1, pNode1, pNode1);

  DestroyList(pNode1);
}

// 输入的两个链表有一个空链表
void Test5() {
  ListNode* pNode1 = CreateListNode(1);
  ListNode* pNode2 = CreateListNode(2);
  ListNode* pNode3 = CreateListNode(3);
  ListNode* pNode4 = CreateListNode(4);
  ListNode* pNode5 = CreateListNode(5);

  ConnectListNodes(pNode1, pNode2);
  ConnectListNodes(pNode2, pNode3);
  ConnectListNodes(pNode3, pNode4);
  ConnectListNodes(pNode4, pNode5);

  Test("Test5", nullptr, pNode1, nullptr);

  DestroyList(pNode1);
}

// 输入的两个链表有一个空链表
void Test6() {
  Test("Test6", nullptr, nullptr, nullptr);
}

void DestroyNode(ListNode* pNode) {
  delete pNode;
  pNode = nullptr;
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
