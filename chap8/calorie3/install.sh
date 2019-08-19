#!/bin/bash

gcc -I./includes -fPIC -c hfcal_UK.c -o hfcal.o

gcc -shared hfcal.o -I./includes -L./libs -o ./libs/libhfcal.so
