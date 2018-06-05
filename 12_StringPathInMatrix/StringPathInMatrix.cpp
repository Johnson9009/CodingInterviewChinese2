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

// 面试题12: 矩阵中的路径
// 题目: 请设计一个函数, 用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径. 路径可以从矩阵
// 中任意一格开始, 每一步可以在矩阵中向左, 右, 上, 下移动一格. 如果一条路径经过了矩阵的某一格, 那么
// 该路径不能再次进入该格子. 例如在下面的3×4的矩阵中包含一条字符串"bfce"的路径(路径中的字母用下划线
// 标出). 但矩阵中不包含字符串"abfb"的路径, 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之
// 后, 路径不能再次进入这个格子.
// A B T G
// C F C S
// J D E H

#include <cstdio>
#include <cstring>
#include <stack>
#include <stdexcept>
#include <string>

bool HasPathCore(char const* matrix, int row_cnt, int col_cnt, int row_idx, int col_idx,
                 char const* cur_char, bool* visited) {
  if ((matrix == nullptr) || (cur_char == nullptr) || (visited == nullptr) || (row_cnt <= 0) ||
      (col_cnt <= 0)) {
    throw std::invalid_argument("");
  }

  int cur_idx = row_idx * col_cnt + col_idx;
  if ((row_idx < 0) || (col_idx < 0) || (row_idx >= row_cnt) || (col_idx >= col_cnt) ||
      (visited[cur_idx] == true) || (matrix[cur_idx] != *cur_char)) {
    return false;
  }
  char const* next_char = cur_char + 1;
  if (*next_char == '\0') return true;

  visited[cur_idx] = true;
  bool result = (HasPathCore(matrix, row_cnt, col_cnt, row_idx - 1, col_idx, next_char, visited) ||
                 HasPathCore(matrix, row_cnt, col_cnt, row_idx + 1, col_idx, next_char, visited) ||
                 HasPathCore(matrix, row_cnt, col_cnt, row_idx, col_idx - 1, next_char, visited) ||
                 HasPathCore(matrix, row_cnt, col_cnt, row_idx, col_idx + 1, next_char, visited));
  visited[cur_idx] = false;
  return result;
}

bool HasPath(char const* matrix, int row_cnt, int col_cnt, char const* str) {
  if ((matrix == nullptr) || (row_cnt <= 0) || (col_cnt <= 0) || (str == nullptr)) {
    throw std::invalid_argument("");
  }
  bool* visited = new bool[row_cnt * col_cnt];
  memset(visited, 0, (row_cnt * col_cnt) * sizeof(bool));

  for (int row_idx = 0; row_idx < row_cnt; ++row_idx) {
    for (int col_idx = 0; col_idx < col_cnt; ++col_idx) {
      if (HasPathCore(matrix, row_cnt, col_cnt, row_idx, col_idx, str, visited) == true) {
        delete[] visited;
        return true;
      }
    }
  }
  delete[] visited;
  return false;
}

// ====================测试代码====================
void Test(const char* testName, const char* matrix, int rows, int cols, const char* str,
          bool expected) {
  if (testName != nullptr) printf("%s begins: ", testName);

  try {
    if (HasPath(matrix, rows, cols, str) == expected) {
      printf("Passed.\n");
    } else {
      printf("FAILED.\n");
    }
  } catch (std::invalid_argument const& ia) {
    if (expected == false) {
      printf("Passed.\n");
    } else {
      printf("FAILED.\n");
    }
  }
}

// ABTG
// CFCS
// JDEH

// BFCE
void Test1() {
  const char* matrix = "ABTGCFCSJDEH";
  const char* str = "BFCE";

  Test("Test1", (const char*)matrix, 3, 4, str, true);
}

// ABCE
// SFCS
// ADEE

// SEE
void Test2() {
  const char* matrix = "ABCESFCSADEE";
  const char* str = "SEE";

  Test("Test2", (const char*)matrix, 3, 4, str, true);
}

// ABTG
// CFCS
// JDEH

// ABFB
void Test3() {
  const char* matrix = "ABTGCFCSJDEH";
  const char* str = "ABFB";

  Test("Test3", (const char*)matrix, 3, 4, str, false);
}

// ABCEHJIG
// SFCSLOPQ
// ADEEMNOE
// ADIDEJFM
// VCEIFGGS

// SLHECCEIDEJFGGFIE
void Test4() {
  const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
  const char* str = "SLHECCEIDEJFGGFIE";

  Test("Test4", (const char*)matrix, 5, 8, str, true);
}

// ABCEHJIG
// SFCSLOPQ
// ADEEMNOE
// ADIDEJFM
// VCEIFGGS

// SGGFIECVAASABCEHJIGQEM
void Test5() {
  const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
  const char* str = "SGGFIECVAASABCEHJIGQEM";

  Test("Test5", (const char*)matrix, 5, 8, str, true);
}

// ABCEHJIG
// SFCSLOPQ
// ADEEMNOE
// ADIDEJFM
// VCEIFGGS

// SGGFIECVAASABCEEJIGOEM
void Test6() {
  const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
  const char* str = "SGGFIECVAASABCEEJIGOEM";

  Test("Test6", (const char*)matrix, 5, 8, str, false);
}

// ABCEHJIG
// SFCSLOPQ
// ADEEMNOE
// ADIDEJFM
// VCEIFGGS

// SGGFIECVAASABCEHJIGQEMS
void Test7() {
  const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
  const char* str = "SGGFIECVAASABCEHJIGQEMS";

  Test("Test7", (const char*)matrix, 5, 8, str, false);
}

// AAAA
// AAAA
// AAAA

// AAAAAAAAAAAA
void Test8() {
  const char* matrix = "AAAAAAAAAAAA";
  const char* str = "AAAAAAAAAAAA";

  Test("Test8", (const char*)matrix, 3, 4, str, true);
}

// AAAA
// AAAA
// AAAA

// AAAAAAAAAAAAA
void Test9() {
  const char* matrix = "AAAAAAAAAAAA";
  const char* str = "AAAAAAAAAAAAA";

  Test("Test9", (const char*)matrix, 3, 4, str, false);
}

// A

// A
void Test10() {
  const char* matrix = "A";
  const char* str = "A";

  Test("Test10", (const char*)matrix, 1, 1, str, true);
}

// A

// B
void Test11() {
  const char* matrix = "A";
  const char* str = "B";

  Test("Test11", (const char*)matrix, 1, 1, str, false);
}

void Test12() {
  Test("Test12", nullptr, 0, 0, nullptr, false);
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
  Test12();

  return 0;
}
