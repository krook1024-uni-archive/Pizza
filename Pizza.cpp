#include "Pizza.h"
#include <ostream>
#include <cmath>

Pizza::Pizza(int price, int diameter, std::string vendor, std::string name) :
    price(price),
    diameter(diameter),
    name(name),
    vendor(vendor),
    area(diameter * diameter * M_PI),
    unitprice(price/area) {}

bool Pizza::operator< (Pizza i) {
    return (this->unitprice < i.unitprice);
}

std::ostream& operator << (std::ostream& stream, const Pizza& obj) {
    stream 
        << "[" << obj.vendor << "] " 
        << obj.name << "\t" 
        << obj.price << "Ft\t"
        << obj.diameter	<<"cm\t"
        << obj.area << "cm^2\t"
        << obj.unitprice << "Ft/cm^2"
    << std::endl;

    return stream;
}