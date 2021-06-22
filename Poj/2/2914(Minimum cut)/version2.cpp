#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 500 + 16
#define INF 0x3f3f3f3f

int G[MAX_N][MAX_N];
int v[MAX_N];			//	v[i]����ڵ�i�ϲ����Ķ���
int w[MAX_N];			//	����w(A,x) = ��w(v[i],x)��v[i]��A
bool visited[MAX_N];	//	��������Ƿ�õ������A����

int stoer_wagner(int n)
{
	int min_cut = INF;
	for (int i = 0; i < n; ++i)
	{
		v[i] = i;		//	��ʼ��δ�ϲ���������ڵ㱾��
	}

	while (n > 1)
	{
		int pre = 0;	//	pre������ʾ֮ǰ����A���ϵĵ㣨��t֮ǰһ���ӽ�ȥ�ĵ㣩
		memset(visited, 0, sizeof(visited));
		memset(w, 0, sizeof(w));
		for (int i = 1; i < n; ++i)
		{
			int k = -1;
			for (int j = 1; j < n; ++j)  //	ѡȡV-A�е�w(A,x)���ĵ�x���뼯��
			{
				if (!visited[v[j]])
				{
					w[v[j]] += G[v[pre]][v[j]];
					if (k == -1 || w[v[k]] < w[v[j]])
					{
						k = j;
					}
				}
			}

			visited[v[k]] = true;		//	��Ǹõ�x�Ѿ�����A����
			if (i == n - 1)				//	��|A|=|V|�����е㶼������A��������
			{
				const int s = v[pre], t = v[k];		//	����ڶ�������A�ĵ㣨v[pre]��Ϊs�����һ������A�ĵ㣨v[k]��Ϊt
				min_cut = min(min_cut, w[t]);		//	��s-t��С��Ϊw(A,t)���������min_cut
				for (int j = 0; j < n; ++j)			//	Contract(s, t)
				{
					G[s][v[j]] += G[v[j]][t];
					G[v[j]][s] += G[v[j]][t];
				}
				v[k] = v[--n];						//	ɾ�����һ���㣨��ɾ��t��Ҳ����t�ϲ���s��
			}
			// else ����
			pre = k;
		}
	}
	return min_cut;
}


///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(G, 0, sizeof(G));
		while (m--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			G[u][v] += w;
			G[v][u] += w;
		}
		printf("%d\n", stoer_wagner(n));
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}
