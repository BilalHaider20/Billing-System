#include <iostream>
using namespace std;
#include "Menu.cpp"
void Menu()
{
    cout << "1.See Menu\n2.Add New Item in Menu\n3.Delete Item in Menu\n4.Exit Menu setting" << endl;
    //Menu menu;

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
            //clear screen statment
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