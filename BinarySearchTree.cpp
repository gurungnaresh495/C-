

#include <iostream>
#include "BinarySearchTree.h"
#include <stack>

/**
 * @brief       This function gives you left pointer
 *
 * @param        none
 *
 * @return      returns the pointer of CSZNode 
 */
void BinarySearchTree::add_iteratively (const CityStateZip& new_city)
{
    CSZNode* new_node = new CSZNode{new_city};
    if ( root == nullptr )
    {
        root = new_node;
    }
    else
    {
        CSZNode* current = root;
        bool found = false;
        while ( !found )
        {
            if ( *new_node < *current && current->get_left() )
            {
                current = current->get_left();
            }
            else if( *new_node < *current )
            {
                found = true;
                current->set_left(new_node);
            }
            else if( current->get_right() )
            {
                current = current->get_right();
            }
            else
            {
                found = true;
                current->set_right( new_node);
            }
        }
    }
 }
 
 void BinarySearchTree::write_recursively( std::ostream& strm ) const
 {
    write_recursively(strm, root);
 }
 
 void BinarySearchTree::write_recursively ( std::ostream& strm, CSZNode* current_root ) const
 {
    if( current_root->get_left() )
    {
        write_recursively( strm, current_root->get_left() );
    }
    strm << *current_root << "\n";
    if ( current_root->get_right() )
    {
        write_recursively(strm, current_root->get_right());
    }
    return;
 }
 
 void BinarySearchTree::add_recursively( const CityStateZip& new_city )
 {
    CSZNode* new_node = new CSZNode{new_city};
    if (root == nullptr)
    {
        root = new_node;
    }
    else
    {
        add_recursively( new_node, root);
    }
 }
 
 void BinarySearchTree::add_recursively( CSZNode* new_node, CSZNode* current_root )
 {
  
    if ((*new_node < *current_root) && current_root->get_left())
    {
      current_root = current_root->get_left();
      add_recursively(new_node, current_root);
    }
    else if (*new_node < *current_root)
    {
      current_root->set_left(new_node);
    }
    
    if ((*current_root < *new_node) && current_root->get_right())
    {
      current_root = current_root->get_right();
      add_recursively(new_node, current_root);
    }
    else if (*current_root < *new_node)
    {
      current_root->set_right(new_node);
    }
 }
 
 void BinarySearchTree::write_iteratively (std::ostream& strm) const
 {
    std::stack<CSZNode*> pointers;
    CSZNode* current = root;
    bool result = true;
    while (result)
    {
        if (current)
        {
            pointers.push(current);
            current = current->get_left();
        }
        else if (!pointers.empty())
        {
            current = pointers.top();
            pointers.pop();
            strm << *current << '\n';
            current = current->get_right();
        }
        else
        {
            result = false;
        }
    }
    
 }
 
void BinarySearchTree::erase_recursively()
{
    erase_recursively(root);
}
void BinarySearchTree::erase_recursively(CSZNode* currentRoot)
 {
    if (currentRoot != nullptr)
    {
        if( currentRoot->get_left() )
        {
            erase_recursively(currentRoot->get_left());
            currentRoot->set_left(nullptr);
        }
        
        if ( currentRoot->get_right() )
        {
            erase_recursively(currentRoot->get_right());
            currentRoot->set_right(nullptr);
        }
        //std::cout << *currentRoot << '\n';
        delete currentRoot;
    }
    root = nullptr;
 }
 
 BinarySearchTree::~BinarySearchTree( )
 {
    std::cout << "** " << '\n';
    erase_recursively();
 }
 