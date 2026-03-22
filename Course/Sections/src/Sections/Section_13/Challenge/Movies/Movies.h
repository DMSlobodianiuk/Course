#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Movie/Movie.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;


class Movies {
private:
	vector<Movie> *collection;
public:
	friend void friend_add_movie(Movies *my_movies, string name, string rating, int watched);

	//Constructor
	Movies(vector<Movie> n_collection = {});

	void add_movie(Movie *movie);
	//Move Constructor
	void add_movie(Movie &&movie);

	void display_movies() const;
	bool increment(string name);

	bool is_name_exist(string name);

	//Destructor
	~Movies();
};

