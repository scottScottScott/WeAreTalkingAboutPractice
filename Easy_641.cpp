#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long, long> pll;

const double PI = 3.14159265;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

class TrianglesContainOrigin {
public:
	long long count(vector <int>, vector <int>);
};

long long TrianglesContainOrigin::count(vector <int> x, vector <int> y) {
	vector<double> info;
	long long result = 0;
	for(int i = 0; i < x.size(); i++) {
		double val = 0;
		if(x[i] == 0) {
			if(y[i] >= 0) val = PI / 2;  
			else val = PI + PI / 2;
		}
		else if(x[i] > 0) {
			val = atan( (double) y[i] / x[i]);
			if(y[i] < 0)
				val = 2 * PI + val;
		}
		else {
			val = atan( (double) y[i] / abs(x[i]));
			val = PI - val;	
		}
		info.push_back(val);
	}
	sort(info.begin(), info.end());

	for(int i = 0; i < info.size(); i++) {
		cout << info[i] << endl;
		for(int j = i + 1; j < info.size(); j++) {
			vector<double> temp;
			temp.push_back(info[i] + PI);
			while(temp[0] > 2 * PI)
				temp[0] -= 2 * PI;
			temp.push_back(info[j] + PI);
			while(temp[1] > 2 * PI)
				temp[1] -= 2 * PI;
				
			if(temp[0] > temp[1]) {
				if(info[i] > temp[0] or info[i] < temp[1])
					swap(temp[0], temp[1]);
			}
			else {
				if(info[i] > temp[0] and info[i] < temp[1])
					swap(temp[0], temp[1]);
			}
			
			auto first = upper_bound(info.begin(), info.end(), temp[0]);
			auto second = upper_bound(info.begin(), info.end(), temp[1]);
			if(first <= second)
				result += second - first;	
			else {
				result += info.end() - first;
				result += second - info.begin();
			}
			cout << result << endl;
		}
	}
	return result / 3;
}
