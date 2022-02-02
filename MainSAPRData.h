#ifndef MainSAPRData_H
#define MainSAPRData_H

#include "Constants.h"


enum tModeCheck
{
    //место
    //vRailCircMode
    vRTBuzyMode,
    vRTFreeMode,
    vOrAndMode,
};

enum tPairType
{
    vPairBuzy,
    vPairFree,
    vPairAnd,
    vPairOr
};

enum tRCMode
{
    vStartStairs,
    vUsualStairs,
    vZero0Stairs,       //Buzy - без изменений, Free  - все нули
    vZero1Stairs,        //Buzy - все единицы  , Free  - все нули
    vZero2Stairs,        //Buzy - все нули,      Free  - все нули
    vZero3Stairs,        //Buzy - все нули,      Free  - все нули
    vFinishStairs
};

enum tVarType
{
    vNoDefine,   //0000 не использовать
    vRailCircut, //0001
    vRCBranch,   //0010
    vRCBuzy,     //0011
    vSignal,     //0100
    vRear,       //0101 Это не используется. Написано, чтобы занять значение 5
    vBolv_6,     //0110 Это не используется. Написано, чтобы занять значение 6
    vBolv_7,     //0111 Это не используется. Написано, чтобы занять значение 7
    vSpecVar,    //1000
    vSpecTbl,    //1001
    vSCTBack,    //1010
    vSCTAuto,    //1011 Это не используется. Пока.
    vBolv_12,    //1100
    vBolv_13,    //1101 Это не используется. Написано, чтобы занять значение 13
    vMarkBack,   //1110
    vBolv_15,    //1111 Это не используется. Написано, чтобы занять значение 15
    vSCTimer,
    vBolv_17,
    vBolv_18,
    vBolv_19,
    vSignKSS,
    vBolv_21,
    vBolv_22,
    vBolv_23,
    vCheckOnly
};

struct tTableSCColumns              //Данные для размеров и расположения таблицы Особых условий ни листе ИД АРС
{
    Integer RowMainCondNum;
    Integer ColsAdditCondAmount;
    Integer ColResultNum;
    Integer *ColsNaborNums; //[]
};

struct tOneVariable
{
    string CustomName;              //То название, которое дано в исходных таблицах от Метропроекта
    string OurProjName;             //Название, которое получено для тестов
    string OurProjNameRea;          //Для названий тыловых контактов, если есть
    Integer GCellsIndx;             //Номер столбца этого элемента на тест-листе, где строится таблицы тестирования.

    Integer SourceRow;              //Строка, откуда прочитан сигнал (из исходных данных)
    Integer SourceCol;              //Также столбец, откуда прочитан сигнал (из исходных данных)
    bool Tee;                       //Реальный тройник
    bool TagRKO;                    //Признак реле КО
    Integer IndKJO;                 //Индекс соответствующего сигнала КЖО. Если нет, то -1

    tVarType VarType;

    Integer PtrToSCTable;
    Integer NextBranch;

    Byte nBitIdx;
    Byte InitState;                 //Исходное (нормальное) состояние: РЦ свободны, сигналы =0
    Byte CurrState;
    bool WasChecked;
};


struct DublLong
{
    Long Hi;
    Long Lo;
};

struct tBitDatas
{
    DublLong bitFunction;               //ЧИСЛО - набор единичных битов-условий. 1, 0
    DublLong bitMask;                   //МАСКА - указывает, какие из битов-условий используются, какие нет (т.е., от каких ЗАВИСИТ - те равны 1)
};

//struct tBitDatasDubl
//    bitFunctionLo As Long             //ЧИСЛО - набор единичных битов-условий.  AND или OR этих условий разрешают Fосн или Fпрд
//    bitFunctionHi As Long             //ЧИСЛО - набор единичных битов-условий.  AND или OR этих условий разрешают Fосн или Fпрд
//    bitMaskLo As Long                 //МАСКА - указывает, какие из битов-условий используются, какие нет (т.е., от каких ЗАВИСИТ - те равны 1)
//    bitMaskHi As Long                 //МАСКА - указывает, какие из битов-условий используются, какие нет (т.е., от каких ЗАВИСИТ - те равны 1)
//    //bitCombination As Long
//};


struct tPointerToVar
{
    Byte VarValue;              //В каком значении сигнал входит в формулу (в строку tOneStringARSTable или tOneStringSCTable)
    Byte BitIndx;               //Индекс-ссылка на эемент массива Всех Переменных
    tVarType VarType;
};


struct tPtoVarsAndBits
{
    //ToVars() As tOneVariable
    tBitDatas bitDatas;
    tPointerToVar *ToVars;       //[]    //Cсылки на элементы массива условий                                        //
};

//struct tBitsDublAndPtoVars
//    bitDatas As tBitDatasDubl
//    ToVars() As tPointerToVar    //Cсылки на элементы массива условий
//};

struct tPairFrontRear
{
    tPointerToVar OnePair[1];
    tPairType PairType;                             //Для раскраски: Buzy, Free или другое
    Integer NumFunction;                            //По сути - это номер строки в таблице
};

struct tFrequences
{
        //MainFrq     As String
        //WarnFrq     As String
        Integer MainFrqValue;                       //        WarnFrqValue     As Integer
        bool OutOfGeneration;
        Integer Priority;
};

struct tOneStringSCTable
{
        tPtoVarsAndBits MainConditions;
        tPtoVarsAndBits *SetsOfAdditCondit;         //[]
        //ResultIndx As Integer //tPointerToVar
};

struct tOneSCTable
{
    //ItemSC  As tOneVariable
    //CurrState As Byte
    tPointerToVar ToHead;                           //Ссылка на Название сигнала - Заголовок - Голова таблицы
    Integer TimerCnt;
    Integer TimerVal;

    tOneStringSCTable StringsSCTable;
    Integer MaxAdditCondSets;

    tPointerToVar *ListInpVars;                     //[]    //Список всех входных ПРОСТЫХ переменных, от которых зависит эта таблица
};

struct tOneStringARSTable
{
        tPtoVarsAndBits RailCircuitsBuzy;
        tPtoVarsAndBits RailCircuitsFree;
        tPtoVarsAndBits ConditionsAnd;
        tPtoVarsAndBits ConditionsOr;
        Integer NumRoute;                           //К какому маршруту относится эта строка (номер маршрута)
        Integer IndxEndRoute;                       //Индекс (номер) последней строки этого маршрута
        tFrequences Frequences;
        //IsSpecCond As Boolean
        //RelayFXOff  As Boolean
        tPointerToVar *SpecCondList;    //[] As
};


struct tGARSData
{
    string GARSName;                    //Для этого ГАРС-Е:
    tPointerToVar *ListRCBuzy;  //()    //Список ссылок на занятые РЦ -
    tPointerToVar *ListRCFree;//() As tPointerToVar       //Список ссылок на свободные РЦ -
    tPointerToVar *ListAndOr;//() As tPointerToVar        //Список ссылок на основные условия "И", "ИЛИ"
    tPointerToVar *ListSCAndOr;//() As tPointerToVar      //Список ссылок на условия "И", "ИЛИ", в доплнение к основным - те, от которых зависят особые условия
    tPointerToVar *ListSCResults;//() As tPointerToVar    //Список ссылок на особые условия - результаты - в самой правой части ("273ФХ=0")
    tPointerToVar *ListSCTimers;//() As tPointerToVar

    Integer NumTopicSheet;            //Номер Топик-листа (куда выводить итоговую таблицу)

    BitsCombination As DublLong             //Главная и единственная битовая комбинация
    AllVariables() As tOneVariable      //Всё!!! И РЦ, и Особые, и другие сигналы

    MainARSTable(1 To ARSTableDimension) As tOneStringARSTable
    SpecConTables() As tOneSCTable

    AmountTableStrings As Integer

    NRowFrq As Integer                  //Номер столбца листа Excel с частотами (последний)
    ZeroFrequency As tFrequences        //Имена частот =0 для этой таблицы (для этого ГАРСа)
    SpeedLimit As tFrequences


    AlwaysTee   As Boolean              //Всегда раскрывать тройники
    DrawNumericComb As Boolean          //Рисовать ли битовые комбинации в промежуточной таблице
    RunningZero As Boolean              //Тип перебора: бегущий ноль
    DrawDebugSC As Boolean
};

enum tFrontRearPair
    vNotPairFR
    vIsPairFR
}

struct tenumContext
    FullenumList() As tPointerToVar
    AmFullenum As Long       //Кол-во строк полного перебора, это же - ЧИСЛО - текущая комбинация перебора
    lBitCap As Integer
    lCurrRow As Integer
    BiDigitsArr() As String     //Массив нулей/единиц
    NoFirstPass  As Boolean     //Непервый проход. Используется для инициализации
    Finished As Boolean
    CellColor As Long
//    AllZero As Boolean
//    AllUnit As Boolean
    Full_BitCombination As Long
};



#endif // MainSAPRData_H
