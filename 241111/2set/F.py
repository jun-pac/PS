n,m=map(int, input().split())
r,c,d=map(int, input().split())
area=[list(map(int,input().split())) for _ in range(n)]

dx=[-1,0,1,0]
dy=[0,1,0,-1]

def in_range(x,y):
    return 0<=x<n and 0<=y<m

def cleaner(x,y,d):
    cnt=0
    while True:
        if area[x][y]==0:
            area[x][y]=-1
            cnt+=1
        for _ in range(4):
            d=(d-1)%4
            nx,ny=x+dx[d], y+dy[d]
            if in_range(nx,ny) and area[nx][ny]==0:
                x,y=nx,ny
                break
            
        x,y=x-dx[d],y-dy[d]
        if in_range(x,y) and area[x][y]==1 or not in_range(x,y):
            print(cnt)
            return
            
cleaner(r,c,d)