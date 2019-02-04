// lab 3 Q2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"rectangle.h";
#include<string>
#include<iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Rectangle r1;
	r1.setLength(10);
	r1.getLength();
	r1.setWidth(9);
	r1.getWidth();
	r1.getArea();
	r1.draw();
	return 0;
}

