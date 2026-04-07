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
