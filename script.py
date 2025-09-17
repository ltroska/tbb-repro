from repro import *
import os
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--access-ets', action='store_true')
parser.add_argument('--run-parallel-algorithm-before', action='store_true')
args = parser.parse_args()

dir_path = os.path.dirname(os.path.realpath(__file__))

if args.run_parallel_algorithm_before:
    run_algorithm()

foo = Foo(os.path.dirname(os.path.realpath(__file__)) + '/build/libfoo.so', access_ets=args.access_ets)
run_algorithm_using_foo(foo)
