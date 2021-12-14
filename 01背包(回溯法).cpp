#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int n, vo; //��Ʒ��Ŀ�Լ���������
int v[maxn], w[maxn]; //ÿ����Ʒ�ļ�ֵ������
int maxV;  //��ȡ������ֵ
int vis[maxn]; //��ǵ�ǰ��Ʒ�Ƿ�ѡȡ
vector<int> now_choice, choice; //ѡȡ����Ʒ���
void init() {  //���ڳ�ʼ�������������
	printf("�������ѡȡ����Ʒ��n������vo��");
	scanf("%d%d", &n, &vo);
	printf("�����������Ӧ����Ʒ����wi: ");
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	printf("�����������Ӧ����Ʒ��ֵvi: ");
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	maxV = 0;  //�Ի��ݷ��ĳ�ʼ�������г�ʼ��
	now_choice.clear();
	choice.clear();
}
void ansbyBacktracking(int V, int Val, int now) {//���ݷ�
	if (now == n + 1) {	//����ķ�������
		if (Val > maxV) {
			maxV = Val;
			choice = now_choice;
		}
		return;
	}
	for (int i = now; i <= n; ++i) {
		//ѡ����Ʒ
		if (w[i] + V <= vo) {
			now_choice.push_back(i);
			ansbyBacktracking(V + w[i], Val + v[i], i + 1);
			now_choice.pop_back(); //����
		}
		ansbyBacktracking(V, Val, i + 1);	//��ѡ����Ʒ
	}
}
void print() {	//��ӡ���
	printf("��������ֵΪ %d\n��ʱѡȡ����Ʒ�ֱ�Ϊ��\n", maxV);
	int sz = choice.size(); //��ȡ��ǰѡ�����Ʒ
	for (int i = 0; i < sz; ++i) {
		cout << choice[i] << " ";
	}
	printf("\n\n");
}
int main() {
	init(); //������������
	ansbyBacktracking(0, 0, 1); //���õ�ǰ�㷨�������
	print(); //��ӡ����
	return 0;
}
