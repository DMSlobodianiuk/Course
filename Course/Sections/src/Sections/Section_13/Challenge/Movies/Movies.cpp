#include "Movies.h"

Movies::Movies(vector<Movie> n_collection)
	:collection{ new vector<Movie>(n_collection) } {
	cout << "Movie collection was created\n" << endl;
}

void Movies::add_movie(Movie *movie) {
	if (is_name_exist(movie->get_name()))
		cout << "Movie '" << movie->get_name() << "' is already in the list, try add another one." << endl;
	else
		collection->push_back(*movie);
}

void Movies::add_movie(Movie&& movie) {
	if (is_name_exist(movie.get_name()))
		cout << "Movie '" << movie.get_name() << "' is already in the list, try add another one." << endl;
	else
		collection->push_back(Movie(movie.get_name(), movie.get_rating(), movie.get_watched()));
}

void Movies::display_movies() const{
	cout << "-------------------------------------" << endl;
	for (auto &mov : (*collection))
		mov.display_movie();
	cout << "-------------------------------------" << endl;
}

void friend_add_movie(Movies *my_movies, string name, string rating, int watched) {
	my_movies->add_movie(Movie{ name,rating,watched });
}

bool Movies::increment(string name) {
	for (auto &mov : (*collection)) {
		if (mov.get_name() == name) {
			mov.watched_increment();
			return true;
		}
	}
	cout << "Sorry, there is no movie with name '" << name << "' to increment" << endl;
}

bool Movies::is_name_exist(string name) {
	for (auto movie : *collection) {
		if (movie.get_name() == name)
			return true;
	}
	return false;
}

Movies::~Movies() {
	delete collection;
	cout<< "Movie collection was destroyed" << endl;
}
