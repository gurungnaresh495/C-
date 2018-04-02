#include <iostream>
#include "MovieNode.h"
#include "Movie.h"
#include "OrderedMovieList.h"
#include <fstream>
    using std::cout;
int main()
{
    OrderedMovieList movie_list;
    std::ifstream    movie_db {"movies.txt"};
    if( movie_db ) {
        while ( movie_db.good() ) {
          movie_list.insert( Movie{movie_db} ); 
        }
        movie_db.close();
        cout << "Alphabetical listing of movies available:\n"
             << movie_list << "\n\n";
    }
    else{
        cout << "file not found!\n";
    }
        
    return 0;
}