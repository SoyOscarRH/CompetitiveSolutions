import sys
import os

filename = sys.argv[1]
name, extension = os.path.splitext(filename)

flags = " ".join([
    "-std=c++14", "-O2", "-Wall", "-Wextra", "-Wshadow",  "-Wpedantic",
    "-fsanitize=undefined", "-fsanitize=address"])

compile = f"g++ {filename} {flags} -o {name}"
os.system(compile)
