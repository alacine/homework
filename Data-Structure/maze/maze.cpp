#include <iostream>
#include <cstring>
#include <stack>
#include <cstdio>

using namespace std;
int w, h;

const int maxn = 1000;

int maze[maxn][maxn];

struct node {
    int x,y;//1,2,3,4 下 左 上 右
};
node op, ed;

stack <node> sk;
stack <node> tmp;

bool check(const node& next) {
    if(next.x < w && next.x >= 0 &&
       next.y < h && next.y >= 0 &&
       maze[next.y][next.x] == 0) {
        return true;
    }
    return false;
}

bool path() {
    node cur; cur.x = op.x; cur.y = op.y;
    node next;
    //将起点入栈
    sk.push(cur);
    while(!sk.empty()) {
        cur = sk.top();
        //判断是否到了终点
        if(cur.x == ed.x && cur.y == ed.y)return true;
        //将该点标记为已经访问
        maze[cur.y][cur.x] = -1;
        //向下运动
        next = cur;
        next.y++;
        if(check(next)) {
            cur = next;
            sk.push(cur);
            continue;
        }
        //向左运动
        next = cur;
        next.x--;
        if(check(next)) {
            cur = next;
            sk.push(cur);
            continue;
        }
        //向上运动
        next = cur;
        next.y--;
        if(check(next)) {
            cur = next;
            sk.push(cur);
            continue;
        }
        //向右运动
        next = cur;
        next.x++;
        if(check(next)) {
            cur = next;
            sk.push(cur);
            continue;
        }
//        cur = sk.top();
        sk.pop();
//      maze[cur.x][cur.y] = 0;
    }
    return false;
}

void print() {
    for(int i = 0; i < h ; i++) {
        for(int j = 0 ; j < w ; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    freopen("in.txt","r",stdin);
    cin >> w >> h;

    memset(maze,0,sizeof(maze));

    for(int i = 0 ; i < h ; i++) {
        for(int j = 0 ; j < w ; j++) {
            int tt;
            cin >> tt;
            if(tt == 3) {
                op.y = i;
                op.x = j;
                maze[i][j] = 0;
//                cout << op.x << " " << op.y << endl;
                continue;
            }
            if(tt == 4) {
                ed.y = i;
                ed.x = j;
                maze[i][j] = 0;
//                cout << ed.x << " " << ed.y << endl;
                continue;
            }
            maze[i][j] = tt;
        }
    }
    if(path()) {
        while(!sk.empty()) {
            node t = sk.top();
            tmp.push(t);
            sk.pop();
//            cout << t.x << " " << t.y << endl;
        }
        while(!tmp.empty()) {
            node t = tmp.top();
            tmp.pop();
            cout << t.x << " " << t.y << endl;
        }
    }
    else {
        cout << "++_++" << endl;
    }
    return 0;
}