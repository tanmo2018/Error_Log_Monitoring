# Error Log Monitoring

## Overview
This program is a C++ solution for managing and analyzing error log entries in a monitoring platform. It provides functionality to submit new log entries, compute statistics based on log types and timestamps, and handle various query operations on the log entries.

## Features
- Submit new log entries to the platform.
- Compute minimum, maximum, and mean severity of log entries associated with a specified log type.
- Compute statistics for log entries occurring before or after a specified timestamp.
- Compute statistics for log entries occurring before or after a specified timestamp and associated with a specified log type.

## Assumptions
1. Timestamps are provided in ascending sorted order.
2. Log types can be any UTF-8 supported string with a maximum length of 100.
3. Severity is represented as a positive non-zero floating-point number with no limit.
4. Severity results are calculated with a precision of 10E-6.

## Requirements
- C++ compiler that supports C++11 or later.
- Standard C++ libraries.

## Usage
1. Clone this repository.
2. Navigate to the project directory.
3. Compile the program using a C++ compiler.
4. Create an input file named `input.txt` containing the operations to be performed. Each operation should be in the format specified in the problem statement.
5. Run the compiled program.
6. After running the program, the output will be generated in the `output.txt` file.
7. View the output in the `output.txt` file to see the results of the operations performed.

## Author
Tanmoy Nandi
