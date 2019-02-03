/*

  _____ _
 |  __ (_)
 | |__) | __________ _
 |  ___/ |_  /_  / _` |
 | |   | |/ / / / (_| |
 |_|   |_/___/___\__,_|

	...because who doesn't love one?


	Molnár Antal Albert © 2019
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <gflags/gflags.h>

#include "Pizza.h"

DEFINE_bool(a, false, "Kilistázza az összes ajánlatot");
DEFINE_bool(h, false, "Használat mutatása");
DEFINE_int32(c, 0, "A legjobb N db pizza");

void usage();

int
main(int argc, char **argv) {
	try {

	gflags::SetUsageMessage("Használat: ");
	gflags::ParseCommandLineFlags(&argc, &argv, true);
	gflags::ParseCommandLineNonHelpFlags(&argc, &argv, true);

	if(FLAGS_h) { usage(); }

	std::ifstream ifs("pizza.txt");
	std::vector<Pizza> pizzak;

	int diameter, price;
	std::string name, vendor, textline;

	while (getline(ifs, textline)) {
		std::string comma_string;
		std::istringstream text_stream(textline);

		// az átmérőt kivesszük a fájlból
  		text_stream >> diameter;
		getline(text_stream, comma_string, ',');

		// folytatjuk az árral
		text_stream >> price;
		getline(text_stream, comma_string, ',');

		// majd a cégnév
		getline(text_stream, vendor, ',');

		// a pizza neve az utolsó paraméter, melyet már a sor végéig
		// nézünk, nem a vesszőig
		getline(text_stream, name, '\n');

		// a pizzak vektort használva konstruáltatjuk meg az elemeket
		pizzak.emplace_back(price, diameter, vendor, name);
	}

	// Rendezzük sorba a pizzákat (jelenleg egységáraik szerint)
	std::sort(pizzak.begin(), pizzak.end());

	// Ha a -a zászlót kaptuk, akkor mindent ki kell listázzunk
	if(FLAGS_a) {
		for(Pizza &p : pizzak) {
			std::cout << p;
		}
	}

	// Ha a -c [szám] zászlót kaptuk, akkor csak a legjobb FLAGS_c darabot listázzuk,
	// már ha van annyi összesen.
	else if(FLAGS_c > 0) {
		if(FLAGS_c <= pizzak.size()) {
			std::cout << "A legjobb " << FLAGS_c << " pizza a következő(ek): " << std::endl;
			for(int i=0; i < FLAGS_c; i++) {
				std::cout << i+1 << ". " << pizzak[i];
			}
		} else {
			std::cout << "Nincsen ennyi ajánlat összesen." << std::endl;
		}
	}

	else {
		std::cout << "A legjobb 5 pizza: " << std::endl;
		for(int i=0; i < 5; i++) {
			// csak akkor írjuk ki ha létezik az az elem egyáltalán...
			if(i <= pizzak.size()) {
				std::cout << "\t" << i+1 << ". " << pizzak[i];
			}
		}
		std::cout << std::endl << std::endl << "Egyéb segítség: ./pizza -h" << std::endl;
	}

	return 0;

	} catch(...) {
        std::cerr << "Ismeretlen hiba történt!" << std::endl;
    }
}

void
usage() {
	std::cout << "Használat: ./pizza -h | vagy -a | vagy -c [szám]" << std::endl;
}
