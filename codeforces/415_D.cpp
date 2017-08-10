#include <iostream>

using namespace std;

bool getDist(int A, int B) {
	printf("1 %d %d\n", A, B);
	fflush(stdout);
	string result;
	cin >> result;
	return result == "TAK";
}

int bSearch(int lo, int hi) {
	while(lo < hi) {
		int mid_1 = lo + (hi - lo) / 2;
		int mid_2 = mid_1 + 1;	
		bool result = getDist(mid_1, mid_2);	
		if(result)
			hi = mid_1;
		else
			lo = mid_2;
	}
	return lo;
}

int main() {
	int N, K;
	cin >> N >> K;
	int dish_1 = bSearch(1, N); 
	int	dish_2 = -1;
	if(dish_1 > 1)
		dish_2 = bSearch(1, dish_1 - 1);
	if(dish_1 < N) {
		int other = bSearch(dish_1 + 1, N);
		if(dish_2 == -1 or getDist(other, dish_2))
			dish_2 = other;
	}
	cout << 2 << " " << dish_1 << " " << dish_2 << endl;
}
