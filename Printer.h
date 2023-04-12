#ifndef PRINTER_H
#define PRINTER_H

#include "GenericDevice.h"

class Printer : public GenericDevice // Use inheritance and the virtual qualifier when needed
{
    private:
        int ppm;
        std::string color;
    public:
        Printer(const int _ppm, const std::string & _color, const std::string & _manufacturer, const std::string & _description, const std::string & _serialNumber);
        void print() const ;
        //add getType
        std::string getType() const;
        bool operator == (const Printer &) const;
       
};

#endif