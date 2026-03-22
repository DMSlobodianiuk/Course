#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Movie {
private:
	string *name;
	string *rating;
	int *watched;
public:

	Movie(string name = "None",string rating = "None",int watched = 0);
	Movie(const Movie& source);

	//getter
	string get_name() const  { return *name; }
	string get_rating() const { return *rating; }
	int get_watched() const { return *watched; }

	//setter
	void set_name(string n_name);
	void set_rating(string n_rating);
	void set_watched(int n_watched);

	//Other
	void display_movie();
	void watched_increment();

	~Movie();
};
