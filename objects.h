#pragma once
#include "foundation.h"
using namespace std;

//����� ������� � ����
class objects
{
protected:
	//�������� �������
	string name;
	//��������� �������
	unsigned cost;
public:
	objects(string name, unsigned cost):
		name(name),
		cost(cost)
	{}
	//��������� �����
	void change_name(string str);
	//��������� ���������
	void change_cost(unsigned cos);
	//����� ���������� �� �������
	virtual void print_info() = 0;
	//������� ��������
	string get_name();
	//������� ���������
	unsigned get_cost();
	//����� �������� � �����
	virtual unsigned find_in_file(string str) = 0;
	//������ �� ����� ����������
	virtual void get_from_file(unsigned numb) = 0;
};


//����� ������ � ����
class weapon: public objects
{
protected:
	//����
	unsigned damage;
	//������ ������������
	unsigned stamin_cons;
	//��������������
	unsigned long_act;
public:
	weapon(string name, unsigned cost, unsigned damage, unsigned stamin_cons, unsigned long_act):
		objects(name, cost),
		damage(damage),
		stamin_cons(stamin_cons),
		long_act(long_act)
	{}
	void print_info();
	//������� �����
	unsigned get_damage();
	//������� ���������� ������������
	unsigned get_stamin_cons();
	//������� ��������������
	unsigned get_long_act();
	//������ �� ����� ���������� �� ������
	void get_from_file(unsigned numb);
	//����� ������ � ����� �� ����� � ������� ��� ������
	unsigned find_in_file(string str);
};


//����� ����� � ����
class protection : public objects
{
protected:
	//���������� �����
	unsigned dam_absorp;
	//���
	unsigned weight;
public:
	protection(string name, unsigned cost, unsigned dam_absorp, unsigned weight):
		objects(name, cost),
		dam_absorp(dam_absorp),
		weight(weight)
	{}
	void print_info();
	//����������� ���������� �����
	unsigned get_dam_absorp();
	//����������� ����
	unsigned get_weight();
	//������ �� ����� ���������� � ����
	void get_from_file(unsigned numb);
	//����� ���� � ����� �� ����� � ������� ��� ������
	unsigned find_in_file(string str);
};


//����� ��������� � ����
class heal : public objects
{
protected:
	//�������������� ��������
	unsigned health_heal;
public:
	heal(string name, unsigned cost, unsigned health_heal) :
		objects(name, cost),
		health_heal(health_heal)
	{}
	void print_info();
	//������� �������������� ��������
	unsigned get_health_heal();
	void get_from_file(unsigned numb);
	//����� ��������� � ����� �� ����� � ������� ��� ������
	unsigned find_in_file(string str);
};