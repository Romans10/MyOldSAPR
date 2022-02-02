#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>

//#define Byte unsigned char


#define Const const


typedef unsigned int Long;
typedef short int Integer;

typedef unsigned char Byte;
using namespace std;


 const string AddrOKShName  = "Адреса";
 const Byte AmBeginLetters   = 5;    //Длина сокращенного имени проекта
 const Byte MaxTopicRowAmount = 200 ;  //Макс строк в топике

 const string BuzyMark  = "*занят*РЦ*";
 const string FreeMark   = "*своб*РЦ*";
 const string ConditionMark  = "*дополн*услов*";
 const string CondAndMark  = "И";
 const string CondOrMark  = "ИЛИ";
 const string CondRearMark  = "тыл";
 const string ColCondSpecMark = "*особ*";

 const string TableSpCondMark  = "Особ*услов*";
 const string SignalTablSCMark = "Сигнал";
 const string ColMainCondTSCMark  = "Основ*услов*";
 const string ColResultTSCMark = "*Результат*";
 const string ColNaborTSCMark  = "*Набор*И*";

 const string FrequecyMark  = "*сигналь*";
 const string FirstColOnAdrSheetMark = "Тип ОК";
 const string RusWordTable = "Таблица";
 const Byte NumLetInTblName = 2;           //Кол-во символоа в номере таблицы (две больших лат. буквы)

 const string GenrMark = "Генератор";              //Признак начала акад-листа на листе эксель //Признак верха таблицы для одного ГАРС-Е
 const string ObjectColName = "Объект";            //Название столбца Объект на листе адресации
 const string OKDName = "ОКД-Е";
 const string GARSName = "ГАРС-Е";

 const string StationMark1   = "ст. ";
 const string StationMark2   = "станция";
 const string StationMark3   = "ст ";

 const Byte NCol_3sheet = 8;            //Для 3-го листа - номер столбца "Имя подключенного объекта", где "наши" наименования

 const Byte StartRowDrawing = 2;                   //Первая строка, от которой рисуются итоговые таблицы на тест-листах
 const Byte tartColDrawing = 2 ;                  //Первый столбец, от которого рисуются итоговые таблицы на тест-листах
 const Byte AddToStartRowForSortRC = 20;           //Начиная от этой цифры будет рисоваться столбики РЦ для сортировки

        //Для Адресация-листа:
 const Byte SymRCCol_ShAddr  = 'P'; //"80; //"P"//             //Символ столбца, где "наши" наименования РЦ. Следующий столбец рядом - "чистые" наименования РЦ, из таблиц
 const Byte RCList1stRow  = 7 ;                   //Номер стартовой строки на листе Адресация, где начинаются РЦ
 const Byte RCList1stCol  = SymRCCol_ShAddr - 65; //Номер столбца, где "наши" наименования РЦ


 const Byte KSSList1stRow  = RCList1stRow;   //Номер столбца, где Список сигналов КС: 116/118КС
 const Byte KSSList1stCol  = RCList1stCol + 3;    //Номер столбца, где Список сигналов КС: 116/118КС



//Для Адресация-листа: места, где ставятся 0/1 для режимов работы
 const Byte WorkModes1stColumn = RCList1stCol - 2;
 const Byte WorkModes2ndColumn = WorkModes1stColumn - 6;

 const Byte DrawNumericCombRow = 1;
 const Byte AlwaysTeeRow = 2;
 const Byte RunningZeroRow = 3;
 const Byte DrawDebugSCRow = 4;
 const Byte ShowWordAtCopyRow = 1;


 const Byte IntermTableSymStartCol  = 85; //SymRCCol_ShAddr + 3 //85 ="U"////Места начала промежуточной таблицы
 const Byte IntermTableNumStartCol = IntermTableSymStartCol - 64;             //Места начала промежуточной таблицы
 const Byte ButtonAdrShtNumtartCol = IntermTableNumStartCol + 3;

 const Byte TestShtButtNumRow  = 2; //RCList1stRow

 const string ListFoundRCText = "Найденные рельсовые цепи";
 const string AmountRCText = "Кол-во";

 const string ListFoundKSSText = "Найденные сигналы КСС";


 const Byte NumColTopic1stGName = 27;     //Место (столбец) на тест-листе в 1-й строке, где хранятся номера строк листа исх. данных для топика (верхний и нижний, подряд).
 const Byte TableCoordColm = 1;           //Место (столбец), куда записываются над каждой таблицей цифры её границ (размеры)
 const Byte ColNameAdrShtOnTestSht = NumColTopic1stGName + 8;   //Место (столбец), где записано имя Станции

 const Byte MaxLenTable  = 26;       //Максимальная длина таблицы инициализации на листе
 const Byte NumRow1Table  = 5;       //Номер первой сроки первой таблицы инициализации
 const Byte NumRow2Table  = 10;      //Номер первой сроки второй таблицы

 //const ItIsFromRearCol = True;                //Признак, что инверсия -  для считываемых сигналов из столбца "Тыл"
// const DontChangeIn = True;                   //Не изменять входной массив при формировании списка условий

 const int ColorRTBuzy      = 10079487;          //РЦ которые заняты. Цвет для них (оранжевый?)
 const int ColorRTFree      = 13434879;          //остальные РЦ, которые "свободны". Цвет для них (светло-желтый)
 const int ColorASAnd       = 16772300;           //Доп. сигналы "фронт И". Цвет для них (слегка-серо-голубой?)
 const int ColorASOr        = 16777164;            //Доп. сигналы "фронт ИЛИ". Цвет для них (светло-голубой)
                     //16764057 Цвет темно-голубой
 const int ColorSpSig       = 52428;              //Спец. сигналы. Цвет для них (зелено-желто-говенный)
 const int ColorFrq         = 16764108;             //Заголовок частоты
 const int ColorError       = 10066431;           //Так "красятся" ячейки, в которых есть сигналы, которые не найдены в списках листа "Адресация_ОК"
 const int ColorZeroFrq     = 16306683;              //Ячейки с собственной частотой нулевого маршрута
 const int ColorBelZeroFrq  = 14408697;        //Ячейки с частотой альтернативной нулевого маршрута (ниже)
 const int ColorFXFrq       = 52428;                //13955299             //Ячейки с частотой FX (275)
 const int ColorFeasibleFrq = 12317334;       //Ячейки с собственной частотой
 const int ColorBelowFrq    = 13827280;          //Ячейки с частотой альтернативной (ниже)
 const int ColorOtherRoute  = 9961444;
 const int ColorResultSC    = 15641053;          //Цвет результатов особых сигналов
 const int ColorInDataSC    = 16765416;          //Цвет исх. данных особых сигналов


 const string FrontSml = "ф"; //фоФаф             //Малая "ф":     Окончание названия для фронт-сигнала, не имеющего полного тройника (или не связанного со своим "тылом")
 const string FrontBig = "Ф"; //ФофаФ             //Большая "Ф":   Окончание названия для фронт-сигнала, имеющего "тыл" и связанного логикой со своим "тылом"
 const string RearSml = "т";                     //Малая "т":     Окончание названия для тыл-сигнала, не имеющего полного тройника (или не связанного со своим "фронтом")
 const string RearBig = "Т";                     //Большая "Т":   Окончание названия для тыл-сигнала, имеющего "фронт" и связанного логикой со своим "фронтом"
 const string EndTRC_PP = "ПП";                  //"ПП" Окончание названия для ТРЦ в файле адресации
 const string EndTRC_P = "П";                    //"П" Окончание названия для ТРЦ в файле теста
 const string Branch1RC = "Р1ПП";                //"Р1ПП" Окончание названия 1-го ответвления для разветвленной ТРЦ в файле теста
 const string Branch2RC = "Р2ПП";                //"Р2ПП" Окончание названия 2-го ответвления для разветвленной ТРЦ в файле теста
 const string Branch3RC = "Р3ПП";                //"Р3ПП" Окончание названия 3-го ответвления для разветвленной ТРЦ в файле теста
 const string RCFrontSml = "Пф";                 //"Пф" Окончание Фронт-сигнала рельсовой цепи (она имеет тройник)
 const string RCRearSml = "Пт";                  //"Пт" Окончание тыл-сигнала рельсовой цепи (она имеет тройник)
 const string KOrelay = "КО";                    //"КО" окончание для особого огневого реле. Мнверсная логика для пары ФТ: "01" - пассивный, все остальное - активный
 const string KJOending = "КЖО";                    //"КО" окончание для особого огневого реле. Мнверсная логика для пары ФТ: "01" - пассивный, все остальное - активный

 const string BranchMask = "*Р#П*";


 const string ASSrelay = "АСС";                  //"АСС" окончание для особого сигнала АСС, связано с аварийной остановкой (?)

 const string FreqFX = "f275";                   //частота для "ФХ"
 const string EquSym = "=";                      //Символ "=", может встретиться, например для инверсии
 const string cLiterZero = "0";

 const string SymFr = ":FR = ";
 const string SymPfr = ":PFR = ";
 const string SymF = "f";

 const string KSMark = "КС";                    //Внутренние сигналы!!!
 const string FXMark = "ФХ";                     //Сигнала фиксация хвоста
 const string NUMark = "НУ=";
 const string SUMark = "СУ=";
 const string CHUMark = "ЧУ=";
 const string VUMark = "ВУ=";
 const string RUMark = "РУ=";

 const string ZanMark = "зан";

 const string TmrMark = "Тмр";

 const string ErrorMark = "???";
 const Byte BaseASFunction = 1;        //Здесь фронт = 1, тыл = 0. Поскольку Фронт младший бит - то 1. Остальные комбинации должны приниматься как Фронт = 0
 const Byte BaseKOFunction = 2;        //Здесь фронт = 0, тыл = 1. Поскольку Фронт младший бит - то 2. Остальные комбинации должны приниматься как Фронт = 1

 const Byte ShortProjNameLen = 5;

 const Byte SetToRear = 1;
 const Byte SetToFront = 2;

 const string TextARSAO = "АРСАО";
 const string SampleARSAO = "АО";
 const Integer ValARSAO = 400;


 const string SLMark = "ОгСк";


 const Byte BitCapacityLong  = 64;

 const Byte NBitForOnes = BitCapacityLong - 2;
 const Byte NBitForZero  = NBitForOnes - 1;

 //const  ClosedLoop As Boolean = False
 //const OpenLoop As Boolean = True
 //const cExeptOnes As Boolean = True

 const Integer ARSTableDimension  = 50;



#endif // CONSTANTS_H
