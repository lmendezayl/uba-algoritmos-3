def main():
    inp: str = input().split()
    n, l, r = int(inp[0]), int(inp[1]), int(inp[2])
    print(sum(f(n)[l:r]))
    
def f(n, seq=None) -> list[int]:
    if seq is None:
        seq = [n//2, n%2, n//2]  
    for e in seq:
        if e == 1 or e == 0:
            return seq
        else:
            return f(e) + [seq[1]] + f(e)[::-1]

if __name__ == '__main__':
    main()
