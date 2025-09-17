# BUILD
Reproduction of segfault on exit from Python script

mkdir build && cd build && cmake .. && make && cd ..
export PYTHONPATH=`pwd`/build:$PYTHONPATH

# C++ => works
cd build; ./main; cd ..

# Python
## no access to ets before parallel alg, no parallel alg before loading library => works
python3 script.py
## no access to ets before parallel alg, parallel alg before loading library => works
python3 script.py --run-parallel-algorithm-before
## access to ets before parallel alg, parallel alg before loading library => works
python3 script.py --access-ets --run-parallel-algorithm-before
## access to ets before parallel alg => segfault
python3 script.py --access-ets
