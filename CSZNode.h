/**
 * @file  CSZNode.h
 *
 * Defines a record containg CityStateZip and its
 * left and right pointer. Also the necessary member
 * functions for editing nodes.
 * 
 * @author  Naresh Gurung
 * @date    23-03-2018
 */
#ifndef CSZNODE_H
#define CSZNODE_H

//header files
#include "CityStateZip.h"
#include <iostream>

//defination of CSZNode class
class CSZNode {
public:
    //constructor
    CSZNode (const CityStateZip& data) : payload{data} {};
    
    //mutators
    void set_left (CSZNode* new_left);
    void set_right (CSZNode* new_right);
    
    //accessors
    CityStateZip get_data( ) const;
    CSZNode* get_left( ) const;
    CSZNode* get_right( ) const;
    
    //member funtions
    bool operator< (const CSZNode& op2) const;
    void write (std::ostream& fout) const;

private:
    
    //private attributes
    CityStateZip payload;   //instance of CityStateZip class
    CSZNode* left  = nullptr;
    CSZNode* right = nullptr;
};

//prototype for the overloading of << operator
std::ostream& operator<< (std::ostream& fout, const CSZNode& n);

#endif