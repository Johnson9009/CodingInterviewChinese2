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

// 面试题53(一): 数字在排序数组中出现的次数
// 题目: 统计一个数字在排序数组中出现的次数. 例如输入排序数组{1, 2, 3, 3, 3, 3, 4, 5}和数字3, 由于3
// 在这个数组中出现了4次, 因此输出4.

#include <cstdio>
#include <stdexcept>

int GetIdxOf1stGtK(int const* data, int length, int k) {
  if ((data == nullptr) || (length <= 0)) throw std::invalid_argument("");
  int begin = 0;
  int end = length;
  while (begin < end) {
    int mid = ((end - begin) >> 1) + begin;
    if (data[mid] <= k) {
      begin = mid + 1;
    } else {
      end = mid;
    }
  }
  return end;
}

int GetIdxOf1stK(int const* data, int length, int k) {
  if ((data == nullptr) || (length <= 0)) throw std::invalid_argument("");
  int begin = 0;
  int end = length;
  while (begin < end) {
    int mid = ((end - begin) >> 1) + begin;
    if (data[mid] < k) {
      begin = mid + 1;
    } else {
      end = mid;
    }
  }
  if ((end == length) || (data[end] != k)) throw std::invalid_argument("");
  return end;
}

int GetNumberOfK(int const* data, int length, int k) {
  if ((data == nullptr) || (length <= 0)) throw std::invalid_argument("");
  return (GetIdxOf1stGtK(data, length, k) - GetIdxOf1stK(data, length, k));
}

// ====================测试代码====================
void Test(const char* testName, int data[], int length, int k, int expected) {
  if (testName != nullptr) printf("%s begins: ", testName);
  try {
    int result = GetNumberOfK(data, length, k);
    if (result == expected) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
  } catch (std::invalid_argument const& ia) {
    if (expected == 0) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
  }
}

// 查找的数字出现在数组的中间
void Test1() {
  int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
  Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的开头
void Test2() {
  int data[] = {3, 3, 3, 3, 4, 5};
  Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3() {
  int data[] = {1, 2, 3, 3, 3, 3};
  Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数字不存在
void Test4() {
  int data[] = {1, 3, 3, 3, 3, 4, 5};
  Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5() {
  int data[] = {1, 3, 3, 3, 3, 4, 5};
  Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6() {
  int data[] = {1, 3, 3, 3, 3, 4, 5};
  Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7() {
  int data[] = {3, 3, 3, 3};
  Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8() {
  int data[] = {3, 3, 3, 3};
  Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9() {
  int data[] = {3};
  Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10() {
  int data[] = {3};
  Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// 鲁棒性测试，数组空指针
void Test11() {
  Test("Test11", nullptr, 0, 0, 0);
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
  Test9();
  Test10();
  Test11();

  return 0;
}
