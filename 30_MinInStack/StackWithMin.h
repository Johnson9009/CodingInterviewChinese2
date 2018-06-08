//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者: 何海涛
//==================================================================

// 面试题30: 包含min函数的栈
// 题目: 定义栈的数据结构, 请在该类型中实现一个能够得到栈的最小元素的min函数. 在该栈中, 调用min,
// push及pop的时间复杂度都是O(1).

#pragma once

#include <assert.h>
#include <stack>

template <typename T>
class StackWithMin {
 public:
  T& top();
  T const& top() const;
  void pop();
  void push(T const& item);
  T const& min() const;
  bool empty() const;
  std::size_t size() const;

 private:
  std::stack<T> data_;
  std::stack<T> min_stack_;
};

template <typename T>
T& StackWithMin<T>::top() {
  return data_.top();
}

template <typename T>
T const& StackWithMin<T>::top() const {
  return data_.top();
}

template <typename T>
void StackWithMin<T>::pop() {
  data_.pop();
  min_stack_.pop();
  return;
}

template <typename T>
void StackWithMin<T>::push(T const& item) {
  data_.push(item);
  if ((min_stack_.empty() == false) && (item > min_stack_.top())) {
    min_stack_.push(min_stack_.top());
  } else {
    min_stack_.push(item);
  }
}

template <typename T>
T const& StackWithMin<T>::min() const {
  return min_stack_.top();
}

template <typename T>
bool StackWithMin<T>::empty() const {
  return data_.empty();
}

template <typename T>
std::size_t StackWithMin<T>::size() const {
  return data_.size();
}
