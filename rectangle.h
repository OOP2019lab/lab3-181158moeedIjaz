#include<iostream>
using namespace std;

class Rectangle{
private:
	int width,length;
public:
	void getWidth();
	void getLength();
	void setLength(int len);
	void setWidth(int wid);
	void getArea();
	void rotateRectangle();
	void draw();
};