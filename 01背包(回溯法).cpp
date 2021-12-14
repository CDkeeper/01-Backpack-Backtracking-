#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int n, vo; //物品数目以及背包容量
int v[maxn], w[maxn]; //每件物品的价值和重量
int maxV;  //获取的最大价值
int vis[maxn]; //标记当前物品是否选取
vector<int> now_choice, choice; //选取的物品编号
void init() {  //用于初始传入待计算数据
	printf("请输入待选取的物品数n与容量vo：");
	scanf("%d%d", &n, &vo);
	printf("请依次输入对应的物品重量wi: ");
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	printf("请依次输入对应的物品价值vi: ");
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	maxV = 0;  //对回溯法的初始条件进行初始化
	now_choice.clear();
	choice.clear();
}
void ansbyBacktracking(int V, int Val, int now) {//回溯法
	if (now == n + 1) {	//程序的返回条件
		if (Val > maxV) {
			maxV = Val;
			choice = now_choice;
		}
		return;
	}
	for (int i = now; i <= n; ++i) {
		//选该物品
		if (w[i] + V <= vo) {
			now_choice.push_back(i);
			ansbyBacktracking(V + w[i], Val + v[i], i + 1);
			now_choice.pop_back(); //回溯
		}
		ansbyBacktracking(V, Val, i + 1);	//不选该物品
	}
}
void print() {	//打印结果
	printf("求解得最大价值为 %d\n此时选取的物品分别为：\n", maxV);
	int sz = choice.size(); //获取当前选择的物品
	for (int i = 0; i < sz; ++i) {
		cout << choice[i] << " ";
	}
	printf("\n\n");
}
int main() {
	init(); //输入待求解数据
	ansbyBacktracking(0, 0, 1); //采用当前算法解决问题
	print(); //打印求解答案
	return 0;
}
