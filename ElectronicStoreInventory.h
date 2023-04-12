#ifndef ELECTRONICSTOREINVENTORY_H
#define ELECTRONICSTOREINVENTORY_H

#include "GenericDevice.h"

const int MAX_SIZE = 100;

class ElectronicStoreInventory
{
    private: 
        GenericDevice *Inventory[MAX_SIZE];
        int count;  // number of devices currently in the store
    public:
        ElectronicStoreInventory();
        ElectronicStoreInventory(const ElectronicStoreInventory &);
        const ElectronicStoreInventory & operator = (const ElectronicStoreInventory &);
        int getCount() {return count;}
        bool addDevice(const GenericDevice &);
        bool removeDevice(const std::string &);
        const GenericDevice & getDevice(int);
        void print() const;
        void summary() const;
        ~ElectronicStoreInventory();
};

#endif
