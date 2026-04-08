#include "..\..\..\..\..\Course\Sections\include\Sections\Section_19\section_19.h"

void streams_case_1() {
	cout << "\n----------------------------------------------\n";
	cout << "10 == 10 -> " << (10 == 10) << endl;
	cout << "10 == 20 -> " << (10 == 20) << endl;

	cout << "\n----------------------------------------------\n";
	cout << "Setting std::boolalpha" << std::boolalpha << endl;
	cout << "10 == 10 -> " << (10 == 10) << endl;
	cout << "10 == 20 -> " << (10 == 20) << endl;

	cout << "\n----------------------------------------------\n";
	cout << "Setting std::noboolalpha" << std::noboolalpha << endl;
	cout << "10 == 10 -> " << (10 == 10) << endl;
	cout << "10 == 20 -> " << (10 == 20) << endl;

	cout << "\n----------------------------------------------\n";
	cout << "Method version" << endl;
	cout << "cout.setf(std::ios::boolalpha)\n";
	cout.setf(std::ios::boolalpha);
	cout << "10 == 10 -> " << (10 == 10) << endl;
	cout << "10 == 20 -> " << (10 == 20) << endl;

	cout << "\n----------------------------------------------\n";
	cout << "Reset to default" << endl;
	cout << "cout<<std::resetiosflags(std::ios::boolalpha)";
	cout << std::resetiosflags(std::ios::boolalpha) << endl;;
	cout << "10 == 10 -> " << (10 == 10) << endl;
	cout << "10 == 20 -> " << (10 == 20) << endl;
	cout << "\n----------------------------------------------\n";
}

void streams_case_2() {
	int num{ 255 };
	cout << "\n----------------------------------------------\n";
	cout << "Decimal, hexadecimal, octal" << endl;
	cout << std::dec << num << endl;
	cout << std::hex << num << endl;
	cout << std::oct << num << endl;

	cout << "----------------------------------------------\n";
	cout << "Decimal, hexadecimal, octal, but with showbase" << endl;
	cout << std::showbase;
	cout << std::dec << num << endl;
	cout << std::hex << num << endl;
	cout << std::oct << num << endl;
	
	cout << "----------------------------------------------\n";
	cout << "Hexadecimal with showbase and uppercase"<<endl;
	//cout << std::showbase << std::uppercase;
	cout.setf(std::ios::showbase);
	cout.setf(std::ios::uppercase);
	cout << std::hex << num << endl;

	cout << "----------------------------------------------\n";
	cout << "Hexadecimal without showbase but with uppercase" << endl;
	cout << std::noshowbase;
	//cout << std::uppercase;
	cout.setf(std::ios::uppercase);
	cout << std::hex << num << endl;

	cout << "----------------------------------------------\n";
	int num1{ 255 };
	int num2{ -255 };
	cout << "Decimal with showpos" << endl; //noshowpos забирає відображення '+'
	cout << std::dec;
	cout << std::showpos;
	//cout << std::resetiosflags(std::ios::showpos); //ресетає до умовного noshowpos
	cout << num1 << endl;
	cout << num2 << endl;

	cout << "----------------------------------------------\n";
}

void streams_case_3() {
	double num{ 123456789.987654321 };

	cout << "-----------------------------------------------\n";
	std::cout.unsetf(std::ios::scientific | std::ios::fixed | std::ios::showbase | std::ios::uppercase | std::ios::showpos);
	cout << "std::setprecision(n) n in {1,3,6,9,19}" << endl;
	cout << num << endl;
	cout << std::setprecision(1) << num << endl;
	cout << std::setprecision(3) << num << endl;
	cout << std::setprecision(6) << num << endl;
	cout << std::setprecision(9) << num << endl;
	cout << std::setprecision(19) << num << endl;

	cout << "-----------------------------------------------\n";
	std::cout.unsetf(std::ios::scientific | std::ios::fixed | std::ios::showbase | std::ios::uppercase | std::ios::showpos);
	cout << "std::setprecision(15)" << endl;
	double num1{ 1234567891 };
	cout << num1 << endl;
	cout << std::setprecision(15)<<num1 << endl;

	cout << "-----------------------------------------------\n";
	std::cout.unsetf(std::ios::scientific | std::ios::fixed | std::ios::showbase | std::ios::uppercase | std::ios::showpos);
	double num2{ 0.123456789 };
	cout << num2 << endl;
	cout << std::setprecision(2)<<std::fixed;
	cout << "std::setprecision(2)<<std::fixed ";
	cout << num2 << endl;

	cout << "-----------------------------------------------\n";
	std::cout.unsetf(std::ios::scientific | std::ios::fixed | std::ios::showbase | std::ios::uppercase | std::ios::showpos);
	cout << "setprecision(3) << std::scientific ";
	double num3{ 0.123456789 };
	cout << std::setprecision(3)
		<< std::scientific;
	cout << num3 << endl;
	cout<< std::uppercase;
	cout << "std::uppercase ";
	cout << num2 << endl;

	cout << "-----------------------------------------------\n";
	std::cout.unsetf(std::ios::scientific | std::ios::fixed | std::ios::showbase | std::ios::uppercase | std::ios::showpos);
	double num4{ 123456789.987654321 };
	cout << num4 << endl;
	cout << std::setprecision(3)
		<< std::fixed
		<< std::showpos;
	cout << "std::setprecision(3) << std::fixed << std::showpos; ";
	cout << num4 << endl;

	cout << "-----------------------------------------------\n";
	std::cout.unsetf(std::ios::scientific | std::ios::fixed | std::ios::showbase | std::ios::uppercase | std::ios::showpos);
	cout << std::resetiosflags(std::ios::showpos);
	double num5{ 12.43 };
	cout << num5 << endl;
	cout << std::showpoint;
	cout << "std::showpoint ";
	cout << num5;
	cout << std::setprecision(8);
	cout << "std::setprecision(8) " << num5 << endl;
}

void streams_case_4() {
	double num1{123456789.987654321};
	double num2{1234.5678};
	double num3{1234.0};

	cout << "--Defaults---------------------------------------------" << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	cout << std::setprecision(2);
	cout << "--Precision 2---------------------------------------------" << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	cout << std::setprecision(5);
	cout << "--Precision 5---------------------------------------------" << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	cout << std::setprecision(3)<<std::fixed;
	cout << "--Precision 3 - fixed---------------------------------------------" << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	cout << std::setprecision(3) << std::scientific;
	cout << "--Precision 3 - scientific---------------------------------------------" << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	cout << std::setprecision(3) << std::scientific<<std::uppercase;
	cout << "--Precision 3 - scientific - uppercase---------------------------------------------" << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	cout << std::setprecision(3) << std::fixed<<std::showpos;
	cout << "--Precision 3 - fixed - showpos---------------------------------------------" << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	//back to defaults
	cout.unsetf(std::ios::scientific | std::ios::fixed);
	cout << std::resetiosflags(std::ios::showpos);

	cout << std::setprecision(10)<<std::showpoint;
	cout << "--Precision 10 - showpoint---------------------------------------------" << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	//back to defaults
	cout.unsetf(std::ios::scientific | std::ios::fixed);
	cout << std::setprecision(6);
	cout << std::resetiosflags(std::ios::showpos);
	cout << std::resetiosflags(std::ios::showpoint);

	cout << "--Back to defaults-------------------------------------------- - " << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;
}

void streams_case_5() {
	cout << "-- setw(n) ----------------------------------\n";
	double num{ 1234.5678 };
	string hello{ "Hello" };

	cout <<"setw(10): " << std::setw(10) << num
		<<endl
		<<"setw(15): " << std::setw(15) << hello << endl;

	cout << "-- setw(n) left ----------------------------------\n";
	cout << "std::left case" << endl;
	cout << "setw(10): " << std::setw(10)<<std::left << num
		<< "setw(15): " << std::setw(15) << hello << endl;

	cout << "-- setw(n) right ----------------------------------\n";
	cout << "std::right case" << endl;
	cout << "setw(10): " << std::setw(10) << num
		<< std::setw(15) << hello
		<< std::setw(15) << hello << endl;

	cout << "-- seftill('') ----------------------------------\n";
	cout << "std::setfill" << endl;
	cout << std::setfill('.') << std::setw(10) << num <<"         " <<hello << endl;
	cout << std::setfill('-') << std::setw(5) << num <<"         " <<hello << endl;
}

void ruler() {
	cout << "\n12345678901234567890123456789012345678901234567890" << endl;
}

void streams_case_6() {
	int num1{ 1234 };
	double num2{ 1234.5678 };
	string hello{ "Hello" };

	cout << "\n-------------------------------------------------------------------------" << endl;
	cout << "Defaults" << endl;
	cout << num1
		<< num2
		<< hello
		<< endl;

	//cout << "\n-------------------------------------------------------------------------" << endl;
	//cout << "Defaults - one per line" << endl;
	//cout << num1 <<endl
	//	<< num2 <<endl
	//	<< hello <<endl
	//	<< endl;

	//cout << "\n-------------------------------------------------------------------------" << endl;
	//cout << "width 10 for num1" << endl;
	//cout << std::setw(10)<<num1 << endl
	//	<< num2 << endl
	//	<< hello << endl
	//	<< endl;

	//cout << "\n-------------------------------------------------------------------------" << endl;
	//cout << "width 10 for num1 and num2" << endl;
	//cout << std::setw(10) << num1 << endl
	//	<<std::setw(10)<< num2 << endl
	//	<< hello << endl
	//	<< endl;

	//cout << "\n-------------------------------------------------------------------------" << endl;
	//cout << "width 10 for num1, num2 and num3" << endl;
	//cout << std::setw(10) << num1 << endl
	//	<< std::setw(10) << num2 << endl
	//	<< std::setw(10) << hello << endl
	//	<< endl;

	//cout << "\n-------------------------------------------------------------------------" << endl;
	//cout << "width 10 for num1, num2 and num3 and right(default) for them" << endl;
	//cout << std::setw(10) << num1
	//	<< std::setw(10) << num2
	//	<< std::setw(10) << hello
	//	<< endl;

	//cout << "\n-------------------------------------------------------------------------" << endl;
	//cout << "width 10 for num1, num2 and num3 and left for them" << endl;
	//cout << std::setw(10) << std::left<<num1
	//	<< std::setw(10) << std::left<< num2
	//	<< std::setw(10) << std::left<< hello
	//	<< endl;

	//cout << "\n-------------------------------------------------------------------------" << endl;
	//cout<<::std::setfill('-');
	//cout << "width 10 for num1, num2 and num3 and left for them and setfill to dash" << endl;
	//cout << std::setw(10) << std::left<<num1
	//	<< std::setw(10) << std::left<< num2
	//	<< std::setw(10) << std::left<< hello
	//	<< endl;

	cout << "\n-------------------------------------------------------------------------" << endl;
	cout << "width 10 for num1, num2 and num3 and left for them and setfill varies" << endl;
	cout << std::setw(10) << std::left <<std::setfill('*') << num1
		<< std::setw(10) << std::left << std::setfill('$')<<num2
		<< std::setw(10) << std::left << std::setfill('/')<<hello
		<< endl;
}

struct City {
	string name;
	long population;
	double cost;
};

struct Country {
	string name;
	vector<City> cities;
};

struct Tours {
	string title;
	vector<Country> countries;
};

void section_19_challenge_1() {
	Tours tours
	{ "Tour Ticket Prices from Miami",
		{
			{
				"Colombia", {
					{ "Bogota", 8778000, 400.98 },
					{ "Cali", 2401000, 424.12 },
					{ "Medellin", 2464000, 350.98 },
					{ "Cartagena", 972000, 345.34 }
				},
			},
			{
				"Brazil", {
					{ "Rio De Janiero", 13500000, 567.45 },
					{ "Sao Paulo", 11310000, 975.45 },
					{ "Salvador", 18234000, 855.99 }
				},
			},
			{
				"Chile", {
					{ "Valdivia", 260000, 569.12 },
					{ "Santiago", 7040000, 520.00 }
			},
		},
			{ "Argentina", {
				{ "Buenos Aires", 3010000, 723.77 }
			}
		},
	}
	};

	int l_value{ 50 };
	int r_value{ 50 };
	int column_width{ 20 };

	cout << std::setw(r_value) << tours.title << std::left << std::setw(l_value) << endl << endl;
	
	cout << std::setw(column_width) << std::left << "Contry"
		<< std::setw(column_width) << std::left << "City"
		<< std::setw(column_width) << std::right << "Population"
		<< std::setw(column_width) << std::right << "Price"
		<< endl;

	cout << std::setfill('-')<<std::setw(column_width*4) << '-' << endl;
	cout << std::setfill(' ');

	//for (auto country : tours.countries) {
	//	//cout << country.name << endl;
	//	for (auto city : country.cities) {
	//		cout << std::setw(column_width) << std::left << country.name
	//			<< std::setw(column_width) << std::left << city.name
	//			<< std::setw(column_width) << std::right << city.population
	//			<< std::setw(column_width) << std::right << city.cost
	//			<< endl;
	//	}
	//}

	for (Country country : tours.countries) {
		for (size_t i = 0; i < country.cities.size(); ++i) {
			cout << std::setw(column_width) << std::left << ((i == 0)?country.name:" ")
				<< std::setw(column_width) << std::left << country.cities.at(i).name
				<< std::setw(column_width) << std::right << country.cities.at(i).population
				<< std::setw(column_width) << std::right << country.cities.at(i).cost
				<< endl;
		}
	}

	cout << endl;
}

void reading_from_file_case_1() {
	std::ifstream in_file;
	string filename{ "../test1.txt" };

	in_file.open(filename);

	//if (in_file.is_open()) {
	//	cout << "Opened" << endl;
	//}
	//else { 
	//	cout << "Not Opened" << endl;
	//}

	if (in_file){
		cout << "Opened" << endl;
	}
	else {
	cout << "Not Opened" << endl;
	}

	in_file.close();
}

void reading_from_file_case_2() {
	
	std::ifstream in_file;
	string line;
	int num;
	double total;

	in_file.open("../Course/Sections/src/Sections/Section_19/TextFiles/test.txt");

	if (!in_file.is_open()) {
		std::cerr << "Problem opening file" << endl;
	}
	else {
		cout << "File is good to go" << endl;
	}
	
	in_file >> line >> num >>total;
	cout << line << endl;
	cout << num<< endl;
	cout << total << endl;

	in_file.close();
}

void reading_from_file_case_3() {
	std::ifstream in_file;
	string line;
	int num;
	double total;

	in_file.open("../Course/Sections/src/Sections/Section_19/TextFiles/test1.txt");

	if (!in_file.is_open()) {
		std::cerr << "Problem opening file" << endl;
	}
	else {
		cout << "File is good to go" << endl;
	}

	cout << std::left << std::setw(10) << "Name" << std::setw(10) << "Number" << std::setw(10) << "Total" << endl;
	cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << endl;
	//while (!in_file.eof()) {
	//	in_file >> line >> num >> total;
	while(in_file >> line >> num >> total){
		cout << std::setw(10) << std::left << line
			<< std::setw(10) << num
			<< std::setw(10) << total
			<< endl;
	}
}

void reading_from_file_case_4() {
	std::ifstream in_file;
	std::ofstream on_file;
	string line;

	in_file.open("../Course/Sections/src/Sections/Section_19/TextFiles/dust.txt");
	on_file.open("../Course/Sections/src/Sections/Section_19/TextFiles/dust_copy.txt");

	if (!in_file) {
		std::cerr << "Problem opening file" << endl;
	}

	while (std::getline(in_file,line)) {
		cout << line << endl;
		on_file << line << endl;
	}

	in_file.close();
	on_file.close();
}

void reading_from_file_case_5() {
	std::ifstream in_file;
	char c;

	in_file.open("../Course/Sections/src/Sections/Section_19/TextFiles/dust.txt");

	if (!in_file) {
		std::cerr << "Problem opening file" << endl;
	}

	while (in_file.get(c))
		cout << c << " ";

	in_file.close();
}

void section_19_challenge_2() {
	std::ifstream in_line;

	int student_setw{ 13 };
	int score_setw{ 10 };
	string answers;
	string line;
	bool selector{ true };
	double global_sum{};
	double global_count{};

	in_line.open("../Course/Sections/src/Sections/Section_19/TextFiles/responces.txt");

	if (!in_line) {
		std::cerr << "Problem opening file" << endl;
	}

	cout << std::left << std::setw(student_setw) << "Student" <<std::right<< std::setw(score_setw) << "Average" << endl;
	cout << std::setfill('-') << std::setw(student_setw + score_setw) << "" << endl;
	cout << std::setfill(' ');

	std::getline(in_line, answers);

	while (std::getline(in_line, line)) {
		if (selector) {
			cout << std::left << std::setw(student_setw) << line;
			global_count++;
			selector = false;
		}
		else {
			double sum{0};
			double total{ static_cast<double>(line.length())};

			for (size_t i{ 0 }; i < line.length(); i++) {
				switch (line[i]) 
				{
					case 'A':
						sum += 5;
						break;
					case 'B':
						sum += 4;
						break;
					case 'C':
						sum += 3;
						break;
					case 'D':
						sum += 2;
						break;
					case 'E':
						sum += 1;
						break;
					default:
						sum += 0;
						break;
				}
			}
			
			global_sum += sum / total;

			cout << std::right << std::setw(score_setw) << sum / total << endl;
			selector = true;
		}
	}

	cout << std::setfill('-') << std::setw(student_setw + score_setw) << "" << endl;
	cout << std::setfill(' ');
	cout << std::left << std::setw(student_setw) << "Average score"
		<< std::right << std::setw(score_setw) << global_sum / global_count
		<< endl;

	in_line.close();
}

bool find_substring(const string& word_to_find, const string& target) {
	size_t found = target.find(word_to_find);
	if (found == string::npos)
		return false;
	else
		return true;
}

void section_19_challenge_3() {
	std::ifstream in_file;
	int words_count{};
	int substring_count{};
	string word_read{};
	//string word_to_find{"love"};
	string word_to_find{"ROMEO"};
	//string word_to_find{"Juliet"};
	//string word_to_find{"Frank"};

	cout << "Enter the substring to seach for: " << word_to_find << endl;
	//cin >> word_to_find;

	in_file.open("../Course/Sections/src/Sections/Section_19/TextFiles/romeoandjuliet.txt");

	if (!in_file)
		std::cerr << "Problem opening file" << endl;

	//cout << std::setfill('-') << std::setw(25)<<std::right << " Custom solution" <<std::setw(15)<<"" << endl;;
	//cout<<std::setfill(' ');
	//while (in_file >> word_read) {
	//	if (word_read != "")
	//		words_count++;
	//	if (word_read.find(word_to_find) != string::npos)
	//		substring_count++;
	//}
	//cout << words_count << " words were searched..." << endl;
	//cout << "The substring " << word_to_find << " was found " << substring_count << " times" << endl;

	cout << std::setfill('-') << std::setw(25) << std::right << "Proposed solution" << std::setw(15) << "" << endl;;
	word_read = "";
	while (in_file >> word_read) {
		++words_count;
		if (find_substring(word_to_find, word_read)) {
			substring_count++;
		}
	}
	cout << words_count << " words were searched..." << endl;
	cout << "The substring " << word_to_find << " was found " << substring_count << " times" << endl;
	
	cout << std::setw(40) << "" << endl;

	cout << std::setfill(' ');

	in_file.close();
}

void writing_to_file_case_1() {
	//std::f stream out_file{ "" };
	std::ofstream out_file;

	out_file.open("../Course/Sections/src/Sections/Section_19/TextFiles/test2.txt");
	//out_file.open("../Course/Sections/src/Sections/Section_19/TextFiles/test2.txt",std::ios::trunc); //trunc - перезапис
	//out_file.open("../Course/Sections/src/Sections/Section_19/TextFiles/test2.txt",std::ios::app); //app - дописує
	//out_file.open("../Course/Sections/src/Sections/Section_19/TextFiles/test2.txt",std::ios::ate); //ate - ?

	if (!out_file) {
		std::cerr << "Problem opening file" << endl;
	}

	int num{ 100 };
	double total{ 255.67 };
	string name{ "Larryy" };

	out_file << num << "\n"
		<< total << "\n"
		<< name
		<< endl;

	out_file.close();
}

void writing_to_file_case_2() {
	std::ifstream in_file;
	std::ofstream out_file;
	string line;

	in_file.open("../Course/Sections/src/Sections/Section_19/TextFiles/romeoandjuliet.txt");
	out_file.open("../Course/Sections/src/Sections/Section_19/TextFiles/file_to_copy.txt");

	if (!in_file || !out_file)
		std::cerr << "Problem opening file" << endl;

	while (std::getline(in_file, line)) {
		out_file << line
			<< endl;
	}

	in_file.close();
	out_file.close();
}

void section_19_challenge_4() {
	std::ifstream in_file;
	std::ofstream out_file;

	string line;
	int line_number{1};

	in_file.open("../Course/Sections/src/Sections/Section_19/TextFiles/romeoandjuliet.txt");
	out_file.open("../Course/Sections/src/Sections/Section_19/TextFiles/romeoandjuliet_out.txt");

	if (!in_file)
		std::cerr << "Problem opening input file" << endl;

	if (!out_file)
		std::cerr << "Problem opening output file" << endl;

	while (std::getline(in_file, line)) {
		if (line == "")
			out_file << endl;
		else {
			out_file << std::left << std::setw(7) << line_number
				<< std::right << line
				<< endl;
			line_number++;
		}
	}

	in_file.close();
	out_file.close();
}

void string_stream_case_1() {

	int num{};
	double total{};
	string name{};
	string info{ "Moe 100 1234.5" };

	std::istringstream iss{ info };

	cout << std::setfill('-') << std::setw(25) <<" Default " << std::setw(25)<< ""<< endl << std::setfill(' ');
	iss >> name >> num >> total;
	cout << "name: " << name << endl;
	cout << "num: " << num << endl;
	cout << "total: " << total << endl;

	cout << std::setfill('-') << std::setw(25)<<" After " << std::setw(25) << "" << endl << std::setfill(' ');
	info = "Larry 200 999";
	iss.clear();
	iss.str(info);
	iss >> name >> num >> total;
	cout << "name: " << name << endl;
	cout << "num: " << num << endl;
	cout << "total: " << total << endl;

	cout << std::setfill('-') << std::setw(25) << " oss " << std::setw(25) << "" << endl << std::setfill(' ');
	std::ostringstream oss{};
	oss << name << " " << num << " " << total;
	cout << oss.str() << endl;
}

//int validation
void string_stream_case_2() {
	int value{};
	string input{};

	cout << "Enter an integer: ";
	cin >> input;

	std::stringstream ss{ input };
	if (ss >> value)
		cout << "An integer was entered" << endl;
	else
		cout << "An integer was NOT entered" << endl;
}

//better int validation
void string_stream_case_3() {
	int value{};
	string entry{};
	bool done = false;

	do {
		cout << "Please enter an integer: ";
		cin >> entry;
		std::istringstream validator{ entry }; //часто називають ss
		if (validator >> value)
			done = true;
		else
			cout << "Sorry, that's not an integer" << endl;

		//discards the input buffer
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (!done);

	cout << "You entered the integer: " << value << endl;
}