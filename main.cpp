#include <iostream>
#include <chrono>
#include "Services/ExcelService.h"
#include "libs/OpenXLSX/OpenXLSX.hpp"
#include "Models/DisputeModel.h"
#include <stack>

using namespace std;
using namespace Services;
using namespace OpenXLSX;
using namespace Models;

std::stack<Models::DisputeModel> ReadExcelFile(string excelFile)
{
    XLDocument doc;
    doc.open(excelFile);

    auto wks = doc.workbook().worksheet("DisputeATM");

    int totalRows = wks.rowCount();

    std::stack<Models::DisputeModel> disputes;

    for (int i = 2; i < totalRows; i++)
    {
        XLCellValue createDateCellValue = wks.cell("B" + to_string(i)).value();
        XLCellValue termIdCellValue = wks.cell("H" + to_string(i)).value();
        XLCellValue branchCellValue = wks.cell("I" + to_string(i)).value();

        Models::DisputeModel dispute(createDateCellValue.get<string>(), branchCellValue.get<string>(), termIdCellValue.get<string>());

        disputes.push(dispute);
    }

    return disputes;
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

    std::stack<Models::DisputeModel> models = ReadExcelFile(excelFile);

    for(int i = 0; i < models.size(); i++)
    {
        Models::DisputeModel dispute = models.top();

        std::cout << dispute.GetBranch() << std::endl;

        models.pop();
    }

    return 0;
}