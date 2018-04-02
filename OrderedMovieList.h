#ifndef ORDEREDMOVIELIST_H
#define ORDEREDMOVIELIST_H

#include "MovieNode.h"
#include <iostream>

class OrderedMovieList
{
    public:
        void write(std::ostream& fout) const;
        Movie removeFromHead();
        void erase();
        void insert(const Movie& new_movie);
        ~OrderedMovieList();
    private:
        MovieNode* head = nullptr;
        
};
std::ostream& operator<<(std::ostream& fout, const OrderedMovieList& rhs);

#endif