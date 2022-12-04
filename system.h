#pragma once
#include "character.h"
#include "foundation.h"

//Создание нового игрока
void new_game(string str);

//Поход в магазин
void go_to_store(Hero H);

//Битва Enemy и Hero
void fight(string str_1, string str_2);

//сражения героя и врагов
void battle(Hero H);