#include "CADARS_GARSclass.h"

CADARS_GARSData::CADARS_GARSData()
{
    Integer iStrARS;
    Integer LSCSize;

    aGD.GARSName = "";

    delete aGD.ListRCBuzy;
    delete aGD.ListRCFree;
    delete aGD.ListAndOr;
    delete aGD.ListSCAndOr;      //Список ссылок на условия "И", "ИЛИ", в доплнение к основным - те, от которых зависят особые условия
    delete aGD.ListSCResults;
    delete aGD.ListSCTimers;

    aGD.NumTopicSheet = 0;
    aGD.AmountTableStrings = 0;
            //.NoErrors = True
            //.BotGARSrow = 0

    aGD.BitsCombination.Hi = 0;                 //Главная и единственная битовая комбинация
    aGD.BitsCombination.Lo = 0;                 //Главная и единственная битовая комбинация

    delete aGD.AllVariables; //() As tOneVariable      //Всё!!! И РЦ, и Особые, и другие сигналы

    if (!aGD.SpecConTables) {
        LSCSize = -1;
    }
    else{
        LSCSize = sizeof(aGD.SpecConTables);
    }

    for (iStrARS = 0; iStrARS<=LSCSize;iStrARS++)
        delete aGD.SpecConTables[iStrARS].ListInpVars;

    delete aGD.SpecConTables; //() As tOneSCTable

    aGD.NRowFrq = 0;

    for (iStrARS = 1; iStrARS<=ARSTableDimension;iStrARS++ )
    {
        aGD.MainARSTable[iStrARS].ConditionsAnd.bitDatas.bitFunction.Hi = 0;
        aGD.MainARSTable[iStrARS].ConditionsAnd.bitDatas.bitFunction.Lo = 0;
        aGD.MainARSTable[iStrARS].ConditionsAnd.bitDatas.bitMask.Hi = 0;
        aGD.MainARSTable[iStrARS].ConditionsAnd.bitDatas.bitMask.Lo = 0;
        delete aGD.MainARSTable[iStrARS].ConditionsAnd.ToVars;

        aGD.MainARSTable[iStrARS].ConditionsOr.bitDatas.bitFunction.Hi = 0;
        aGD.MainARSTable[iStrARS].ConditionsOr.bitDatas.bitFunction.Lo = 0;
        aGD.MainARSTable[iStrARS].ConditionsOr.bitDatas.bitMask.Hi = 0;
        aGD.MainARSTable[iStrARS].ConditionsOr.bitDatas.bitMask.Lo = 0;
        delete aGD.MainARSTable[iStrARS].ConditionsOr.ToVars;

        aGD.MainARSTable[iStrARS].RailCircuitsBuzy.bitDatas.bitFunction.Hi = 0;
        aGD.MainARSTable[iStrARS].RailCircuitsBuzy.bitDatas.bitFunction.Lo = 0;
        aGD.MainARSTable[iStrARS].RailCircuitsBuzy.bitDatas.bitMask.Hi = 0;
        aGD.MainARSTable[iStrARS].RailCircuitsBuzy.bitDatas.bitMask.Lo = 0;
        delete aGD.MainARSTable[iStrARS].RailCircuitsBuzy.ToVars;

        aGD.MainARSTable[iStrARS].RailCircuitsFree.bitDatas.bitFunction.Hi = 0;
        aGD.MainARSTable[iStrARS].RailCircuitsFree.bitDatas.bitFunction.Lo = 0;
        aGD.MainARSTable[iStrARS].RailCircuitsFree.bitDatas.bitMask.Hi = 0;
        aGD.MainARSTable[iStrARS].RailCircuitsFree.bitDatas.bitMask.Lo = 0;
        delete aGD.MainARSTable[iStrARS].RailCircuitsFree.ToVars;

        aGD.MainARSTable[iStrARS].Frequences.MainFrqValue = 0;
        aGD.MainARSTable[iStrARS].Frequences.WarnFrqValue = 0;
        aGD.MainARSTable[iStrARS].Frequences.OutOfGeneration = false;
        aGD.MainARSTable[iStrARS].Frequences.Priority = 0;

        delete aGD.MainARSTable[iStrARS].SpecCondList;
        aGD.MainARSTable[iStrARS].IndxEndRoute = 0;
        aGD.MainARSTable[iStrARS].NumRoute = 0;
    }//Next        //Инициализированы все строки таблицы АРС

    aGD.ZeroFrequency = DefFrequency("0", "0");
    aGD.SpeedLimit = DefFrequency("NoLim", "NoLim");
    aGD.AlwaysTee = false;
    aGD.DrawNumericComb = false;
    aGD.RunningZero = false;
    aGD.DrawDebugSC = false;

}

tFrequences CADARS_GARSData::DefFrequency(string MainFName,string WarnFName)
{
    //Запомнить нормальные числа частоты и определить приоритет.  Это не нужно->ByVal GARName As String,
    tFrequences R;

    R.MainFrqValue= ConvStrToFreq(MainFName);
    R.WarnFrqValue = ConvStrToFreq(WarnFName);
    R.OutOfGeneration=false;

    if (R.WarnFrqValue == 0)
    {
        if (R.MainFrqValue != 0)
        {
            R.WarnFrqValue = R.MainFrqValue;
        }
        else
        {
           R.OutOfGeneration= true;
        }
    }

    if (R.MainFrqValue > 400 or R.WarnFrqValue > 400)
        R.Priority = 5000;
    else if (R.MainFrqValue == 75 and R.WarnFrqValue == 325)
           R.Priority = 1000;
    else if (R.MainFrqValue == 75 and R.WarnFrqValue == 125)
        R.Priority = 950;
    else if (R.MainFrqValue == 75 and R.WarnFrqValue == 175)
        R.Priority = 900;
    else if (R.MainFrqValue == 125 and R.WarnFrqValue == 325)
        R.Priority = 850;
    else if (R.MainFrqValue == 125 and R.WarnFrqValue == 175)
        R.Priority = 800;
    else if (R.MainFrqValue == 125 and R.WarnFrqValue == 225)
        R.Priority = 750;
    else if (R.MainFrqValue == 175 and R.WarnFrqValue == 325)
        R.Priority = 700;
    else if (R.MainFrqValue == 175 and R.WarnFrqValue == 225)
        R.Priority = 650;
    else if (R.MainFrqValue == 175 and R.WarnFrqValue == 275)
        R.Priority = 600;
    else if (R.MainFrqValue == 225 and R.WarnFrqValue == 325)
        R.Priority = 1100;
    else if (R.MainFrqValue == 225 and R.WarnFrqValue == 225)
        R.Priority = 500;
    else if (R.MainFrqValue == 225 and R.WarnFrqValue == 275)
        R.Priority = 450;
    else if (R.MainFrqValue == 275 and R.WarnFrqValue == 275)
        R.Priority = 400;
    else if (R.MainFrqValue == ValARSAO and R.WarnFrqValue == ValARSAO)
        R.Priority = 200;
    else
        R.Priority = 1;
    return R;
}


Integer CADARS_GARSData::ConvStrToFreq(string InpStr)
{
    if (InpStr.find("NoLim"))
        return 999;
    else if (InpStr.find(SampleARSAO))
        return ValARSAO; //"АРСАО"
    else if (InpStr.find("325"))
        return 325;
    else if (InpStr.find("275"))
        return 275;
    else if (InpStr.find("225"))
        return 225;
    else if (InpStr.find("175"))
        return 175;
    else if (InpStr.find("125"))
        return 125;
    else if (InpStr.find("75"))
        return 75;
    else
        return 0;
}


