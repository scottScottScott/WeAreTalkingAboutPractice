#include <iostream>
#include <algorithm>
#include <set>
#include <tuple>
#include <queue>
#include <vector>
#include <climits>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef tuple<long long, long long, long long> tpl;

void dijkstra(int start, vector<long long> &dist, vector<vector<pii>> &adjList) {
	priority_queue<pll, vector<pll>, greater<pll>> Q;
	Q.emplace(0, start);
	while(!Q.empty()) {
		pll curr = Q.top();
		Q.pop();
		if(dist[curr.second] < curr.first) continue;
		dist[curr.second] = curr.first;	
		for(pll next : adjList[curr.second]) {
			long long temp_dist = curr.first + next.second;
			if(dist[next.first] > temp_dist) {
				dist[next.first] = temp_dist;
				Q.emplace(temp_dist, next.first);	
			}
		}
	}
}

int main() {
	int N, M, S, T;	
	cin >> N >> M >> S >> T;
	S--;
	T--;
	vector<tpl> roads;
	vector<vector<pii>> adjList(N);
	vector<vector<pii>> adjListRev(N);
	for(int i = 0; i < M; i++) {
		int A, B, L;
		cin >> A >> B >> L;
		A--;
		B--;
		adjList[A].emplace_back(B, L);
		adjListRev[B].emplace_back(A, L);
		roads.emplace_back(A, B, L);
	}
	
	vector<long long> dist_S(N, LLONG_MAX);
	vector<long long> dist_T(N, LLONG_MAX);
	dijkstra(S, dist_S, adjList);
	dijkstra(T, dist_T, adjListRev);
	long long shortest = dist_S[T];

	vector<tpl> s_roads;
	for(long long i = 0; i < M; i++) {
		long long A = get<0>(roads[i]);
		long long B = get<1>(roads[i]);
		long long C = get<2>(roads[i]);

		if(dist_S[A] == LLONG_MAX or dist_T[B] == LLONG_MAX) continue;
		long long curr_dist = dist_S[A] + dist_T[B];
		if(curr_dist + C == shortest)
			s_roads.emplace_back(dist_S[A], dist_S[A] + C, i);
	}
	sort(s_roads.begin(), s_roads.end());
	set<int> valid;
	long long right = get<1>(s_roads[0]);
	long long prev = get<2>(s_roads[0]);
	for(long long i = 1; i < s_roads.size(); i++) {
		if(get<0>(s_roads[i]) >= right) {
			if(prev != -1) valid.insert(prev);
			prev = get<2>(s_roads[i]);
			right = get<1>(s_roads[i]);
		} 
		else {
			prev = -1;
			right = max(right, get<1>(s_roads[i]));
		}
	}
	if(prev != -1) valid.insert(prev);

	for(int i = 0; i < M; i++) {
		tpl curr = roads[i];
		long long A = get<0>(curr);
		long long B = get<1>(curr);
		long long C = get<2>(curr);

		if(dist_S[A] == LLONG_MAX or dist_T[B] == LLONG_MAX) {
			printf("NO\n");
			continue;
		}

		long long curr_dist = dist_S[A] + dist_T[B];
		if(valid.count(i))
			printf("YES\n");
		else if(curr_dist + 1 < shortest) {
			long long temp = shortest - curr_dist - 1;
			long long need = C - temp;
			printf("CAN %I64d\n", need);
		}
		else printf("NO\n");
	}
}
