#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string comeback;
	string path = "history.txt";
	
	fstream fs;

	//меню
menu:
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~ Game of Heroes ~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\tStart" << endl;
	cout << "\t\tHistory" << endl;
	cout << "\t\tAbout" << endl;
	cout << "\t\tExit" << endl;

	cout << "What do you want? : ";
	string choose_menu;
	cin >> choose_menu;


	//починаєм грати
	if (choose_menu == "Start")
	{
		srand(time(NULL));

		vector<string> NamePlayer = { "Yura","Maks","Igor","Anton","Alex","Vlad","Turar","Boris","Nastya","Volodya" };				//можливі гравці
		vector<string> NameHero = { "Sven","Zeus","Kunkka","Pangolier","Lycan","Underlord","Pudge","Huskar","Sniper","Tiny" };	//можливі герої

		vector<string> NamePlayerTeamOne;							//для формування команд
		vector<string> NamePlayerTeamTwo;

		vector<int> Rank_after_game_TeamOne;						//для обрахунку рейтингу після гри
		vector<int> Rank_after_game_TeamTwo;

		int Rank[10] = { 100,200,150,250,175,225,75,125,200,300 };			//рейтинг гравців

		int Damage[10] = { 100,200,250,150,175,235,400,500,550,450 };		//характеристики героїв
		int HP[10] = { 500,700,800,950,600,900,550,700,800,990 };


		int random;							//змінна для випадкового отримання гравця та героя

		int TeamOneHP = 0;						//змінні для загальних НР та Damage команди (№1)							
		int TeamTwoHP = 0;

		int TeamOneDamage = 0;					//змінні для загальних НР та Damage команди (№2)
		int TeamTwoDamage = 0;

		int rezult_hp_one, rezult_hp_two;

		string Winner = ""; //змінна для зберігання назви команди, що перемогла

		cout << "------------Team Natus Vincere-------------" << endl << "Players: " << endl;

		bool check_players[10] = { false };			//масиви для усунення повторень гравців
		bool check_heroes[10] = { false };			//масиви для усунення повторень героїв

		int n;										//змінна для перевірки зайнятості позиції у масивах усунення повторень
		for (int i = 0; i < 5; ++i)
		{
			while (check_players[n = rand() % 10]);		//перевірка повторень гравців
			check_players[n] = true;
			random = n;

			NamePlayerTeamOne.push_back(NamePlayer[random]);		//додавання в команду гравців
			Rank_after_game_TeamOne.push_back(Rank[random]);		//додавання в команду рейтингу гравців

			cout << "\tName: " << NamePlayer[random] << "\t" << "Rank: " << Rank[random] << endl;
		}
		cout << "Heroes: " << endl;

		for (int i = 0; i < 5; ++i)
		{
			while (check_heroes[n = rand() % 10]);			//перевірка повторень героїв
			check_heroes[n] = true;
			random = n;

			TeamOneDamage += Damage[random];				//формування загальних характеристик команди
			TeamOneHP += HP[random];

			cout << "\tName: " << NameHero[random] << "\t" << "HP: " << HP[random] << "\t" << "Damage: " << Damage[random] << endl;

		}

		cout << "-------------------------------------------" << endl;
		cout << "----------------Team Liquid----------------" << endl << "Players: " << endl;

		for (int j = 0; j < 5; ++j)
		{
			while (check_players[n = rand() % 10]);				//перевірка повторень гравців
			check_players[n] = true;
			random = n;

			NamePlayerTeamTwo.push_back(NamePlayer[random]);		//додавання в команду гравців
			Rank_after_game_TeamTwo.push_back(Rank[random]);		//додавання в команду рейтингу гравців

			cout << "\tName: " << NamePlayer[random] << "\t" << "Rank: " << Rank[random] << endl;
		}
		cout << "Heroes: " << endl;
		for (int j = 0; j < 5; ++j)
		{
			while (check_heroes[n = rand() % 10]);				//перевірка повторень героїв
			check_heroes[n] = true;
			random = n;

			TeamTwoDamage += Damage[random];					//формування загальних характеристик команди
			TeamTwoHP += HP[random];

			cout << "\tName: " << NameHero[random] << "\t" << "HP: " << HP[random] << "\t" << "Damage: " << Damage[random] << endl;
		}

		cout << "-------------------------------------------" << endl;

		cout << "Natus Vincere " << "\tAll Hp: " << TeamOneHP << "\tAll Damage: " << TeamOneDamage << endl;		//підрахнок загальної кількості НР та Damage команд
		cout << "Liquid " << "\t\tAll Hp: " << TeamTwoHP << "\tAll Damage: " << TeamTwoDamage << endl;
		cout << endl;

		rezult_hp_one = TeamOneHP - TeamTwoDamage;											//обрахунок кількості НР після атак команд
		rezult_hp_two = TeamTwoHP - TeamOneDamage;

		(rezult_hp_one > rezult_hp_two) ? Winner = "Natus Vincere" : Winner = "Luquid";   //перевірка переможця

		cout << "-------------------------------------------" << endl;
		cout << "*-*-*-*-*-* Team winner: " << Winner << " *-*-*-*-*-*" << endl;	//вивід переможця
		cout << "-------------------------------------------" << endl;

		//розподіл рейтингу (+-25)
		if (Winner == "Natus Vincere")
		{
			for (int i = 0; i < 5; i++)											//якщо перемогла команда №1,																
			{																	//то гравцям цієї команди до рейтингу + 25
				Rank_after_game_TeamOne[i] = Rank_after_game_TeamOne[i] + 25;
			}
			for (int j = 0; j < 5; j++)											// а гравцям іншої команди -25 від рейтингу
			{
				Rank_after_game_TeamTwo[j] = Rank_after_game_TeamTwo[j] - 25;
			}
		}
		else
		{                                                                       //аналогічно, якщо перемогла команда №2
			for (int i = 0; i < 5; i++)
			{
				Rank_after_game_TeamTwo[i] = Rank_after_game_TeamTwo[i] + 25;
			}
			for (int j = 0; j < 5; j++)
			{
				Rank_after_game_TeamOne[j] = Rank_after_game_TeamOne[j] - 25;
			}
		}
		//вивід команд та рейтингу після
		cout << "___________ Teams after the game __________" << endl;
		cout << "-------------- Natus Vincere --------------" << endl << "Players: " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "\tName: " << NamePlayerTeamOne[i] << "\tRank: " << Rank_after_game_TeamOne[i] << endl;

		}

		cout << "-------------- Team Liquid ----------------" << endl << "Players: " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "\tName: " << NamePlayerTeamTwo[i] << "\tRank: " << Rank_after_game_TeamTwo[i] << endl;

		}
		cout << "___________________________________________" << endl;

		//продовження гри або кінець	
		string choose;

		cout << "Continue the game? (y/n): ";
		cin >> choose;

		if (choose == "y")
		{
			fs.open(path, fstream::in | fstream::out | fstream::app);
			if (!fs.is_open())
			{
				cout << "Error!!! The session was not recorded!!" << endl;
			}
			
			fs << "-------------- Natus Vincere --------------" << endl;

			for (int i = 0; i < 5; i++)
			{
				fs << "\tName: " << NamePlayerTeamOne[i] << "\tRank: " << Rank_after_game_TeamOne[i] << endl;
			}

			fs << "-------------- Team Liquid ----------------" << endl;

			for (int i = 0; i < 5; i++)
			{
				fs << "\tName: " << NamePlayerTeamTwo[i] << "\tRank: " << Rank_after_game_TeamTwo[i] << endl;
			}
			fs << "*******************************************" << endl;
			fs << "\t\tWinner: " << Winner << endl;
			fs << "*******************************************" << endl;

			fs.close();
			system("cls");
			goto menu;
		}
		else if (choose == "n")
		{
			system("cls");
			cout << "Goodbye!!!" << endl;
			system("pause");
			return 0;
		}
	}

	//інформація про гру
	if (choose_menu == "About")
	{
		cout << "Two teams are created, in which 5 players are randomly selected." << endl;
		cout << "Each player is randomly assigned one of the available characters.HP and" << endl;
		cout << "Damage per team is calculated by summing the corresponding scores of the" << endl;
		cout << "team heroes. The total number of HP and Damage per team is calculated by" << endl;
		cout << "summing the corresponding scores of the team heroes. The winning team is" << endl;
		cout << "determined: The Damage of the opposing team is subtracted from the HP team," << endl;
		cout << "after which the team with the most HP left is considered the winner." << endl << endl;
		
		cout << "Go back? (y)";
		cin >> comeback;

		while (comeback != "y")
		{
			cout << "Error!!!" << endl;
			cin >> comeback;
		}
		if (comeback == "y")
		{
			system("cls");
			goto menu;
		}
	}

	//історія ігор
	if (choose_menu == "History")
	{
		fs.open(path, fstream::in);

		while (!fs.eof())
			{
				string msg = "";
				getline(fs, msg);
				cout << msg << endl;
			}
	fs.close();

	cout << "Go back? (y|n)";
	cin >> comeback;

	if (comeback == "y")
		{
			system("cls");
			goto menu;
		}
		else if (comeback == "n")
			{
				return 0;
			}
	}

	//вихід з гри
	if (choose_menu == "Exit")
	{
		cout << "Goodbye, my friend!";
			return 0;
	}
	
}