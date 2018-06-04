/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题3(一):找出数组中重复的数字
// 题目: 在一个长度为n的数组里的所有数字都在0到n-1的范围内. 数组中某些数字是重复的, 但不知道有几个数
// 字重复了, 也不知道每个数字重复了几次. 请找出数组中任意一个重复的数字. 例如, 如果输入长度为7的数组
// {2, 3, 1, 0, 2, 5, 3}, 那么对应的输出是重复的数字2或者3.

#include <cstdio>
#include <stdexcept>
#include <utility>

int duplicate(int* data, int length) {
  if ((data == nullptr) || (length <= 1)) throw std::invalid_argument("");

  int pos = 0;
  while (pos < length) {
    int cur_value = data[pos];
    if (cur_value == pos) {
      ++pos;
    } else {
      // This check is very important.
      if ((cur_value < 0) || (cur_value >= length)) throw std::invalid_argument("");

      if (cur_value == data[cur_value]) {
        return cur_value;
      } else {
        std::swap(data[pos], data[cur_value]);
      }
    }
  }
  throw std::invalid_argument("");
}

// ====================测试代码====================
bool contains(int array[], int length, int number) {
  for (int i = 0; i < length; ++i) {
    if (array[i] == number) return true;
  }

  return false;
}

void test(char const* testName, int numbers[], int lengthNumbers, int expected[],
          int expectedExpected, bool validArgument) {
  printf("%s begins: ", testName);

  try {
    int duplication = duplicate(numbers, lengthNumbers);
    if (contains(expected, expectedExpected, duplication)) {
      printf("Passed.\n");
    } else {
      printf("FAILED.\n");
    }
  } catch (std::invalid_argument const& ia) {
    if (validArgument == false) {
      printf("Passed.\n");
    } else {
      printf("FAILED.\n");
    }
  }
}

// 重复的数字是数组中最小的数字
void test1() {
  int numbers[] = {2, 1, 3, 1, 4};
  int duplications[] = {1};
  test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2() {
  int numbers[] = {2, 4, 3, 1, 4};
  int duplications[] = {4};
  test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3() {
  int numbers[] = {2, 4, 2, 1, 4};
  int duplications[] = {2, 4};
  test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4() {
  int numbers[] = {2, 1, 3, 0, 4};
  int duplications[] = {-1};  // not in use in the test function
  test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5() {
  int numbers[] = {2, 1, 3, 5, 4};
  int duplications[] = {-1};  // not in use in the test function
  test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6() {
  int* numbers = nullptr;
  int duplications[] = {-1};  // not in use in the test function
  test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  return 0;
}
