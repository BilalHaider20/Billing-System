#include <iostream>
#include "hotel.h"

using namespace std;

int main()
{
	Hotel *hotel = new Hotel("Fri-Chicks");
	hotel->MainMenu();
	return 0;
}