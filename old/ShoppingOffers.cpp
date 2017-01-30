#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

int memo[5 + 1][5 + 1][5 + 1][5 + 1][5 + 1];

typedef struct {
	int code;
	int num;
	int price;
} product;
vector<product> products;

int S;
vector<int> offers[99];
vector<int> oPrice(99);

bool compareProducts(product a, product b) {
	if(a.code < b.code)
		return true;
	else
		return false;
}

int solve(int numProd[]) {
	int k0 = numProd[0];
	int k1 = numProd[1]; 
	int k2 = numProd[2]; 
	int k3 = numProd[3]; 
	int k4 = numProd[4]; 

	if(k0 + k1 + k2 + k3 + k4 == 0)
		return 0;
	if(memo[k0][k1][k2][k3][k4] != 0)	
		return memo[k0][k1][k2][k3][k4];

	int price = 0;
	for(int i = 0; i < 5; i++) {
		price += numProd[i] * products[i].price;
	}
	//cout << price << endl;
	for(int i = 0; i < S; i++) {
		int j;
		int newNumProd[5];
		for(j = 0; j < 5; j++) {
			if(numProd[j] - offers[i][j] < 0)
				break;
			newNumProd[j] = numProd[j] - offers[i][j];
		}
		if(j == 5) {
			if(solve(newNumProd) + oPrice[i] < price) 
				price = solve(newNumProd) + oPrice[i];
		}
	}
	memo[k0][k1][k2][k3][k4] = price;
	return price;
}

int main() {
	ifstream fin("shopping.in");
	ofstream fout("shopping.out");

	fin >> S;
	vector<int> oCode[S];
	vector<int> oNum[S];
	for(int i = 0; i < S; i++) {
		int j;
		fin >> j;
		for( ; j > 0; j--) {
			int c, k;
			fin >> c >> k;
			oCode[i].push_back(c);
			oNum[i].push_back(k);
		}
		fin >> oPrice[i];
	}

	int B;
	fin >> B;
	for(int i = 0; i < B; i++) {
		product temp;
		fin >> temp.code >> temp.num >> temp.price;
		products.push_back(temp);
	}	

	sort(products.begin(), products.end(), compareProducts);	
	map<int, int> codeToIndex;	
	for(int i = 0; i < products.size(); i++) {
		codeToIndex[products[i].code] = i;
	}
	products.resize(5);

	int numProd[5];
	for(int i = 0; i < 5; i++) {
		numProd[i] = products[i].num;
		//cout << numProd[i] << " ";
	}
	//cout << endl;

	for(int i = 0; i < S; i++) {
		offers[i].resize(5, 0);
		for(int j = 0; j < oCode[i].size(); j++) {
			int code = oCode[i][j];
			int index = codeToIndex[code];
			offers[i][index] = oNum[i][j];
		}
	}

	fout << solve(numProd) << endl;

	return 0;
}
