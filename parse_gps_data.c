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

void convert_time_to_utc(char* input) {
    int hours, minutes, seconds;
    sscanf_s(input, "%2d%2d%2d", &hours, &minutes, &seconds);
    // Exports the output as "Time: HH:MM:SS UTC"
    printf("Time: %02d:%02d:%02d UTC\n", hours, minutes, seconds);
}

void print_parsed_data(const char* packet, GPSData* gpsData)
{
    printf("GPS LOCKED SUCCESSFULLY!\n");
    printf("String: %s\n", packet);
    convert_time_to_utc(gpsData->params[0]);   //comment this & uncomment the line below if you don't want utc conversion
    //printf("Time: %s\n", gpsData->params[0]);
    printf("Latitude: %s\n", gpsData->params[1]);
    printf("Latitude Direction: %s\n", gpsData->params[2]);
    printf("Longitude: %s\n", gpsData->params[3]);
    printf("Longitude Direction: %s\n", gpsData->params[4]);
    printf("Fix Quality: %s\n", gpsData->params[5]);
    printf("Number of Satellites: %s\n", gpsData->params[6]);
    printf("HDOP: %s\n", gpsData->params[7]);
    printf("Altitude: %s\n", gpsData->params[8]);
    printf("Height of Geoid: %s\n", gpsData->params[9]);
    printf("\n");
}

void extract_func(const char* packet, GPSData* gpsData) {

    int tokenStart = 7; // Start index of the first token
    int tokenEnd;

    for (int i = 0; i < 10; ++i) {
        tokenEnd = tokenStart;
        while (packet[tokenEnd] != ',' && packet[tokenEnd] != '\0') {
            tokenEnd++;
        }
        strncpy_s(gpsData->params[i], sizeof(gpsData->params[i]), &packet[tokenStart], tokenEnd - tokenStart);
        gpsData->params[i][tokenEnd - tokenStart] = '\0';
        tokenStart = tokenEnd + 1; // Moves to the next token
    }
    print_parsed_data(packet, gpsData);
}

int parse_gps_data(const char* packet, GPSData* gpsData)
{
    if (!gga_validation(packet, gpsData)) return 0;
    checksum_validation(packet, gpsData) ? extract_func(packet, gpsData) : printf("GPS LOCK FAILURE!\n");
}