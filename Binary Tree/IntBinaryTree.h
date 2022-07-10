//
// Created by CosaNostra on 15.04.2022.
//

#ifndef LAB_TREE_INTBINARYTREE_H
#define LAB_TREE_INTBINARYTREE_H

#include <iostream>
using namespace std;
class IntBinaryTree {
private:
    struct TreeNode {
        int value;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int value1,
                 TreeNode *left1 = nullptr,
                 TreeNode *right1 = nullptr) {
            value = value1;
            left = left1;
            right = right1;
        }
    };

    TreeNode  *root;

    void insert(TreeNode *&tree, int num) const;

    void destroySubtree(TreeNode *&) const;

    void displayPreOrder(const TreeNode *tree) const;

    int size(TreeNode *&tree) const;

    int maxDepth(TreeNode *&tree) const;

    bool search(int num) const;



public:

    IntBinaryTree()              // Constructor
    {
        root = nullptr;
    }

    ~IntBinaryTree()             // Destructor
    {
        destroySubtree(root);
    }

    void Find(){
        cout<<"Enter Num"<<endl;
        int num;
        cin>>num;
        if(search(num)){cout<<"Found"<<endl;}
        else{cout<<"Not found"<<endl;}

    }

    void Insertion() {
        cout<<"Enter Num"<<endl;
        int num;
        cin>>num;
        insert(root, num);
    }

    void showPreOrder() const {
        displayPreOrder(root);
    }

    void showSize() {
        cout << size(root) << endl;
    }

    void showHeight() {
        cout << maxDepth(root) << endl;

    };
};

#endif //LAB_TREE_INTBINARYTREE_H
