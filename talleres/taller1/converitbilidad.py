def main():
    inp = input().split()
    x, y = int(inp[0]), int(inp[1])
    seq = convertibilidad(x,y)
    if seq is None:
        print("NO")
    else:
        print("YES")
        print(len(seq))
        print(*seq)

def convertibilidad(x, y, seq=None):
    if seq is None: 
        seq = [x]
    if x == y:
        return seq
    if x > y:
        return None
    res = convertibilidad(x * 2, y, seq + [x * 2])
    if res is not None:
        return res
    res = convertibilidad(x * 10 + 1, y, seq + [x * 10 + 1])
    if res is not None:
        return res
    return None

if __name__ == '__main__':
        main()
