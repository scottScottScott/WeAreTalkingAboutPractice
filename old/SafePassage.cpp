#include <iostream> 
#include <deque> 
#include <algorithm> 

using namespace std;

int minTime = 500000;

void recursiveSolve(int currTime, deque<int> gate, deque<int> dorm) {
	if(gate.empty()) {
		if(currTime < minTime)
			minTime = currTime;
		return;
	}
	if(gate.size() == 2) {
		currTime += gate[1];
		if(currTime < minTime)
			minTime = currTime;
		return;
	}
		

	deque<int> gate2{gate};
	deque<int> dorm2{dorm};
	int currTime2 = currTime;

	if(dorm.empty() == false) {
		int A = gate.front();
		gate.pop_front();
		int B = gate.front();
		gate.pop_front();
		int C = gate.front();
		gate.pop_front();

		currTime += C;

		dorm.push_back(B);
		dorm.push_back(C);
	
		int D = dorm.front();
		dorm.pop_front();

		currTime += D;

		gate.push_front(D);
		gate.push_front(A);

		sort(dorm.begin(), dorm.end());
		recursiveSolve(currTime, gate, dorm);
	}

	int A = gate2.front();
	gate2.pop_front();
	int B = gate2.front();
	gate2.pop_front();
		
	currTime2 += B;

	dorm2.push_back(B);

	currTime2 += A;
		
	gate2.push_front(A);

	sort(dorm2.begin(), dorm2.end());
	recursiveSolve(currTime2, gate2, dorm2);
}

int main() {
	int N;
	cin >> N;

	deque<int> gate(N);
	for(int i = 0; i < N; i++) {
		cin >> gate[i];					
	}
	sort(gate.begin(), gate.end());

	recursiveSolve(0, gate, deque<int> {});

	cout << minTime << endl;
}
