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

// 面试题58(一): 翻转单词顺序
// 题目: 输入一个英文句子, 翻转句子中单词的顺序, 但单词内字符的顺序不变. 为简单起见, 标点符号和普通
// 字母一样处理. 例如输入字符串"I am a student.", 则输出"student. a am I".

#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <string>
#include "../Utilities/StringUtil.h"

void ReverseString(char* str, int begin, int end) {
  int length = strlen(str);
  if ((str == nullptr) || (begin > end) || (begin < 0) || (end > length)) {
    throw std::invalid_argument("");
  }
  if ((begin + 1) >= end) return;
  int first = begin;
  int last = end - 1;
  while (first < last) {
    std::swap(str[first], str[last]);
    ++first;
    --last;
  }
  return;
}

void ReverseSentence(char* str) {
  if (str == nullptr) throw std::invalid_argument("");
  int length = strlen(str);
  int begin = 0;
  int end = 0;
  while (str[end] != '\0') {
    if (str[end] == ' ') {
      ReverseString(str, begin, end);
      while (str[end] == ' ') ++end;
      begin = end;
    } else {
      ++end;
    }
  }
  ReverseString(str, begin, end);
  ReverseString(str, 0, length);
  return;
}

// ====================测试代码====================
void Test(const char* testName, char* input, const char* expectedResult) {
  if (testName != nullptr) printf("%s begins: ", testName);
  try {
    ReverseSentence(input);
    if ((input == nullptr && expectedResult == nullptr) ||
        (input != nullptr && strcmp(input, expectedResult) == 0)) {
      printf("Passed.\n\n");
    } else {
      printf("Failed.\n\n");
    }
  } catch (std::invalid_argument const& ia) {
    if (expectedResult == nullptr) {
      printf("Passed.\n\n");
    } else {
      printf("Failed.\n\n");
    }
  }
}

// 功能测试，句子中有多个单词
void Test1() {
  char input[] = "I am a student.";
  char expected[] = "student. a am I";

  Test("Test1", input, expected);
}

// 功能测试，句子中只有一个单词
void Test2() {
  char input[] = "Wonderful";
  char expected[] = "Wonderful";

  Test("Test2", input, expected);
}

// 鲁棒性测试
void Test3() {
  Test("Test3", nullptr, nullptr);
}

// 边界值测试，测试空字符串
void Test4() {
  char input[] = "";
  Test("Test4", input, "");
}

// 边界值测试，字符串中只有空格
void Test5() {
  char input[] = "   ";
  char expected[] = "   ";
  Test("Test5", input, expected);
}

int main(int argc, char* argv[]) {
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();

  return 0;
}
