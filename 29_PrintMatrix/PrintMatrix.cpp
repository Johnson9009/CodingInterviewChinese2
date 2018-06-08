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

// 面试题29: 顺时针打印矩阵
// 题目: 输入一个矩阵, 按照从外向里以顺时针的顺序依次打印出每一个数字.

#include <cstdio>
#include <stdexcept>

void PrintMatrixClockwisely(int* matrix, int row_cnt, int col_cnt) {
  if ((matrix == nullptr) || (row_cnt <= 0) || (col_cnt <= 0)) throw std::invalid_argument("");
  int row_first_idx = 0;
  int row_last_idx = row_cnt - 1;
  int col_first_idx = 0;
  int col_last_idx = col_cnt - 1;

  while ((row_first_idx <= row_last_idx) && (col_first_idx <= col_last_idx)) {
    for (int i = col_first_idx; i <= col_last_idx; ++i) {
      printf("%d ", matrix[row_first_idx * col_cnt + i]);
    }
    ++row_first_idx;

    for (int i = row_first_idx; i <= row_last_idx; ++i) {
      printf("%d ", matrix[i * col_cnt + col_last_idx]);
    }
    --col_last_idx;

    if (row_first_idx <= row_last_idx) {
      for (int i = col_last_idx; i >= col_first_idx; --i) {
        printf("%d ", matrix[row_last_idx * col_cnt + i]);
      }
      --row_last_idx;
    }

    if (col_first_idx <= col_last_idx) {
      for (int i = row_last_idx; i >= row_first_idx; --i) {
        printf("%d ", matrix[i * col_cnt + col_first_idx]);
      }
      ++col_first_idx;
    }
  }
  return;
}

// ====================测试代码====================
void Test(int columns, int rows) {
  printf("Test Begin: %d columns, %d rows.\n", columns, rows);

  if (columns < 1 || rows < 1) return;

  int* numbers = new int[rows * columns];
  for (int i = 0; i < (rows * columns); ++i) numbers[i] = i + 1;

  PrintMatrixClockwisely(numbers, rows, columns);
  printf("\n");

  delete[] numbers;
}

int main(int argc, char* argv[]) {
  /*
  1
  */
  Test(1, 1);

  /*
  1    2
  3    4
  */
  Test(2, 2);

  /*
  1    2    3    4
  5    6    7    8
  9    10   11   12
  13   14   15   16
  */
  Test(4, 4);

  /*
  1    2    3    4    5
  6    7    8    9    10
  11   12   13   14   15
  16   17   18   19   20
  21   22   23   24   25
  */
  Test(5, 5);

  /*
  1
  2
  3
  4
  5
  */
  Test(1, 5);

  /*
  1    2
  3    4
  5    6
  7    8
  9    10
  */
  Test(2, 5);

  /*
  1    2    3
  4    5    6
  7    8    9
  10   11   12
  13   14   15
  */
  Test(3, 5);

  /*
  1    2    3    4
  5    6    7    8
  9    10   11   12
  13   14   15   16
  17   18   19   20
  */
  Test(4, 5);

  /*
  1    2    3    4    5
  */
  Test(5, 1);

  /*
  1    2    3    4    5
  6    7    8    9    10
  */
  Test(5, 2);

  /*
  1    2    3    4    5
  6    7    8    9    10
  11   12   13   14    15
  */
  Test(5, 3);

  /*
  1    2    3    4    5
  6    7    8    9    10
  11   12   13   14   15
  16   17   18   19   20
  */
  Test(5, 4);

  return 0;
}
