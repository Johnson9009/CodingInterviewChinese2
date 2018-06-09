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

// 面试题33：二叉搜索树的后序遍历序列
// 题目: 输入一个整数数组, 判断该数组是不是某二叉搜索树的后序遍历的结果. 如果是则返回true, 否则返回
// false. 假设输入的数组的任意两个数字都互不相同.

#include <cstdio>
#include <stdexcept>

bool IsValidPostOrderOfBstCore(int const* post_order, int begin, int end) {
  if ((post_order == nullptr) || (begin > end)) throw std::invalid_argument("");
  if ((begin + 1) >= end) return true;

  int root_value = post_order[end - 1];
  int idx = begin;
  while (post_order[idx] < root_value) ++idx;
  for (int i = idx; i < end; ++i) {
    if (post_order[i] < root_value) return false;
  }
  // NOTE: Must be "(end - 1)" can't be "end";
  return (IsValidPostOrderOfBstCore(post_order, begin, idx) &&
          IsValidPostOrderOfBstCore(post_order, idx, (end - 1)));
}

bool IsValidPostOrderOfBst(int const* post_order, int length) {
  if ((post_order == nullptr) || (length <= 0)) throw std::invalid_argument("");
  return IsValidPostOrderOfBstCore(post_order, 0, length);
}

// ====================测试代码====================
void Test(const char* testName, int sequence[], int length, bool expected) {
  if (testName != nullptr) printf("%s begins: ", testName);

  try {
    if (IsValidPostOrderOfBst(sequence, length) == expected) {
      printf("passed.\n");
    } else {
      printf("failed.\n");
    }
  } catch (std::invalid_argument const& ia) {
    if (expected == false) {
      printf("passed.\n");
    } else {
      printf("failed.\n");
    }
  }
}

//          10
//         /  \
//        6    14
//       / \   / \
//      4   8 12 16
void Test1() {
  int data[] = {4, 8, 6, 12, 16, 14, 10};
  Test("Test1", data, sizeof(data) / sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2() {
  int data[] = {4, 6, 7, 5};
  Test("Test2", data, sizeof(data) / sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3() {
  int data[] = {1, 2, 3, 4, 5};
  Test("Test3", data, sizeof(data) / sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4() {
  int data[] = {5, 4, 3, 2, 1};
  Test("Test4", data, sizeof(data) / sizeof(int), true);
}

// 树中只有1个结点
void Test5() {
  int data[] = {5};
  Test("Test5", data, sizeof(data) / sizeof(int), true);
}

void Test6() {
  int data[] = {7, 4, 6, 5};
  Test("Test6", data, sizeof(data) / sizeof(int), false);
}

void Test7() {
  int data[] = {4, 6, 12, 8, 16, 14, 10};
  Test("Test7", data, sizeof(data) / sizeof(int), false);
}

void Test8() {
  Test("Test8", nullptr, 0, false);
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

  return 0;
}
