#include <iostream>
#include "Services/ExcelService.h"

using namespace std;
using namespace Services;

int main() {   

    cout << "Hello World" << endl;

    string name = Services::GetName();

    cout << "You name is " + name << endl;

    return 0;
}