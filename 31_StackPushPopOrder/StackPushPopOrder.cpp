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

// 面试题31: 栈的压入, 弹出序列
// 题目: 输入两个整数序列, 第一个序列表示栈的压入顺序, 请判断第二个序列是否为该栈的弹出顺序. 假设压
// 入栈的所有数字均不相等. 例如序列1, 2, 3, 4, 5是某栈的压栈序列, 序列4, 5, 3, 2, 1是该压栈序列对应
// 的一个弹出序列, 但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列.

#include <cstdio>
#include <stack>
#include <stdexcept>

bool IsPopOrder(int const* push_order, int const* pop_order, int length) {
  if ((push_order == nullptr) || (pop_order == nullptr) || (length <= 0)) {
    throw std::invalid_argument("");
  }
  std::stack<int> stack;
  int push_idx = 0;
  int pop_idx = 0;

  while (pop_idx < length) {
    while ((stack.empty() == true) || (stack.top() != pop_order[pop_idx])) {
      if (push_idx >= length) return false;
      stack.push(push_order[push_idx]);
      ++push_idx;
    }
    stack.pop();
    ++pop_idx;
  }
  return ((pop_idx == length) && (push_idx == length) && (stack.empty() == true));
}

// ====================测试代码====================
void Test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected) {
  if (testName != nullptr) printf("%s begins: ", testName);
  try {
    if (IsPopOrder(pPush, pPop, nLength) == expected) {
      printf("Passed.\n");
    } else {
      printf("failed.\n");
    }
  } catch (std::invalid_argument const& ia) {
    if (expected == false) {
      printf("Passed.\n");
    } else {
      printf("failed.\n");
    }
  }
}

void Test1() {
  const int nLength = 5;
  int push[nLength] = {1, 2, 3, 4, 5};
  int pop[nLength] = {4, 5, 3, 2, 1};

  Test("Test1", push, pop, nLength, true);
}

void Test2() {
  const int nLength = 5;
  int push[nLength] = {1, 2, 3, 4, 5};
  int pop[nLength] = {3, 5, 4, 2, 1};

  Test("Test2", push, pop, nLength, true);
}

void Test3() {
  const int nLength = 5;
  int push[nLength] = {1, 2, 3, 4, 5};
  int pop[nLength] = {4, 3, 5, 1, 2};

  Test("Test3", push, pop, nLength, false);
}

void Test4() {
  const int nLength = 5;
  int push[nLength] = {1, 2, 3, 4, 5};
  int pop[nLength] = {3, 5, 4, 1, 2};

  Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5() {
  const int nLength = 1;
  int push[nLength] = {1};
  int pop[nLength] = {2};

  Test("Test5", push, pop, nLength, false);
}

void Test6() {
  const int nLength = 1;
  int push[nLength] = {1};
  int pop[nLength] = {1};

  Test("Test6", push, pop, nLength, true);
}

void Test7() {
  Test("Test7", nullptr, nullptr, 0, false);
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
