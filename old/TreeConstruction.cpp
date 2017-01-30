#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;

	int root;
	cin >> root;
	map<int, int> greater { {root, -1} };
	map<int, int> less { {root, -1} };

	for(int i = 2; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
			
		auto curr = greater.upper_bound(temp);
		if(curr == greater.begin()) curr = greater.end();
		else curr--;

		if(curr != greater.end() and (curr->second == -1 or temp < curr->second) ) {
			greater[temp] = curr->second; 
			less[temp] = curr->first;
			printf("%d", curr->first);
			greater.erase(curr);
		}
		else {
			curr = less.upper_bound(temp);
			greater[temp] = curr->first; 
			less[temp] = curr->second;
			printf("%d", curr->first);
			less.erase(curr);	
		}
		if(i != N) printf(" ");
		else printf("\n");
	}
}
