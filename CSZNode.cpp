/**
 * @file    CSZNode.cpp
 * @brief   implementation file of CSZNode.h
 *
 * This files contains all the implementation of the
 * mutators, accessors and the member functions
 *
 * @author  Naresh Gurung
 * @date    23-03-2018
 */

//header files
#include <iostream>
#include "CSZNode.h"

/**
 * @brief   this function sets the new pointer as a left pointer
 * 
 * @param        new_left       pointer of CSZNode
 */
void CSZNode::set_left( CSZNode* new_left )
{
    left = new_left;
}

/**
 * @brief     This function sets the new pointer as a right pointer       
 *
 * @param        new_right      pointer of CSZNode
 */
void CSZNode::set_right( CSZNode* new_right )
{
    right = new_right;
}

/**
 * @brief       This function gets the data of the node
 *
 * @param        none
 *
 * @return      returns the instance of CityStateZip
 */
CityStateZip CSZNode::get_data( ) const
{
    return payload;
}

/**
 * @brief       This function gives you left pointer
 *
 * @param        none
 *
 * @return      returns the pointer of CSZNode 
 */
CSZNode* CSZNode::get_left( ) const
{
    return left;
}

/**
 * @brief       This function gives you right pointer
 *
 * @param        none
 *
 * @return      returns the pointer of CSZNode 
 */
CSZNode* CSZNode::get_right( ) const
{
    return right;
}

/**
 * @brief       this function writes the data of the node on stream
 *
 * @param        fout       instance of ostream 
 */
void CSZNode::write( std::ostream& fout ) const
{
    payload.write(fout);
}

/**
 * @brief       this function writes the data of the given node on
 *              stream calling write function
 *
 * @param       fout       instance of ostream
 * @param       n          instance of CSZNode
 *
 * @return      returns the instance of ostream
 */
std::ostream& operator<<( std::ostream& fout, const CSZNode& n )
{
    n.write(fout);
    return fout;
}

/**
 * @brief       compares the two nodes using thier data
 *
 * @param        op2     instance of CSZNode
 *
 * @return  true if left node is smaller or else false
 */
bool CSZNode::operator < (const CSZNode& op2) const
{
    return (payload.city() < op2.get_data().city());
}