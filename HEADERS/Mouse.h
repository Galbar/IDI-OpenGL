#ifndef MOUSE
#define MOUSE

#include <cstddef>

class Mouse {
private:
	static Mouse* instance;
	int x;
	int y;

	bool buttons[3];

	int getDiff(int val1, int val2);

public:
	Mouse();

	static Mouse* i();

	void deleteInstance();

	void pressed(int i);

	void released(int i);

	bool isPressed(int i);

	void update(int x, int y);

	int getDeltaX(int x);

	int getDeltaY(int y);
};

#endif
