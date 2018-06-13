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

// 面试题9: 用两个栈实现队列
// 题目: 用两个栈实现一个队列. 队列的声明如下, 请实现它的两个函数appendTail和deleteHead, 分别完成在
// 队列尾部插入结点和在队列头部删除结点的功能.

#pragma once
#include <stack>
#include <stdexcept>

template <typename T>
class CQueue {
 public:
  CQueue(void);
  ~CQueue(void);

  // 在队列末尾添加一个结点
  void appendTail(const T& node);

  // 删除队列的头结点
  T deleteHead();

 private:
  std::stack<T> stack1;
  std::stack<T> stack2;
};

template <typename T>
CQueue<T>::CQueue(void) {}

template <typename T>
CQueue<T>::~CQueue(void) {}

template <typename T>
void CQueue<T>::appendTail(const T& element) {
  stack1.push(element);
}

template <typename T>
T CQueue<T>::deleteHead() {
  if (stack2.empty() == true) {
    while (stack1.empty() == false) {
      T const& item = stack1.top();
      // The push method of std::stack only use input to initialize the its inside item, so const
      // reference is enough.
      stack2.push(item);
      stack1.pop();
    }
  }

  if (stack2.empty() == true) throw std::logic_error("queue empty!");
  T const& head_item = stack2.top();
  stack2.pop();
  return head_item;
}
