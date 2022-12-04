#pragma once
#include "objects.h"

//Класс персонажа
class character
{
protected:
	//Имя персонажа
	string name;
	//Количество очков здоровья
	unsigned HP;
	//Баланс (в монетах)
	unsigned balance;
	//Вещь в руке (атака)
	weapon weap;
	//Вещь в руке (защита)
	protection prot;
	//Количество вещей в инвентаре
	unsigned numb_items;
	//Инвентарь
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
	//Возврат имени
	string get_name();
	//Возврат количества очков здоровья
	unsigned get_HP();
	//Возврат названия оружия
	string get_name_prot();
	//Возврат баланса
	unsigned get_balance();
	//Действие
	virtual unsigned action(string str, string str_1) = 0;
	//Взятие информации из файла
	virtual void get_inf_file(string f_txt) = 0;
	//Парирование атаки
	virtual void parrying(unsigned dam) = 0;
	//Сохранение прогресса в файл
	virtual void save_to_file(string str) = 0;
};

//Класс героя
class Hero: public character
{
protected:
	//Выносливость
	unsigned stamina;
	//Восстановление выносливости за ход (лечения, отступления)
	unsigned rest_stam_turn;
public:
	Hero(unsigned a):
		character(a),
		stamina(),
		rest_stam_turn()
	{}
	void print_info();
	//Возвращение количества выносливости
	unsigned get_stamina();
	//Возвращение восстановления выносливости за ход бездействия (лечения, отступления)
	unsigned get_rest_stam_turn();
	//Сохранение прогресса в файл
	void save_to_file(string str);
	unsigned action(string str, string str_1);
	void get_inf_file(string f_txt);
	void parrying(unsigned dam);
	//Изменение баланса
	void change_balance(int money);
	//Смена оружия
	void swap_weap(string str);
	//Смена щита
	void swap_prot(string str);
	//Добавление в инвентарь
	void add_to_invent(string str);
	//Удаление из инвентаря
	void del_from_invent(string str);
};

//Класс врага
class Enemy: public character
{
protected:
	//Уровень
	unsigned level;
	//Расстояние (метры)
	unsigned distance;
public:
	Enemy(unsigned a) :
		character(a),
		level(),
		distance()
	{}
	//Возвращение количества выносливости
	unsigned get_level();
	//Возвращение дистанции (в метрах)
	unsigned get_distance();
	unsigned action(string str, string str_1);
	void get_inf_file(string f_txt);
	//Приближение (отдаление) к (от) врагу(-у)
	void distant(int dist);
	void parrying(unsigned dam);
	void save_to_file(string str);
};