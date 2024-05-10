// Day started: Dec/3/2023
// Movie Management main source file
// Eric Roquel Correa
// S01468715


#include <iostream>
#include "Genre.h"
#include "GBSTree.h"
#include "GDLList.h"
#include <limits>

using namespace std;

int main() {
	// Declare pointers for Genre and Movie objects
    Genre* genre;
    Movie* movie;
	// Create an instance of GBSTree to store genres
    GBSTree<Genre> genreList;
	// Declare variables for user input
    string fName, lName, mTitle, mGenre, mSynopsis, mDirector;
    int choice, mYear;

    do {																										// Display menu options
        cout << "\n===== Movie Management Program! =====" << endl;
        cout << "\n1. Add a genre" << endl;
        cout << "2. Add a movie" << endl;
        cout << "3. Modify a movie" << endl;
        cout << "4. List all genres" << endl;
        cout << "5. Delete a movie" << endl;
        cout << "6. List all movies for a selected genre" << endl;
        cout << "7. Search for a movie" << endl;
        cout << "8. Exit" << endl;
        cout << "\nWhat would you like to do?" << endl;
        cout << "Enter an option (1-8): ";
        cin >> choice;

		if (cin.fail()) {																						// Check for invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 8." << endl;
            continue; 																							// Jump to the next cycle of the loop
        }

		if (choice >= 1 && choice <= 8){																		// Process user choice if it is within valid range
        switch (choice) {
            case 1: {																							// Option 1: Add a genre
                cout << "\nAdd a Genre" << endl;
                cout << "\nEnter the name of the genre: " << endl;
                cin >> mGenre;
                genre = new Genre(mGenre);
                genreList.insert(*genre);
                break;
            }

            case 2: {																							// Option 2: Add a movie
                cout << "\nAdd a Movie" << endl;
                do {																							// Ask the user to select a genre from the existing list
                    genreList.printInOrder();
                    cout << "Enter the name of a movie genre as it is listed above: " << endl;
                    cin >> mGenre;
                    genre = new Genre(mGenre);
                    genre->setGenre(mGenre);
                } while (genreList.search(*genre) == 0);

				// Get details of the movie from the user
                cout << "\nEnter the details of the movie." << endl;
                cout << "Title: ";
                cin.ignore();
                getline(cin, mTitle);

                cout << "Synopsis: ";
                getline(cin, mSynopsis);
                cout << "Director: ";
				getline(cin, mDirector);

                    while (true) {																				// Read the release year and handle possible errors
                        cout << "Release Year: ";
                        if (cin >> mYear) {
                            break;  																			// Exit the loop if the input is successful
                        } else {
                            // There was an error in reading, clear the buffer and display a message
                            cout << "Invalid input. Please enter a valid number for the year." << endl;
                            cin.clear();  																		// Clear the error flag
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');  								// Clear the buffer
                        }
                    }
				// Create a new Movie object and insert it into the appropriate genre
                movie = new Movie(mTitle, mGenre, mSynopsis, mDirector, mYear);
                genreList.search(*genre)->getInfo().getMovie()->sortInsert(*movie);
                break;
            }
			
			case 3: {																							// Option 3: Modify a Movie
 				cout << "\nModify a Movie" << endl;
    			do {																							// Ask the user to select a genre from the existing list
       	 			genreList.printInOrder();
        			cout << "Enter the name of a movie genre as it is listed above: ";
        			cin >> mGenre;
        			genre = new Genre(mGenre);
        			genre->setGenre(mGenre);
    			} while (genreList.search(*genre) == 0);
				// Ask the user to enter the title of the movie to be modified
    			cout << "Enter the title of the movie you want to modify: ";
    			cin.ignore();
    			getline(cin, mTitle);

    			// Search for the movie in the list associated with the selected genre
    			GDLList<Movie>* movieList = genreList.search(*genre)->getInfo().getMovie();
    			GDLLNode<Movie>* movieNode = movieList->searchByTitle(mTitle);

    			if (movieNode) {																				// Movie found, prompt user for new details
        			cout << "\nEnter the new details of the movie:" << endl;
        			cout << "Title: ";
        			getline(cin, mTitle);
        			cout << "Synopsis: ";
        			getline(cin, mSynopsis);
        			cout << "Director: ";
        			getline(cin, mDirector);
			
                    while (true) {																				// Read the release year and handle possible errors
                    	cout << "Release Year: ";
                    if (cin >> mYear) {
                    	break;  																				// Exit the loop if the input is successful
                    } else {
                    	// Error in reading, clear the buffer and display a message
                    	cout << "Invalid input. Please enter a valid number for the year." << endl;
                    	cin.clear();  																			// Clear the error flag
                    	cin.ignore(numeric_limits<streamsize>::max(), '\n');  									// Clear the buffer
                	}
        		}
        		// Modify the movie with the new information
        		Movie newMovie(mTitle, mGenre, mSynopsis, mDirector, mYear);
        		movieNode->setMovie(newMovie);
        		cout << "\nMovie modified successfully." << endl;
    			} else {
				// Movie not found
        		cout << "\nMovie not found." << endl;
    		}
    	break;
	}

            case 4: {																							// Option 4: List all genres
                cout << endl;
                genreList.printInOrder();																		// Print all genres in alphabetical order
                break;
            }

			case 5: {																							// Option 5: Delete a Movie
    			cout << "\nDelete a Movie" << endl;

   				do {																							// Prompt user to select a genre from the existing list
        			genreList.printInOrder();
        			cout << "Enter the name of a movie genre as it is listed above: ";
        			cin >> mGenre;
        			genre = new Genre(mGenre);
        			genre->setGenre(mGenre);
    			} while (genreList.search(*genre) == 0);

				// Ask the user to enter the title of the movie to be deleted
    			cout << "Enter the title of the movie you want to delete: ";
    			cin.ignore();
    			getline(cin, mTitle);

				// Search for the movie in the list associated with the selected genre
    			GDLLNode<Movie>* movieNode = genreList.search(*genre)->getInfo().getMovie()->searchByTitle(mTitle);

    		 	if (movieNode) {																				// Found the movie, delete the node directly (calling the Movie destructor)
        			genreList.search(*genre)->getInfo().getMovie()->deleteNode(mTitle);
        			cout << "Movie deleted successfully." << endl;
    			} else {
				// Movie not found
        		cout << "Movie not found." << endl;
    		}
    	break;
		}

		case 6: {																								// Option 6: List all movies for a selected genre
    		cout << "\nList all movies for a selected genre" << endl;

    		do {																								// Ask the user to select a genre from the existing list
        		genreList.printInOrder();
        		cout << "Enter the name of a movie genre as it is listed above: ";
        		cin >> mGenre;
        		genre = new Genre(mGenre);
        		genre->setGenre(mGenre);
    		} while (genreList.search(*genre) == 0);

			// Print all movies for the selected genre
    		cout << "\nMovies for the selected genre (" << mGenre << "):" << endl;
    		genreList.search(*genre)->getInfo().getMovie()->printList();
    		break;
		}

		case 7: {																								// Option 7: Search for a movie
    		cout << "\nSearch for a movie" << endl;
    		do {																								// Ask the user to select a genre from the existing list
        		genreList.printInOrder();
        		cout << "Enter the name of a movie genre as it is listed above: ";
        		cin >> mGenre;
        		genre = new Genre(mGenre);
        		genre->setGenre(mGenre);
    		} while (genreList.search(*genre) == 0);

			// Ask the user to enter the title of the movie to be searched
    		cout << "Enter the title of the movie you want to search for: ";
    		cin.ignore();
    		getline(cin, mTitle);

			// Search for the movie in the list associated with the selected genre
    		GDLLNode<Movie>* movieNode = genreList.search(*genre)->getInfo().getMovie()->searchByTitle(mTitle);

    		if (movieNode) {																					// Movie found, print its information
        		cout << "\nMovie found:" << endl;
        		cout << "\nTitle: " << movieNode->getMovie().getTitle() << endl;
        		cout << "Synopsis: " << movieNode->getMovie().getSynopsis() << endl;
        		cout << "Director: " << movieNode->getMovie().getDirector() << endl;
        		cout << "Release Year: " << movieNode->getMovie().getYear() << endl;
    		} else {
			// Movie not found
        	cout << "\nMovie not found." << endl;
    	  }
    break;
   }


		case 8: {																								// Option 8: Exit
        	cout << "Exiting the program. Goodbye!" << endl;
        break;
    }

        default: {																								// Default option
        	cout << "\nInvalid choice. Please try again." << endl;
        break;
    }
  }																												// End of choice
}																												// End of if (choice)

} while (choice != 8);																							// End of while loop, while choice is not equal to 8

	// Free up memory before exit
    delete genre;
    delete movie;

    return 0;

	
}
