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

// 面试题21: 调整数组顺序使奇数位于偶数前面
// 题目: 输入一个整数数组, 实现一个函数来调整该数组中数字的顺序, 使得所有奇数位于数组的前半部分, 所
// 有偶数位于数组的后半部分.

#include <cstdio>
#include <stdexcept>

// ====================方法一====================
void ReorderOddEven_1(int* data, unsigned int length) {
  if (data == nullptr || length == 0) return;

  int* left = data;
  int* right = data + length - 1;
  while (left < right) {
    while (left < right && (*left & 0x1) != 0) ++left;
    while (left < right && (*right & 0x1) == 0) --right;
    if (left < right) {
      std::swap(*left, *right);
      ++left;
      --right;
    }
  }
  return;
}

// ====================方法二====================
bool IsOdd(int value) {
  return ((value & 1) == 1);
}

void ReorderOddEven_2(int* data, int length, bool (*Estimator)(int value)) {
  if ((data == nullptr) || (length <= 0) || (Estimator == nullptr)) throw std::invalid_argument("");
  int left_idx = 0;
  for (int i = 0; i < length; ++i) {
    if ((*Estimator)(data[i]) == true) {
      if (left_idx != i) {
        std::swap(data[left_idx], data[i]);
      }
      ++left_idx;
    }
  }
  return;
}

// ====================测试代码====================
void PrintArray(int numbers[], int length) {
  if (length < 0) return;

  for (int i = 0; i < length; ++i) printf("%d\t", numbers[i]);

  printf("\n");
}

void Test(char const* testName, int numbers[], int length, bool is_invalid_args) {
  if (testName != nullptr) printf("%s begins:\n", testName);

  int* copy = new int[length];
  for (int i = 0; i < length; ++i) {
    copy[i] = numbers[i];
  }

  printf("Test for solution 1:\n");
  PrintArray(numbers, length);
  ReorderOddEven_1(numbers, length);
  PrintArray(numbers, length);

  printf("Test for solution 2:\n");
  PrintArray(copy, length);
  try {
    ReorderOddEven_2(copy, length, IsOdd);
  } catch (std::invalid_argument const& ia) {
    if (is_invalid_args == true) {
      printf("Passed!\n");
    } else {
      printf("Failed!\n");
    }
  }
  PrintArray(copy, length);

  delete[] copy;
}

void Test1() {
  int numbers[] = {1, 2, 3, 4, 5, 6, 7};
  Test("Test1", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test2() {
  int numbers[] = {2, 4, 6, 1, 3, 5, 7};
  Test("Test2", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test3() {
  int numbers[] = {1, 3, 5, 7, 2, 4, 6};
  Test("Test3", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test4() {
  int numbers[] = {1};
  Test("Test4", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test5() {
  int numbers[] = {2};
  Test("Test5", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test6() {
  Test("Test6", nullptr, 0, true);
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
