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

// 面试题10: 斐波那契数列
// 题目: 写一个函数, 输入n, 求斐波那契(Fibonacci)数列的第n项.

#include <cstdint>
#include <cstdio>

// ====================方法1：递归====================
uint64_t FibonacciRecursively(uint32_t n) {
  if (n < 2) return n;
  return (FibonacciRecursively(n - 1) + FibonacciRecursively(n - 2));
}

// ====================方法2：循环====================
uint64_t FibonacciIteratively(uint32_t n) {
  if (n < 2) return n;
  uint64_t fn_minus_2 = 0;
  uint64_t fn_minus_1 = 1;
  for (uint32_t i = 2; i <= n; ++i) {
    uint64_t fn = fn_minus_1 + fn_minus_2;
    fn_minus_2 = fn_minus_1;
    fn_minus_1 = fn;
  }
  return fn_minus_1;
}

// ====================方法3：基于矩阵乘法====================
#include <cassert>

struct Matrix2By2 {
  Matrix2By2(long long m00 = 0, long long m01 = 0, long long m10 = 0, long long m11 = 0)
      : m_00(m00), m_01(m01), m_10(m10), m_11(m11) {}

  long long m_00;
  long long m_01;
  long long m_10;
  long long m_11;
};

Matrix2By2 MatrixMultiply(const Matrix2By2& matrix1, const Matrix2By2& matrix2) {
  return Matrix2By2(matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
                    matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
                    matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
                    matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11);
}

Matrix2By2 MatrixPower(unsigned int n) {
  assert(n > 0);

  Matrix2By2 matrix;
  if (n == 1) {
    matrix = Matrix2By2(1, 1, 1, 0);
  } else if (n % 2 == 0) {
    matrix = MatrixPower(n / 2);
    matrix = MatrixMultiply(matrix, matrix);
  } else if (n % 2 == 1) {
    matrix = MatrixPower((n - 1) / 2);
    matrix = MatrixMultiply(matrix, matrix);
    matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
  }

  return matrix;
}

long long Fibonacci_Solution3(unsigned int n) {
  int result[2] = {0, 1};
  if (n < 2) return result[n];

  Matrix2By2 PowerNMinus2 = MatrixPower(n - 1);
  return PowerNMinus2.m_00;
}

// ====================测试代码====================
void Test(int n, int expected) {
  if (FibonacciRecursively(n) == expected)
    printf("Test for %d in solution1 passed.\n", n);
  else
    printf("Test for %d in solution1 failed.\n", n);

  if (FibonacciIteratively(n) == expected)
    printf("Test for %d in solution2 passed.\n", n);
  else
    printf("Test for %d in solution2 failed.\n", n);

  if (Fibonacci_Solution3(n) == expected)
    printf("Test for %d in solution3 passed.\n", n);
  else
    printf("Test for %d in solution3 failed.\n", n);
}

int main(int argc, char* argv[]) {
  Test(0, 0);
  Test(1, 1);
  Test(2, 1);
  Test(3, 2);
  Test(4, 3);
  Test(5, 5);
  Test(6, 8);
  Test(7, 13);
  Test(8, 21);
  Test(9, 34);
  Test(10, 55);

  Test(40, 102334155);

  return 0;
}
