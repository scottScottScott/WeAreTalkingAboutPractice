#include <list>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ios>

using namespace std;

struct Window { Window(char key, int x, int y, int X, int Y) {
		this->key = key;
		this->x = x;
		this->y = y;
		this->X = X;
		this->Y = Y;
	}

	double area() {
		return (X - x) * (y - Y);
	}

	void print() {
		cout << key << " " << x << " " << y << " " << X << " " << Y << endl;
	}

	int x, y, X, Y;
	char key;
};

int main() {
	ifstream fin("window.in");	
	ofstream fout("window.out");

	list<Window*> window_list;
	string curr_line;
	while( getline(fin, curr_line) ) {
		stringstream str(curr_line);
		char instruction;
		str >> instruction;	
		char skip;
		char I; 
		str >> skip >> I;
		switch(instruction) {
			case 'w': {
				int x, y, X, Y;
				str >> skip >> x >> skip >> y >> skip >> X >> skip >> Y;
				Window *new_window;
				int min_x = min(x, X);
				int max_x = max(x, X);
				int min_y = min(y, Y);
				int max_y = max(y, Y);
				new_window = new Window(I, min_x, max_y, max_x, min_y);
				window_list.push_front(new_window);
				new_window->print();
				break;
			}
			case 't': {
				list<Window*>::iterator itr;
				for(itr = window_list.begin(); itr != window_list.end() && (*itr)->key != I; itr++);
				window_list.push_front(*itr);
				window_list.erase(itr);
				break;
			}
			case 'b': {
				list<Window*>::iterator itr;
				for(itr = window_list.begin(); itr != window_list.end() && (*itr)->key != I; itr++);
				window_list.push_back(*itr);
				window_list.erase(itr);
				break;
			}
			case 'd': {
				list<Window*>::iterator itr;
				for(itr = window_list.begin(); itr != window_list.end() && (*itr)->key != I; itr++);
				delete *itr;
				window_list.erase(itr);
				break;
			}
			case 's': {
				list<Window*>::iterator itr;
				for(itr = window_list.begin(); itr != window_list.end() && (*itr)->key != I; itr++);
				double totalArea =	(**itr).area(); 
				cout << totalArea << endl;
				list<Window> areas;
				areas.emplace_back('x', (*itr)->x, (*itr)->y, (*itr)->X, (*itr)->Y);

				for(itr	= window_list.begin(); itr != window_list.end() && (*itr)->key != I; itr++) {
					Window *above = *itr;
					cout << above->key << endl;
					list<Window>::iterator curr = areas.begin();
					while(curr != areas.end()) {
						bool changed = false;
						if(above->y <= curr->Y || above->Y >= curr->y) {
							curr++;
							continue;
						}
						if(above->x >= curr->x && above->x < curr->X) {
							changed = true;
							if(above->x != curr->x)
								areas.emplace_front('x', curr->x, curr->y, above->x, curr->Y);

							if(above->Y < curr->y && above->Y > curr->Y) 
								areas.emplace_front('x', above->x, above->Y, min(above->X, curr->X), curr->Y);
							if(above->y < curr->y && above->y > curr->Y) 
								areas.emplace_front('x', above->x, curr->y, min(above->X, curr->X), above->y);
							
							if(above->X < curr->X)
								areas.emplace_front('x', above->X, curr->y, curr->X, curr->Y);
						}
						else if(above->X > curr->x && above->X <= curr->X) {
							changed = true;
							if(above->X != curr->X)
								areas.emplace_front('x', above->X, curr->y, curr->X, curr->Y);

							if(above->Y < curr->y && above->Y > curr->Y)
								areas.emplace_front('x', curr->x, above->Y, above->X, curr->Y);
							if(above->y < curr->y && above->y > curr->Y)
								areas.emplace_front('x', curr->x, curr->y, above->X, above->y);
						}

						else if(above->x < curr->x && above->X > curr->X) {
							changed = true;
							if(above->Y < curr->y && above->Y > curr->Y) {
								areas.emplace_front('x', curr->x, above->Y, curr->X, curr->Y);
							}
							if(above->y < curr->y && above->y > curr->Y) {
								areas.emplace_front('x', curr->x, curr->y, curr->X, above->y);
							}
						}
						if(changed)
							curr = areas.erase(curr);	
						else
							curr++;
					}
				}

				double uncovered = 0;
				cout << "SIZE: " << areas.size() << endl;
				for(auto x : areas) {
					uncovered += x.area();
					x.print();
					cout << x.area() << endl;
				}
				double percent = 100 * (uncovered / totalArea);
				fout << setprecision(3) << fixed << percent << endl;
				break;
			}
		}
	}	
}
