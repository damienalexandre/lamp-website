#!/bin/sh

set -u
set -x
set -e

for conc in 50 100 150 200 250 300 350; do
    echo "siege -b -c$conc -t1m -f urls.txt"
    siege -d1 -c$conc -t1m -f urls.txt
done
