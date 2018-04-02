#include "OrderedMovieList.h"
#include "MovieNode.h"
#include <stdexcept>

void OrderedMovieList::write(std::ostream& fout) const
{
    MovieNode* current = head;
    while (current != nullptr)
    {
        current->write(fout);
        current = current->get_next();
    }
}

std::ostream& operator<<(std::ostream& fout, const OrderedMovieList& rhs)
{
    rhs.write(fout);
    return fout;
}

Movie OrderedMovieList::removeFromHead()
{
    MovieNode* old_head = head;
    Movie old_movie = old_head->get_movie();
    if (!head)
    {
        throw std::length_error("Cannot remove from empty list."); 
    }
    else
    {
        head = old_head->get_next();
        head = head->get_next();
        delete old_head;
    }
    return old_movie;   
}    

void OrderedMovieList::erase()
{
    while ( head != nullptr)
    {
        removeFromHead();
        
    }
}

void OrderedMovieList::insert(const Movie& new_movie)
{
    MovieNode* new_node = new MovieNode{new_movie};
    if (!head)
    {
        head = new_node;
    }
    else
    {
        MovieNode* current = head;
        MovieNode* previous = nullptr;
        if (!(current->get_next()) && (*head < *new_node))
        {
            current->set_next(new_node);
            
        }
        else
        {
            if (*new_node < *head)
            {
                new_node->set_next(head);
                head = new_node;
            }
            else
            {
                previous = current;
                current = current->get_next();
                while ((current != nullptr) && (*current < *new_node))
                {
                    previous = current;
                    current = current->get_next();
                }
                new_node->set_next(current);
                previous->set_next(new_node);
            }
        }
        
    }
}

OrderedMovieList::~OrderedMovieList()
{
    erase();
}