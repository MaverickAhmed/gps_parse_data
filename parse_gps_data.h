#include <stdbool.h>
#include <stdio.h>

typedef struct {
    char params[10][20]; //defining a 2-dim array that can store upto 10 parameters
} GPSData;

bool checksum_validation(const char* packet, GPSData* gpsData);
void extract_func(const char* packet, GPSData* gpsData);
void parse_gps_data(const char* packet, GPSData* gpsData);

#endif  // PARSE_GPS_DATA_H