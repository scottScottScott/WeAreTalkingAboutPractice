#include <iostream>
#include <vector>
#include <cmath>
#include <deque>

using namespace std;

#define max_X 200

struct Point {
	Point(int x, int y, int r) {
		this->x = x;
		this->y = y;
		this->r = r;
	}

	string toString() {
		string output = to_string(x) + " " + to_string(y) + " " + to_string(r); 
		return output;
	}

	int x, y, r;
};

double dist(Point *a, Point *b) {
	double result = pow(a->x - b->x, 2) + pow(a->y - b->y, 2);
	return sqrt(result);
}

bool intersect(Point *a, Point *b) {
	if(dist(a, b) < a->r + b->r)
		return true;
	return false;
}

int main() {
	int N;
	cin >> N;

	vector<Point*> points(N);	
	for(int i = 0; i < N; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		points[i] = new Point(x, y, r);
	}

	vector<vector<int>> adjList(N);
	
	for(int i = 0; i < N; i++) {

		for(int j = 0; j < i; j++) {
			if(intersect(points[i], points[j]))  {
				adjList[i].push_back(j);
				adjList[j].push_back(i);
			}
		}

		vector<bool> seen(i + 1);
		deque<int> toVisit;
		for(int j = 0; j <= i; j++) {
			if(points[j]->x - points[j]->r < 0) {
				toVisit.push_back(j);		
				seen[j] = 1;
			}
		}

		while(toVisit.empty() == false) {
			int index = toVisit.front();
			toVisit.pop_front();
			if(points[index]->x + points[index]->r > max_X) {
				cout << i << endl;
				return 0;
			}

			for(int j = 0; j < adjList[index].size(); j++) {
				if(seen[adjList[index][j]] == false) {
					seen[adjList[index][j]] = true;
					toVisit.push_back(adjList[index][j]);
				}
			}
		}

	}

}
