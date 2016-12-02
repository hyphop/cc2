import bisect

def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect.bisect_right(a, x)
    if i:
        return a[i-1]
    raise ValueError
    
def find_ge(a, x):
    'Find leftmost item greater than or equal to x'
    i = bisect.bisect_left(a, x)
    if i != len(a):
        return a[i]
    raise ValueError

n, x, y = [int(_) for _ in input().split()]

exams = []

for _ in range(n):
    exams.append([int(_) for _ in input().split()])

enter = [int(_) for _ in input().split()]
exit = [int(_) for _ in input().split()]

enter.sort()
exit.sort()

cur_best = 1e9

for l, r in exams:
    try:
        a = find_le(enter, l)
        b = find_ge(exit, r)
        cur_best = min(cur_best, b - a + 1)
    except ValueError:
        pass

print(cur_best)
    