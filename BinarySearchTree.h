/**
 * @file    BinarySearchTree.h
 * @brief   header file of BinarySearchTree class
 *
 * This file contains the defination of BinarySearchTree class with its
 * constructor, destructor and member functions.
 *
 * @remarks some of the functions are not implemented and hence were written
 * just for the implementation of Rule of Three.
 * 
 * @author  Naresh Gurung
 * @date    23-03-2018
 */
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

//header files
#include <iostream>
#include "CSZNode.h"

//defination of class BinarySearchTree
class BinarySearchTree {
public:
    //constructor
    BinarySearchTree( ) = default;
    
    //destructor
    ~BinarySearchTree( );
    
    //member functions for adding and writing
    void add_recursively (const CityStateZip& new_city);
    void add_iteratively (const CityStateZip& new_city);
    void write_recursively (std::ostream& strm) const;
    void write_iteratively (std::ostream& strm) const;
    void erase_recursively();

private:                 
    // methods
    // called by public version
    void add_recursively (CSZNode* new_node, CSZNode* current_root);
    // called by public version
    void write_recursively (std::ostream& strm, CSZNode* current_root) const;
    void erase_recursively (CSZNode* currentRoot);
    
    // attributes
    CSZNode* root = nullptr; // initially empty tree (null root)
    
    // disallow copy-ctor and assignment:
    BinarySearchTree (const BinarySearchTree&) = delete;
    BinarySearchTree& operator= (const BinarySearchTree& rhs) = delete;
};

#endif