// Day started: Dec/3/2023
// Genre header file
// Eric Roquel Correa
// S01468715
#ifndef GENRE_H
#define GENRE_H

#include <string>
#include "Movie.h"
#include "GDLList.h"

using namespace std;

class Genre {
	private:
		string genre;																					// Name of the genre
		GDLList<Movie>* movies;																			// List of movies associated with the genre
	public:
		// Constructors
		Genre();																						// Default constructor
		Genre(string, GDLList<Movie>*);																	// Constructor with name and movie list
		Genre(string);																					// Constructor with name

		// Setter methods
		void setGenre(string);																			// Set the name of the genre
		void setMovie(GDLList<Movie>*);																	// Set the list of movies for the genre

		// Getter methods
		string getGenre();																				// Get the name of the genre
		GDLList<Movie>* getMovie();																		// Get the list of movies for the genre

		// Comparison operators for alphabetical sorting
		bool operator > (const Genre&);
		bool operator < (const Genre&);
		bool operator == (const Genre&);
};

Genre::Genre(){																							// Default constructor
	genre = "";
	movies = new GDLList<Movie>;
}

Genre::Genre(string g, GDLList<Movie>* m) { 															// Constructor with name and movie list
	genre = g;
	movies = m;
}

Genre::Genre(string g) {																				// Constructor with name
	genre = g;
	movies = new GDLList<Movie>;
}

void Genre::setGenre(string g) { genre = g; }															// Set the name of the genre
void Genre::setMovie(GDLList<Movie>* m) { movies = m; }													// Set the list of movies for the genre
string Genre::getGenre() { return genre; }																// Get the name of the genre
GDLList<Movie>* Genre::getMovie() { return movies; }													// Get the list of movies for the genre

bool Genre::operator > (const Genre& l) {																// Comparison operators for alphabetical sorting (greater than)

	bool pos;																							// Variable to store the result of the comparison
	if (genre > l.genre) {																				// Check if the current genre is greater than or equal to the compared genre
	pos = true;																							// If greater, set result to true
	} else if (genre == l.genre) {
	pos = true;																							// If equal, set result to true (ensures stability for sorting)
	} else {
	pos = false;																						// If less, set result to false
	}

	return pos;																							// Return the final result
}

bool Genre::operator < (const Genre& l) {																// Comparison operator for alphabetical sorting (less than)

	bool pos;																							// Variable to store the result of the comparison
	if (genre < l.genre) {																				// Check if the current genre is less than or equal to the compared genre
	pos = true;																							// If less, set result to true
	}
	else if (genre == l.genre) {
	pos = true;																							// If equal, set result to true (ensures stability for sorting)
	}
	else {
	pos = false;																						// If greater, set result to false
	}
	 
	return pos;																							// Return the final result
}

bool Genre::operator == (const Genre& l) {																// Comparison operator for equality

	bool pos;																							// Variable to store the result of the comparison
	if (genre == l.genre) {																				// Check if the current genre is equal to the compared genre
	pos = true;																							// If equal, set result to true
	} else {
	pos = false;																						// If not equal, set result to false
	}

	return pos;																							// Return the final result
}

#endif // GENRE_H
