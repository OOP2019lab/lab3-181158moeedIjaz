#include"stdafx.h";
#include<iostream>
#include"rectangle.h";
using namespace std;

void Rectangle::getWidth(){
	cout<<"Width is : "<<width<<endl;
}
void Rectangle::getLength(){
	cout<<"Length is : "<<length<<endl;
}
void Rectangle::setLength(int len){
	length=len;
}
void Rectangle::setWidth(int wid){
	width=wid;
}
void Rectangle::getArea(){
	cout<<"The area is : "<<(length*width)<<endl;
}
void Rectangle::rotateRectangle(){
	int temp;
	temp=width;
	width=length;
	length=temp;
}
void Rectangle::draw(){
	for(int i=0;i<width;i++){
		for(int j=0;j<length;j++){
		cout<<"*";
		}
	cout<<endl;
	}
}