#include <ncurses>
#include <utility>

class Frame{
public:
	void add(char, int, int);
	void refresh();
private:
	WINDOW* window;
	std::pair<int,int> xy;
	std::pair<int,int> rc;
};
