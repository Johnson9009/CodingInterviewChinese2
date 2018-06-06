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

// 面试题18(一): 在O(1)时间删除链表结点
// 题目: 给定单向链表的头指针和一个结点指针, 定义一个函数在O(1)时间删除该结点.

#include <cstdio>
#include <stdexcept>
#include "../Utilities/List.h"

void DeleteNode(ListNode** head, ListNode* delete_node) {
  if ((head == nullptr) || (*head == nullptr) || (delete_node == nullptr)) {
    throw std::invalid_argument("");
  }

  if (delete_node->m_pNext == nullptr) {
    if (*head == delete_node) {
      *head = nullptr;
      delete delete_node;
      delete_node = nullptr;
      return;
    }
    ListNode* node = *head;
    while (node->m_pNext != delete_node) {
      node = node->m_pNext;
      if (node == nullptr) throw std::invalid_argument("");
    }
    node->m_pNext = nullptr;
    delete delete_node;
    delete_node = nullptr;
    return;
  }

  ListNode* real_delete_node = delete_node->m_pNext;
  delete_node->m_nValue = real_delete_node->m_nValue;
  delete_node->m_pNext = real_delete_node->m_pNext;
  delete real_delete_node;
  real_delete_node = nullptr;
  return;
}

// ====================测试代码====================
void Test(ListNode* pListHead, ListNode* pNode, bool is_invalid_args) {
  printf("The original list is: \n");
  PrintList(pListHead);

  printf("The node to be deleted is: \n");
  PrintListNode(pNode);
  try {
    DeleteNode(&pListHead, pNode);
  } catch (std::invalid_argument const& ia) {
    if (is_invalid_args == true) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
  }
  printf("The result list is: \n");
  PrintList(pListHead);
}

// 链表中有多个结点，删除中间的结点
void Test1() {
  ListNode* pNode1 = CreateListNode(1);
  ListNode* pNode2 = CreateListNode(2);
  ListNode* pNode3 = CreateListNode(3);
  ListNode* pNode4 = CreateListNode(4);
  ListNode* pNode5 = CreateListNode(5);

  ConnectListNodes(pNode1, pNode2);
  ConnectListNodes(pNode2, pNode3);
  ConnectListNodes(pNode3, pNode4);
  ConnectListNodes(pNode4, pNode5);

  Test(pNode1, pNode3, false);

  DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2() {
  ListNode* pNode1 = CreateListNode(1);
  ListNode* pNode2 = CreateListNode(2);
  ListNode* pNode3 = CreateListNode(3);
  ListNode* pNode4 = CreateListNode(4);
  ListNode* pNode5 = CreateListNode(5);

  ConnectListNodes(pNode1, pNode2);
  ConnectListNodes(pNode2, pNode3);
  ConnectListNodes(pNode3, pNode4);
  ConnectListNodes(pNode4, pNode5);

  Test(pNode1, pNode5, false);

  DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
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

  Test(pNode1, pNode1, false);

  DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test4() {
  ListNode* pNode1 = CreateListNode(1);

  Test(pNode1, pNode1, false);
}

// 链表为空
void Test5() {
  Test(nullptr, nullptr, true);
}

int main(int argc, char* argv[]) {
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();

  return 0;
}
