#include "section_13_challenge.h"
#include "Movies/Movies.h"
#include "Movie/Movie.h"

Section_13::Section_13() {
	cout << "Section " << section_num << " was created" << endl;
}

void Section_13::run() {
	cout << std::boolalpha;

	Movies* liba = new Movies;

	Movie* m1 = new Movie("Spider-man","PG-13",15);
	Movie* m2 = new Movie("Hulk","PG",4);
	Movie* m3 = new Movie("Iron-man","PG-13",27);
	Movie* m4 = new Movie("MadMax","R",9);
	Movie* m5 = new Movie("MadMax");

	liba->add_movie(Movie{ "Lorax","custom"});
	liba->add_movie(m1);
	liba->add_movie(m2);
	liba->add_movie(m3);
	liba->add_movie(m4);
	liba->add_movie(m5);

	liba->display_movies();

	liba->increment("Hulk");
	liba->increment(m4->get_name());
	liba->increment("MadMax");
	liba->increment("Madagascar");

	friend_add_movie(liba, "Big", "PG-13", 2);

	liba->display_movies();

	cout << endl;
	delete m1;
	delete m2;
	delete m3;
	delete m4;
	delete liba;
}

Section_13::~Section_13() {
	cout << "Section " << section_num << " was destroyed" << endl;
}
