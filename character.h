#pragma once
#include "objects.h"

//����� ���������
class character
{
protected:
	//��� ���������
	string name;
	//���������� ����� ��������
	unsigned HP;
	//������ (� �������)
	unsigned balance;
	//���� � ���� (�����)
	weapon weap;
	//���� � ���� (������)
	protection prot;
	//���������� ����� � ���������
	unsigned numb_items;
	//���������
	vector <objects*> inventory;
public:
	character(unsigned b) :
		name(),
		HP(),
		balance(b),
		weap("w", 0, 0, 0, 0),
		prot("p", 0, 0, 0),
		numb_items(b),
		inventory(0)
	{}
	//������� �����
	string get_name();
	//������� ���������� ����� ��������
	unsigned get_HP();
	//������� �������� ������
	string get_name_prot();
	//������� �������
	unsigned get_balance();
	//��������
	virtual unsigned action(string str, string str_1) = 0;
	//������ ���������� �� �����
	virtual void get_inf_file(string f_txt) = 0;
	//����������� �����
	virtual void parrying(unsigned dam) = 0;
	//���������� ��������� � ����
	virtual void save_to_file(string str) = 0;
};

//����� �����
class Hero: public character
{
protected:
	//������������
	unsigned stamina;
	//�������������� ������������ �� ��� (�������, �����������)
	unsigned rest_stam_turn;
public:
	Hero(unsigned a):
		character(a),
		stamina(),
		rest_stam_turn()
	{}
	void print_info();
	//����������� ���������� ������������
	unsigned get_stamina();
	//����������� �������������� ������������ �� ��� ����������� (�������, �����������)
	unsigned get_rest_stam_turn();
	//���������� ��������� � ����
	void save_to_file(string str);
	unsigned action(string str, string str_1);
	void get_inf_file(string f_txt);
	void parrying(unsigned dam);
	//��������� �������
	void change_balance(int money);
	//����� ������
	void swap_weap(string str);
	//����� ����
	void swap_prot(string str);
	//���������� � ���������
	void add_to_invent(string str);
	//�������� �� ���������
	void del_from_invent(string str);
};

//����� �����
class Enemy: public character
{
protected:
	//�������
	unsigned level;
	//���������� (�����)
	unsigned distance;
public:
	Enemy(unsigned a) :
		character(a),
		level(),
		distance()
	{}
	//����������� ���������� ������������
	unsigned get_level();
	//����������� ��������� (� ������)
	unsigned get_distance();
	unsigned action(string str, string str_1);
	void get_inf_file(string f_txt);
	//����������� (���������) � (��) �����(-�)
	void distant(int dist);
	void parrying(unsigned dam);
	void save_to_file(string str);
};