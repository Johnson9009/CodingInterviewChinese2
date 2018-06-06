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

// 面试题17: 打印1到最大的n位数
// 题目: 输入数字n, 按顺序打印出从1最大的n位十进制数. 比如输入3, 则打印出1, 2, 3一直到最大的3位数即
// 999.

#include <cstdio>
#include <cstring>
#include <memory>

void PrintNumber(char const* number_str) {
  char const* cur_char = number_str;
  while (*cur_char == '0') ++cur_char;
  while (*cur_char != '\0') {
    printf("%c", *cur_char);
    ++cur_char;
  }
  printf("\t");
}

// ====================方法一====================
bool IncreaseNumber(char* number_str) {
  if (number_str == nullptr) throw std::invalid_argument("");
  int length = strlen(number_str);
  int carry = 1;
  int cur_idx = length - 1;
  while (carry != 0) {
    int result = (number_str[cur_idx] - '0') + carry;
    number_str[cur_idx] = '0' + result % 10;
    carry = result / 10;
    --cur_idx;
    if ((cur_idx < 0) && (carry != 0)) return true;
  }
  return false;
}

void Print1ToMaxOfNDigits_1(int n) {
  if (n <= 0) throw std::invalid_argument("");
  char* number_str = new char[n + 1];
  std::memset(number_str, '0', ((n + 1) * sizeof(char)));
  number_str[n] = '\0';

  while (IncreaseNumber(number_str) == false) {
    PrintNumber(number_str);
  }
  delete[] number_str;
  return;
}

// ====================方法二====================
void Print1ToMaxOfNDigits_Recursively(char* number_str, int length, int cur_idx) {
  if ((number_str == nullptr) || (length <= 0) || (cur_idx < 0) || (cur_idx > length)) {
    throw std::invalid_argument("");
  }

  if (cur_idx == length) {
    PrintNumber(number_str);
    return;
  }
  for (int i = 0; i < 10; ++i) {
    number_str[cur_idx] = '0' + i;
    Print1ToMaxOfNDigits_Recursively(number_str, length, (cur_idx + 1));
  }
  return;
}

void Print1ToMaxOfNDigits_2(int n) {
  if (n <= 0) throw std::invalid_argument("");
  char* number_str = new char[n + 1];
  std::memset(number_str, 0, (n + 1) * sizeof(char));
  Print1ToMaxOfNDigits_Recursively(number_str, n, 0);
  delete[] number_str;
  return;
}

// ====================测试代码====================
void Test(int n, bool is_invalid_args) {
  printf("Test for %d begins:\n", n);
  try {
    Print1ToMaxOfNDigits_1(n);
    Print1ToMaxOfNDigits_2(n);
  } catch (std::invalid_argument const& ia) {
    if (is_invalid_args == true) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
  }

  printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[]) {
  Test(1, false);
  Test(2, false);
  Test(3, false);
  Test(0, true);
  Test(-1, true);

  return 0;
}
