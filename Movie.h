#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>

struct Movie
{
    std::string title;              /// Movie title
    int year;            /// Movie release year
    std::string director;           /// Director's name
    std::string rating;             /// Movie audience rating

    Movie() = default;
    Movie( std::istream& infile );  /// construct given an input stream
    void write( std::ostream& outfile ) const;
};
std::ostream& operator<<( std::ostream& outfile, const Movie& movie );

#endif