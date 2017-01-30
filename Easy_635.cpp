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

double getLength(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

class SimilarRatingGraph {
public:
	double maxLength(vector <int>, vector <int>);
};

double SimilarRatingGraph::maxLength(vector <int> date, vector <int> rating) {
	double result = 0;
	int n = date.size();	
	for(int i = 0; i + 1 < n; i++) {
		for(int j = i + 1; j + 1 < n; j++) {
			double l_1 = 0;
			double l_2 = 0;
			int a = i;
			int b = j;
			for( ; b + 1 < n; a++, b++) {
				long first = (long) (rating[a + 1] - rating[a]) * (date[b + 1] - date[b]); 
				long second = (long) (date[a + 1] - date[a]) * (rating[b + 1] - rating[b]);
				if(first != second) break;
				long third = (long) (rating[j + 1] - rating[j]) * (rating[a + 1] - rating[a]);
				long fourth = (long) (rating[b + 1] - rating[b]) * (rating[i + 1] - rating[i]);
				if(third != fourth) break; 
				long fifth = (long) (date[j + 1] - date[j]) * (date[a + 1] - date[a]);
				long sixth = (long) (date[b + 1] - date[b]) * (date[i + 1] - date[i]);
				if(fifth != sixth) break; 
				l_1 += getLength(date[a], rating[a], date[a + 1], rating[a + 1]);
				l_2 += getLength(date[b], rating[b], date[b + 1], rating[b + 1]);
			}
			result = max(result, l_1);
			result = max(result, l_2);
		}
	}
	return result;
}
