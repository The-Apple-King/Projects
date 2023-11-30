#!/bin/bash

for filepath in attacks/*; do
  echo "Processing file: $filepath"
  ./bcimgview -c "$filepath"
  echo ""
  echo ""
rm attacks/*.ppm
done