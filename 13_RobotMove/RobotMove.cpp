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

// 面试题13: 机器人的运动范围
// 题目: 地上有一个m行n列的方格. 一个机器人从坐标(0, 0)的格子开始移动, 它每一次可以向左、右、上、下
// 移动一格, 但不能进入行坐标和列坐标的数位之和大于k的格子. 例如, 当k为18时, 机器人能够进入方格(35,
// 37), 因为3+5+3+7=18. 但它不能进入方格(35, 38), 因为3+5+3+8=19. 请问该机器人能够到达多少个格子?

#include <cstdio>
#include <cstring>
#include <stdexcept>

int DigitSum(int a, int b) {
  int result = 0;
  while (a > 0) {
    result += a % 10;
    a /= 10;
  }
  while (b > 0) {
    result += b % 10;
    b /= 10;
  }
  return result;
}

int VisitedCountCore(int row_cnt, int col_cnt, int row_idx, int col_idx, int threshold,
                     bool* visited) {
  if ((row_cnt <= 0) || (col_cnt <= 0) || (threshold < 0) || (visited == nullptr)) {
    throw std::invalid_argument("");
  }

  int cur_idx = row_idx * col_cnt + col_idx;
  if ((row_idx < 0) || (row_idx >= row_cnt) || (col_idx < 0) || (col_idx >= col_cnt) ||
      (visited[cur_idx] == true) || (DigitSum(row_idx, col_idx) > threshold)) {
    return 0;
  }

  visited[cur_idx] = true;
  int count = (1 + VisitedCountCore(row_cnt, col_cnt, (row_idx - 1), col_idx, threshold, visited) +
               VisitedCountCore(row_cnt, col_cnt, (row_idx + 1), col_idx, threshold, visited) +
               VisitedCountCore(row_cnt, col_cnt, row_idx, (col_idx - 1), threshold, visited) +
               VisitedCountCore(row_cnt, col_cnt, row_idx, (col_idx + 1), threshold, visited));
  // This visited flag of current cell can't be reset!
  return count;
}

int VisitedCount(int row_cnt, int col_cnt, int threshold) {
  if ((row_cnt < 0) || (col_cnt < 0)) throw std::invalid_argument("");
  if ((row_cnt == 0) || (col_cnt == 0) || (threshold < 0)) return 0;

  bool* visited = new bool[row_cnt * col_cnt];
  std::memset(visited, 0, (row_cnt * col_cnt) * sizeof(bool));
  int count = VisitedCountCore(row_cnt, col_cnt, 0, 0, threshold, visited);
  delete[] visited;
  return count;
}

// ====================测试代码====================
void test(char const* testName, int threshold, int rows, int cols, int expected) {
  if (testName != nullptr) printf("%s begins: ", testName);

  if (VisitedCount(rows, cols, threshold) == expected)
    printf("Passed.\n");
  else
    printf("FAILED.\n");
}

// 方格多行多列
void test1() {
  test("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void test2() {
  test("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void test3() {
  test("Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void test4() {
  test("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void test5() {
  test("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void test6() {
  test("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void test7() {
  test("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void test8() {
  test("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
void test9() {
  test("Test9", -10, 10, 10, 0);
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

  return 0;
}
