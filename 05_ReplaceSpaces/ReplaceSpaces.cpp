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

// 面试题5: 替换空格
// 题目: 请实现一个函数, 把字符串中的每个空格替换成"%20". 例如输入"We are happy.", 则输出
// "We%20are%20happy.".

#include <cstdio>
#include <cstring>
#include <stdexcept>

void ReplaceBlank(char* str, int capacity) {
  if ((str == nullptr) || (capacity <= 0)) throw std::invalid_argument("");
  int orig_length = 0;
  int blank_cnt = 0;
  int i = 0;
  while ((str[i] != '\0') && (i < capacity)) {
    ++orig_length;
    if (str[i] == ' ') ++blank_cnt;
    ++i;
  }
  if (i >= capacity) throw std::invalid_argument("");
  int final_length = orig_length + blank_cnt * 2;
  if ((final_length + 1) > capacity) throw std::invalid_argument("");

  int final_idx = final_length;
  int orig_idx = orig_length;
  while ((orig_idx >= 0) && (final_idx > orig_idx)) {
    if (str[orig_idx] == ' ') {
      str[final_idx] = '0';
      str[final_idx - 1] = '2';
      str[final_idx - 2] = '%';
      final_idx -= 2;
    } else {
      str[final_idx] = str[orig_idx];
    }
    --orig_idx;
    --final_idx;
  }
  return;
}

// ====================测试代码====================
void Test(char const* testName, char str[], int length, char const expected[]) {
  if (testName != nullptr) printf("%s begins: ", testName);

  try {
    ReplaceBlank(str, length);
    if (strcmp(str, expected) == 0) {
      printf("passed.\n");
    } else {
      printf("failed.\n");
    }
  } catch (std::invalid_argument const& ia) {
    if (expected == nullptr) {
      printf("passed.\n");
    } else {
      printf("failed.\n");
    }
  }
}

// 空格在句子中间
void Test1() {
  const int length = 100;

  char str[length] = "hello world";
  Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2() {
  const int length = 100;

  char str[length] = " helloworld";
  Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3() {
  const int length = 100;

  char str[length] = "helloworld ";
  Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4() {
  const int length = 100;

  char str[length] = "hello  world";
  Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5() {
  Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6() {
  const int length = 100;

  char str[length] = "";
  Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7() {
  const int length = 100;

  char str[length] = " ";
  Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8() {
  const int length = 100;

  char str[length] = "helloworld";
  Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9() {
  const int length = 100;

  char str[length] = "   ";
  Test("Test9", str, length, "%20%20%20");
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

  return 0;
}
