#pragma once
#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>

namespace VECTOR
{
	class Vector
	{
	public://���б𿴴���
		enum Mode{RECT,POL};//RECT����ֱ������POL��������
	private:
		//RECT
		double x;
		double y;
		//POL
		double mag;//�����곤��
		double ang;//������Ƕ�
		//��ʾ��ʽ
		Mode mode;//RECT ��POL��ѡһ
		
		void set_mag();//
		void set_ang();
		void set_x();
		void set_y();
	public://prototype����ԭ��
		//���캯��-----ͨ�����캯�����Զ�����һ������
		Vector();
		Vector(double n1, double n2, Mode form = RECT);//���캯��Ĭ�ϲ����棨���أ�
		//-----
		~Vector();//��������
		void reset(double n1, double n2, Mode form = RECT);//
		//ͨ���๫�к���������˽�г�Ա
		double xval() const { return x; }//�Զ��γ���������
		double yval()const { return y; }
		double magval()const { return mag; }
		double angval()const { return ang; }
		//-----
		void polar_mode();
		void rect_mode();
		//operator ���������
		Vector operator+(const Vector& b)const;
		//Vector operator+(const Vector& b)const;
		Vector operator-(const Vector& b)const;
		Vector operator-()const;//��ʾȡ����
		Vector operator*(double n) const;
		//��Ԫ����
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);//����һ��std::ostream�������

	};
}

#endif // !VECTOR_H_
