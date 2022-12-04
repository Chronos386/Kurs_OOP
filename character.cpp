#include "character.h"
#include "foundation.h"

//������� �����
string character::get_name()
{
	return this->name;
}

//������� ���������� ����� ��������
unsigned character::get_HP()
{
	return this->HP;
}

//������� �������
unsigned character::get_balance()
{
	return this->balance;
}

//������� ���������� ����� ������������
unsigned Hero::get_stamina()
{
	return this->stamina;
}

//������� ���������� ����� ������������, �������������� �� ���
unsigned Hero::get_rest_stam_turn()
{
	return this->rest_stam_turn;
}

//������� �������� ������
string character::get_name_prot()
{
	return prot.get_name();
}

//��������� �������
void Hero::change_balance(int money)
{
	balance += money;
	cout << endl << "����� ������: " << balance;
}

//����� ������
void Hero::swap_weap(string str)
{
	unsigned num = weap.find_in_file(str);
	weap.get_from_file(num);
}

//����� ����
void Hero::swap_prot(string str)
{
	unsigned num = prot.find_in_file(str);
	prot.get_from_file(num);
}

//����� ���������� � �����
void Hero::print_info()
{
	cout << endl << "���������� � ����� ���������:";
	cout << endl << "���: " << name;
	cout << endl << "��������: " << HP;
	cout << endl << "������������: " << stamina;
	cout << endl << "�������������� ������������ �� ��� (�������, �����������):" << rest_stam_turn;
	cout << endl << "������ (������): " << balance;
	cout << endl << "���� � ���� (�����): " << weap.get_name();
	cout << endl << "���� � ���� (������): " << prot.get_name();
	cout << endl << "���������� ����� � ���������: " << numb_items;
	cout << endl << "���������:";
	for(int i = 0; i < numb_items; i++)
		cout << endl << inventory[i]->get_name();
}

//���������� ��������� � ����
void Hero::save_to_file(string str)
{
	string f_name = str;
	ofstream f;
	f.open(f_name);
	f << "���\n";
	f << name << "\n";
	f << "\n��������\n";
	f << HP << "\n";
	f << "\n������������\n";
	f << stamina << "\n";
	f << "\n�������������� ������������ �� ��� ����������� (�������, �����������)\n";
	f << rest_stam_turn << "\n";
	f << "\n������ (������)\n";
	f << balance << "\n";
	f << "\n���� � ���� (�����)\n";
	f << weap.get_name() << "\n";
	f << "\n���� � ���� (������)\n";
	f << prot.get_name() << "\n";
	f << "\n���������� ����� � ���������:\n";
	f << numb_items << "\n";
	f << "\n���������:\n";
	for(unsigned i = 0; i < numb_items - 1; i++)
		f << inventory[i]->get_name() << "\n";
	f << inventory[numb_items - 1]->get_name();
	f.close();
}

//�������� ������ �� �����
void Hero::get_inf_file(string f_txt)
{
	string f_name = f_txt, str;
	ifstream fin(f_name);
	if (!fin.is_open())
	{
		cout << endl << "� ���������, ����� � ����� ������ �� ����������";
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
				cout << "� ����� ������ ����� �������� �������������� ������. ���������� ������ ���������.";
				exit(0);
			}
			break;
		case 5:
			numb = prot.find_in_file(str);
			if (numb != -1)
				prot.get_from_file(numb);
			else
			{
				cout << "� ����� ������ ����� ������� �������������� ���. ���������� ������ ���������.";
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

//���������� � ���������
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

//�������� �� ���������
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

//��������
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
	cout << endl << endl << "��� ������� ������������: " << stamina;
	if (En.get_distance() <= weap.get_long_act())
	{
		if (nom_h != -1)
		{
			if (col_weap > 1)
			{
				if (stamina >= weap.get_stamin_cons())
				{
					cout << endl << "�������:\n1 - ���� ������ ���������";
					cout << endl << "2 - ���� ������ ��������� �����";
					cout << endl << "3 - ���� ������ ����������";
					cout << endl << "����� ������ ����� - ���� ������ ������� ������";
					cout << endl << "����: ";
					cin >> opr;
					if ((opr < 1) || (opr > 3))
						opr = 5;
					else
						opr++;
				}
				else
				{
					cout << endl << "�������:\n1 - ���� ������ ���������";
					cout << endl << "2 - ���� ������ ����������";
					cout << endl << "����� ������ ����� - ���� ������ ������� ������";
					cout << endl << "����: ";
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
					cout << endl << "�������:\n1 - ���� ������ ���������";
					cout << endl << "2 - ���� ������ ��������� �����";
					cout << endl << "����� ������ ����� - ���� ������ ����������";
					cout << endl << "����: ";
					cin >> opr;
					if ((opr < 1) || (opr > 2))
						opr = 4;
					else
						opr++;
				}
				else
				{
					cout << endl << "�������:\n1 - ���� ������ ���������";
					cout << endl << "����� ������ ����� - ���� ������ ����������";
					cout << endl << "����: ";
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
					cout << endl << "�������:\n1 - ���� ������ ���������";
					cout << endl << "2 - ���� ������ ��������� �����";
					cout << endl << "����� ������ ����� - ���� ������ ������� ������";
					cout << endl << "����: ";
					cin >> opr;
					if ((opr < 1) || (opr > 2))
						opr = 5;
					else
						opr++;
				}
				else
				{
					cout << endl << "�������:\n1 - ���� ������ ���������";
					cout << endl << "����� ������ ����� - ���� ������ ������� ������";
					cout << endl << "����: ";
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
					cout << endl << "�������:\n1 - ���� ������ ���������";
					cout << endl << "����� ������ ����� - ���� ������ ��������� �����";
					cout << endl << "����: ";
					cin >> opr;
					if (opr != 1)
						opr = 3;
					else
						opr = 2;
				}
				else
				{
					cout << endl << "����� ������ ����� - ���� ������ ���������";
					cout << endl << "����: ";
					cin >> opr;
					opr = 2;
				}
			}
		}
	}
	else
	{
		cout << endl << "���������� ����� ���� � ������: " << En.get_distance();
		if (nom_h != -1)
		{
			if (col_weap > 1)
			{
				cout << endl << "�������:\n1 - ���� ������ ������� � �����";
				cout << endl << "2 - ���� ������ ���������";
				cout << endl << "3 - ���� ������ ����������";
				cout << endl << "����� ������ ����� - ���� ������ ������� ������";
				cout << endl << "����: ";
				cin >> opr;	
				if ((opr < 1) || (opr > 3))
					opr = 5;
			}
			else
			{
				cout << endl << "�������:\n1 - ���� ������ ������� � �����";
				cout << endl << "2 - ���� ������ ���������";
				cout << endl << "����� ������ ����� - ���� ������ ����������";
				cout << endl << "����: ";
				cin >> opr;
				if ((opr < 1) || (opr > 2))
					opr = 4;
			}
		}
		else
		{
			if (col_weap > 1)
			{
				cout << endl << "�������:\n1 - ���� ������ ������� � �����";
				cout << endl << "2 - ���� ������ ���������";
				cout << endl << "����� ������ ����� - ���� ������ ������� ������";
				cout << endl << "����: ";
				cin >> opr;
				if ((opr < 1) || (opr > 2))
					opr = 5;
			}
			else
			{
				cout << endl << "�������:\n1 - ���� ������ ������� � �����";
				cout << endl << "����� ������ ����� - ���� ������ ���������";
				cout << endl << "����: ";
				cin >> opr;
				if (opr != 1)
					opr = 2;
			}
		}
	}
	switch (opr)
	{
	case 1:
		//����������� � �����
		En.distant(-5);
		break;
	case 2:
		//�����������
		if (stamina + rest_stam_turn > 50)
			stamina = 50;
		else
			stamina += rest_stam_turn;
		En.distant(5);
		break;
	case 3:
		//��������� �����
		stamina -= weap.get_stamin_cons();
		En.parrying(weap.get_damage());
		cout << endl << "��� ������� ������������: " << stamina;
		break;
	case 4:
		//�������
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
		cout << endl << "�� ����������.���� �������� ������: " << HP;

		break;
	case 5:
		//����� ������
		if (stamina + rest_stam_turn > 50)
			stamina = 50;
		else
			stamina += rest_stam_turn;
		cout << "�������� ������ �� ������:\n";
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
		cout << endl << "������� ����� ������ (���� �������� ����� ������ ���������� ������, ������������� ���������� ������): ";
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

//����������� �����
void Hero::parrying(unsigned dam)
{
	float at_h = 0, at_e = 0;
	for(int i = 0; i < 10; i++)
		at_h = rand() % 100;
	for (int i = 0; i < 10; i++)
		at_e = rand() % 100;
	//�������� ����� �� ����
	if (at_e >= at_h)
	{
		cout << endl << "���� ���� �� ���";
		for (int i = 0; i < 10; i++)
			at_h = rand() % 100;
		for (int i = 0; i < 10; i++)
			at_e = rand() % 100;
		//�������� ���� �� ����� �������� �����
		if (at_h > at_e)
		{
			cout << endl << "�� ������� ���� ���";
			//��������, �������� �� ��� �����
			if (prot.get_dam_absorp() >= dam)
				cout << endl << "��� ��� �������� ������� ����� ����������";
			else
			{
				//�������� �� �����
				if (HP <= (dam - prot.get_dam_absorp()))
				{
					cout << endl << "�� �������. ���� ��������.";
					exit(0);
				}
				else
				{
					HP = HP - (dam - prot.get_dam_absorp());
					cout << endl << "���� ���� ��� ����. ���� ���� ��������: " << HP;
				}

			}
		}
		else
		{
			cout << endl << "�� �� ������ �������� ����� ����������.";
			//�������� �� �����
			if (HP <= dam)
			{
				cout << endl << "�� �������. ���� ��������.";
				exit(0);
			}
			else
			{
				HP = HP - dam;
				cout << endl << "���� ���� ��� ����. ���� ���� ��������: " << HP;
			}
		}
	}
	else
	{
		cout << endl << "���� ��������� ������� ����, �� �����������.";
	}
}

//����������� ���������� ������������
unsigned Enemy::get_level()
{
	return this->level;
}

//����������� ��������� (� ������)
unsigned Enemy::get_distance()
{
	return this->distance;
}

//�����������(���������) �(��) �����(-�)
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

//���������� ��������� � ����
void Enemy::save_to_file(string str)
{
	string f_name = str;
	ofstream f;
	f.open(f_name);
	f << "���\n";
	f << name << "\n";
	f << "\n�������\n";
	f << level << "\n";
	f << "\n�������� (HP)\n";
	f << HP << "\n";
	f << "\n������ (������)\n";
	f << balance << "\n";
	f << "\n���� � ���� (�����)\n";
	f << weap.get_name() << "\n";
	f << "\n���� � ���� (������)\n";
	f << prot.get_name() << "\n";
	f << "\n���������� (�����)\n";
	f << distance << "\n";
	f << "\n���������� ����� � ���������:\n";
	f << numb_items << "\n";
	f << "\n���������:\n";
	for (unsigned i = 0; i < numb_items - 1; i++)
		f << inventory[i]->get_name() << "\n";
	f << inventory[numb_items - 1]->get_name();
	f.close();
}

//������ ���������� �� �����
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

//����������� �����
void Enemy::parrying(unsigned dam)
{
	float at_h = 0, at_e = 0;
	for (int i = 0; i < 10; i++)
		at_h = rand() % 100;
	for (int i = 0; i < 10; i++)
		at_e = rand() % 100;
	//�������� ����� �� �����
	if (at_e >= at_h)
	{
		cout << endl << "�� ����� �� �����";
		for (int i = 0; i < 10; i++)
			at_h = rand() % 100;
		for (int i = 0; i < 10; i++)
			at_e = rand() % 100;
		//�������� ���� �� ���� �������� �����
		if (at_e > at_h)
		{
			cout << endl << "���� ����� ������� ���� ���";
			//�������� �������� �� ��� �����
			if (prot.get_dam_absorp() >= dam)
				cout << endl << "��� ����� �������� ������� ����� �����";
			else
			{
				//�������� �� �����
				if (HP <= (dam - prot.get_dam_absorp()))
				{
					HP = 0;
					cout << endl << "���� �����.";
					
				}
				else
				{
					HP = HP - (dam - prot.get_dam_absorp());
					cout << endl << "�� ������ ���� �� �����. ��� ��������: " << HP;
				}

			}
		}
		else
		{
			cout << endl << "���� �� ���� �������� ���� �����.";
			//�������� �� �����
			if (HP <= dam)
			{
				cout << endl << "���� �����.";
				HP = 0;
			}
			else
			{
				HP = HP - dam;
				cout << endl << "�� ������ ���� �� �����. ��� ��������: " << HP;
			}
		}
	}
	else
		cout << endl << "�� ���������� ������� ���� �� �����, �� ������������.";
}

//��������
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
		//�����
		cout << endl << endl << "���� ����� ������� �� ��� ����.";
		dem = weap.get_damage();
		he.parrying(dem);
		break;
	case 2:
		//�������
		cout << endl << endl << "���� �������.";
		HP += h.get_health_heal();
		for (int i = nom_h; i < numb_items - 1; i++)
			inventory[i + 1] = inventory[i];
		numb_items--;
		break;
	case 3:
		//�����������
		cout << endl << endl << "���� ���������.";
		distance += 5;
		break;
	case 4:
		//�����������
		cout << endl << "���������� �� �����: " << distance << endl << "���� ������������.";
		distance -= len;
		break;
	}
	save_to_file(str_1);
	he.save_to_file(str);
	return he.get_HP();
}