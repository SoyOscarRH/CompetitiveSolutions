t = int(input())
while t > 0:
    n, k = (input().split())
    n = int(n)+1
    k = int(k)+1
    res = k*n*(n+1)//2
    print(int(res%1000000007))
    t-=1
