#include <iostream>
#include <vector>

using namespace std;

int ask(int x1, int y1, int x2, int y2) {
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int result;
	scanf("%d", &result);
	return result;
}

int main() {
	int n;
	cin >> n;
	vector<int> result;
	int lo, hi, r_line, l_line, t_line, b_line;

	lo = 1;
	hi = n;
	r_line = n;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		int numRec = ask(1, 1, n, mid);
		if(numRec == 0)
			lo = mid + 1;
		else {
			hi = mid - 1;
			r_line = mid;
		}
	}
	
	lo = 1;
	hi = n;
	t_line = n;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		int numRec = ask(1, 1, mid, r_line);
		if(numRec == 0)
			lo = mid + 1;
		else {
			hi = mid - 1;
			t_line = mid;
		}
	}
	
	lo = 1;
	hi = t_line;
	b_line = 1;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		int numRec = ask(mid, 1, t_line, r_line);
		if(numRec == 0)
			hi = mid - 1;
		else {
			lo = mid + 1;
			b_line = mid;
		}
	}

	lo = 1;
	hi = r_line;
	l_line = 1;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		int numRec = ask(b_line, mid, t_line, r_line);
		if(numRec == 0)
			hi = mid - 1;
		else {
			lo = mid + 1;
			l_line = mid;
		}
	}

	result.push_back(b_line);	
	result.push_back(l_line);
	result.push_back(t_line);
	result.push_back(r_line);

	lo = 1;
	hi = n;
	l_line = 1;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		int numRec = ask(1, mid, n, n);
		if(numRec == 0)
			hi = mid - 1;
		else {
			lo = mid + 1;
			l_line = mid;
		}
	}

	lo = 1;
	hi = n;
	b_line = 1;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		int numRec = ask(mid, l_line, n, n);
		if(numRec == 0)
			hi = mid - 1;
		else {
			lo = mid + 1;
			b_line = mid;
		}
	}

	lo = b_line;
	hi = n;
	t_line = n;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		int numRec = ask(b_line, l_line, mid, n);
		if(numRec == 0)
			lo = mid + 1;
		else {
			hi = mid - 1;
			t_line = mid;
		}
	}

	lo = l_line;
	hi = n;
	r_line = n;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		int numRec = ask(b_line, l_line, t_line, mid);
		if(numRec == 0)
			lo = mid + 1;
		else {
			hi = mid - 1;
			r_line = mid;
		}
	}

	result.push_back(b_line);	
	result.push_back(l_line);
	result.push_back(t_line);
	result.push_back(r_line);

	cout << "!";
	for(int i = 0; i < result.size(); i++)
		cout << " " << result[i];	
	cout << endl;
	fflush(stdout);
}
