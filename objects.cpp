#include "objects.h"

//������� ��������
string objects::get_name()
{
	return this->name;
}

//������� ���������
unsigned objects::get_cost()
{
	return this->cost;
}

//������� �����
unsigned weapon::get_damage()
{
	return this->damage;
}

//������� ���������� ������������
unsigned weapon::get_stamin_cons()
{
	return this->stamin_cons;
}

//������� ��������������
unsigned weapon::get_long_act()
{
	return this->long_act;
}

//����� ���������� �� ������
void weapon::print_info()
{
	cout << "��������: " << get_name() << endl;
	cout << "����: " << get_damage() << endl;
	cout << "������ ������������ �� ���: " << get_stamin_cons() << endl;
	cout << "�������������� (� ������): " << get_long_act() << endl;
	cout << "���������: " << get_cost() << endl;
}

//������ �� ����� ���������� �� ������
void weapon::get_from_file(unsigned numb)
{
	string str;
	ifstream fin("weapon.txt");
	if (!fin.is_open())
	{
		cout << endl << "��������� �� ���������� ����� � �������. ���������� ������ ���������.";
		exit(0);
	}
	for (int i = 1; i <= 9; i++)
		getline(fin, str);
	unsigned temp = StrToDigit(str);
	if (temp < numb)
	{
		cout << endl << "� ����� � ������� ������������ ������. ����� �� ������������.";
		return;
	}
	string nam;
	unsigned dam = 0, stam = 0, lon = 0, cos = 0;
	for (unsigned i = 1; i <= numb; i++)
	{
		getline(fin, str);
		//������ �����
		getline(fin, nam);
		//������ �����
		getline(fin, str);
		dam = StrToDigit(str);
		//������ ������� ������������
		getline(fin, str);
		stam = StrToDigit(str);
		//������ ��������������
		getline(fin, str);
		lon = StrToDigit(str);
		//������ ���������
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

//����� ������ � ����� �� ����� � ������� ��� ������
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


//������� ��������������
unsigned protection::get_dam_absorp()
{
	return this->dam_absorp;
}

//����������� ����
unsigned protection::get_weight()
{
	return this->weight;
}

//����� ���������� � ����
void protection::print_info()
{
	cout << "��������: " << get_name() << endl;
	cout << "���������� �����: " << get_dam_absorp() << endl;
	cout << "���: " << get_weight() << endl;
	cout << "���������: " << get_cost() << endl;
}

//������ �� ����� ���������� � ����
void protection::get_from_file(unsigned numb)
{
	string str;
	ifstream fin("protection.txt");
	if (!fin.is_open())
	{
		cout << endl << "��������� �� ���������� ����� �� ������. ���������� ������ ���������.";
		exit(0);
	}
	for (int i = 1; i <= 8; i++)
		getline(fin, str);
	unsigned temp = StrToDigit(str);
	if (temp < numb)
	{
		cout << endl << "� ����� �� ������ ������������ �����. ����� �� ������������.";
		return;
	}
	string nam;
	unsigned dam = 0, weig = 0, cos = 0;
	for (unsigned i = 1; i <= numb; i++)
	{
		getline(fin, str);
		//������ �����
		getline(fin, nam);
		//������ ���������� �����
		getline(fin, str);
		dam = StrToDigit(str);
		//������ ����
		getline(fin, str);
		weig = StrToDigit(str);
		//������ ���������
		getline(fin, str);
		cos = StrToDigit(str);
	}
	name = nam;
	cost = cos;
	dam_absorp = dam;
	weight = weig;
	fin.close();
}

//����� ���� � ����� �� ����� � ������� ��� ������
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


//������� �������������� ��������
unsigned heal::get_health_heal()
{
	return this->health_heal;
}

//����� ���������� � ���������
void heal::print_info()
{
	cout << "��������: " << get_name() << endl;
	cout << "�������������� ��������: " << get_health_heal() << endl;
	cout << "���������: " << get_cost() << endl;
}

//��������� �����
void objects::change_name(string str)
{
	name = str;
}

//��������� ���������
void objects::change_cost(unsigned cos)
{
	cost = cos;
}

//������ �� ����� ���������� �� �������
void heal::get_from_file(unsigned numb)
{
	string str;
	ifstream fin("heal.txt");
	if (!fin.is_open())
	{
		cout << endl << "��������� �� ���������� ����� � �����������. ���������� ������ ���������.";
		exit(0);
	}
	for (int i = 1; i <= 7; i++)
		getline(fin, str);
	unsigned temp = StrToDigit(str);
	if (temp < numb)
	{
		cout << endl << "� ����� � ����������� ������������ ��������. ����� �� ������������.";
		return;
	}
	string nam;
	unsigned hp = 0, cos = 0;
	for (unsigned i = 1; i <= numb; i++)
	{
		getline(fin, str);
		//������ �����
		getline(fin, nam);
		//������ ���������� �����
		getline(fin, str);
		hp = StrToDigit(str);
		//������ ���������
		getline(fin, str);
		cos = StrToDigit(str);
	}
	name = nam;
	cost = cos;
	health_heal = hp;
	fin.close();
}

//����� ��������� � ����� �� ����� � ������� ��� ������
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