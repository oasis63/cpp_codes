#!/bin/bash

# Delete all .exe files
find . -type f -name "*.exe" -exec rm -v {} \;

find . -type f -name "*.o" -exec rm -v {} \;

find . -type f -name "*.out" -exec rm -v {} \;


