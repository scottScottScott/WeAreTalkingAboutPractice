#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
	int N, C;
	cin >> N >> C;

	vector<pii> boxes;
	for(int i = 0; i < N; i++) {
		int w, h;
		cin >> w >> h;
		boxes.emplace_back(w, h);
	}
vector<pii> memo;
	memo.emplace_back(boxes[0].first, boxes[0].second);
	int prevRowHeight = 0;
	for(int i = 1; i < N; i++) {
		int newWidth, newHeight;
		newHeight = -1;

		if(boxes[i].first + memo[i - 1].first <= C) {
			newWidth = boxes[i].first + memo[i - 1].first;
			newHeight = max(boxes[i].second + prevRowHeight, memo[i - 1].second);
		}

		int currRowWidth = boxes[i].first;
		int currRowHeight = boxes[i].second;

		int bestWidth = currRowWidth;
		int bestHeight = currRowHeight + memo[i - 1].second;
		int bestPrevRowHeight = memo[i - 1].second;	

		for(int j = i - 1; j >= 1; j--) {
			currRowWidth += boxes[j].first;
			currRowHeight = max(currRowHeight, boxes[j].second);
			if(currRowWidth <= C) {
				if(currRowHeight + memo[j - 1].second < bestHeight or  
						(currRowHeight + memo[j - 1].second == bestHeight and currRowWidth < bestWidth)) {
					bestWidth = currRowWidth;
					bestHeight = currRowHeight + memo[j - 1].second;
					bestPrevRowHeight = memo[j - 1].second;
				}
			}
			else
				break;
		}

		if(bestHeight < newHeight or newHeight == -1) {
			newWidth = bestWidth;
			newHeight = bestHeight;
			prevRowHeight = bestPrevRowHeight;
		}

		memo.emplace_back(newWidth, newHeight);	
	}

//	for(int i = 0; i < N; i++) {
//		cout << memo[i].first << " " << memo[i].second << endl;
//	}
	cout << memo[N-1].second << endl;
}
