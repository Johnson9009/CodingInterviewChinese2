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

// 面试题51: 数组中的逆序对
// 题目: 在数组中的两个数字如果前面一个数字大于后面的数字, 则这两个数字组成一个逆序对. 输入一个数组,
// 求出这个数组中的逆序对的总数.

#include <cstdio>
#include <cstring>
#include <stdexcept>

int MergeCore(int* data, int* tmp, int first, int last) {
  if ((data == nullptr) || (tmp == nullptr) || (first > last)) throw std::invalid_argument("");
  int mid_idx = ((last - first) >> 1) + first;
  int left_idx = mid_idx;
  int right_idx = last;
  int tmp_idx = last;
  int count = 0;
  while ((left_idx >= first) && (right_idx > mid_idx)) {
    if (data[left_idx] > data[right_idx]) {
      count += right_idx - (mid_idx + 1) + 1;
      tmp[tmp_idx] = data[left_idx];
      --left_idx;
    } else {
      tmp[tmp_idx] = data[right_idx];
      --right_idx;
    }
    --tmp_idx;
  }
  while (left_idx >= first) {
    tmp[tmp_idx] = data[left_idx];
    --tmp_idx;
    --left_idx;
  }
  while (right_idx > mid_idx) {
    tmp[tmp_idx] = data[right_idx];
    --tmp_idx;
    --right_idx;
  }
  for (int i = first; i <= last; ++i) {
    data[i] = tmp[i];
  }
  return count;
}

int MergeSort(int* data, int* tmp, int first, int last) {
  if ((data == nullptr) || (tmp == nullptr) || (first > last)) throw std::invalid_argument("");
  if (first == last) return 0;
  int mid = ((last - first) >> 1) + first;
  int left_count = MergeSort(data, tmp, first, mid);
  int right_count = MergeSort(data, tmp, (mid + 1), last);
  int count = MergeCore(data, tmp, first, last);
  return (left_count + right_count + count);
}

int InversePairs(int* data, int length) {
  if ((data == nullptr) || (length <= 0)) throw std::invalid_argument("");
  int* tmp = new int[length];
  std::memset(tmp, 0, (length * sizeof(int)));
  int count = MergeSort(data, tmp, 0, (length - 1));
  delete[] tmp;
  return count;
}

// ====================测试代码====================
void Test(char const* testName, int* data, int length, int expected) {
  if (testName != nullptr) printf("%s begins: ", testName);
  try {
    if (InversePairs(data, length) == expected) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
  } catch (std::invalid_argument const& ia) {
    if (expected == 0) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
  }
}

void Test1() {
  int data[] = {1, 2, 3, 4, 7, 6, 5};
  int expected = 3;

  Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2() {
  int data[] = {6, 5, 4, 3, 2, 1};
  int expected = 15;

  Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3() {
  int data[] = {1, 2, 3, 4, 5, 6};
  int expected = 0;

  Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4() {
  int data[] = {1};
  int expected = 0;

  Test("Test4", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递增排序
void Test5() {
  int data[] = {1, 2};
  int expected = 0;

  Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6() {
  int data[] = {2, 1};
  int expected = 1;

  Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7() {
  int data[] = {1, 2, 1, 2, 1};
  int expected = 3;

  Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8() {
  int expected = 0;

  Test("Test8", nullptr, 0, expected);
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

  return 0;
}
