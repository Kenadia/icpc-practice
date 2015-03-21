//escape.cpp

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "newline" << endl;
    cout << "MEOW \n" << endl;
    cout << "carriage return" << endl;
    cout << "meow meow \r" << endl;
    cout << "vertical tab" << endl;
    cout << "\v meow " << endl;
    cout << "Form feed" << endl;
    cout << "\f whut " << endl;
    cout << "Alert (beep)" << endl;
    cout << "alert??? \a" << endl;
    cout << "Question mark " << endl;
    cout << "h3ll0\?" << endl;

    cout << "double quotation" << endl;
    cout << "\"" << endl;
    cout << "backslash" << endl;
    cout << "\\" << endl;


    string s = "string expressed in \
    multiple lines";

    cout << s << endl;
    return 0;
}