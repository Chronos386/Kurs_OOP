#include "character.h"
#include "foundation.h"

//Возврат имени
string character::get_name()
{
	return this->name;
}

//Возврат количества очков здоровья
unsigned character::get_HP()
{
	return this->HP;
}

//Возврат баланса
unsigned character::get_balance()
{
	return this->balance;
}

//Возврат количества очков выносливости
unsigned Hero::get_stamina()
{
	return this->stamina;
}

//Возврат количества очков выносливости, восстановленых за ход
unsigned Hero::get_rest_stam_turn()
{
	return this->rest_stam_turn;
}

//Возврат названия оружия
string character::get_name_prot()
{
	return prot.get_name();
}

//Изменение баланса
void Hero::change_balance(int money)
{
	balance += money;
	cout << endl << "Новый баланс: " << balance;
}

//Смена оружия
void Hero::swap_weap(string str)
{
	unsigned num = weap.find_in_file(str);
	weap.get_from_file(num);
}

//Смена щита
void Hero::swap_prot(string str)
{
	unsigned num = prot.find_in_file(str);
	prot.get_from_file(num);
}

//Вывод информации о герое
void Hero::print_info()
{
	cout << endl << "Информация о Вашем персонаже:";
	cout << endl << "Имя: " << name;
	cout << endl << "Здоровье: " << HP;
	cout << endl << "Выносливость: " << stamina;
	cout << endl << "Восстановление выносливости за ход (лечения, отступления):" << rest_stam_turn;
	cout << endl << "Баланс (монеты): " << balance;
	cout << endl << "Вещь в руке (атака): " << weap.get_name();
	cout << endl << "Вещь в руке (защита): " << prot.get_name();
	cout << endl << "Количество вещей в инвентаре: " << numb_items;
	cout << endl << "Инвентарь:";
	for(int i = 0; i < numb_items; i++)
		cout << endl << inventory[i]->get_name();
}

//Сохранение прогресса в файл
void Hero::save_to_file(string str)
{
	string f_name = str;
	ofstream f;
	f.open(f_name);
	f << "Имя\n";
	f << name << "\n";
	f << "\nЗдоровье\n";
	f << HP << "\n";
	f << "\nВыносливость\n";
	f << stamina << "\n";
	f << "\nВосстановление выносливости за ход бездействия (лечения, отступления)\n";
	f << rest_stam_turn << "\n";
	f << "\nБаланс (монеты)\n";
	f << balance << "\n";
	f << "\nВещь в руке (атака)\n";
	f << weap.get_name() << "\n";
	f << "\nВещь в руке (защита)\n";
	f << prot.get_name() << "\n";
	f << "\nКоличество вещей в инвентаре:\n";
	f << numb_items << "\n";
	f << "\nИнвентарь:\n";
	for(unsigned i = 0; i < numb_items - 1; i++)
		f << inventory[i]->get_name() << "\n";
	f << inventory[numb_items - 1]->get_name();
	f.close();
}

//Загрузка данных из файла
void Hero::get_inf_file(string f_txt)
{
	string f_name = f_txt, str;
	ifstream fin(f_name);
	if (!fin.is_open())
	{
		cout << endl << "К сожалению, героя с таким именем не существует";
		return;
	}
	getline(fin, str);
	getline(fin, str);
	name = str;
	for (int i = 0; i < 7; i++)
	{
		getline(fin, str);
		getline(fin, str);
		getline(fin, str);
		unsigned numb = 0;
		switch (i)
		{
		case 0:
			HP = StrToDigit(str);
			break;
		case 1:
			stamina = StrToDigit(str);
			break;
		case 2:
			rest_stam_turn = StrToDigit(str);
			break;
		case 3:
			balance = StrToDigit(str);
			break;
		case 4:
			numb = weap.find_in_file(str);
			if (numb != -1)
				weap.get_from_file(numb);
			else
			{
				cout << "В файле Вашего героя записано несуществующее оружие. Завершение работы программы.";
				exit(0);
			}
			break;
		case 5:
			numb = prot.find_in_file(str);
			if (numb != -1)
				prot.get_from_file(numb);
			else
			{
				cout << "В файле Вашего героя записан несуществующий щит. Завершение работы программы.";
				exit(0);
			}
			break;
		case 6:
			numb_items = StrToDigit(str);
			break;
		}
	}
	getline(fin, str);
	getline(fin, str);
	unsigned number = numb_items;
	numb_items = 0;
	for (unsigned i = 0; i < number; i++)
	{
		getline(fin, str);
		add_to_invent(str);
	}
	fin.close();
}

//Добавление в инвентарь
void Hero::add_to_invent(string str)
{
	weapon wep("", 0, 0, 0, 0);
	protection pr("", 0, 0, 0);
	heal h("", 0, 0);
	unsigned opr = weap.find_in_file(str), numb = 0;
	if (opr != -1)
		numb = 1;
	opr = prot.find_in_file(str);
	if (opr != -1)
		numb = 2;
	opr = h.find_in_file(str);
	if (opr != -1)
		numb = 3;
	switch (numb)
	{
	case 1:
		inventory.push_back(new weapon(str, 0, 0, 0, 0));
		numb = weap.find_in_file(str);
		wep.get_from_file(numb);
		inventory[numb_items]->get_from_file(numb);
		if (inventory[numb_items]->get_name() != str)
		{
			inventory[numb_items]->change_name(str);
			inventory[numb_items]->change_cost(wep.get_cost());
		}
		break;
	case 2:
		inventory.push_back(new protection(str, 0, 0, 0));
		numb = prot.find_in_file(str);
		pr.get_from_file(numb);
		inventory[numb_items]->get_from_file(numb);
		if (inventory[numb_items]->get_name() != str)
		{
			inventory[numb_items]->change_name(str);
			inventory[numb_items]->change_cost(pr.get_cost());
		}
		break;
	case 3:
		inventory.push_back(new heal(str, 0, 0));
		numb = h.find_in_file(str);
		h.get_from_file(numb);
		inventory[numb_items]->get_from_file(numb);
		if (inventory[numb_items]->get_name() != str)
		{
			inventory[numb_items]->change_name(str);
			inventory[numb_items]->change_cost(h.get_cost());
		}
		break;
	}
	numb_items++;
}

//Удаление из инвентаря
void Hero::del_from_invent(string str)
{
	int nom = 0;
	for (int i = 0; i < numb_items; i++)
		if (str == inventory[i]->get_name())
			nom = i;
	for (int i = nom; i < numb_items - 1; i++)
		inventory[i + 1] = inventory[i];
	numb_items--;
}

//Действие
unsigned Hero::action(string str, string str_1)
{
	Enemy En(0);
	En.get_inf_file(str);
	int opr = 0;
	unsigned nom_h = -1, col_weap = 0;
	heal h("", 0, 0);
	for (unsigned i = 0; (i < numb_items) && (nom_h == -1); i++)
		nom_h = h.find_in_file(inventory[i]->get_name());
	if (nom_h != -1)
		h.get_from_file(nom_h);
	for (unsigned i = 0; i < numb_items; i++)
	{
		unsigned fin = weap.find_in_file(inventory[i]->get_name());
		if (-1 != fin)
			col_weap++;
	}
	cout << endl << endl << "Ваш остаток выносливости: " << stamina;
	if (En.get_distance() <= weap.get_long_act())
	{
		if (nom_h != -1)
		{
			if (col_weap > 1)
			{
				if (stamina >= weap.get_stamin_cons())
				{
					cout << endl << "Введите:\n1 - если хотите отступить";
					cout << endl << "2 - если хотите атаковать врага";
					cout << endl << "3 - если хотите вылечиться";
					cout << endl << "любое другое число - если хотите сменить оружие";
					cout << endl << "Ввод: ";
					cin >> opr;
					if ((opr < 1) || (opr > 3))
						opr = 5;
					else
						opr++;
				}
				else
				{
					cout << endl << "Введите:\n1 - если хотите отступить";
					cout << endl << "2 - если хотите вылечиться";
					cout << endl << "любое другое число - если хотите сменить оружие";
					cout << endl << "Ввод: ";
					cin >> opr;
					if ((opr < 1) || (opr > 2))
						opr = 5;
					else
					{
						if (opr == 1)
							opr++;
						else
							opr = 4;
					}
				}
			}
			else
			{
				if (stamina >= weap.get_stamin_cons())
				{
					cout << endl << "Введите:\n1 - если хотите отступить";
					cout << endl << "2 - если хотите атаковать врага";
					cout << endl << "любое другое число - если хотите вылечиться";
					cout << endl << "Ввод: ";
					cin >> opr;
					if ((opr < 1) || (opr > 2))
						opr = 4;
					else
						opr++;
				}
				else
				{
					cout << endl << "Введите:\n1 - если хотите отступить";
					cout << endl << "любое другое число - если хотите вылечиться";
					cout << endl << "Ввод: ";
					cin >> opr;
					if (opr != 1)
						opr = 4;
					else
						opr++;
				}
			}
		}
		else
		{
			if (col_weap > 1)
			{
				if (stamina >= weap.get_stamin_cons())
				{
					cout << endl << "Введите:\n1 - если хотите отступить";
					cout << endl << "2 - если хотите атаковать врага";
					cout << endl << "любое другое число - если хотите сменить оружие";
					cout << endl << "Ввод: ";
					cin >> opr;
					if ((opr < 1) || (opr > 2))
						opr = 5;
					else
						opr++;
				}
				else
				{
					cout << endl << "Введите:\n1 - если хотите отступить";
					cout << endl << "любое другое число - если хотите сменить оружие";
					cout << endl << "Ввод: ";
					cin >> opr;
					if (opr != 1)
						opr = 5;
					else
						opr++;
				}
			}
			else
			{
				if (stamina >= weap.get_stamin_cons())
				{
					cout << endl << "Введите:\n1 - если хотите отступить";
					cout << endl << "любое другое число - если хотите атаковать врага";
					cout << endl << "Ввод: ";
					cin >> opr;
					if (opr != 1)
						opr = 3;
					else
						opr = 2;
				}
				else
				{
					cout << endl << "любое другое число - если хотите отступить";
					cout << endl << "Ввод: ";
					cin >> opr;
					opr = 2;
				}
			}
		}
	}
	else
	{
		cout << endl << "Расстояние между Вами и врагом: " << En.get_distance();
		if (nom_h != -1)
		{
			if (col_weap > 1)
			{
				cout << endl << "Введите:\n1 - если хотите подойти к врагу";
				cout << endl << "2 - если хотите отступить";
				cout << endl << "3 - если хотите вылечиться";
				cout << endl << "любое другое число - если хотите сменить оружие";
				cout << endl << "Ввод: ";
				cin >> opr;	
				if ((opr < 1) || (opr > 3))
					opr = 5;
			}
			else
			{
				cout << endl << "Введите:\n1 - если хотите подойти к врагу";
				cout << endl << "2 - если хотите отступить";
				cout << endl << "любое другое число - если хотите вылечиться";
				cout << endl << "Ввод: ";
				cin >> opr;
				if ((opr < 1) || (opr > 2))
					opr = 4;
			}
		}
		else
		{
			if (col_weap > 1)
			{
				cout << endl << "Введите:\n1 - если хотите подойти к врагу";
				cout << endl << "2 - если хотите отступить";
				cout << endl << "любое другое число - если хотите сменить оружие";
				cout << endl << "Ввод: ";
				cin >> opr;
				if ((opr < 1) || (opr > 2))
					opr = 5;
			}
			else
			{
				cout << endl << "Введите:\n1 - если хотите подойти к врагу";
				cout << endl << "любое другое число - если хотите отступить";
				cout << endl << "Ввод: ";
				cin >> opr;
				if (opr != 1)
					opr = 2;
			}
		}
	}
	switch (opr)
	{
	case 1:
		//Приближение к врагу
		En.distant(-5);
		break;
	case 2:
		//Отступление
		if (stamina + rest_stam_turn > 50)
			stamina = 50;
		else
			stamina += rest_stam_turn;
		En.distant(5);
		break;
	case 3:
		//Атаковать врага
		stamina -= weap.get_stamin_cons();
		En.parrying(weap.get_damage());
		cout << endl << "Ваш остаток выносливости: " << stamina;
		break;
	case 4:
		//Лечение
		if (stamina + rest_stam_turn > 50)
			stamina = 50;
		else
			stamina += rest_stam_turn;
		if (HP + h.get_health_heal() > 100)
			HP = 100;
		else
			HP += h.get_health_heal();
		for (int i = nom_h; i < numb_items - 1; i++)
			inventory[i + 1] = inventory[i];
		numb_items--;
		cout << endl << "Вы вылечились.Ваше здоровье теперь: " << HP;

		break;
	case 5:
		//Смена оружия
		if (stamina + rest_stam_turn > 50)
			stamina = 50;
		else
			stamina += rest_stam_turn;
		cout << "Выберете оружие из списка:\n";
		int weap_nom = 0, wep, ind = 0;
		for (unsigned i = 0; i < numb_items; i++)
		{
			unsigned fin = weap.find_in_file(inventory[i]->get_name());
			if (-1 != fin)
			{
				weap_nom++;
				cout << endl << weap_nom << ") " << inventory[i]->get_name();
			}
		}
		cout << endl << "Введите номер оружия (если введённое число больше количества оружия, автоматически выберается первое): ";
		cin >> wep;
		weap_nom = 0;
		for (unsigned i = 0; (i < numb_items) && (weap_nom != wep); i++)
		{
			unsigned fin = weap.find_in_file(inventory[i]->get_name());
			if (-1 != fin)
			{
				weap_nom++;
				if (weap_nom == wep)
					ind = i;
			}
		}
		wep = weap.find_in_file(inventory[ind]->get_name());
		weap.get_from_file(wep);
		break;
	}
	save_to_file(str_1);
	En.save_to_file(str);

	return En.get_HP();
}

//Парирование атаки
void Hero::parrying(unsigned dam)
{
	float at_h = 0, at_e = 0;
	for(int i = 0; i < 10; i++)
		at_h = rand() % 100;
	for (int i = 0; i < 10; i++)
		at_e = rand() % 100;
	//проверка попал ли враг
	if (at_e >= at_h)
	{
		cout << endl << "Враг бъёт по Вам";
		for (int i = 0; i < 10; i++)
			at_h = rand() % 100;
		for (int i = 0; i < 10; i++)
			at_e = rand() % 100;
		//проверка смог ли герой отразить атаку
		if (at_h > at_e)
		{
			cout << endl << "Вы подняли свой щит";
			//проверка, выдержал ли щит атаку
			if (prot.get_dam_absorp() >= dam)
				cout << endl << "Ваш щит оказался сильнее атаки противника";
			else
			{
				//Проверка на сметь
				if (HP <= (dam - prot.get_dam_absorp()))
				{
					cout << endl << "Вы погибли. Игра окончена.";
					exit(0);
				}
				else
				{
					HP = HP - (dam - prot.get_dam_absorp());
					cout << endl << "Враг нанёс Вам удар. Ваши очки здоровья: " << HP;
				}

			}
		}
		else
		{
			cout << endl << "Вы не смогли отразить атаку противника.";
			//Проверка на сметь
			if (HP <= dam)
			{
				cout << endl << "Вы погибли. Игра окончена.";
				exit(0);
			}
			else
			{
				HP = HP - dam;
				cout << endl << "Враг нанёс Вам удар. Ваши очки здоровья: " << HP;
			}
		}
	}
	else
	{
		cout << endl << "Враг попытался нанести удар, но промахнулся.";
	}
}

//Возвращение количества выносливости
unsigned Enemy::get_level()
{
	return this->level;
}

//Возвращение дистанции (в метрах)
unsigned Enemy::get_distance()
{
	return this->distance;
}

//Приближение(отдаление) к(от) врагу(-у)
void Enemy::distant(int dist)
{
	if (dist < 0)
	{
		if (abs(dist) > distance)
			distance = 1;
		else
			distance += dist;
	}
	else
		distance += dist;
}

//Сохранение прогресса в файл
void Enemy::save_to_file(string str)
{
	string f_name = str;
	ofstream f;
	f.open(f_name);
	f << "Имя\n";
	f << name << "\n";
	f << "\nУровень\n";
	f << level << "\n";
	f << "\nЗдоровье (HP)\n";
	f << HP << "\n";
	f << "\nБаланс (монеты)\n";
	f << balance << "\n";
	f << "\nВещь в руке (атака)\n";
	f << weap.get_name() << "\n";
	f << "\nВещь в руке (защита)\n";
	f << prot.get_name() << "\n";
	f << "\nРасстояние (метры)\n";
	f << distance << "\n";
	f << "\nКоличество вещей в инвентаре:\n";
	f << numb_items << "\n";
	f << "\nИнвентарь:\n";
	for (unsigned i = 0; i < numb_items - 1; i++)
		f << inventory[i]->get_name() << "\n";
	f << inventory[numb_items - 1]->get_name();
	f.close();
}

//Взятие информации из файла
void Enemy::get_inf_file(string f_txt)
{
	string f_name = f_txt, str;
	ifstream fin(f_name);
	getline(fin, str);
	getline(fin, str);
	name = str;
	for (int i = 0; i < 7; i++)
	{
		getline(fin, str);
		getline(fin, str);
		getline(fin, str);
		unsigned numb = 0;
		switch (i)
		{
		case 0:
			level = StrToDigit(str);
			break;
		case 1:
			HP = StrToDigit(str);
			break;
		case 2:
			balance = StrToDigit(str);
			break;
		case 3:
			numb = weap.find_in_file(str);
			weap.get_from_file(numb);
			break;
		case 4:
			numb = prot.find_in_file(str);
			prot.get_from_file(numb);
			break;
		case 5:
			distance = StrToDigit(str);
			break;
		case 6:
			numb_items = StrToDigit(str);
			break;
		}
	}
	getline(fin, str);
	getline(fin, str);
	for (unsigned i = 0; i < numb_items; i++)
	{
		getline(fin, str);
		unsigned opr = weap.find_in_file(str), numb = 0;
		if (opr != -1)
			numb = 1;
		opr = prot.find_in_file(str);
		if (opr != -1)
			numb = 2;
		heal h("h", 0, 0);
		opr = h.find_in_file(str);
		if (opr != -1)
			numb = 3;
		switch (numb)
		{
		case 1:
			inventory.push_back(new weapon(str, 0, 0, 0, 0));
			break;
		case 2:
			inventory.push_back(new protection(str, 0, 0, 0));
			break;
		case 3:
			inventory.push_back(new heal(str, 0, 0));
			break;
		}
		numb = inventory[i]->find_in_file(str);
		inventory[i]->get_from_file(numb);
	}
	fin.close();
}

//Парирование атаки
void Enemy::parrying(unsigned dam)
{
	float at_h = 0, at_e = 0;
	for (int i = 0; i < 10; i++)
		at_h = rand() % 100;
	for (int i = 0; i < 10; i++)
		at_e = rand() % 100;
	//проверка попал ли герой
	if (at_e >= at_h)
	{
		cout << endl << "Вы бъёте по врагу";
		for (int i = 0; i < 10; i++)
			at_h = rand() % 100;
		for (int i = 0; i < 10; i++)
			at_e = rand() % 100;
		//проверка смог ли враг отразить атаку
		if (at_e > at_h)
		{
			cout << endl << "Враг успел поднять свой щит";
			//проверка выдержал ли щит атаку
			if (prot.get_dam_absorp() >= dam)
				cout << endl << "Щит врага оказался сильнее Вашей атаки";
			else
			{
				//Проверка на сметь
				if (HP <= (dam - prot.get_dam_absorp()))
				{
					HP = 0;
					cout << endl << "Враг погиб.";
					
				}
				else
				{
					HP = HP - (dam - prot.get_dam_absorp());
					cout << endl << "Вы нанёсли удар по врагу. Его здоровье: " << HP;
				}

			}
		}
		else
		{
			cout << endl << "Враг не смог отразить Вашу атаку.";
			//Проверка на сметь
			if (HP <= dam)
			{
				cout << endl << "Враг погиб.";
				HP = 0;
			}
			else
			{
				HP = HP - dam;
				cout << endl << "Вы нанёсли удар по врагу. Его здоровье: " << HP;
			}
		}
	}
	else
		cout << endl << "Вы попытались нанести удар по врагу, но промахнулись.";
}

//Действие
unsigned Enemy::action(string str, string str_1)
{
	Hero he(0);
	he.get_inf_file(str);
	int opr = 1;
	unsigned nom_h = -1, len = 0;

	heal h("", 0, 0);
	if (HP <= 10)
	{
		for (unsigned i = 0; (i < numb_items) && (nom_h == -1); i++)
			nom_h = h.find_in_file(inventory[i]->get_name());
		if (nom_h != -1)
		{
			if (distance < 5)
				opr = 3;
			else
			{
				opr = 2;
				h.get_from_file(nom_h);
			}
		}
		else
			opr = 1;
	}
	else
	{
		if (weap.get_long_act() >= distance)
			opr = 1;
		else
		{
			if (distance > 5)
				len = 5;
			else
				len = 4;
			opr = 4;
		}
	}
	unsigned dem = 0;
	switch (opr)
	{
	case 1:
		//атака
		cout << endl << endl << "Враг хочет нанести по Вам удар.";
		dem = weap.get_damage();
		he.parrying(dem);
		break;
	case 2:
		//Лечение
		cout << endl << endl << "Враг лечится.";
		HP += h.get_health_heal();
		for (int i = nom_h; i < numb_items - 1; i++)
			inventory[i + 1] = inventory[i];
		numb_items--;
		break;
	case 3:
		//Отступление
		cout << endl << endl << "Враг отступает.";
		distance += 5;
		break;
	case 4:
		//Приближение
		cout << endl << "Расстояние до врага: " << distance << endl << "Враг приближается.";
		distance -= len;
		break;
	}
	save_to_file(str_1);
	he.save_to_file(str);
	return he.get_HP();
}