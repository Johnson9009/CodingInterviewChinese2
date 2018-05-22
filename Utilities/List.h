/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

#ifdef _WIN32
#define EXPORT __declspec (dllexport)
#else
#define EXPORT
#endif

struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;
};

EXPORT ListNode* CreateListNode(int value);
EXPORT void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
EXPORT void PrintListNode(ListNode* pNode);
EXPORT void PrintList(ListNode* pHead);
EXPORT void DestroyList(ListNode* pHead);
EXPORT void AddToTail(ListNode** pHead, int value);
EXPORT void RemoveNode(ListNode** pHead, int value);
