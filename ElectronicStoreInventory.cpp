#include "ElectronicStoreInventory.h"
#include "Printer.h"
#include "Computer.h"
#include <cstdlib>
//FIXME: provide the complete implementation for the following empty member functions!!

ElectronicStoreInventory::ElectronicStoreInventory()
{
count=0;
for(int i=0; i<MAX_SIZE;i++){
   Inventory[i]= nullptr;
}
}

bool ElectronicStoreInventory::addDevice(const GenericDevice & _device)
{
if(count>=MAX_SIZE){
   return false;}
if(_device.getType()=="Computer"){
    Inventory[count] = new Computer((Computer &) _device);}
else if (_device.getType()=="Printer"){
    Inventory[count] = new Printer((Printer &) _device);}
count++;
return true;
}


bool ElectronicStoreInventory::removeDevice(const std::string & _serialNumber)
{

   for(int i=0;i<MAX_SIZE;i++)
   {
       if(Inventory[i]->getSerialNumber()== _serialNumber)
       {
           delete Inventory[i];
           Inventory[i]=nullptr;
           count--;
           return true;
        }
   }
return false;
}

void ElectronicStoreInventory::print() const
{

for(int i=0;i<MAX_SIZE;i++)
{
if(Inventory[i] != nullptr)
Inventory[i]->print();
}

}

void ElectronicStoreInventory::summary() const
{
int computers = 0, printers = 0;
for(int i=0;i<MAX_SIZE;i++)
{
if(Inventory[i] != nullptr)
{
if(Inventory[i]->getType() == "Computer")
computers++;
else if(Inventory[i]->getType() == "Printer")
printers++;
}
}
std::cout << "Total number of computers in the store = " << computers << std::endl;
std::cout << "Total number of printers in the store = " << printers << std::endl;
}


ElectronicStoreInventory::~ElectronicStoreInventory()
{
for(int i=0;i<count;i++)
{

delete Inventory[i];
Inventory[i] = nullptr;
}
}

const GenericDevice & ElectronicStoreInventory::getDevice(int pos)
{
    if(pos >=0 && pos < MAX_SIZE && Inventory[pos]!=nullptr)
        return *Inventory[pos];
    else
    {
        std::cout << "Invalid position" << std::endl;
        exit(0);
    }
    
}

ElectronicStoreInventory::ElectronicStoreInventory(const ElectronicStoreInventory & objToCopy)
{
    count = objToCopy.count;
    for (int i =0; i < MAX_SIZE; i++)
        if (objToCopy.Inventory[i]!=nullptr)
        {
            if (objToCopy.Inventory[i]->getType() == "Computer")
            {
                Inventory[i] = new Computer((Computer &)*objToCopy.Inventory[i]);
            }
            else if (objToCopy.Inventory[i]->getType() == "Printer")
            {
                Inventory[i] = new Printer((Printer &)*objToCopy.Inventory[i]);   
            }
            
        }
        else
        {
            Inventory[i] = nullptr;
        }
        
}

const ElectronicStoreInventory & ElectronicStoreInventory::operator = (const ElectronicStoreInventory & RHS)
{
    if (this != &RHS)
    {
        int _count = 0;
        int i=0;
        while(_count < count)
        {
            if (Inventory[i]!= nullptr)
            {
                delete Inventory[i];
                Inventory[i] = nullptr;
                _count++;
            }
            i++;
        }
        count = RHS.count;
        for (int i =0; i < MAX_SIZE; i++)
            if (RHS.Inventory[i]!=nullptr)
            {
                if (RHS.Inventory[i]->getType() == "Computer")
                {
                    Inventory[i] = new Computer((Computer &)*RHS.Inventory[i]);
                }
                else if (RHS.Inventory[i]->getType() == "Printer")
                {
                Inventory[i] = new Printer((Printer &)*RHS.Inventory[i]);   
                }
            
            }
            else
            {
            Inventory[i] = nullptr;
            }   
    }
    return *this;
}


