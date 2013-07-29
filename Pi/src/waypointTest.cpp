//waypoint class testing

#include "waypoint.h"
#include "utilities.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

	GPSPoint first = {4413.4334, 7629.3137};
	GPSPoint second = {413.4225, 7629.2946};

	waypoint* test = new waypoint();

	cout<<"Testing GPSPoint"<<endl;
	cout<< "Lat: " <<first.lat<< " Lon: " << first.lon<<endl;

}