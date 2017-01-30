#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <stack>
#include <cmath>
#include <iomanip>
#include <ios>

using namespace std;

double minX;
double minY;

double dist(double x1, double y1, double x2, double y2) {
	double answer = pow(x1 - x2, 2) + pow(y1 - y2, 2);
	answer = sqrt(answer);
	return answer;
}

bool cmp(pair<double, double> pt1, pair<double, double> pt2) {
	double x1 = pt1.first;
	double y1 = pt1.second;
	double x2 = pt2.first;
	double y2 = pt2.second;
	
	if(x1 == 0 && x2 == 0)
		return y1 > y2;
	if(x1 == 0)
		return false;
	if(x2 == 0)
		return true;	
		
	double slope1 = y1 / x1;
	double slope2 = y2 / x2;
	if(slope1 == slope2) {
		return x1 < x2; 
	}

	return slope1 < slope2;
}

bool ccw(pair<double, double> pt1, pair<double, double> pt2, pair<double, double> pt3) {
	double x1 = pt2.first - pt1.first;
	double y1 = pt2.second - pt1.second;
	double x2 = pt3.first - pt1.first;
	double y2 = pt3.second - pt1.second;

	//cout << "ERROR?" << endl;
	//cout << x1 * y2 - y1 * x2 << endl;
	return (x1 * y2 - y1 * x2) >= 0 ? true : false;
}

int main() {
	ifstream fin("fc.in");
	ofstream fout("fc.out");

	int N;
	fin >> N;	

	vector<pair<double, double>> points;
	set<pair<double, double>> visited;
	int minPoint_index = 0;

	for(int i = 0; i < N; i++) {
		double x, y;
		fin >> x >> y;
		if(!visited.count(make_pair(x, y))) {
			visited.emplace(x, y);
			points.emplace_back(x, y);
			if(points[i].first < points[minPoint_index].first || 
				(points[i].first == points[minPoint_index].first && points[i].second < points[minPoint_index].second) ) {
				minPoint_index = i;
			}
		}
	}

	if(points.size() == 0 || points.size() == 1) {
		fout << "0.00" << endl;
		return 0;
	}
	if(points.size() == 2) {
		fout << fixed << setprecision(2) << dist(points[0].first, points[0].second, points[1].first, points[1].second) << endl;
		return 0;
	}

	minX = points[minPoint_index].first;
	minY = points[minPoint_index].second;
	//cout << minX << " " << minY << endl;
	points.erase(points.begin() + minPoint_index);

	for(int i = 0; i < points.size(); i++) {
		points[i].first -= minX;
		points[i].second -= minY;
	}
	sort(points.begin(), points.end(), cmp);
	points.insert(points.begin(), make_pair(0, 0));

	/*
	for(auto x : points) {
		cout << x.second / x.first << endl;
		cout << "(" << x.first / 100 << ", " << x.second /100 << ")" << endl;
	}
	*/

	stack<int> convexHull;	
	convexHull.push(0);
	convexHull.push(1);
	for(int i = 2; i < points.size(); i++) {
		//cout << i << endl;
		if(i + 1 < points.size()) {
			if(points[i].first != 0 && points[i + 1].first != 0) {
				if(points[i].second / points[i].first == points[i + 1].second / points[i + 1].first) {
					//cout << "WRONG!" << endl;
					continue;
				}
			}
		}	
		bool point_added = false;	
		while(!point_added) {
			int b = convexHull.top();
			convexHull.pop();
			int a = convexHull.top();
			if( ccw(points[a], points[b], points[i]) ) {
				//cout << "OKAY" << endl;
				point_added = true;
				convexHull.push(b);
				convexHull.push(i);
			}
		}
	}
	
	//cout << "SIZE: " << convexHull.size() << endl;
	
	double fence = 0;
	int curr = convexHull.top();
	int first_point = curr;
	convexHull.pop();
	while(!convexHull.empty()) {
		int next = convexHull.top();
		//cout << points[next].first << " " << points[next].second << endl;
		convexHull.pop();
		fence += dist(points[curr].first, points[curr].second, points[next].first, points[next].second);
		curr = next;
	}
	fence += dist(points[first_point].first, points[first_point].second, points[curr].first, points[curr].second);
	
	fout << fixed << setprecision(2) << fence << endl;
}
