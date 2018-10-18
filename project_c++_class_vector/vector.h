#pragma once
#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>

namespace VECTOR
{
	class Vector
	{
	public://公有别看错了
		enum Mode{RECT,POL};//RECT代表直角坐标POL代表极坐标
	private:
		//RECT
		double x;
		double y;
		//POL
		double mag;//极坐标长度
		double ang;//极坐标角度
		//表示方式
		Mode mode;//RECT 和POL二选一
		
		void set_mag();//
		void set_ang();
		void set_x();
		void set_y();
	public://prototype函数原型
		//构造函数-----通过构造函数会自动生成一个对象
		Vector();
		Vector(double n1, double n2, Mode form = RECT);//构造函数默认参数版（重载）
		//-----
		~Vector();//析构函数
		void reset(double n1, double n2, Mode form = RECT);//
		//通过类公有函数访问类私有成员
		double xval() const { return x; }//自动形成内联函数
		double yval()const { return y; }
		double magval()const { return mag; }
		double angval()const { return ang; }
		//-----
		void polar_mode();
		void rect_mode();
		//operator 运算符重载
		Vector operator+(const Vector& b)const;
		//Vector operator+(const Vector& b)const;
		Vector operator-(const Vector& b)const;
		Vector operator-()const;//表示取负数
		Vector operator*(double n) const;
		//友元函数
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);//返回一个std::ostream类的引用

	};
}

#endif // !VECTOR_H_
