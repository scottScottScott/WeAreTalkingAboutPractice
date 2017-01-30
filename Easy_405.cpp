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

class RelativePath {
public:
	string makeRelative(string, string);
};

bool isEqual(string currDir, string path) {
	if(currDir.size() > path.size()) return false;
	for(int i = 0; i < currDir.size(); i++)
		if(currDir[i] != path[i]) return false;
	if(path.size() > currDir.size() and path[currDir.size()] != '/') return false;
	return true;
}

void remove_last(string &currDir) {
	while(currDir.back() != '/') currDir.pop_back();
	if(currDir.back() == '/') currDir.pop_back();
}

string RelativePath::makeRelative(string path, string currentDir) {
	if(currentDir == "/") currentDir = "";
	if(path == "/") path = "";
	string result;
	while(!isEqual(currentDir, path)) {
		remove_last(currentDir);
		if(result != "") result += "/";
		result += "..";
	}
	result += path.substr(currentDir.size());
	return (result.size() > 0 and result[0] == '/') ? result.substr(1) : result;
}
