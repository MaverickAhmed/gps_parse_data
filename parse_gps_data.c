#include "parse_gps_data.h"
#include <string.h>
#include <stdlib.h>

bool checksum_validation(const char* packet, GPSData* gpsData) {
    int i = 1;                               // Start after '$' symbol
    unsigned char cal_checksum = 0;          // Using unsigned char for bitwise operations

    while (packet[i] != '*' && packet[i] != '\0') {
        cal_checksum ^= packet[i];           // XOR operation to calculate checksum
        i++;
    }
    const char* packet_checksum = &packet[i + 1];   // Start of the checksum field
    char* endptr;
    unsigned char checksum = strtol(packet_checksum, &endptr, 16);

    return (cal_checksum == checksum);
}