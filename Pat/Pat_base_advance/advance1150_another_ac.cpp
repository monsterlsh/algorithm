#include<iostream>
#include<vector>
using namespace std;
 
struct Graph {
    int Nv;
    int Ne;
    vector<vector<int>> G;
};
 
int ShortestDist = -1;
int ShortestPath = -1;
 
void solve(Graph &G, int path)
{
    int n;
    cin >> n;
    vector<int> Path(n);
    for(int i = 0; i < n; i++) cin >> Path[i];
    string Description = "(TS simple cycle)";
    if(Path[0] != Path[n-1]) Description = "(Not a TS cycle)";
    vector<int> Visited(G.Nv+1, 0);
    int TotalDist = 0;
    int src = 0, adj;
    for(int i = 0; i < n; i++) {
        adj = Path[i];
        Visited[adj]++;
        if(src != 0) {
            if(G.G[src][adj] == 0) {
                TotalDist = -1;
                Description = "(Not a TS cycle)";
                break;
            }
            TotalDist += G.G[src][adj];
        }
        src = adj;
    }
    if(Description == "(TS simple cycle)") {
        for(int i = 1; i <= G.Nv; i++) {
            if((i == Path[0] && Visited[i] > 2) || (i != Path[0] && Visited[i] > 1)) {
                Description = "(TS cycle)";
            } else if(Visited[i] == 0) {
                Description = "(Not a TS cycle)";
                break;
            }
        }
        if((Description != "(Not a TS cycle)") && (ShortestDist == -1 || ShortestDist > TotalDist)) {
            ShortestPath = path;
            ShortestDist = TotalDist;
        }
    }
    cout << "Path " << path << ": ";
    if(TotalDist==-1) cout << "NA";
    else cout << TotalDist;
    cout << " " << Description << endl;
}
 
int main()
{
    int N, M, K;
    cin >> N >> M;
    Graph G;
    G.Nv = N, G.Ne = M, G.G.resize(N+1);
    for(int i = 1; i <= N; i++) G.G[i].resize(N+1);
    for(int i = 1; i <= M; i++) {
        int c1, c2, dist;
        cin >> c1 >> c2 >> dist;
        G.G[c1][c2] = G.G[c2][c1] = dist;
    }
    cin >> K;
    for(int i = 1; i <= K; i++) solve(G, i);
    cout << "Shortest Dist(" << ShortestPath << ") ";
    cout << "= " << ShortestDist << endl;
}