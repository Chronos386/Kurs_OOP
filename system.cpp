#include "system.h"

//�������� ������ ������
void new_game(string str)
{
    system("cls");
    cout << "����� ���������� � ����� ����!" << endl;
    string f_name = str + ".txt";
    ofstream f;
    f.open(f_name);
    f << "���\n";
    f << str << "\n";
    f << "\n��������\n";
    f << 100 << "\n";
    f << "\n������������\n";
    f << 50 << "\n";
    f << "\n�������������� ������������ �� ��� ����������� (�������, �����������)\n";
    f << 10 << "\n";
    f << "\n������ (������)\n";
    f << 0 << "\n";

    cout << endl << "�������� ���� �� ������������  ������:";
    weapon weap("", 0, 0, 0, 0);
    weap.get_from_file(1);
    cout << endl << "1)";
    weap.print_info();
    weap.get_from_file(2);
    cout << endl << endl << "2)";
    weap.print_info();
    weap.get_from_file(3);
    cout << endl << endl << "3)";
    weap.print_info();

    cout << endl << "�������:";
    cout << endl << "1 - ���� ��������� ������ �������";
    cout << endl << "2 - ���� ��������� ������ �������";
    cout << endl << "����� ������ ����� - ���� ��������� ������ �������";
    cout << endl << "����: ";
    int opr;
    cin >> opr;
    if ((opr < 1) || (opr > 2))
        opr = 3;
    weap.get_from_file(opr);
    f << "\n���� � ���� (�����)\n";
    f << weap.get_name() << "\n";

    f << "\n���� � ���� (������)\n";
    f << "���" << "\n";
    f << "\n���������� ����� � ���������:\n";
    f << 3 << "\n";
    f << "\n���������:\n";
    f << weap.get_name() << "\n";
    f << "���" << "\n";
    f << "������ ������� ������";
    f.close();
    system("pause");
    system("cls");
}


//����� � �������
void go_to_store(Hero H)
{
    system("cls");
    cout << "����� ���������� � �������!";
    unsigned numb = 0, max_n, opr = 0;
    string str;

    weapon weap("", 0, 0, 0, 0);
    ifstream fin("weapon.txt");
    if (!fin.is_open())
    {
        cout << endl << endl << "��������� �� ���������� ����� � �������. ���������� ������ ���������.";
        exit(0);
    }
    for (int i = 1; i <= 9; i++)
        getline(fin, str);
    fin.close();
    max_n = StrToDigit(str);
    srand(time(NULL));
    numb = rand() % (max_n + 1);
    if (numb == 0)
        numb = 1;
    weap.get_from_file(numb);
    cout << endl << endl << "������������ ������:" << endl;
    weap.print_info();

    protection prot("", 0, 0, 0);
    ifstream fin_2("protection.txt");
    if (!fin_2.is_open())
    {
        cout << endl << "��������� �� ���������� ����� �� ������. ���������� ������ ���������.";
        exit(0);
    }
    for (int i = 1; i <= 8; i++)
        getline(fin_2, str);
    fin_2.close();
    max_n = StrToDigit(str);
    numb = rand() % (max_n + 1);
    if (numb == 0)
        numb = 1;
    prot.get_from_file(numb);
    cout << endl << endl << "������������ ���:" << endl;
    prot.print_info();

    heal Heal("", 0, 0);
    ifstream fin_3("heal.txt");
    if (!fin_3.is_open())
    {
        cout << endl << "��������� �� ���������� ����� � �����������. ���������� ������ ���������.";
        exit(0);
    }
    for (int i = 1; i <= 7; i++)
        getline(fin_3, str);
    fin_3.close();
    max_n = StrToDigit(str);
    numb = rand() % (max_n + 1);
    if (numb == 0)
        numb = 1;
    Heal.get_from_file(numb);
    cout << endl << endl << "������������ ����� �������������� ��:" << endl;
    Heal.print_info();

    numb = 1;
    unsigned opr_w = 1, opr_pr = 1, opr_h = 1;
    while (numb != 0)
    {
        cout << endl << endl << "�������:";

        if (opr_w == 1)
        {
            if (opr_pr == 1)
            {
                if (opr_h == 1)
                {
                    cout << endl << "1 - ���� ������ ������ ������";
                    cout << endl << "2 - ���� ������ ������ ���";
                    cout << endl << "3 - ���� ������ ������ ����� �������������� ��";
                    cout << endl << "4 - ���� ������ ��������� ��� ������";
                    cout << endl << "����� ������ ����� - ���� ������ ��������� �������";
                    cout << endl << "����: ";
                    cin >> numb;
                    if ((numb < 1) || (numb > 4))
                        numb = 0;
                }
                else
                {
                    cout << endl << "1 - ���� ������ ������ ������";
                    cout << endl << "2 - ���� ������ ������ ���";
                    cout << endl << "3 - ���� ������ ��������� ��� ������";
                    cout << endl << "����� ������ ����� - ���� ������ ��������� �������";
                    cout << endl << "����: ";
                    cin >> numb;
                    if ((numb < 1) || (numb > 3))
                        numb = 0;
                    else
                        if (numb == 3)
                            numb = 4;
                }
            }
            else
            {
                if (opr_h == 1)
                {
                    cout << endl << "1 - ���� ������ ������ ������";
                    cout << endl << "2 - ���� ������ ������ ����� �������������� ��";
                    cout << endl << "3 - ���� ������ ��������� ��� ������";
                    cout << endl << "����� ������ ����� - ���� ������ ��������� �������";
                    cout << endl << "����: ";
                    cin >> numb;
                    if ((numb < 1) || (numb > 3))
                        numb = 0;
                    else
                        if (numb >= 2)
                            numb++;
                }
                else
                {
                    cout << endl << "1 - ���� ������ ������ ������";
                    cout << endl << "2 - ���� ������ ��������� ��� ������";
                    cout << endl << "����� ������ ����� - ���� ������ ��������� �������";
                    cout << endl << "����: ";
                    cin >> numb;
                    if ((numb < 1) || (numb > 2))
                        numb = 0;
                    else
                        if (numb == 2)
                            numb = 4;
                }
            }
        }
        else
        {
            if (opr_pr == 1)
            {
                if (opr_h == 1)
                {
                    cout << endl << "1 - ���� ������ ������ ���";
                    cout << endl << "2 - ���� ������ ������ ����� �������������� ��";
                    cout << endl << "3 - ���� ������ ��������� ��� ������";
                    cout << endl << "����� ������ ����� - ���� ������ ��������� �������";
                    cout << endl << "����: ";
                    cin >> numb;
                    if ((numb < 1) || (numb > 3))
                        numb = 0;
                    else
                        numb++;
                }
                else
                {
                    cout << endl << "1 - ���� ������ ������ ���";
                    cout << endl << "2 - ���� ������ ��������� ��� ������";
                    cout << endl << "����� ������ ����� - ���� ������ ��������� �������";
                    cout << endl << "����: ";
                    cin >> numb;
                    if ((numb < 1) || (numb > 2))
                        numb = 0;
                    else
                    {
                        if (numb == 1)
                            numb = 2;
                        else
                            numb = 4;
                    }
                }
            }
            else
            {
                if (opr_h == 1)
                {
                    cout << endl << "1 - ���� ������ ������ ����� �������������� ��";
                    cout << endl << "2 - ���� ������ ��������� ��� ������";
                    cout << endl << "����� ������ ����� - ���� ������ ��������� �������";
                    cout << endl << "����: ";
                    cin >> numb;
                    if ((numb < 1) || (numb > 2))
                        numb = 0;
                    else
                            numb += 2;
                }
                else
                {
                    cout << endl << "1 - ���� ������ ��������� ��� ������";
                    cout << endl << "����� ������ ����� - ���� ������ ��������� �������";
                    cout << endl << "����: ";
                    cin >> numb;
                    if (numb != 1)
                        numb = 0;
                    else
                        numb = 4;
                }
            }
        }
        switch (numb)
        {
        case 1:
            if (weap.get_cost() > H.get_balance())
            {
                cout << endl << "� ��� ������������ ����� ��� ������� ������: " << weap.get_name();
            }
            if (weap.get_cost() <= H.get_balance())
            {
                H.change_balance((-1)*weap.get_cost());
                cout << endl << "������ �������� ��� ����������� ������ �� �����?";
                cout << endl << "�������:";
                cout << endl << "1 - ���� ��";
                cout << endl << "����� ������ ����� - ���� ���";
                cout << endl << "����: ";
                cin >> opr;
                if (opr == 1)
                    H.swap_weap(weap.get_name());
                H.add_to_invent(weap.get_name());
                opr_w = 0;
            }
            break;
        case 2:
            if (prot.get_cost() > H.get_balance())
            {
                cout << endl << "� ��� ������������ ����� ��� ������� ����: " << prot.get_name();
            }
            if (prot.get_cost() <= H.get_balance())
            {
                H.change_balance((-1) * prot.get_cost());
                H.swap_prot(prot.get_name());
                H.add_to_invent(prot.get_name());
                opr_pr = 0;
            }
            break;
        case 3:
            if (Heal.get_cost() > H.get_balance())
            {
                cout << endl << "� ��� ������������ ����� ��� ������� ����� �������������� ��: " << Heal.get_name();
            }
            if (Heal.get_cost() <= H.get_balance())
            {
                H.change_balance((-1) * Heal.get_cost());
                H.add_to_invent(Heal.get_name());
                opr_h = 0;
            }
            break;
        case 4:
            cout << endl << "��� ������:" << H.get_balance();
            break;
        }
    }

    if ((opr_w == 0) || (opr_pr == 0) || (opr_h == 0))
        cout << endl << endl << "������� �� �������!" << endl;
    else
        cout << endl << endl << "� ��������� ��� ��������� �� ����..." << endl;
    H.save_to_file(H.get_name() + ".txt");
    system("pause");
    system("cls");
}

//����� Enemy � Hero
void fight(string str_1, string str_2)
{
    cout << "��������� ���." << endl;
    Hero FINN(0);
    FINN.get_inf_file(str_1 + ".txt");
    string str_h = FINN.get_name() + "_01.txt", str_e;
    FINN.save_to_file(str_h);

    Enemy Dr_Heinz(0);
    Dr_Heinz.get_inf_file(str_2 + ".txt");
    str_e = Dr_Heinz.get_name() + "_01.txt";
    Dr_Heinz.save_to_file(str_e);
    int opred = -1;
    srand(time(NULL));
    while (opred != 0)
    {
        FINN.get_inf_file(str_h);
        Dr_Heinz.get_inf_file(str_e);

        Dr_Heinz.action(str_h, str_e);

        Dr_Heinz.save_to_file(str_e);


        FINN.get_inf_file(str_h);
        Dr_Heinz.get_inf_file(str_e);

        opred = FINN.action(str_e, str_h);

        FINN.save_to_file(str_h);
    }
    FINN.change_balance(Dr_Heinz.get_balance());
    FINN.save_to_file(str_1 + ".txt");

    remove(str_h.c_str());
    remove(str_e.c_str());
}

//�������� ����� � ������
void battle(Hero H)
{
    system("cls");
    cout << "�� ������� �� ���������� �����";
    cout << endl << endl << "�� ������ ����� �����:";
    string str;
    srand(time(NULL));
    unsigned opr = rand() % 5;
    switch (opr)
    {
    case 0:
        cout << endl << "1-�� �� ������-���������" << endl << endl;
        str = "strong_warrior";
        fight(H.get_name(), str);
        break;
    case 1:
        cout << endl << "1-�� ����� ������� ���������� � 1-�� �������" << endl << endl;
        str = "warrior";
        fight(H.get_name(), str);
        cout << endl << endl;
        str = "archer";
        fight(H.get_name(), str);
        break;
    case 2:
        cout << endl << "2-� �������� � 1-�� �����-�������" << endl << endl;
        str = "archer";
        fight(H.get_name(), str);
        cout << endl << endl;
        fight(H.get_name(), str);
        cout << endl << endl;
        str = "weak_warrior";
        fight(H.get_name(), str);
        break;
    case 3:
        cout << endl << "1-�� �������� ������� � 1-�� �����-�������" << endl << endl;
        str = "strong_archer";
        fight(H.get_name(), str);
        cout << endl << endl;
        str = "weak_warrior";
        fight(H.get_name(), str);
        break;
    case 4:
        cout << endl << "�������� ������� � ��� �������" << endl << endl;
        str = "strong_archer";
        fight(H.get_name(), str);
        cout << endl << endl;
        str = "archer";
        fight(H.get_name(), str);
        break;
    }
    H.get_inf_file(H.get_name() + ".txt");
    cout << endl << endl << "�� ���� ����� �� ����� �����������!" << endl << "�� ������� � ���������� �����." << endl;
    H.save_to_file(H.get_name() + ".txt");
    system("pause");
    system("cls");
}