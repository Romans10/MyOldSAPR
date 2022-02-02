#ifndef CADARS_GARSDATA_H
#define CADARS_GARSDATA_H
#include "CADARS_DataTypes.h"

class CADARS_GARSData
{
    tGARSData aGD;
    Integer ConvStrToFreq(string MainFName);

public:
    CADARS_GARSData();
    tFrequences DefFrequency(string MainFName, string WarnFName);
};

#endif // CADARS_GARSDATA_H
