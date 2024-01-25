#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Menu.h"
void Menu()
{
    cout << "1.See Menu\n2.Add New Item in Menu\n3.Delete Item in Menu\n4.Exit Menu setting" << endl;
    char user_input;
    cin >> user_input;
    Menu menu();
    switch(user_input)
    {
        case '1':
            menu.Display_menu();
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            return;
            break;

    }

}
int main()
{
    cout << "\t\tFri-Chicks\n" << endl;
    cout << "1.Menu Setting\n2.Generate Bill\n3.Billing History\n4.Total Sales\n5.Exit" << endl;
    cout << "Enter the corresponding number ";
    char input;
    cin >> input;
    switch(input)
    {
        case '1':
            system("CLS");
            Menu();
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        default:
            return 0; //will change it to show input again if invalid
    }
    return 0;
}