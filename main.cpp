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

#include "Pizza.h"

void usage();

int
main(int argc, char **argv) {
	try {
	
	// kapcsolók feldolgozása
	// TODO
	





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

	// egy, vagy kettő bemenet érkezett?

	/*GetOpt getopt(argc, argv, "ahc:");
	int option_char, pizza_count;

	while((option_char = getopt()) != EOF) {
		switch(option_char) {
			case 'a':
				for(Pizza &p : pizzak) {
					std::cout << p;
				}
				break;
			
			case 'c':
				pizza_count = atoi(getopt.optarg);
				std::cout << "A legjobb " << pizza_count << " pizza a következő(k):" << std::endl;
				for(int i=0; i < pizza_count; i++) {
					std::cout << pizzak[i];
				}
				break;

			case 'h': usage(); break;
			case '?': usage(); break;
		}
	}*/


	/*if(argc == 2 | argc == 3) {
		// jegyezzük meg a kapcsolót
		char *option = *++argv;

		if (option[1] == 'a') { // a -a kapcsoló jön?
			// Kiírjuk az összes pizza adatait
			for(Pizza &p : pizzak) {
				std::cout << p;
			}
		}

		else if(option[1] == 'h') { // vagy a -h kapcsoló?
			usage();
		}

		else if(option[1] == 'c') {
			// TODO: segmentation fault lesz ebbű
			int count = atoi(*++argv);
			if(count > 0) {
				if(count < pizzak.size()) {
					std::cout << "A legjobb " << count << " pizza a következő(k):" << std::endl;
					for(int i=0; i < count; i++) {
						std::cout << pizzak[i];
					}
				} else {
					std::cout << "Nincs ennyi féle pizza összesen." << std::endl;
				}
			} else {
				usage();
			}
		}

		else {
			usage();
			return -1;
		}
	}

	// nem érkezett bemenet?
	else if(argc == 1) {
		std::cout << "A legjobban ez a pizza éri meg jelenleg:" << std::endl;
		std::cout << pizzak[0];
	}*/

	return 0;

	} catch(...) {
        std::cerr << "Ismeretlen hiba történt!" << std::endl;
    }
}

void
usage() {
	std::cout << "Használat: ./pizza -h | vagy -a | vagy -c [szám]" << std::endl;
}