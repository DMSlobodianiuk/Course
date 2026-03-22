#include "Movie.h"

Movie::Movie(string n_name, string n_rating, int n_watched)
	:name{ new string(n_name )}, rating{ new string(n_rating)}, watched{ new int(n_watched )} {
}

Movie::Movie(const Movie& source)
	: name{ new string(*source.name) },
	rating{ new string(*source.rating) },
	watched{ new int(*source.watched) } {
}

void Movie::set_name(string n_name) {
	*name = n_name;
}

void Movie::set_rating(string n_rating) {
	*rating = n_rating;
}

void Movie::set_watched(int n_watched) {
	*watched = n_watched;
}

void Movie::display_movie() {
	cout << "Movie '" << *name << "' with rating " << *rating << " and watch count " << *watched << " was displayed" << endl;
}

void Movie::watched_increment() {
	(*watched)++;
}

Movie::~Movie() {
	delete name;
	delete rating;
	delete watched;
}
