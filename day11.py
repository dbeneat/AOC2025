with open("data/input11.txt") as f:
    L=f.read().strip().split("\n")
    L=[x.split(":") for x in L]
    L={x[0]:x[1].strip().split(" ") for x in L}

def npaths(src,dst):
    mem={}
    def f(src):
        if src in mem:
            return mem[src]
        if src==dst:res=1
        elif src in L:res=sum(f(x) for x in L[src])
        else:res=0
        mem[src]=res
        return res
    return f(src)

part1=npaths("you","out")
part2=npaths("svr","dac")*npaths("dac","fft")*npaths("fft","out")
part2+=npaths("svr","fft")*npaths("fft","dac")*npaths("dac","out")
print(part1,part2)
