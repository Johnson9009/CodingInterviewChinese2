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

// 面试题67: 把字符串转换成整数
// 题目: 请你写一个函数StrToInt, 实现把字符串转换成整数这个功能. 当然, 不能使用atoi或者其他类似的库
// 函数.

#include <climits>
#include <cstdio>
#include <stdexcept>

int StrToInt(char const* str) {
  if ((str == nullptr) || (str[0] == '\0')) throw std::invalid_argument("");
  int sign = 1;
  int idx = 0;
  if ((str[idx] == '+') || (str[idx] == '-')) {
    if (str[idx] == '-') sign = -1;
    ++idx;
    if (str[idx] == '\0') throw std::invalid_argument("");
  }
  int base = 0;
  while (str[idx] != '\0') {
    if ((str[idx] > '9') || (str[idx] < '0')) throw std::invalid_argument("");
    if ((base > (INT_MAX / 10)) ||
        ((base == (INT_MAX / 10)) && ((str[idx] - '0') > (INT_MAX % 10)))) {
      return (sign == 1) ? INT_MAX : INT_MIN;
    }
    base = base * 10 + (str[idx] - '0');
    ++idx;
  }
  return (sign * base);
}

// ====================测试代码====================
void Test(const char* string) {
  try {
    printf("number for %s is: %d.\n", string, StrToInt(string));
  } catch (std::invalid_argument const& ia) {
    printf("the input %s is invalid.\n", string);
  }
}

int main(int argc, char* argv[]) {
  Test(nullptr);
  Test("");
  Test("123");
  Test("+123");
  Test("-123");
  Test("1a33");
  Test("+0");
  Test("-0");
  //有效的最大正整数, 0x7FFFFFFF
  Test("+2147483647");
  Test("-2147483647");
  Test("+2147483648");
  //有效的最小负整数, 0x80000000
  Test("-2147483648");
  Test("+2147483649");
  Test("-2147483649");
  Test("+");
  Test("-");
  return 0;
}
