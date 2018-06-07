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

// 面试题20: 表示数值的字符串
// 题目: 请实现一个函数用来判断字符串是否表示数值(包括整数和小数). 例如, 字符串"+100", "5e2",
// "-123", "3.1416"及"-1E-16"都表示数值, 但"12e", "1a3.14", "1.2.3", "+-5"及"12e+5.4"都不是.

#include <stdio.h>
#include <stdexcept>

bool ScanUnsignedNumber(char const* str, int& idx) {
  if ((str == nullptr) || (idx < 0)) throw std::invalid_argument("");
  int orig_idx = idx;
  while ((str[idx] != '\0') && (str[idx] >= '0') && (str[idx] <= '9')) ++idx;
  return (idx > orig_idx) ? true : false;
}

bool ScanSignedNumber(char const* str, int& idx) {
  if ((str == nullptr) || (idx < 0)) throw std::invalid_argument("");
  if ((str[idx] == '+') || (str[idx] == '-')) ++idx;
  return ScanUnsignedNumber(str, idx);
}

bool IsNumeric(char const* str) {
  if (str == nullptr) throw std::invalid_argument("");
  int cur_idx = 0;
  bool result = ScanSignedNumber(str, cur_idx);

  if (str[cur_idx] == '.') {
    ++cur_idx;
    result |= ScanUnsignedNumber(str, cur_idx);
  }

  if ((str[cur_idx] == 'e') || (str[cur_idx] == 'E')) {
    ++cur_idx;
    result &= ScanSignedNumber(str, cur_idx);
  }
  return ((str[cur_idx] == '\0') && result);
}

// ====================测试代码====================
void Test(const char* testName, const char* str, bool expected) {
  if (testName != nullptr) printf("%s begins: ", testName);

  try {
    if (IsNumeric(str) == expected) {
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

int main(int argc, char* argv[]) {
  Test("Test1", "100", true);
  Test("Test2", "123.45e+6", true);
  Test("Test3", "+500", true);
  Test("Test4", "5e2", true);
  Test("Test5", "3.1416", true);
  Test("Test6", "600.", true);
  Test("Test7", "-.123", true);
  Test("Test8", "-1E-16", true);
  Test("Test9", "1.79769313486232E+308", true);

  printf("\n\n");

  Test("Test10", "12e", false);
  Test("Test11", "1a3.14", false);
  Test("Test12", "1+23", false);
  Test("Test13", "1.2.3", false);
  Test("Test14", "+-5", false);
  Test("Test15", "12e+5.4", false);
  Test("Test16", ".", false);
  Test("Test17", ".e1", false);
  Test("Test18", "e1", false);
  Test("Test19", "+.", false);
  Test("Test20", "", false);
  Test("Test21", nullptr, false);

  return 0;
}
