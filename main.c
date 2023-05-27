#include <stdio.h>
#include "parse_gps_data.h"

int main() {
    // Given GGA packet 
    const char* packet = "$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";
    //comment above packet & uncomment any one of the following packets to try out different test cases
    //const char* packet ="$GPGSA,A,3,07,02,26,27,09,04,15, , , , , ,1.8,1.0,1.5*33"; //When GPS is not locked
    
    //Declaring a structure named data_struct 
    GPSData data_struct;
    // Calling the Parsing function
    parse_gps_data(packet, &data_struct);

    return 0;
}