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

// 面试题57(二): 和为s的连续正数序列
// 题目: 输入一个正数s, 打印出所有和为s的连续正数序列(至少含有两个数). 例如输入15, 由于1 + 2 + 3 +
// 4 + 5 = 4 + 5 + 6 = 7 + 8 = 15, 所以结果打印出3个连续序列1～5, 4～6和7～8.

#include <cstdio>
#include <stdexcept>

void FindContinuousSequence(int n) {
  if (n <= 2) throw std::invalid_argument("");
  int first = 1;
  int last = 2;
  while (last <= ((n >> 1) + 1)) {
    int sum = ((first + last) * (last - first + 1)) >> 1;
    if (sum == n) {
      printf("%d ~ %d\n", first, last);
      ++last;
    } else if (sum < n) {
      ++last;
    } else {
      ++first;
    }
  }
  return;
}

// ====================测试代码====================
void Test(const char* testName, int sum) {
  if (testName != nullptr) printf("%s for %d begins: \n", testName, sum);
  try {
    FindContinuousSequence(sum);
  } catch (std::invalid_argument const& ia) {
    if (sum <= 2) {
      printf("Passed!\n");
    } else {
      printf("Failed!\n");
    }
  }
}

int main(int argc, char* argv[]) {
  Test("test1", 1);
  Test("test2", 3);
  Test("test3", 4);
  Test("test4", 9);
  Test("test5", 15);
  Test("test6", 100);

  return 0;
}
