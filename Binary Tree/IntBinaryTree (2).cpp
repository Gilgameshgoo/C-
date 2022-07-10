//
// Created by CosaNostra on 15.04.2022.
//

#include "IntBinaryTree.h"
#include <iostream>
 #include "IntBinaryTree.h"
 using namespace std;


void IntBinaryTree::insert(TreeNode * &tree, int num) const
{
    if (!tree)
    {
        tree = new TreeNode(num);
        return;
    }

    if (tree->value == num){return;}

    if (num < tree->value){insert(tree->left, num);}
    else{insert(tree->right, num);}

}


void IntBinaryTree::displayPreOrder(const TreeNode *tree) const
{
    if (tree)
    {
        cout << tree->value << "  ";
        displayPreOrder(tree->left);
        displayPreOrder(tree->right);
    }
}


bool IntBinaryTree::search(int num) const
{
    TreeNode *tree = root;

    while (tree)
    {
        if (tree->value == num)
        return true;
        else if (num < tree->value)
        tree = tree->left;
        else
        tree = tree->right;
    }
    return false;
}


void IntBinaryTree::destroySubtree(TreeNode * &tree) const
 {
       if (!tree) return;
       destroySubtree(tree->left);
       destroySubtree(tree->right);
       delete tree;
 }

int IntBinaryTree::size(TreeNode *&tree)const
    {
    if (!tree)
    return 0;
    else
    return(size(tree->left) + 1 + size(tree->right));
    }




int IntBinaryTree::maxDepth(TreeNode* &tree) const
{
    if (!tree)
        return -1;
    else
    {

        int lDepth = maxDepth(tree->left);
        int rDepth = maxDepth(tree->right);



        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}



