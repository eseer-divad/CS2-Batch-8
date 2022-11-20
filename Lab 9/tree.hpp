/*
   COPYRIGHT (C) 1923 David Reese (dcr54@uakron.edu ) All rights reserved.
   Version. 1.01 09.09.1923
*/
#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <algorithm>
#include "Treenode.hpp"

// Tree class-template definition
template<typename NODETYPE> class Tree {
public:
   // insert node in Tree
   void insertNode(const NODETYPE& value) {
      insertNodeHelper(&rootPtr, value);
   }

   // begin preorder traversal of Tree
   void preOrderTraversal() const {
      preOrderHelper(rootPtr);
   }

   // begin inorder traversal of Tree
   void inOrderTraversal() const {
      inOrderHelper(rootPtr);
   }

   // begin postorder traversal of Tree
   void postOrderTraversal() const {
      postOrderHelper(rootPtr);
   }

   // get the depth of the tree
   int getDepth() const {
      return determineDepth(rootPtr);
   }

   // begin binary search
   TreeNode<NODETYPE>* binaryTreeSearch(int val) const {
      return binarySearchHelper(rootPtr, val);
   }

   // gives out the count of nodes in the tree
   int Count()
   {
       return countNodes(rootPtr);
   }


   void Optimize()
   {

   }

private:
   TreeNode<NODETYPE>* rootPtr{nullptr};

   // utility function called by insertNode; receives a pointer
   // to a pointer so that the function can modify pointer's value
   void insertNodeHelper(
      TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
      // subtree is empty; create new TreeNode containing value
      if (*ptr == nullptr) {
         *ptr = new TreeNode<NODETYPE>(value);
      }
      else { // subtree is not empty
             // data to insert is less than data in current node
         if (value <= (*ptr)->data) {
            insertNodeHelper(&((*ptr)->leftPtr), value);
         }
         else {
            insertNodeHelper(&((*ptr)->rightPtr), value);
         }
      }
   }

   // utility function to perform preorder traversal of Tree
   void preOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         std::cout << ptr->data << ' '; // process node
         preOrderHelper(ptr->leftPtr); // traverse left subtree
         preOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform inorder traversal of Tree
   void inOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         inOrderHelper(ptr->leftPtr); // traverse left subtree
         std::cout << ptr->data << ' '; // process node
         inOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform postorder traversal of Tree
   void postOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         postOrderHelper(ptr->leftPtr); // traverse left subtree
         postOrderHelper(ptr->rightPtr); // traverse right subtree
         std::cout << ptr->data << ' '; // process node
      }
   }

   // calculate the depth of the tree
   int determineDepth(TreeNode<NODETYPE>* parentPtr) const {

    if (parentPtr == NULL)
        return 0;

    // Find the height of left, right subtrees
    int left_depth = determineDepth(parentPtr->leftPtr);
    int right_depth = determineDepth(parentPtr->rightPtr);

    if (left_depth > right_depth)
        return (left_depth+1);
    else
        return (right_depth+1);

   }

   // do a binary search on the Tree
   TreeNode<NODETYPE>* binarySearchHelper(TreeNode<NODETYPE>* ptr, NODETYPE data) const {

    // Base Cases: root is null or data is present at root
    if (ptr == NULL || ptr->data == data)
       return ptr;

    // Key is greater than root's data
    if (ptr->data < data)
       return binarySearchHelper(ptr->rightPtr, data);

    // Key is smaller than root's data
    return binarySearchHelper(ptr->leftPtr, data);
   }
   //count the nodes of the tree starting from the root node rootPtr
   int countNodes(TreeNode<NODETYPE> *rootPtr) const
   {
       return 1 + countNodes(rootPtr->leftPtr) + countNodes(rootPtr->rightPtr);
   }
   //clean the nodes of the tree starting from the root node rootPtr
   void deleteSubTree(TreeNode<NODETYPE> *rootPtr)
   {
       if(rootPtr == NULL)
        return;

        deleteSubTree(rootPtr->leftPtr);
        deleteSubTree(rootPtr->rightPtr);

        std::cout << std::endl << rootPtr->data << "removed!";
        delete rootPtr;
        rootPtr = NULL;
    }
    //traverse the tree with in-order method. Put the values into the array
    //since it is in-order, the values in the array are small to large sorted
    //precondition: subTreeRootPtr is the root node of the tree. It starts from
    //                  the root node of the whole tree
    //              index is the array index which holds the value of the node subTreeRootPtr
    //                  It starts from 0, then increments
    //              arr is the array to hold values of all nodes
    //postcondition: when finished, arr holds values of all nodes in sorted order
    void PopulateArrayInOrder(TreeNode<NODETYPE> * subTreeRootPtr, int &index, NODETYPE arr[]) const
    {

    }
};

#endif // TREE_HPP
