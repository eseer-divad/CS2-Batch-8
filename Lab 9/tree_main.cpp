// Assignment 8 Binary Search Tree driver
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tree.hpp"

int main() {
    int num = 14;
    for(int round=1; round <= 2; round++){
    std::cout << "Round " << round << std::endl;
    Tree<int> myTree;
    for(int i=0; i < round * num; i++){
    myTree.insertNode(i * 3);
    }
    std::cout<<"whole tree values (In Order):"<<std::endl;
    myTree.inOrderTraversal();
    std::cout<<std::endl;
    std::cout<<"whole tree values (Pre Order):"<<std::endl;
    myTree.postOrderTraversal();
    std::cout<<std::endl;
    std::cout << "Number of nodes: " << myTree.Count() << std::endl;
    std::cout << "Height of the tree: " << myTree.getDepth() << std::endl;
    myTree.Optimize();
    std::cout<<std::endl<<"After optimization:"<<std::endl;
    std::cout<<"whole tree values (In Order):"<<std::endl;
    myTree.inOrderTraversal();
    std::cout<<std::endl;
    std::cout<<"whole tree values (Pre Order):"<<std::endl;
    myTree.postOrderTraversal();
    std::cout<<std::endl;
    std::cout << "Number of nodes: " << myTree.Count() << std::endl;
    std::cout << "Height of the tree: " << myTree.getDepth() << std::endl;
    std::cout << std::endl;
    }
    std::cout << "Done" << std::endl;
    return 0;
}
