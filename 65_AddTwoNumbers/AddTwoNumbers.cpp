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

// 面试题65: 不用加减乘除做加法
// 题目: 写一个函数, 求两个整数之和, 要求在函数体内不得使用+, -, *、/四则运算符号.

#include <cstdio>

int Add(int number1, int number2) {
  int sum = number1 ^ number2;
  int carry = (number1 & number2) << 1;
  while (carry != 0) {
    int tmp = sum;
    sum ^= carry;
    carry = (carry & tmp) << 1;
  }
  return sum;
}

// ====================测试代码====================
void Test(int num1, int num2, int expected) {
  int result = Add(num1, num2);
  if (result == expected)
    printf("%d + %d is %d. Passed\n", num1, num2, result);
  else
    printf("%d + %d is %d. FAILED\n", num1, num2, result);
}

int main(int argc, char* argv[]) {
  Test(1, 2, 3);
  Test(111, 899, 1010);

  Test(-1, 2, 1);
  Test(1, -2, -1);

  Test(3, 0, 3);
  Test(0, -4, -4);

  Test(-2, -8, -10);

  return 0;
}
