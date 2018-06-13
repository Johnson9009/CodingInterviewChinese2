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

// 面试题40: 最小的k个数
// 题目: 输入n个整数, 找出其中最小的k个数. 例如输入4, 5, 1, 6, 2, 7, 3, 8这8个数字, 则最小的4个数字
// 是1, 2, 3, 4.

#include <cstdio>
#include "../Utilities/Array.h"

#include <functional>
#include <iostream>
#include <queue>
#include <vector>

// ====================方法1====================
void GetLeastNumbers_Solution1(int* data, int length, int* output, int k) {
  if ((data == nullptr) || (output == nullptr) || (k <= 0) || (length < k)) {
    throw std::invalid_argument("");
  }
  int begin = 0;
  int end = length;
  while ((begin + 1) < end) {
    int pivot_idx = Partition(data, begin, end);
    if ((pivot_idx + 1) == k) {
      break;
    } else if ((pivot_idx + 1) < k) {
      begin = pivot_idx + 1;
    } else {
      end = pivot_idx;
    }
  }
  for (int i = 0; i < k; ++i) output[i] = data[i];
  return;
}

// ====================方法2====================
void GetLeastNumbers_Solution2(std::vector<int>* data, std::priority_queue<int>* leastNumbers,
                               int k) {
  if ((data == nullptr) || (leastNumbers == nullptr) || (k <= 0) ||
      (k > static_cast<int>(data->size()))) {
    throw std::invalid_argument("");
  }

  for (auto const& number : *data) {
    if (leastNumbers->size() < static_cast<std::size_t>(k)) {
      leastNumbers->push(number);
    } else {
      if (number < leastNumbers->top()) {
        leastNumbers->pop();
        leastNumbers->push(number);
      }
    }
  }
  return;
}

// ====================测试代码====================
void Test(char const* testName, int* data, int n, int* expectedResult, int k) {
  if (testName != nullptr) printf("%s begins: \n", testName);

  if (expectedResult == nullptr)
    printf("The input is invalid, we don't expect any result.\n");
  else {
    printf("Expected result: \n");
    for (int i = 0; i < k; ++i) printf("%d\t", expectedResult[i]);
    printf("\n");
  }

  printf("Result for solution1:\n");
  int* output = new int[k];
  try {
    GetLeastNumbers_Solution1(data, n, output, k);
    for (int i = 0; i < k; ++i) printf("%d\t", output[i]);
    printf("\n");
  } catch (std::invalid_argument const& ia) {
    if (expectedResult == nullptr) {
      printf("Passed!\n");
    } else {
      printf("Failed!\n");
    }
  }

  delete[] output;

  printf("Result for solution2:\n");
  std::vector<int> vectorData;
  for (int i = 0; i < n; ++i) vectorData.push_back(data[i]);
  std::priority_queue<int> leastNumbers;
  try {
    GetLeastNumbers_Solution2(&vectorData, &leastNumbers, k);
    printf("The actual output numbers are:\n");
    while (leastNumbers.empty() == false) {
      printf("%d\t", leastNumbers.top());
      leastNumbers.pop();
    }
  } catch (std::invalid_argument const& ia) {
    if (expectedResult == nullptr) {
      printf("Passed!\n");
    } else {
      printf("Failed!\n");
    }
  }

  printf("\n\n");
}

// k小于数组的长度
void Test1() {
  int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
  int expected[] = {1, 2, 3, 4};
  Test("Test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于数组的长度
void Test2() {
  int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
  int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
  Test("Test2", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k大于数组的长度
void Test3() {
  int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
  int* expected = nullptr;
  Test("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

// k等于1
void Test4() {
  int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
  int expected[] = {1};
  Test("Test4", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于0
void Test5() {
  int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
  int* expected = nullptr;
  Test("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

// 数组中有相同的数字
void Test6() {
  int data[] = {4, 5, 1, 6, 2, 7, 2, 8};
  int expected[] = {1, 2};
  Test("Test6", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// 输入空指针
void Test7() {
  int* expected = nullptr;
  Test("Test7", nullptr, 0, expected, 0);
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
