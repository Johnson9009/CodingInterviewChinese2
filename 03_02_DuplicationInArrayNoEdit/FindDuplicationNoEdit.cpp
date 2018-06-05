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

// 面试题3(二): 不修改数组找出重复的数字
// 题目: 在一个长度为n+1的数组里的所有数字都在1到n的范围内, 所以数组中至少有一个数字是重复的. 请找出
// 数组中任意一个重复的数字, 但不能修改输入的数组. 例如, 如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6,
// 7}, 那么对应的输出是重复的数字2或者3.

#include <iostream>
#include <stdexcept>

int CountRange(int const* data, int length, int first, int last) {
  if ((data == nullptr) || (length <= 0) || (first > last)) throw std::invalid_argument("");
  int count = 0;
  for (int i = 0; i < length; ++i) {
    if ((data[i] >= first) && (data[i] <= last)) ++count;
  }
  return count;
}

int getDuplication(int const* data, int length) {
  if ((data == nullptr) || (length <= 1)) throw std::invalid_argument("");

  int first = 1;
  int last = length - 1;
  while (first <= last) {
    int middle = ((last - first) >> 1) + first;
    int count = CountRange(data, length, first, middle);
    if ((first == last) && (count > 1)) return first;
    if (count <= (middle - first + 1)) {
      first = middle + 1;
    } else {
      last = middle;
    }
  }
  throw std::invalid_argument("");
}

// ====================测试代码====================
void test(const char* testName, int* numbers, int length, int* duplications, int dupLength) {
  try {
    int result = getDuplication(numbers, length);
    for (int i = 0; i < dupLength; ++i) {
      if (result == duplications[i]) {
        std::cout << testName << " passed." << std::endl;
        return;
      }
    }
    std::cout << testName << " FAILED." << std::endl;
  } catch (std::invalid_argument const& ia) {
    if ((dupLength == 1) && (duplications[0] == -1)) {
      std::cout << testName << " passed. " << std::endl;
    } else {
      std::cout << testName << " FAILED." << std::endl;
    }
  }
}

// 多个重复的数字
void test1() {
  int numbers[] = {2, 3, 5, 4, 3, 2, 6, 7};
  int duplications[] = {2, 3};
  test("test1", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int));
}

// 一个重复的数字
void test2() {
  int numbers[] = {3, 2, 1, 4, 4, 5, 6, 7};
  int duplications[] = {4};
  test("test2", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int));
}

// 重复的数字是数组中最小的数字
void test3() {
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 1, 8};
  int duplications[] = {1};
  test("test3", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int));
}

// 重复的数字是数组中最大的数字
void test4() {
  int numbers[] = {1, 7, 3, 4, 5, 6, 8, 2, 8};
  int duplications[] = {8};
  test("test4", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int));
}

// 数组中只有两个数字
void test5() {
  int numbers[] = {1, 1};
  int duplications[] = {1};
  test("test5", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int));
}

// 重复的数字位于数组当中
void test6() {
  int numbers[] = {3, 2, 1, 3, 4, 5, 6, 7};
  int duplications[] = {3};
  test("test6", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int));
}

// 多个重复的数字
void test7() {
  int numbers[] = {1, 2, 2, 6, 4, 5, 6};
  int duplications[] = {2, 6};
  test("test7", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int));
}

// 一个数字重复三次
void test8() {
  int numbers[] = {1, 2, 2, 6, 4, 5, 2};
  int duplications[] = {2};
  test("test8", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int));
}

// 没有重复的数字
void test9() {
  int numbers[] = {1, 2, 6, 4, 5, 3};
  int duplications[] = {-1};
  test("test9", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int));
}

// 无效的输入
void test10() {
  int* numbers = nullptr;
  int duplications[] = {-1};
  test("test10", numbers, 0, duplications, sizeof(duplications) / sizeof(int));
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  test10();
  return 0;
}
