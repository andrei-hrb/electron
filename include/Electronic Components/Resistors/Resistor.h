#ifndef REZISTOR_H
#define REZISTOR_H

#include "Electronic Components/ElectronicComponent.h"

class Resistor : public ElectronicComponent{

public:
    Resistor();

    //Drawing the component:
    void Show();
};

#endif // REZISTOR_H
