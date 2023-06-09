# PARSE GPS DATA
The ESP-32 GPS Data Parsing Library is a versatile software solution designed to facilitate the extraction and parsing of GPS data from NMEA-formatted packets. Built specifically for the ESP-32 microcontroller using the esp-idf v5.0 stable framework, this library empowers developers to effortlessly integrate GPS functionality into their ESP-32 projects. By leveraging the library's features, developers can efficiently extract vital information such as time, latitude, and longitude from GPS packets, enabling real-time positioning and location-based applications. With its emphasis on accuracy, reliability, and resource efficiency, the ESP-32 GPS Data Parsing Library is an essential tool for ESP-32 developers seeking to harness the power of GPS technology in their projects.

### NOTE
This library is written in C, and can be used for any C compatible frameworks.

## Features
1. GPS Data Parsing: The library provides functions to parse GPS data in NMEA format, specifically focusing on extracting relevant information from GGA packets.

2. ESP-32 Integration: The library is designed to work with ESP-32 microcontroller using the esp-idf v5.0 stable framework. 

3. Structured Data: The parsed GPS data is organized and stored in a structured format using a custom-defined struct, making it easy to access and use individual GPS parameters such as time, latitude, and longitude.

4. Checksum Validation: The library includes functionality to validate the checksum of the received GPS packets, ensuring the integrity of the data and detecting any transmission errors.

5. Efficient Implementation: The library is implemented with efficiency in mind, using optimized code and algorithms to process and extract GPS data.

## Installation
1. Clone the repository to your local machine.
2. Copy the library files into your ESP-IDF project directory.
3. Set up the ESP-IDF development environment on your machine.
4. Integrate the library by adding it to your ESP-IDF project's components folder.
5. Modify the CMakeLists.txt file to include the library in your build.
6. Implement GPS parsing in your project using the library's functions and structures.
7. Build and flash your ESP-IDF project to the ESP-32 device.