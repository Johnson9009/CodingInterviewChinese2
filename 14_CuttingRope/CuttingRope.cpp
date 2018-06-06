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

// 面试题14: 剪绳子
// 题目: 给你一根长度为n绳子, 请把绳子剪成m段(m, n都是整数, n>1并且m>=1).每段的绳子的长度记为k[0],
// k[1], ..., k[m]. k[0]*k[1]*...*k[m]可能的最大乘积是多少? 例如当绳子的长度是8时, 我们把它剪成长度
// 分别为2, 3, 3的三段, 此时得到最大的乘积18.

#include <cmath>
#include <cstring>
#include <iostream>
#include <stdexcept>

// ====================动态规划====================
int MaxProductAfterCuttingDynamicProgramming(int length) {
  if (length <= 1) throw std::invalid_argument("");
  if (length == 2) return 1;
  if (length == 3) return 2;
  int* products = new int[length + 1];
  std::memset(products, 0, ((length + 1) * sizeof(int)));
  products[1] = 1;
  products[2] = 2;
  products[3] = 3;

  for (int i = 4; i <= length; ++i) {
    int max = 0;
    for (int j = 1; j <= (i >> 1); ++j) {
      int product = products[j] * products[i - j];
      if (product > max) max = product;
    }
    products[i] = max;
  }

  int result = products[length];
  delete[] products;
  return result;
}
// ====================贪婪算法====================
int MaxProductAfterCuttingGreedy(int length) {
  if (length <= 1) throw std::invalid_argument("");
  if (length == 2) return 1;
  if (length == 3) return 2;

  int count_of_3 = length / 3;
  int count_of_2 = 0;
  if ((length % 3) == 1) {
    count_of_2 = 2;
    --count_of_3;
  } else if ((length % 3) == 2) {
    count_of_2 = 1;
  }
  return (std::pow(3, count_of_3) * std::pow(2, count_of_2));
}

// ====================测试代码====================
void test(const char* testName, int length, int expected) {
  try {
    int result1 = MaxProductAfterCuttingDynamicProgramming(length);
    if (result1 == expected) {
      std::cout << "Solution1 for " << testName << " passed." << std::endl;
    } else {
      std::cout << "Solution1 for " << testName << " FAILED." << std::endl;
    }
  } catch (std::invalid_argument const& ia) {
    if (expected == 0) {
      std::cout << "Solution1 for " << testName << " passed." << std::endl;
    } else {
      std::cout << "Solution1 for " << testName << " FAILED." << std::endl;
    }
  }

  try {
    int result2 = MaxProductAfterCuttingGreedy(length);
    if (result2 == expected) {
      std::cout << "Solution2 for " << testName << " passed." << std::endl;
    } else {
      std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
    }
  } catch (std::invalid_argument const& ia) {
    if (expected == 0) {
      std::cout << "Solution2 for " << testName << " passed." << std::endl;
    } else {
      std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
    }
  }
}

void test1() {
  int length = 1;
  int expected = 0;
  test("test1", length, expected);
}

void test2() {
  int length = 2;
  int expected = 1;
  test("test2", length, expected);
}

void test3() {
  int length = 3;
  int expected = 2;
  test("test3", length, expected);
}

void test4() {
  int length = 4;
  int expected = 4;
  test("test4", length, expected);
}

void test5() {
  int length = 5;
  int expected = 6;
  test("test5", length, expected);
}

void test6() {
  int length = 6;
  int expected = 9;
  test("test6", length, expected);
}

void test7() {
  int length = 7;
  int expected = 12;
  test("test7", length, expected);
}

void test8() {
  int length = 8;
  int expected = 18;
  test("test8", length, expected);
}

void test9() {
  int length = 9;
  int expected = 27;
  test("test9", length, expected);
}

void test10() {
  int length = 10;
  int expected = 36;
  test("test10", length, expected);
}

void test11() {
  int length = 50;
  int expected = 86093442;
  test("test11", length, expected);
}

int main(int agrc, char* argv[]) {
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
  test11();

  return 0;
}
