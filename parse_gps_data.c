#include "parse_gps_data.h"
#include <string.h>
#include <stdlib.h>

bool gga_validation(const char* packet, GPSData* gpsData)
{
    if (packet == NULL || gpsData == NULL || strncmp(packet, "$GPGGA,", 7) != 0) {
        // Null packet or not a GGA packet
        printf("INVALID FORMAT (GGA FORMAT NOT FOUND)!\n");
        return false;
    }
    return true;
}

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

int parse_gps_data(const char* packet, GPSData* gpsData)
{
    if (!gga_validation(packet, gpsData)) return 0;
    checksum_validation(packet, gpsData) ? extract_func(packet, gpsData) : printf("GPS LOCK FAILURE!\n");
}