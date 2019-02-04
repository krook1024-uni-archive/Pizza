/*


               _,--~~    ~~--._
            ,/'  m%%%%%%=@%%m  `\.
           /' m%%o(_)%%o%%%%o%%m `\
         /' %%@=%o%%%o%%%o%(_)o%%% `\
        /  %o%%%%%=@%%%(_)%%o%%@=%%  \
       |  (_)%(_)%%o%%%o%%%%=@(_)%%%  |
       | %%o%%%%o%%%(_)%%o%%o%%%%o%%% |
       | %%o%(_)%%%%%o%(_)%%%o%%o%o%% |
       |  (_)%%=@%(_)%o%o%%(_)%o(_)%  |
        \ ~%%o%%%%%o%o%=@%%o%%@%%o%~ /
         \. ~o%%(_)%%%o%(_)%%(_)o~ ,/
           \_ ~o%=@%(_)%o%%(_)%~ _/
             `\_~~o%%%o%%%%%~~_/'
                `--..____,,--'

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

#define DEFAULT_N_OF_PIZZAS 10

DEFINE_bool(a, false, "Kilistázza az összes ajánlatot");
DEFINE_bool(h, false, "Használat mutatása");
DEFINE_int32(c, 0, "A legjobb N db pizza");

void
usage() {
	std::cout << "Használat: ./pizza vagy ./pizza [-a -h -c [szám]" << std::endl
		<< "\t-a\t\tAz összes ajánlat kiiíratása" << std::endl
		<< "\t-c N\t\tA legjobb N darab ajánlat kiíratása" << std::endl
		<< "\t-a\t\tSegítség megjelenítése" << std::endl;
}

int
main(int argc, char **argv) {
	try {

	if(FLAGS_h || FLAGS_c && FLAGS_a) {
	    usage(); exit(0);
	}

	std::ifstream ifs("pizza.txt");
	std::vector<Pizza> pizzas;

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

		// a pizzas vektort használva konstruáltatjuk meg az elemeket
		pizzas.emplace_back(price, diameter, vendor, name);
	}

	// Rendezzük sorba a pizzákat (jelenleg egységáraik szerint)
	std::sort(pizzas.begin(), pizzas.end());

	// Ha a -a zászlót kaptuk, akkor mindent ki kell listázzunk
	if(FLAGS_a) {
		for(Pizza &p : pizzas) {
			std::cout << p;
		}
	}

	// Ha a -c [szám] zászlót kaptuk, akkor csak a legjobb FLAGS_c darabot listázzuk,
	// már ha van annyi összesen.
	else if(FLAGS_c > 0) {
		if(FLAGS_c <= pizzas.size()) {
			std::cout << "A legjobb " << FLAGS_c << " pizza a következő(ek): " << std::endl;
			for(int i=0; i < FLAGS_c; i++) {
				std::cout << i+1 << ". " << pizzas[i];
			}
		} else {
			std::cout << "Nincsen ennyi ajánlat összesen." << std::endl;
		}
	}

	else {
		std::cout << "A legjobb " << DEFAULT_N_OF_PIZZAS <<  " pizza: " << std::endl;
		for(int i=0; i < DEFAULT_N_OF_PIZZAS; i++) {
			// csak akkor írjuk ki ha létezik az az elem egyáltalán...
			if(i < pizzas.size()) {
				std::cout << "\t" << i+1 << ". " << pizzas[i];
			}
		}
		std::cout << std::endl << std::endl << "Egyéb segítség: ./pizza -h" << std::endl;
	}

	return 0;

	} catch(...) {
        std::cerr << "Ismeretlen hiba történt!" << std::endl;
    }
}


