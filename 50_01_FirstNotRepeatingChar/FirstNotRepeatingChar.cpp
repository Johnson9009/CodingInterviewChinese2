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

// 面试题50(一): 字符串中第一个只出现一次的字符
// 题目: 在字符串中找出第一个只出现一次的字符. 如输入"abaccdeff", 则输出'b'.

#include <cstdio>
#include <stdexcept>
#include <string>

char FirstNotRepeatingChar(char const* str) {
  if (str == nullptr) throw std::invalid_argument("");
  int counts[256] = {0};
  char const* cur_char = str;
  while (*cur_char != '\0') {
    ++(counts[*cur_char]);
    ++cur_char;
  }
  cur_char = str;
  while (*cur_char != '\0') {
    if (counts[*cur_char] == 1) return *cur_char;
    ++cur_char;
  }
  throw std::invalid_argument("");
}

// ====================测试代码====================
void Test(const char* pString, char expected) {
  try {
    if (FirstNotRepeatingChar(pString) == expected) {
      printf("Test passed.\n");
    } else {
      printf("Test failed.\n");
    }
  } catch (std::invalid_argument const& ia) {
    if (expected == '\0') {
      printf("Test passed.\n");
    } else {
      printf("Test failed.\n");
    }
  }
}

int main(int argc, char* argv[]) {
  // 常规输入测试，存在只出现一次的字符
  Test("google", 'l');

  // 常规输入测试，不存在只出现一次的字符
  Test("aabccdbd", '\0');

  // 常规输入测试，所有字符都只出现一次
  Test("abcdefg", 'a');

  // 鲁棒性测试，输入nullptr
  Test(nullptr, '\0');

  return 0;
}
