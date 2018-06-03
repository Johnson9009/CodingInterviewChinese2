/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer――名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

#include "Array.h"
#include <stdlib.h>
#include <utility>
#include <stdexcept>

// Random Partition
int RandomInRange(int begin, int end) {
  if ((begin + 1) >= end) throw std::invalid_argument("");
  int length = end - begin;
  return ((rand() % length) + begin);
}

int Partition(int *data, int begin, int end) {
  // This function should not be invoked when the data contain zero or only one item, and this
  // invoke condition must be ensured by the caller, because the caller must need to do this thing
  // no matter what is done here, so just throw exception.
  // Note that the "begin" and "end" can be unsigned type, so the condition mustn't contain minus
  // operator, in order to avoid something like you think the number is a negative number but
  // actually it is a very large positive number.
  if ((data == nullptr) || ((begin + 1) >= end)) throw std::invalid_argument("");
  int pivot_idx = RandomInRange(begin, end);
  std::swap(data[pivot_idx], data[end - 1]);
  int pivot = data[end - 1];
  int small_idx = begin;
  for (int i = begin; i < end; ++i) {
    if (data[i] < pivot) {
      if (i != small_idx) {
        std::swap(data[small_idx], data[i]);
      }
      ++small_idx;
    }
  }
  std::swap(data[small_idx], data[end - 1]);
  return small_idx;
}
