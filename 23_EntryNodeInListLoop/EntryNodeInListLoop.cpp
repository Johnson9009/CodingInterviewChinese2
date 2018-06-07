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

// 面试题23: 链表中环的入口结点
// 题目: 一个链表中包含环, 如何找出环的入口结点? 例如, 在图3.8的链表中, 环的入口结点是结点3.

#include <cstdio>
#include <stdexcept>
#include "../Utilities/List.h"

ListNode* EntryNodeOfLoop(ListNode* head) {
  if (head == nullptr) throw std::invalid_argument("");
  ListNode const* fast = head->m_pNext;
  ListNode const* slow = head;
  while ((fast != nullptr) && (fast->m_pNext != nullptr) && (fast != slow)) {
    fast = fast->m_pNext->m_pNext;
    slow = slow->m_pNext;
  }
  if ((fast == nullptr) || (fast->m_pNext == nullptr)) throw std::invalid_argument("");
  int loop_length = 1;
  ListNode const* node = fast->m_pNext;
  while (node != fast) {
    ++loop_length;
    node = node->m_pNext;
  }
  ListNode* ahead = head;
  ListNode* behind = head;
  for (int i = 0; i < loop_length; ++i) {
    ahead = ahead->m_pNext;
  }
  while (ahead != behind) {
    ahead = ahead->m_pNext;
    behind = behind->m_pNext;
  }
  return ahead;
}

// ==================== Test Code ====================
void Test(char const* testName, ListNode* pHead, ListNode* entryNode) {
  if (testName != nullptr) printf("%s begins: ", testName);
  try {
    if (EntryNodeOfLoop(pHead) == entryNode) {
      printf("Passed.\n");
    } else {
      printf("FAILED.\n");
    }
  } catch (std::invalid_argument const& ia) {
    if (entryNode == nullptr) {
      printf("Passed.\n");
    } else {
      printf("FAILED.\n");
    }
  }
}

// A list has a node, without a loop
void Test1() {
  ListNode* pNode1 = CreateListNode(1);

  Test("Test1", pNode1, nullptr);

  DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2() {
  ListNode* pNode1 = CreateListNode(1);
  ConnectListNodes(pNode1, pNode1);

  Test("Test2", pNode1, pNode1);

  delete pNode1;
  pNode1 = nullptr;
}

// A list has multiple nodes, with a loop
void Test3() {
  ListNode* pNode1 = CreateListNode(1);
  ListNode* pNode2 = CreateListNode(2);
  ListNode* pNode3 = CreateListNode(3);
  ListNode* pNode4 = CreateListNode(4);
  ListNode* pNode5 = CreateListNode(5);

  ConnectListNodes(pNode1, pNode2);
  ConnectListNodes(pNode2, pNode3);
  ConnectListNodes(pNode3, pNode4);
  ConnectListNodes(pNode4, pNode5);
  ConnectListNodes(pNode5, pNode3);

  Test("Test3", pNode1, pNode3);

  delete pNode1;
  pNode1 = nullptr;
  delete pNode2;
  pNode2 = nullptr;
  delete pNode3;
  pNode3 = nullptr;
  delete pNode4;
  pNode4 = nullptr;
  delete pNode5;
  pNode5 = nullptr;
}

// A list has multiple nodes, with a loop
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
  ConnectListNodes(pNode5, pNode1);

  Test("Test4", pNode1, pNode1);

  delete pNode1;
  pNode1 = nullptr;
  delete pNode2;
  pNode2 = nullptr;
  delete pNode3;
  pNode3 = nullptr;
  delete pNode4;
  pNode4 = nullptr;
  delete pNode5;
  pNode5 = nullptr;
}

// A list has multiple nodes, with a loop
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
  ConnectListNodes(pNode5, pNode5);

  Test("Test5", pNode1, pNode5);

  delete pNode1;
  pNode1 = nullptr;
  delete pNode2;
  pNode2 = nullptr;
  delete pNode3;
  pNode3 = nullptr;
  delete pNode4;
  pNode4 = nullptr;
  delete pNode5;
  pNode5 = nullptr;
}

// A list has multiple nodes, without a loop
void Test6() {
  ListNode* pNode1 = CreateListNode(1);
  ListNode* pNode2 = CreateListNode(2);
  ListNode* pNode3 = CreateListNode(3);
  ListNode* pNode4 = CreateListNode(4);
  ListNode* pNode5 = CreateListNode(5);

  ConnectListNodes(pNode1, pNode2);
  ConnectListNodes(pNode2, pNode3);
  ConnectListNodes(pNode3, pNode4);
  ConnectListNodes(pNode4, pNode5);

  Test("Test6", pNode1, nullptr);

  DestroyList(pNode1);
}

// Empty list
void Test7() {
  Test("Test7", nullptr, nullptr);
}

int main(int argc, char* argv[]) {
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();
  Test6();
  Test7();

  return 0;
}
