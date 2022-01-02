#ifndef MEASUREMENTSINFO_H
#define MEASUREMENTSINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class MeasurementsInfo
{
    public:
        MeasurementsInfo();
        
        Button exit;
        Ammeter ammeter;
        Voltmeter voltmeter;

        int window_code;
        void Show(double w, double h);
        int WatchClick();
        void WatchExit();
};


#endif // MEASUREMENTSINFO_H
