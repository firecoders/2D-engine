#!/bin/bash

case $1 in
    "setup")
        cmake -H. -Bbuild
        ;;
    "rebuild")
        cmake -H. -Bbuild
        ;;
    "debug")
        cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Debug
        ;;
    "clean")
        echo "removing build/, lib2D-engine.a and test_executable"
        rm -rf build lib2D-engine.a test_executable
        ;;
    *)
        make -C build $1
        ;;
esac

if [ $# -gt 1 ]
    then
        shift
        ./cmake.sh $*
fi
