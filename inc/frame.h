#include <ncurses>
#include <utility>

class Frame{
public:
private:
	WINDOW* window;
	std::pair<int,int> xy;
	std::pair<int,int> rc;
};
