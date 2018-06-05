/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer――名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

#include <cstdio>
#include <stack>
#include "../Utilities/List.h"

void PrintListReversingly_Iteratively(ListNode const* head) {
  if (head == nullptr) return;

  std::stack<ListNode const*> nodes;
  ListNode const* node = head;
  while (node != nullptr) {
    nodes.push(node);
    node = node->m_pNext;
  }
  while (nodes.empty() == false) {
    printf("%d\t", nodes.top()->m_nValue);
    nodes.pop();
  }
  return;
}

void PrintListReversingly_Recursively(ListNode const* head) {
  if (head == nullptr) return;
  if (head->m_pNext != nullptr) PrintListReversingly_Recursively(head->m_pNext);
  printf("%d\t", head->m_nValue);
}

// ====================测试代码====================
void Test(ListNode* pHead) {
  PrintList(pHead);
  PrintListReversingly_Iteratively(pHead);
  printf("\n");
  PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void Test1() {
  printf("\nTest1 begins.\n");

  ListNode* pNode1 = CreateListNode(1);
  ListNode* pNode2 = CreateListNode(2);
  ListNode* pNode3 = CreateListNode(3);
  ListNode* pNode4 = CreateListNode(4);
  ListNode* pNode5 = CreateListNode(5);

  ConnectListNodes(pNode1, pNode2);
  ConnectListNodes(pNode2, pNode3);
  ConnectListNodes(pNode3, pNode4);
  ConnectListNodes(pNode4, pNode5);

  Test(pNode1);

  DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2() {
  printf("\nTest2 begins.\n");

  ListNode* pNode1 = CreateListNode(1);

  Test(pNode1);

  DestroyList(pNode1);
}

// 空链表
void Test3() {
  printf("\nTest3 begins.\n");

  Test(nullptr);
}

int main(int argc, char* argv[]) {
  Test1();
  Test2();
  Test3();

  return 0;
}
