#include <iostream>
#include <chrono>
#include "Services/ExcelService.h"
#include "libs/OpenXLSX/OpenXLSX.hpp"

using namespace std;
using namespace Services;
using namespace OpenXLSX;

void ReadExcelFile(string excelFile)
{
    XLDocument doc;
    doc.open(excelFile);

    auto wks = doc.workbook().worksheet("DisputeATM");

    int totalRows = wks.rowCount();

    for (int i = 2; i < totalRows; i++)
    {
        XLCellValue createDateCellValue = wks.cell("B" + to_string(i)).value();
        XLCellValue termIdCellValue = wks.cell("H" + to_string(i)).value();
        XLCellValue branchCellValue = wks.cell("I" + to_string(i)).value();

        cout << "RowNo: " + to_string(i) 
             << ", Create Date: " + createDateCellValue.get<string>() 
             << ", Term Id: " + termIdCellValue.get<string>() 
             << ", Branch: " + branchCellValue.get<string>() 
             << endl;
    }
}

void CreateExcelFile()
{
    XLDocument doc;
    doc.create("Spreadsheet.xlsx");

    auto wks = doc.workbook().worksheet("Sheet1");

    wks.cell("A1").value() = "Hello, OpenXLSX!";

    doc.save();
}

int main()
{

    cout << "Hello World" << endl;

    string name = Services::GetName();

    cout << "You name is " + name << endl;

    string excelFile = "/Users/arahkyambubpah/Sources/Playgrounds/C++/ExcelReader/files/DisputeATM_01-260124.xlsx";

    ReadExcelFile(excelFile);

    return 0;
}