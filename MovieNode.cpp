#include "MovieNode.h"
#include <iostream>

Movie MovieNode::get_movie( ) const
{
    return movie;
}

MovieNode* MovieNode::get_next( ) const
{
    return next;
}

void MovieNode::set_next(MovieNode* new_next)
{
    next = new_next;
}

void MovieNode::write(std::ostream& fout) const
{
    movie.write(fout);
    if (next == nullptr)
    {
        fout << "( --------- )" << std::endl;
    }
    
    else
    {
        fout << "( " << next->movie.title << " )"<< std::endl;
    }
}

std::ostream& operator<<(std::ostream& outfile, const MovieNode& new_movie)
{
    new_movie.write(outfile);
    return outfile;
}

bool MovieNode::operator < ( const MovieNode& rhs ) const
{
    return (movie.title < rhs.get_movie().title);
}