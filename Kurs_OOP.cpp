#include"character.h"
#include "system.h"
#include "foundation.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int opred = 0, end_cicle = 0;
    string name_pers;
    Hero h(0);
    cout << "Добро пожаловать в игру!" << endl;
    cout << endl << endl << "Введите:";
    cout << endl << "1 - если хотите начать новую игру";
    cout << endl << "2 - если хотите загрузить своего персонажа";
    cout << endl << "3 - если хотите удалить своего старого персонажа и начать новую игру";
    cout << endl << "любое другое число - если хотите выйти из игры";
    cout << endl << "Ввод: ";
    cin >> opred;
    if ((opred < 1) || (opred > 3))
        opred = 4;
    while (end_cicle != 1)
    {
        switch (opred)
        {
        case 3:
            cout << endl << endl << "Введите имя старого персонажа.";
            cout << endl << "Ввод: ";
            cin >> name_pers;
            remove((name_pers + ".txt").c_str());
        case 1:
            cout << endl << endl << "Введите имя нового персонажа.";
            cout << endl << "Ввод: ";
            cin >> name_pers;
            new_game(name_pers);
            h.get_inf_file(name_pers + ".txt");
            end_cicle = 1;
            break;
        case 2:
            cout << endl << endl << "Введите имя своего персонажа.";
            cout << endl << "Ввод: ";
            cin >> name_pers;
            h.get_inf_file(name_pers + ".txt");
            if(h.get_name() != name_pers)
                end_cicle = 0;
            else
                end_cicle = 1;
            break;
        case 4:
            cout << endl << "Выход из игры.";
            exit(0);
            break;
        }
    }
    end_cicle = 0;
    
    while (end_cicle != 1)
    {
        h.get_inf_file(h.get_name() + ".txt");
        cout << "Введите:";
        cout << endl << "1 - если хотите узнать информацию о Вашем персонаже";
        cout << endl << "2 - если хотите вступить в новый бой";
        cout << endl << "3 - если хотите отправиться в магазин";
        cout << endl << "любое другое число - если хотите выйти из игры";
        cout << endl << "Ввод: ";
        cin >> opred;
        if ((opred < 1) || (opred > 3))
            opred = 4;
        switch (opred)
        {
        case 1:
            h.print_info();
            cout << endl << endl;
            break;
        case 2:
            battle(h);
            break;
        case 3:
            go_to_store(h);
            break;
        case 4:
            h.save_to_file(h.get_name() + ".txt");
            cout << endl << "Выход из игры.";
            end_cicle = 1;
            break;
        }
    }
    return 0;
}