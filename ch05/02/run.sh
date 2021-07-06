#!/bin/bash

number=0
while [ "$number" -lt 30 ]; do
  ./open-fork
  number=$((number + 1))
done
