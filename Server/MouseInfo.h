#ifndef MOUSEINFO_H
#define MOUSEINFO_H

#include <string>

class MouseInfo
{
private:
	int x;
	int y;
	int click;
public:
	MouseInfo();
	~MouseInfo();
	int getX();
	void setX(int value);
	int getY();
	void setY(int value);
	std::string getClick();
	void setClick(int value);
};

#endif // MOUSEINFO_H