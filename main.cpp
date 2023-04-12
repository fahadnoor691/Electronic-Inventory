#include <iostream>
#include "ElectronicStoreInventory.h"
#include "Computer.h"
#include "Printer.h"

int main()
{
   //Uncomment when ready to test
   Computer C1("Intel I5","SSD",1024,16,"DELL","Desktop Computer","123456");
   Computer C2("Intel I5","SSD",1024,16,"DELL","Laptop Computer","123457");
   Computer C3("Intel I5","SSD",1024,16,"DELL","Laptop Computer","123458");
   Printer P1(10,"YES","BROTHER","Laser Printer","654321");
   Printer P2(11,"NO","HP","Inject Printer","654322");
   ElectronicStoreInventory myStore;
   myStore.addDevice(C1);
   myStore.addDevice(P1);
   myStore.addDevice(C2);
   myStore.addDevice(C3);
   myStore.addDevice(P2);
   myStore.removeDevice("123458");
   myStore.print();
   myStore.summary();
   return 0;
}
