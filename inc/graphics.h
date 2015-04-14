#include <ncurses.h>
#include <vector>

class graphics{
public:
	void refresh();
	void drawScreen();
	void setUp();
	void shutDown();
private:
	std::vector<Frame> frames;
};
