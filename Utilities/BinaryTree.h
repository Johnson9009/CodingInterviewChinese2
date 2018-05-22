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

#pragma once

#ifdef _WIN32
#define EXPORT __declspec (dllexport)
#else
#define EXPORT
#endif

struct BinaryTreeNode 
{
    int                    m_nValue; 
    BinaryTreeNode*        m_pLeft;  
    BinaryTreeNode*        m_pRight; 
};

EXPORT BinaryTreeNode* CreateBinaryTreeNode(int value);
EXPORT void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
EXPORT void PrintTreeNode(const BinaryTreeNode* pNode);
EXPORT void PrintTree(const BinaryTreeNode* pRoot);
EXPORT void DestroyTree(BinaryTreeNode* pRoot);
