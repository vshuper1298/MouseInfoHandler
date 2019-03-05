#include "MouseInfo.h"


MouseInfo::MouseInfo(){

}


MouseInfo::~MouseInfo(){

}

 int MouseInfo::getX(){
	return x;
}

 void MouseInfo::setX(int value){
	 x = value;
 }

int MouseInfo::getY(){
	return y;
}

void MouseInfo::setY(int value){
	y = value;
}

std::string MouseInfo::getClick(){
	switch (click){
	case 0:
		return "";
		break;
	case 1:
		return "LMK";
		break;
	case 2:
		return "RMK";
		break;
	}
}

void MouseInfo::setClick(int value){
	click = value;
}
