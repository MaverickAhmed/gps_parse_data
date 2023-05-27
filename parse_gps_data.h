#include <stdbool.h>
#include <stdio.h>

typedef struct {
    char params[10][20]; //defining a 2-dim array that can store upto 10 parameters
} GPSData;

void parse_gps_data(const char* packet, GPSData* gpsData);
#endif  // PARSE_GPS_DATA_H