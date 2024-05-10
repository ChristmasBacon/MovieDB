// Day started: Dec/7/2023
// Genre header file
// Eric Roquel Correa
// S01468715

#include <string>
#include <iostream>

using namespace std;

//Class declaration
class Movie {
	// Private member variables
	private:
		string title, genre, synopsis, director;
		int year;
	
	public:
		// Constructors
		Movie();																								// Default constructor
		Movie(string, string, string, string, int);																// Parameterized constructor
		
		// Setter methods
		void setTitle(string); 
		void setGenre(string);
		void setSynopsis(string);
		void setDirector(string);
		void setYear(int);
		
		// Getter methods
		string getTitle();
		string getGenre();
		string getSynopsis();
		string getDirector();
		int getYear();
		
		void display();																							// Display method

		// Comparison operators for alphabetical sorting
		bool operator > (const Movie&);
		bool operator < (const Movie&);
		bool operator == (const Movie&); 

		bool operator<(const Movie& other) const {
        // Comparar los títulos de las películas
        return this->title < other.title;
		}
};

Movie::Movie() {																								// Default constructor
	title = "";
	genre = "";
	synopsis = "";
	director = "";
	year = 0;
}

Movie::Movie(string t, string g, string s, string d, int y) {													// Parameterized constructor
	title = t;
	genre = g;
	synopsis = s;
	director = d;
	year = y;
}

// Setter methods
void Movie::setTitle(string t) { title = t; }
void Movie::setGenre(string g) { genre = g; }
void Movie::setSynopsis(string s) { synopsis = s; }
void Movie::setDirector(string d) { director = d; }
void Movie::setYear(int y) { year = y; }

// Getter methods
string Movie::getTitle() { return title; }
string Movie::getGenre() { return genre; }
string Movie::getSynopsis() { return synopsis; }
string Movie::getDirector() { return director; }
int Movie::getYear() { return year; }

bool Movie::operator > (const Movie& l) {																		// Overloaded greater-than operator for alphabetical sorting
	bool pos;
	if (title > l.title) {																						// Check if the title of the current movie is greater than the title of the compared movie
	pos = true;																									// If greater, set result to true
	}
	else if (title == l.title) {																				// If titles are equal, ensure stability in sorting by returning false
	pos = false;																								// Set result to false (ensures stability for sorting)
	}
	else {																										// If the title is less than the compared title, set result to false
	pos = false;
	}
	return pos;																									// Return the final result
}

bool Movie::operator < (const Movie& l) {																		// Overloaded less-than operator for alphabetical sorting
	bool pos;
	if (title < l.title) {																						// Check if the title of the current movie is less than the title of the compared movie
	pos = true;																									// If less, set result to true
	}
	else if (title == l.title ) {																				// If titles are equal, ensure stability in sorting by returning true
	pos = true;																									// Set result to true (ensures stability for sorting)
	}
	else {																										// If the title is greater than the compared title, set result to false
	pos = false;
	}
	return pos;																									// Return the final result
}

bool Movie::operator == (const Movie& l) {																		// Overloaded equality operator
	bool pos;
	if (title == l.title) {																						// Check if the title of the current movie is equal to the title of the compared movie
	pos = true;																									// If equal, set result to true
	}
	else {																										// If titles are not equal, set result to false
	pos = false;
	}
	return pos;																									// Return the final result
}

void Movie::display() {																							// Display method
	cout << "\nTitle: " << title << endl;
	cout << "Genre: " << genre << endl;
	cout << "Synopsis: " << synopsis << endl; 
	cout << "Director: " << director << endl;
	cout << "Release Year: " << year << endl;
}