#include <iostream>
#include "Services/ExcelService.h"
#include "OpenXLSX/OpenXLSX.hpp"

using namespace std;
using namespace Services;
using namespace OpenXLSX;

int main() {   

    cout << "Hello World" << endl;

    string name = Services::GetName();

    cout << "You name is " + name << endl;

    XLDocument doc;
    doc.create("Spreadsheet.xlsx");

    auto wks = doc.workbook().worksheet("Sheet1");

    wks.cell("A1").value() = "Hello, OpenXLSX!";

    doc.save();

    return 0;
}