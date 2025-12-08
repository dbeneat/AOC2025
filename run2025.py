from os.path import exists
from time import perf_counter
import subprocess

N=12
chrono=[0]*12
names=["day01.c","day02.c","day03bis.c","day04.c","day05.c","day06.c","day07.c","day08bis.c","","","",""]


for i in range(N):
    print(f"Compiling day {i+1}")
    fname=names[i]
    if exists(fname):
        subprocess.run(f"gcc -std=c99 -Ofast -Wall -Wextra -Werror -Wpedantic {fname} -o build/day{i+1:02}.exe")
for i in range(0,N):
    execname=f"build/day{i+1:02}.exe"
    if exists(execname):
        tic = perf_counter()
        with open(f"data/input{i+1:02}.txt") as f:
            a=subprocess.run(execname,capture_output=True,input=f.read(),encoding="UTF-8")
        toc=perf_counter()
        chrono[i]=round(toc-tic,3)
        tot=toc-tic
    else:
        chrono[i]="Missing"




print("Execution times (in sec)")
for i in range(N):
    print("day",i+1,".....",chrono[i])
print("Grand total: ",sum(x for x in chrono if x!="Missing"))
