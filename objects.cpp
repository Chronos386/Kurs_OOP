#include "objects.h"

//Возврат названия
string objects::get_name()
{
	return this->name;
}

//Возврат стоимости
unsigned objects::get_cost()
{
	return this->cost;
}

//Возврат урона
unsigned weapon::get_damage()
{
	return this->damage;
}

//Возврат поглащения выносливости
unsigned weapon::get_stamin_cons()
{
	return this->stamin_cons;
}

//Возврат дальнодействия
unsigned weapon::get_long_act()
{
	return this->long_act;
}

//Вывод информации об оружии
void weapon::print_info()
{
	cout << "Название: " << get_name() << endl;
	cout << "Урон: " << get_damage() << endl;
	cout << "Расход выносливости за ход: " << get_stamin_cons() << endl;
	cout << "Дальнобойность (в метрах): " << get_long_act() << endl;
	cout << "Стоимость: " << get_cost() << endl;
}

//Запись из файла информации об оружии
void weapon::get_from_file(unsigned numb)
{
	string str;
	ifstream fin("weapon.txt");
	if (!fin.is_open())
	{
		cout << endl << "Программа не обнаружила файла с оружием. Завершение работы программы.";
		exit(0);
	}
	for (int i = 1; i <= 9; i++)
		getline(fin, str);
	unsigned temp = StrToDigit(str);
	if (temp < numb)
	{
		cout << endl << "В файле с оружием недостаточно оружия. Выход из подпрограммы.";
		return;
	}
	string nam;
	unsigned dam = 0, stam = 0, lon = 0, cos = 0;
	for (unsigned i = 1; i <= numb; i++)
	{
		getline(fin, str);
		//Взятие имени
		getline(fin, nam);
		//Взятие урона
		getline(fin, str);
		dam = StrToDigit(str);
		//Взятие расхода выносливости
		getline(fin, str);
		stam = StrToDigit(str);
		//Взятие дальнобойности
		getline(fin, str);
		lon = StrToDigit(str);
		//Взятие стоимости
		getline(fin, str);
		cos = StrToDigit(str);
	}
	name = nam;
	cost = cos;
	damage = dam;
	stamin_cons = stam;
	long_act = lon;
	fin.close();
}

//Поиск оружия в файле по имени и возврат его номера
unsigned weapon::find_in_file(string str)
{
	string wep_n;
	ifstream f_w("weapon.txt");
	for (int i = 1; i <= 9; i++)
		getline(f_w, wep_n);
	unsigned col = StrToDigit(wep_n), numb = 0;
	bool fl = false;
	for (unsigned i = 1; (i <= col) && (!fl); i++)
	{
		getline(f_w, wep_n);
		getline(f_w, wep_n);
		if (wep_n == str)
		{
			fl = true;
			numb = i;
		}
		else
		{
			getline(f_w, wep_n);
			getline(f_w, wep_n);
			getline(f_w, wep_n);
			getline(f_w, wep_n);
		}
	}
	if (fl)
		return numb;
	else
		return -1;
	f_w.close();
}


//Возврат дальнодействия
unsigned protection::get_dam_absorp()
{
	return this->dam_absorp;
}

//Возвращение веса
unsigned protection::get_weight()
{
	return this->weight;
}

//Вывод информации о щите
void protection::print_info()
{
	cout << "Название: " << get_name() << endl;
	cout << "Поглащение урона: " << get_dam_absorp() << endl;
	cout << "Вес: " << get_weight() << endl;
	cout << "Стоимость: " << get_cost() << endl;
}

//Запись из файла информации о щите
void protection::get_from_file(unsigned numb)
{
	string str;
	ifstream fin("protection.txt");
	if (!fin.is_open())
	{
		cout << endl << "Программа не обнаружила файла со щитами. Завершение работы программы.";
		exit(0);
	}
	for (int i = 1; i <= 8; i++)
		getline(fin, str);
	unsigned temp = StrToDigit(str);
	if (temp < numb)
	{
		cout << endl << "В файле со щитами недостаточно щитов. Выход из подпрограммы.";
		return;
	}
	string nam;
	unsigned dam = 0, weig = 0, cos = 0;
	for (unsigned i = 1; i <= numb; i++)
	{
		getline(fin, str);
		//Взятие имени
		getline(fin, nam);
		//Взятие поглощения урона
		getline(fin, str);
		dam = StrToDigit(str);
		//Взятие веса
		getline(fin, str);
		weig = StrToDigit(str);
		//Взятие стоимости
		getline(fin, str);
		cos = StrToDigit(str);
	}
	name = nam;
	cost = cos;
	dam_absorp = dam;
	weight = weig;
	fin.close();
}

//Поиск щита в файле по имени и возврат его номера
unsigned protection::find_in_file(string str)
{
	string wep_n;
	ifstream f_w("protection.txt");
	for (int i = 1; i <= 8; i++)
		getline(f_w, wep_n);
	unsigned col = StrToDigit(wep_n), numb = 0;
	bool fl = false;
	for (unsigned i = 1; (i <= col) && (!fl); i++)
	{
		getline(f_w, wep_n);
		getline(f_w, wep_n);
		if (wep_n == str)
		{
			fl = true;
			numb = i;
		}
		else
		{
			getline(f_w, wep_n);
			getline(f_w, wep_n);
			getline(f_w, wep_n);
		}
	}
	if (fl)
		return numb;
	else
		return -1;
	f_w.close();
}


//Возврат восстановления здоровья
unsigned heal::get_health_heal()
{
	return this->health_heal;
}

//Вывод информации о лекарстве
void heal::print_info()
{
	cout << "Название: " << get_name() << endl;
	cout << "Восстановление здоровья: " << get_health_heal() << endl;
	cout << "Стоимость: " << get_cost() << endl;
}

//изменение имени
void objects::change_name(string str)
{
	name = str;
}

//изменение стоимости
void objects::change_cost(unsigned cos)
{
	cost = cos;
}

//Запись из файла информации об аптечке
void heal::get_from_file(unsigned numb)
{
	string str;
	ifstream fin("heal.txt");
	if (!fin.is_open())
	{
		cout << endl << "Программа не обнаружила файла с лекарствами. Завершение работы программы.";
		exit(0);
	}
	for (int i = 1; i <= 7; i++)
		getline(fin, str);
	unsigned temp = StrToDigit(str);
	if (temp < numb)
	{
		cout << endl << "В файле с лекарствами недостаточно лекарств. Выход из подпрограммы.";
		return;
	}
	string nam;
	unsigned hp = 0, cos = 0;
	for (unsigned i = 1; i <= numb; i++)
	{
		getline(fin, str);
		//Взятие имени
		getline(fin, nam);
		//Взятие поглощения урона
		getline(fin, str);
		hp = StrToDigit(str);
		//Взятие стоимости
		getline(fin, str);
		cos = StrToDigit(str);
	}
	name = nam;
	cost = cos;
	health_heal = hp;
	fin.close();
}

//Поиск лекарства в файле по имени и возврат его номера
unsigned heal::find_in_file(string str)
{
	string wep_n;
	ifstream f_w("heal.txt");
	for (int i = 1; i <= 7; i++)
		getline(f_w, wep_n);
	unsigned col = StrToDigit(wep_n), numb = 0;
	bool fl = false;
	for (unsigned i = 1; (i <= col) && (!fl); i++)
	{
		getline(f_w, wep_n);
		getline(f_w, wep_n);
		if (wep_n == str)
		{
			fl = true;
			numb = i;
		}
		else
		{
			getline(f_w, wep_n);
			getline(f_w, wep_n);
		}
	}
	if (fl)
		return numb;
	else
		return -1;
	f_w.close();
}