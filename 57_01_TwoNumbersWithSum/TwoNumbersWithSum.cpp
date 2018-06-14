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

// 面试题57(一): 和为s的两个数字
// 题目: 输入一个递增排序的数组和一个数字s, 在数组中查找两个数, 使得它们的和正好是s. 如果有多对数字
// 的和等于s, 输出任意一对即可.

#include <cstdio>
#include <stdexcept>

bool FindNumbersWithSum(int const* data, int length, int sum, int* number1, int* number2) {
  if ((data == nullptr) || (length < 2) || (number1 == nullptr) || (number2 == nullptr)) {
    throw std::invalid_argument("");
  }
  int left_idx = 0;
  int right_idx = length - 1;
  while (left_idx < right_idx) {
    int cur_sum = data[left_idx] + data[right_idx];
    if (cur_sum == sum) {
      *number1 = data[left_idx];
      *number2 = data[right_idx];
      return true;
    } else if (cur_sum > sum) {
      --right_idx;
    } else {
      ++left_idx;
    }
  }
  return false;
}

// ====================测试代码====================
void Test(const char* testName, int data[], int length, int sum, bool expectedReturn) {
  if (testName != nullptr) printf("%s begins: ", testName);

  int num1, num2;
  try {
    int result = FindNumbersWithSum(data, length, sum, &num1, &num2);
    if (result == expectedReturn) {
      if (result) {
        if (num1 + num2 == sum) {
          printf("Passed. \n");
        } else {
          printf("FAILED. \n");
        }
      } else {
        printf("Passed. \n");
      }
    } else {
      printf("FAILED. \n");
    }
  } catch (std::invalid_argument const& ia) {
    if (expectedReturn == false) {
      printf("Passed. \n");
    } else {
      printf("FAILED. \n");
    }
  }
}

// 存在和为s的两个数字，这两个数字位于数组的中间
void Test1() {
  int data[] = {1, 2, 4, 7, 11, 15};
  Test("Test1", data, sizeof(data) / sizeof(int), 15, true);
}

// 存在和为s的两个数字，这两个数字位于数组的两段
void Test2() {
  int data[] = {1, 2, 4, 7, 11, 16};
  Test("Test2", data, sizeof(data) / sizeof(int), 17, true);
}

// 不存在和为s的两个数字
void Test3() {
  int data[] = {1, 2, 4, 7, 11, 16};
  Test("Test3", data, sizeof(data) / sizeof(int), 10, false);
}

// 鲁棒性测试
void Test4() {
  Test("Test4", nullptr, 0, 0, false);
}

int main(int argc, char* argv[]) {
  Test1();
  Test2();
  Test3();
  Test4();

  return 0;
}
