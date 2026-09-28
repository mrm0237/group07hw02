#!/bin/bash

set +e

run_test() {
    echo "Running: ./a.out $*"
    timeout 15 ./a.out "$@"
    status=$?
    if [ $status -eq 124 ]; then
        echo "  -> TIMED OUT"
    else
        echo "  -> Exit code: $status"
    fi
    echo "-----------------------------"
}

run_test 1000 18 50
run_test 2000 12 80
run_test 1000 12 11
run_test 1000 12 1010
run_test 1000 50 2000
run_test 1000 0 10
run_test 2000 50 80
run_test 1000 12 10
run_test -1000
run_test abc 
run_test 1000 -18
run_test 1000 abc
run_test 1000 18 -50  
run_test 1000 18 abc

exit 0
