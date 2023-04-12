#include "Computer.h"

//add getType
std::string Computer::getType() const{
 return "Computer";  
}

Computer::Computer(const std::string & _cpu, const std::string & _diskType, const int _diskSizeGB, const int _memSizeGB, const std::string & _manufacturer, const std::string & _description, const std::string & _serialNumber):GenericDevice(_manufacturer, _description, _serialNumber)
{
    cpu = _cpu;
    diskType = _diskType;
    diskSizeGB = _diskSizeGB;
    memSizeGB = _memSizeGB;
    frfrfr
}

void Computer::print() const
{  
    std::cout << "Computer: CPU = " << cpu << ", Disk type = " << diskType << ", Disk size (GB) = " << diskSizeGB << ", Manufacturer = " << getManufacturer() << ", Description = " << getDescription() << ", SN = " << getSerialNumber() << std::endl; 
}

bool Computer::operator == (const Computer & RHS) const
{
    if( getManufacturer() == RHS.getManufacturer() && getDescription() == RHS.getDescription() && 
    getSerialNumber() == RHS.getSerialNumber() && cpu == RHS.cpu && diskType == RHS.diskType &&
    diskSizeGB == RHS.diskSizeGB && memSizeGB == RHS.memSizeGB)
        return true;
    return false;
}
