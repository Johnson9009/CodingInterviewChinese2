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

// 面试题38: 字符串的排列
// 题目: 输入一个字符串, 打印出该字符串中字符的所有排列. 例如输入字符串abc, 则打印出由字符a, b, c所
// 能排列出来的所有字符串abc, acb, bac, bca, cab和cba.

#include <cstdio>
#include <cstring>
#include <stdexcept>

void PermutationCore(char* str, int idx) {
  int length = strlen(str);
  if ((str == nullptr) || (idx < 0) || (idx > length)) throw std::invalid_argument("");
  if (idx == length) {
    printf("%s ", str);
    return;
  }
  for (int i = idx; i < length; ++i) {
    std::swap(str[idx], str[i]);
    PermutationCore(str, (idx + 1));
    std::swap(str[i], str[idx]);
  }
  return;
}

void Permutation(char* str) {
  if (str == nullptr) throw std::invalid_argument("");
  PermutationCore(str, 0);
  return;
}

// ====================测试代码====================
void Test(char* pStr) {
  if (pStr == nullptr) {
    printf("Test for nullptr begins:\n");
  } else {
    printf("Test for %s begins:\n", pStr);
  }

  try {
    Permutation(pStr);
  } catch (std::invalid_argument const& ia) {
    if (pStr == nullptr) {
      printf("Passed!\n");
    } else {
      printf("Failed!\n");
    }
  }
  printf("\n");
}

int main(int argc, char* argv[]) {
  Test(nullptr);

  char string1[] = "";
  Test(string1);

  char string2[] = "a";
  Test(string2);

  char string3[] = "ab";
  Test(string3);

  char string4[] = "abc";
  Test(string4);

  return 0;
}
