#ifndef MOVIENODE_H
#define MOVIENODE_H

#include "Movie.h"

class MovieNode{
public:
    MovieNode (const Movie& new_movie) : movie{new_movie}{}
    
    Movie      get_movie ( ) const;
    MovieNode* get_next     ( ) const;
    void          set_next     (MovieNode* new_next);
    void          write        (std::ostream& fout) const;
    bool operator < ( const MovieNode& rhs ) const;
private:
    Movie      movie;
    MovieNode* next = nullptr;
};
std::ostream& operator<<(std::ostream& outfile, const MovieNode& new_movie);
#endif