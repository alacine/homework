#include <iostream>
#include <cstring>
#include <stack>
#include <cstdio>
using namespace std;

const int maxn = 1000;
int w, h;
int maze[maxn][maxn];

struct node {
    int x,y;
};
node op, ed;

stack <node> sk;
stack <node> tmp;

bool check(const node& next) { //�жϸĵ��Ƿ����
    if(next.x < w && next.x >= 0 &&
       next.y < h && next.y >= 0 &&
       maze[next.y][next.x] == 0) {
        return true;
    }
    return false;
}

bool path() { //�ж��Ƿ���ͨ·
    node cur; cur.x = op.x; cur.y = op.y;
    node next;
    sk.push(cur); //�����ջ
    while(!sk.empty()) {
        cur = sk.top();
        if(cur.x == ed.x && cur.y == ed.y) { //�ж��Ƿ����յ�
            return true;
        }
        maze[cur.y][cur.x] = 6; //���õ���Ϊ�Ѿ�����
        //�����˶�
        next = cur;
        next.y++;
        if(check(next)) {
            cur = next;
            sk.push(cur);
            continue;
        }
        //�����˶�
        next = cur;
        next.x--;
        if(check(next)) {
            cur = next;
            sk.push(cur);
            continue;
        }
        //�����˶�
        next = cur;
        next.y--;
        if(check(next)) {
            cur = next;
            sk.push(cur);
            continue;
        }
        //�����˶�
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

void PrintMap() {
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
            int t;
            cin >> t;
            if(t == 3) {
                op.y = i;
                op.x = j;
                maze[i][j] = 0;
                continue;
            }
            if(t == 4) {
                ed.y = i;
                ed.x = j;
                maze[i][j] = 0;
                continue;
            }
            maze[i][j] = t;
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
            maze[t.y][t.x] = 7;
        }
        PrintMap();
    }
    else {
        cout << "no way out" << endl;
    }
    return 0;
}
