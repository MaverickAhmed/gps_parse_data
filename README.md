# PARSE GPS DATA
This repository takes GPS packet in GGA format, and parses/extracts it into individual parameters. 

## Features
1. GPS Data Parsing: The library provides functions to parse GPS data in NMEA format, specifically focusing on extracting relevant information from GGA packets.

2. ESP-32 Integration: The library is designed to work with ESP-32 microcontroller using the esp-idf v5.0 stable framework. 

3. Structured Data: The parsed GPS data is organized and stored in a structured format using a custom-defined struct, making it easy to access and use individual GPS parameters such as time, latitude, and longitude.

4. Checksum Validation: The library includes functionality to validate the checksum of the received GPS packets, ensuring the integrity of the data and detecting any transmission errors.

5. Efficient Implementation: The library is implemented with efficiency in mind, using optimized code and algorithms to process and extract GPS data.

## Installation
