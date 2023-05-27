#include <stdbool.h>
#include <stdio.h>

typedef struct {
    char params[10][20]; //defining a 2-dim array that can store upto 10 parameters
} GPSData;

bool gga_validation(const char* packet, GPSData* gpsData);
bool checksum_validation(const char* packet, GPSData* gpsData);
void convert_time_to_utc(char* input);
void print_parsed_data(const char* packet, GPSData* gpsData);
void extract_func(const char* packet, GPSData* gpsData);
int parse_gps_data(const char* packet, GPSData* gpsData);

#endif  // PARSE_GPS_DATA_H