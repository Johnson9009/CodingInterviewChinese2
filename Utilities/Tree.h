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

#include <vector>

struct TreeNode 
{
    int                       m_nValue;    
    std::vector<TreeNode*>    m_vChildren;    
};

EXPORT TreeNode* CreateTreeNode(int value);
EXPORT void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild);
EXPORT void PrintTreeNode(const TreeNode* pNode);
EXPORT void PrintTree(const TreeNode* pRoot);
EXPORT void DestroyTree(TreeNode* pRoot);
