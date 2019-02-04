#include <ostream>
#include <string>

class Pizza {
public:
	Pizza(int price, int diameter, std::string vendor, std::string name);
	friend std::ostream& operator<< (std::ostream& stream, const Pizza& obj);
	bool operator< (Pizza i);
private:
	int price, diameter;
	double area, unitprice;
	std::string name, vendor;
};
