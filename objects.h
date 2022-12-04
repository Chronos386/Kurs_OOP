#pragma once
#include "foundation.h"
using namespace std;

//Класс объекта в игре
class objects
{
protected:
	//Название объекта
	string name;
	//Стоимость объекта
	unsigned cost;
public:
	objects(string name, unsigned cost):
		name(name),
		cost(cost)
	{}
	//изменение имени
	void change_name(string str);
	//изменение стоимости
	void change_cost(unsigned cos);
	//Вывод информации об объекте
	virtual void print_info() = 0;
	//Возврат названия
	string get_name();
	//Возврат стоимости
	unsigned get_cost();
	//Поиск предмета в файле
	virtual unsigned find_in_file(string str) = 0;
	//Запись из файла информации
	virtual void get_from_file(unsigned numb) = 0;
};


//Класс оружия в игре
class weapon: public objects
{
protected:
	//Урон
	unsigned damage;
	//Расход выносливости
	unsigned stamin_cons;
	//Дальнодействие
	unsigned long_act;
public:
	weapon(string name, unsigned cost, unsigned damage, unsigned stamin_cons, unsigned long_act):
		objects(name, cost),
		damage(damage),
		stamin_cons(stamin_cons),
		long_act(long_act)
	{}
	void print_info();
	//Возврат урона
	unsigned get_damage();
	//Возврат поглащения выносливости
	unsigned get_stamin_cons();
	//Возврат дальнодействия
	unsigned get_long_act();
	//Запись из файла информации об оружии
	void get_from_file(unsigned numb);
	//Поиск оружия в файле по имени и возврат его номера
	unsigned find_in_file(string str);
};


//Класс щитов в игре
class protection : public objects
{
protected:
	//Поглощение урона
	unsigned dam_absorp;
	//Вес
	unsigned weight;
public:
	protection(string name, unsigned cost, unsigned dam_absorp, unsigned weight):
		objects(name, cost),
		dam_absorp(dam_absorp),
		weight(weight)
	{}
	void print_info();
	//Возвращение поглощения урона
	unsigned get_dam_absorp();
	//Возвращение веса
	unsigned get_weight();
	//Запись из файла информации о щите
	void get_from_file(unsigned numb);
	//Поиск щита в файле по имени и возврат его номера
	unsigned find_in_file(string str);
};


//Класс лекарства в игре
class heal : public objects
{
protected:
	//Восстановление здоровья
	unsigned health_heal;
public:
	heal(string name, unsigned cost, unsigned health_heal) :
		objects(name, cost),
		health_heal(health_heal)
	{}
	void print_info();
	//Возврат восстановления здоровья
	unsigned get_health_heal();
	void get_from_file(unsigned numb);
	//Поиск лекарства в файле по имени и возврат его номера
	unsigned find_in_file(string str);
};