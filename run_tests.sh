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
run_test 5000 6 200
run_test 15000 4.5 300
run_test 800 0 100
run_test 250000 3.75 1500
run_test 1000000 5 10000
run_test -1000 5 200
run_test 1000 -5 200
run_test 1000 5 0
run_test 1000 5 -50
run_test abc 5 200

exit 0
