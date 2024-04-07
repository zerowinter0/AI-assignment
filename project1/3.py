"""
待补充代码：对搜索过的格子染色
"""
import matplotlib.pyplot as plt
import queue
def visualize_maze_with_path(maze, path,st):
    
    plt.figure(figsize=(len(maze[0]), len(maze)))  # 设置图形大小
    plt.imshow(maze, cmap='viridis', interpolation='nearest')  # 使用灰度色图，并关闭插值

    # 绘制路径
    if path:
        path_x, path_y = zip(*path)
        plt.plot(path_y, path_x, marker='o', markersize=8, color='red', linewidth=3)

    # 设置坐标轴刻度和边框
    plt.xticks(range(len(maze[0])))
    plt.yticks(range(len(maze)))
    plt.gca().set_xticks([x - 0.5 for x in range(1, len(maze[0]))], minor=True)
    plt.gca().set_yticks([y - 0.5 for y in range(1, len(maze))], minor=True)
    plt.grid(which="minor", color="black", linestyle='-', linewidth=2)

    plt.axis('on')  # 显示坐标轴
    plt.show()

# 提供迷宫的二维数组

def getNab(node,maze):
    ret=list()
    lenx=len(maze[0])
    leny=len(maze)
    if(node[0]>0 and maze[node[0]-1][node[1]]==0):
        ret.append((node[0]-1,node[1]))
    if(node[0]<lenx-1 and maze[node[0]+1][node[1]]==0):
        ret.append((node[0]+1,node[1]))
    if(node[1]>0 and maze[node[0]][node[1]-1]==0):
        ret.append((node[0],node[1]-1))
    if(node[1]<leny-1 and maze[node[0]][node[1]+1]==0):
        ret.append((node[0],node[1]+1))
    return ret

def bfs(S,T,maze):
    step=dict()
    fa=dict()
    fa[S]=S
    step[S]=0
    q=queue.Queue()
    q.put(S)
    while(not q.empty()):
        now=q.get()
        nxt=getNab(now,maze)
        for i in nxt:
            if(not fa.get(i)):
                step[i]=step[now]+1
                fa[i]=now
                q.put(i)
                if(i==T):
                    break
        if(fa.get(T)):break
    if(not fa.get(T)):return -1
    ret=list()
    now=T
    while(1):
        ret.append(now)
        if(now==S):
            break
        now=fa[now]
        
    ret.reverse()
    return ret,step.keys()

def dfs(S,T,maze):
    stack=list()
    fa=dict()
    stack.append(S)
    fa[S]=S
    while(not len(stack)==0):
        now=stack.pop()
        for i in getNab(now,maze):
            if(not fa.get(i)):
                fa[i]=now
                stack.append(i)
                if(i==T):break
        if(fa.get(T)):break
    if(not fa.get(T)):
        return -1,fa.keys()
    now=T
    ret=list()
    while(1):
        ret.append(now)
        if(now==S):
            break
        now=fa[now]
    ret.reverse()
    return ret,fa.keys()
def evaluate(now,T):
    return abs(now[0]-T[0])+abs(now[1]-T[1])

def Astar(S,T,maze):
    q=queue.PriorityQueue()
    q.put((0,S))
    fa=dict()
    fa[S]=S
    step=dict()
    step[S]=0
    while(not q.empty()):
        tmp=q.get()
        now=tmp[1]
        if(now==T):
            break
        if(tmp[0]>step[now]+evaluate(now,T)):
            continue
        for i in getNab(now,maze):
            if((not fa.get(i))or(step[i]>step[now]+1)):
                step[i]=step[now]+1
                fa[i]=now
                q.put((step[i]+evaluate(i,T),i))
    if(not fa.get(T)):
        return -1
    ret=list()
    now=T
    while(1):
        ret.append(now)
        if(now==S):
            break
        now=fa[now]
    return ret,fa
def main():
    maze = [
        [0, 1, 0, 0, 0],
        [0, 1, 0, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 1, 0]
    ]

    S=(0,0)
    T=(len(maze[0])-1,len(maze)-1)
    T=(4,0)
    path,st = Astar(S,T,maze)
    for i in st:
            maze[i[0]][i[1]]=0.5
    # 可视化迷宫及路径
    if(path!=-1):visualize_maze_with_path(maze, path,st)

if __name__ == '__main__': 
    main()