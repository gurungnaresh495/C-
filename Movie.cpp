#include "Movie.h"
#include <iostream>

Movie::Movie( std::istream& infile )
{
       
    std::getline(infile, title, '|');
    
    infile >> year;
    infile.ignore();
    getline(infile, director, '|');
    infile >> rating;
    infile.ignore();
}

void Movie::write( std::ostream& outfile ) const
{
    outfile << title << " (" << year << ") " << rating << " - "
            << director ;
}

std::ostream& operator<<( std::ostream& outfile, const Movie& movie )
{
    movie.write(outfile);
    return outfile;
}