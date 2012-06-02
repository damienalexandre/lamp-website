#!/bin/sh

set -u
set -x
set -e

for size in 1G; do
             sysbench --mysql-user=root --mysql-password=poney --test=oltp --file-num=1 --file-total-size=$size prepare
             for threads in 16 32 64 128 256; do
                    echo PARAMS $size $threads> results-sysb/sysbench-size-$size-threads-$threads

                    sysbench --test=oltp --oltp-table-size=$size --db-driver=mysql --mysql-host=localhost --mysql-user=root --mysql-password=poney \
                    --init-rng=1 --num-threads=$threads --max-requests=0 --oltp-read-only \
                    --oltp-dist-type=uniform --max-time=180 run \
                        >> results-sysb/sysbench-size-$size-threads-$threads 2>&1
             done
             sysbench --mysql-user=root --mysql-password=poney --test=oltp --file-total-size=$size cleanup
done
