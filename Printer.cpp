#include "Printer.h"
//using namespace std;

//add getType
std::string Printer::getType() const
{
return "Printer";
}

Printer::Printer(const int _ppm, const std::string & _color, const std::string & _manufacturer, const std::string & _description, const std::string & _serialNumber):GenericDevice(_manufacturer, _description, _serialNumber)
{
    ppm = _ppm;
    color = _color;
}

void Printer::print() const
{
    std::cout << "Printer: PPM = " << ppm << ", Color Printer = " << color << ", Manufacturer = " << getManufacturer() << ", Description = " << getDescription() << ", SN = " << getSerialNumber() << std::endl; 
}

bool Printer::operator == (const Printer & RHS) const
{
    if( getManufacturer() == RHS.getManufacturer() && getDescription() == RHS.getDescription() && 
    getSerialNumber() == RHS.getSerialNumber() && ppm == RHS.ppm && color == RHS.color)
        return true;
    return false;
}
