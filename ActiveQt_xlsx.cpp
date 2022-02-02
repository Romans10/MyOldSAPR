#include "ActiveQt_xlsx.h"
//#include

ActiveQt_xlsx::ActiveQt_xlsx()
{
    // получаем указатель на Excel

    int ass;
    std::string tStr;

    ass=5+5;

    //return;

    QAxObject *mExcel = new QAxObject( "Excel.Application" /*,this*/);

    mExcel->querySubObject( "Visible",true);

    // на книги
    QAxObject *workbooks = mExcel->querySubObject( "Workbooks" );

    // на директорию, откуда грузить книгу
    tStr="D:\\_Qt_Homework\\_Qt\\SAPRbase\\Адр АРС_Карачарово_V22.xlsx";

    QAxObject *workbook = workbooks->querySubObject( "Open(const QString&)", "D:\\_Qt_Homework\\SAPRbase\\Адр АРС_Карачарово_V22.xlsx");

    // на листы (снизу вкладки)
    QAxObject *mSheets = workbook->querySubObject( "Sheets" );

    mExcel->querySubObject( "Visible",false);

    // указываем, какой лист выбрать.
    QAxObject *StatSheet = mSheets->querySubObject( "Item(const QVariant&)", QVariant("Begin") );

}
