import math

def main():
    n: int = int(input())
    l: int = int(input())
    r: int = int(input())   
    print(sum(f(n)[l-1:r))

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
