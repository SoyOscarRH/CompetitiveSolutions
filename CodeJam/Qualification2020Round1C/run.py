import os
import sys

filename = sys.argv[1]
optimization = "-O2"
version = "c++14"
space = " "

flags = [
    "-Wall", "-Wextra", "-Wshadow",  "-Wpedantic",
    "-fsanitize=undefined", "-fsanitize=address"]

compile = f"g++ {filename} -std={version} {optimization} {space.join(flags)}"
#print(compile)
os.system(compile)