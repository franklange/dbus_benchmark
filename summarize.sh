#!/bin/bash

cat data/avg_* > data/all.txt
paste -sd+ data/all.txt | bc

