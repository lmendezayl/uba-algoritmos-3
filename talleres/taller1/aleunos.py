def main():
    inp: str = input().split()
    n, l, r = int(inp[0]), int(inp[1]), int(inp[2]) #int int int
    print(f(n))
    
def f(n, seq=None):
    if seq is None:
        seq = [n//2, n%2, n//2]
    for e in seq:
        if e == 1 or e == 0:
            return seq
        else:
            return f(e) + [seq[1]] + f(e)[::-1]

if __name__ == '__main__':
    main()
