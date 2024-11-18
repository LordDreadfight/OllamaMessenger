#!/bin/bash

# Set the source file and output binary names
SOURCE="main.cpp"
OUTPUT="OllamaMessengerCPP"

# Check if the source file exists
if [ ! -f "$SOURCE" ]; then
    echo "Error: $SOURCE not found!"
    exit 1
fi

# Compile the source file
echo "Compiling $SOURCE..."
g++ -std=c++17 -o "$OUTPUT" "$SOURCE"

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Build successful. Output: $OUTPUT"
else
    echo "Build failed."
    exit 1
fi
