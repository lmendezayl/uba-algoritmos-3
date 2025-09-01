# -*- coding: utf-8 -*-

def main():
    alf = [chr(i) for i in range(ord('a'), ord('z') + 1)]
    casos: int = int(input())
    for _ in range(casos):
        n: int = int(input())
        s: str = input().strip()
        print(klindo(s, 0, n, 'a', alf))

def klindo(s:str, l: int, r: int, letr: str, alf: list[str], d=0):
    n = r-l # tenia escrito 1, no l             
    if n == 1:
        return 0 if s[l] == letr else 1
    # correcto hasta aca
    izq = n // 2 - sum(1 for i in range(l, l + n // 2) if s[i] == letr) + klindo(s, l + n // 2, r, alf[d+1], alf, d+1) # pasos recurs
    der = n // 2 - sum(1 for i in range(l + n // 2, r) if s[i] == letr) + klindo(s, l, l + n // 2, alf[d+1], alf, d+1)
    return min(izq, der)

if __name__ == "__main__":
    main()
