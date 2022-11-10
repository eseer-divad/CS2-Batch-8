#ifndef TREENODE_HPP
#define TREENODE_HPP

// TreeNode class-template definition.

// forward declaration of class Tree
template<typename NODETYPE> class Tree;

// TreeNode class-template definition
template<typename NODETYPE>
class TreeNode {
   friend class Tree<NODETYPE>;
public:
   // constructor
   TreeNode(const NODETYPE& d) : data{d} {}

   // return copy of node's data
   NODETYPE getData() const {return data;}

   // return a leftPtr
   TreeNode* getLeftPtr() const {
      return leftPtr;
   }

   // return a rightPtr
   TreeNode* getRightPtr() const {
      return rightPtr;
   }

   // set value for leftPtr
   void setLeftPtr(TreeNode* ptr) {
      leftPtr = ptr;
   }

   // set value for rightPtr
   void setRightPtr(TreeNode* ptr) {
      rightPtr = ptr;
   }
private:
   TreeNode<NODETYPE>* leftPtr{nullptr}; // pointer to left subtree
   NODETYPE data;
   TreeNode<NODETYPE>* rightPtr{nullptr}; // pointer to right subtree
};

#endif // TREENODE_HPP
