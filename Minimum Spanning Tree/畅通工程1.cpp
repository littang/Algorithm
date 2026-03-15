/*某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。问最少还需要建设多少条道路？
输入
测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是城镇数目N ( < 1000 )和道路数目M；随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。
注意:两个城市之间可以有多条道路相通,也就是说
3 3
1 2
1 2
2 1
这种输入也是合法的
当N为0时，输入结束，该用例不被处理。
输出
对每个测试用例，在1行里输出最少还需要建设的道路数目。
样例输入 Copy
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
样例输出 Copy
1
0
2
998
*/

#include <stdio.h>

#define MAXN 1000

int father[MAXN + 1];

// 查找根节点（路径压缩）
int find(int x) {
    if (father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}

// 合并两个集合
void unionSet(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        father[fx] = fy;
}

int main() {
    int N, M;
    while (scanf("%d", &N) == 1 && N != 0) {
        scanf("%d", &M);
        // 初始化并查集
        for (int i = 1; i <= N; i++)
            father[i] = i;
        // 读入道路并合并
        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            unionSet(u, v);
        }
        // 统计连通分量个数
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (father[i] == i)
                cnt++;
        }
        // 需要建设的道路数 = 连通分量数 - 1
        printf("%d\n", cnt - 1);
    }
    return 0;
}