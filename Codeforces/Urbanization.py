#!/usr/bin/env python3

n, n1, n2 = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]

arr.sort(reverse=True)

smaller = min(n1, n2)
larger = max(n1, n2)

arr = arr[:(smaller + larger)]

print(sum(arr[:smaller]) / smaller + sum(arr[smaller:]) / larger) 