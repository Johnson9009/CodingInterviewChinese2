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

// 面试题16: 数值的整数次方
// 题目: 实现函数double Power(double base, int exponent), 求base的exponent次方. 不得使用库函数, 同时
// 不需要考虑大数问题.

#include <cmath>
#include <iostream>

bool DoubleEqual(double a, double b) {
  return (std::abs(a - b) < 1e-7) ? true : false;
}

double PowerUnsignedExponent(double base, uint32_t exponent) {
  if (exponent == 0) return 1;
  if (exponent == 1) return base;
  double result = PowerUnsignedExponent(base, (exponent >> 1));
  result *= result;
  if ((exponent & 1) == 1) result *= base;
  return result;
}

double Power(double base, int exponent) {
  bool is_negative_exponent = false;
  uint32_t unsigned_exponent = exponent;
  if (exponent < 0) {
    is_negative_exponent = true;
    unsigned_exponent = -exponent;
  }
  if ((DoubleEqual(base, 0.0) == true) && (is_negative_exponent == true)) {
    throw std::invalid_argument("");
  }
  double result = PowerUnsignedExponent(base, unsigned_exponent);
  if (is_negative_exponent == true) result = 1.0 / result;
  return result;
}

// ====================测试代码====================
void Test(const char* testName, double base, int exponent, double expectedResult,
          bool expectedFlag) {
  try {
    double result = Power(base, exponent);
    if (DoubleEqual(result, expectedResult) == true) {
      std::cout << testName << " passed" << std::endl;
    } else {
      std::cout << testName << " FAILED" << std::endl;
    }
  } catch (std::invalid_argument const& ia) {
    if (expectedFlag == true) {
      std::cout << testName << " passed" << std::endl;
    } else {
      std::cout << testName << "FAILED" << std::endl;
    }
  }
}

int main(int argc, char* argv[]) {
  // 底数、指数都为正数
  Test("Test1", 2, 3, 8, false);

  // 底数为负数、指数为正数
  Test("Test2", -2, 3, -8, false);

  // 指数为负数
  Test("Test3", 2, -3, 0.125, false);

  // 指数为0
  Test("Test4", 2, 0, 1, false);

  // 底数、指数都为0
  Test("Test5", 0, 0, 1, false);

  // 底数为0、指数为正数
  Test("Test6", 0, 4, 0, false);

  // 底数为0、指数为负数
  Test("Test7", 0, -4, 0, true);

  return 0;
}
