import os
import re

filename = str(input())
my_filename = str(input())

my_filename, my_extention = os.path.splitext(my_filename)

if (my_filename != filename or my_extention not in {".c", ".cpp", ".java", ".py"}):
    print("Compile Error")
    exit()

return_val, max_time, my_time = map(int, str(input()).split())
if (return_val != 0):
    print("Run-Time Error")
    exit()

if (my_time > max_time):
    print("Time Limit Exceeded")
    exit()

num_correct_answers = int(input())
correct_answers = [str(input()) for _ in range(num_correct_answers)]

num_my_answers = int(input())
my_answers = [str(input()) for _ in range(num_my_answers)]

if my_answers != correct_answers:
    print("Wrong Answer")
    exit()

print("Correct")