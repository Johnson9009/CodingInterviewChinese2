# Copyright (c) 2018-present, Johnson9009.
#
# This file is distributed under the MIT license. See the LICENSE file for details.

# The Top CMake Script
#
# This project use Google Test as unit test framework, the code of this project follow Google C++
# Style Guide, in order to checking source files automatically, a custom target is created to call
# the lint tool "cpplint.py".

cmake_minimum_required(VERSION 3.9)
project(CodingInterviewChinese2 CXX)

# In our project, we organize all source files of each target through CMake script files recursive
# including. Every directory with source files in it, must have a CMake script file "source.cmake",
# and each CMake script file(this file(CMakeLists.txt) no exception) should contain all its sub
# directory's "source.cmake" by "include" command.
include(${CMAKE_CURRENT_LIST_DIR}/01_AssignmentOperator/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/03_01_DuplicationInArray/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/03_02_DuplicationInArrayNoEdit/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/04_FindInPartiallySortedMatrix/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/05_ReplaceSpaces/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/06_PrintListInReversedOrder/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/07_ConstructBinaryTree/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/08_NextNodeInBinaryTrees/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/09_QueueWithTwoStacks/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/10_Fibonacci/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/11_MinNumberInRotatedArray/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/12_StringPathInMatrix/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/13_RobotMove/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/14_CuttingRope/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/15_NumberOf1InBinary/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/16_Power/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/17_Print1ToMaxOfNDigits/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/18_01_DeleteNodeInList/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/18_02_DeleteDuplicatedNode/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/19_RegularExpressionsMatching/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/20_NumericStrings/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/21_ReorderArray/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/22_KthNodeFromEnd/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/23_EntryNodeInListLoop/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/24_ReverseList/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/25_MergeSortedLists/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/26_SubstructureInTree/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/27_MirrorOfBinaryTree/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/28_SymmetricalBinaryTree/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/29_PrintMatrix/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/30_MinInStack/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/31_StackPushPopOrder/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/32_01_PrintTreeFromTopToBottom/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/32_02_PrintTreesInLines/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/32_03_PrintTreesInZigzag/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/33_SquenceOfBST/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/34_PathInTree/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/35_CopyComplexList/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/36_ConvertBinarySearchTree/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/37_SerializeBinaryTrees/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/38_StringPermutation/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/39_MoreThanHalfNumber/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/40_KLeastNumbers/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/41_StreamMedian/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/42_GreatestSumOfSubarrays/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/43_NumberOf1/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/44_DigitsInSequence/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/45_SortArrayForMinNumber/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/46_TranslateNumbersToStrings/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/47_MaxValueOfGifts/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/48_LongestSubstringWithoutDup/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/49_UglyNumber/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/50_01_FirstNotRepeatingChar/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/50_02_FirstCharacterInStream/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/51_InversePairs/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/52_FirstCommonNodesInLists/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/53_01_NumberOfK/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/53_02_MissingNumber/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/53_03_IntegerIdenticalToIndex/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/54_KthNodeInBST/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/55_01_TreeDepth/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/55_02_BalancedBinaryTree/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/56_01_NumbersAppearOnce/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/56_02_NumberAppearingOnce/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/57_01_TwoNumbersWithSum/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/57_02_ContinuousSquenceWithSum/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/58_01_ReverseWordsInSentence/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/58_02_LeftRotateString/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/59_01_MaxInSlidingWindow/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/59_02_QueueWithMax/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/60_DicesProbability/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/61_ContinousCards/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/62_LastNumberInCircle/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/63_MaximalProfit/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/64_Accumulate/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/65_AddTwoNumbers/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/66_ConstuctArray/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/67_StringToInt/source.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/68_CommonParentInTree/source.cmake)

# Because source file list of each target, such as "UNIT_TEST_SOURCES", is defined in above CMake
# script files, so we must lay all commands which need source file list, such as "add_executable",
# bellow to any "include" command which aim to include "source.cmake".
