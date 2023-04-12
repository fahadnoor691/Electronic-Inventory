#include "GenericDevice.h"

GenericDevice::GenericDevice(const std::string & _manufacturer, const std::string & _description, const std::string & _serialNumber)
{
    manufacturer = _manufacturer;
    description = _description;
    serialNumber = _serialNumber;
}

std::string GenericDevice::getManufacturer() const
{
    return manufacturer;
}

std::string GenericDevice::getDescription() const
{
    return description;
}

std::string GenericDevice::getSerialNumber() const
{
    return serialNumber;
}


void GenericDevice::print() const
{
    std::cout << "Manufacturer: " << manufacturer << ", Description: " << description << ", Type: Other" << std::endl;
}

bool GenericDevice::operator == (const GenericDevice & RHS) const
{
        if (manufacturer == RHS.manufacturer && description == RHS.description &&
        serialNumber == RHS.serialNumber)
            return true;
        return false;
}