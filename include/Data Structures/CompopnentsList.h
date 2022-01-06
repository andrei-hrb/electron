#ifndef COMPOPNENTSLIST_H
#define COMPOPNENTSLIST_H

#include "ElectronicComponent.h"

class CompopnentsList{
    private:
        int numberOfComponents = 0;


    public:
        CompopnentsList();
        ElectronicComponent* componentsList[50];

        int getNumberOfComponents();
        void addComponent(int componentCode);
        void removeComponent(std::string thisComponentCode);
        ElectronicComponent* getSelectedComponent();
};

#endif // COMPOPNENTSLIST_H
