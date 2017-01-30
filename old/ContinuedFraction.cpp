#include <iostream>
#include <algorithm>

using namespace std;

void swap(long &num, long &denom) {
	int temp = num;
	num = denom;
	denom = temp;
}

class single_frac {
	public:
		single_frac(const vector<int> &A_vec) {
			int N = A_vec.size();
			num = A_vec[N - 1];				
			denom = 1;

			for(int i = N - 2; i >= 0; i--) {
				swap(num, denom);
				num += A_vec[i] * denom;
			}
		}	

		single_frac() {
			num = 1;
			denom = 1;
		}
		
		vector<int> continued_frac() {
			vector<int> result;
			while(denom != 0) {
				int curr = num / denom;
				result.push_back(curr);
				num -= curr * denom;

				swap(num, denom);
			}
			return result;
		}

		long num;
		long denom;
};

single_frac operator+(single_frac A, single_frac B) {
	single_frac result;
	result.num = A.num * B.denom + B.num * A.denom;
	result.denom = A.denom * B.denom;
	return result;
}

single_frac operator-(single_frac A, single_frac B) {
	B.num *= -1;
	return A + B;
}

single_frac operator*(single_frac A, single_frac B) {
	single_frac result;
	result.num = A.num * B.num;
	result.denom = A.denom * B.denom;
	return result;
}

single_frac operator/(single_frac A, single_frac B) {
	swap(B.num, B.denom);
	return A * B;
}

int main() {
	int N_A, N_B;
	cin >> N_A >> N_B;
	
	vector<int> A_vec(N_A);
	vector<int> B_vec(N_B);

	for(int i = 0; i < N_A; i++)
		cin >> A_vec[i];
	for(int i = 0; i < N_B; i++)
		cin >> B_vec[i];

	single_frac A(A_vec);	
	single_frac B(B_vec);

	vector<single_frac> results = {A + B, A - B, A * B, A / B};

	for(single_frac &result : results) {
		vector<int> result_vec = result.continued_frac();	
		for(int i = 0; i < result_vec.size(); i++) {
			cout << result_vec[i] << (i != result_vec.size() - 1 ? " " : "\n");
		}
	}
}
