//
//  main.cpp
//  superTrunfo
//
//  Created by Danilo Ribeiro on 12/11/2017.
//  Copyright © 2017 Danilo Ribeiro. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include <limits>
#include <ctime>
#include <cstdlib>

using namespace std;

void menu();
void cinVerificador()
{
	if(cin.fail())
	{
		cin.ignore();
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

struct Carta
{
	char element[30];
	char symbol[30];
	int atomicNumber;
	double atomicWeight;
	double density;
	double melt;
	double boil;
	double abundance;
	bool superTrunfo;
	bool active;

	void build(char e[30], char symb[30], int z, double aw, double dens, double mel, double boi, double abnd, bool st, bool actv)
	{
		for(int i = 0; i <= 30; i++)
		{
			element[i] = e[i];
		}
		for(int i = 0; i <= 30; i++)
		{
			symbol[i] = symb[i];
		}

		atomicNumber = z;
		atomicWeight = aw;
		density = dens;
		melt = mel;
		boil = boi;
		abundance = abnd;
		superTrunfo = st;
		active = actv;
	}
	void choose(int pro)
	{
		switch(pro)
		{
		case 1:
			cout << "Atomic Number: " << atomicNumber << endl;
			break;
		case 2:
			cout << "Atomic Weight: " << atomicWeight << endl;
			break;
		case 3:
			cout << "Density: " << density << endl;
			break;
		case 4:
			cout << "Melt: " << melt << endl;
			break;
		case 5:
			cout << "Boil: " << boil << endl;
			break;
		case 6:
			cout << "Abundance: " << abundance << endl;
			break;
		default:
			break;
		}
	}
	void reveal()
	{
		if(active)
		{
			if(superTrunfo)
			{
				cout << "+--------------------+" << endl;
				cout << "|*** SUPER TRUNFO ***|" << endl;
			}
			cout << "+--------------------+" << endl;
			cout << "| " << element << endl;
			cout << "| " << symbol << endl;
			cout << "+--------------------+" << endl;
			cout << "| Atomic Number: " << atomicNumber << endl;
			cout << "| Atomic Weight: " << atomicWeight << endl;
			cout << "| Density: " << density << endl;
			cout << "| Melt: " << melt << endl;
			cout << "| Boil: " << boil << endl;
			cout << "| Abundance: " << abundance << endl;
			cout << "+--------------------+" << endl;
			cout << endl;
		}

	}
};

Carta cartas[120];
fstream def;
fstream slot1;
fstream slot2;
fstream slot3;

void addEditCard()
{
	char element[30];
	char symbol[30];
	int atomicNumber;
	double atomicWeight = 0.0;
	double density = 0.0;
	double melt = 0.0;
	double boil = 0.0;
	double abundance = 0.0;
	bool superTrunfo = false;
	bool active = false;
	int choose;

	do
	{
		system("cls");
		cout << "Entre com o número atomico da carta (1 até 120): ";
		cin >> atomicNumber;
		cinVerificador();
		if(atomicNumber < 1 || atomicNumber > 120)
		{
			cout << "Número atomico inválido! Tente novamente!" << endl;
			system("pause");
		}
	}
	while(!(atomicNumber > 0 && atomicNumber <= 120));


	do
	{
		system("cls");


		switch(cartas[atomicNumber - 1].active)
		{
		case false:
			cout << "Carta NÃO cadastrada!" << endl;
			cout << "0. Voltar para o menu" << endl;
			cout << "1. Adicionar nova carta" << endl;
			cout << "Opção: ";
			cin >> choose;
			cinVerificador();
			cout << choose;
			if (choose != 1 && choose != 0)
			{
				choose = 9;
			}
			break;
		case true:
			cout << "Carta JÁ cadastrada!" << endl;
			cartas[atomicNumber - 1].reveal();
			cout << "0. Voltar para o menu" << endl;
			cout << "1. Editar carta existente" << endl;
			cout << "Opção: ";
			cin >> choose;
			cinVerificador();
			if (choose == 1)
			{
				choose = 2;
			}
		default:
			break;
		}

		if(choose < 0 && choose > 2)
		{
			cout << "Opção inválida! Tente novamente!" << endl;
			system("pause");
		};

	}
	while (!(choose == 0 || choose == 1 || choose == 2));



	switch (choose)
	{
	case 0:
		menu();
		break;
	case 1:
		system("cls");
		active = true;
		cout << "Entre com o nome do elemento: ";
		cin.ignore();
		cin.getline(element, 30);
		cout << "Entre com o símbolo do elemento: ";
		cin.getline(symbol, 30);

		do
		{
			cout << "Entre com o peso atômico (> 0): ";
			cin >> atomicWeight;
			cinVerificador();
			if(atomicWeight < 0)
			{
				cout << "Peso atomico incorreto! Tente novamente!" << endl;
			}
		}
		while(!(atomicWeight > 0));

		do
		{
			cout << "Entre com a densidade (> 0): ";
			cin >> density;
			cinVerificador();
			if(density < 0)
			{
				cout << "Densidade incorreta! Tente novamente!" << endl;
			}
		}
		while(!(density > 0));

		do
		{
			cout << "Entre com a temperatura de fusão em K (> 0): ";
			cin >> melt;
			cinVerificador();
			if(melt < 0)
			{
				cout << "Temperatura incorreta! Tente novamente!" << endl;
			}
		}
		while(!(melt > 0));

		do
		{
			cout << "Entre com a temperatura de ebulição em K (> 0): ";
			cin >> boil;
			cinVerificador();
			if(boil < 0)
			{
				cout << "Temperatura incorreta! Tente novamente!" << endl;
			}
		}
		while(!(boil > 0));

		do
		{
			cout << "Entre com a abundância do elemento na terra (=> 0): ";
			cin >> abundance;
			cinVerificador();
			if(abundance < 0)
			{
				cout << "Valor de abundância incorreta! Tente novamente!" << endl;
			}
		}
		while(abundance < 0);

		do
		{
			cout << "Esta carta é um SuperTrunfo? (1-sim | 2-não): ";
			cin >> choose;
			cinVerificador();
			if(choose == 1)
			{
				superTrunfo = true;
			}
			else if(choose == 2)
			{
				superTrunfo = false;
			}
			else if(choose < 1 || choose > 2)
			{
				cout << "Opção incorreta! Tente novamente!" << endl;
			}
		}
		while (!(choose == 1 || choose == 2));

		cartas[atomicNumber - 1].build(element, symbol, atomicNumber, atomicWeight, density, melt, boil, abundance, superTrunfo, active);

		system("cls");

		cout << "Adição/Edição da carta concluída" << endl;
		cartas[atomicNumber - 1].reveal();

		system("pause");

		menu();

		break;
	case 2:
		do
		{
			system("cls");
			cout << "Qual atributo deseja editar?" << endl;
			cout << "1. Nome do elemento" << endl;
			cout << "2. Símbolo do elemento" << endl;
			cout << "3. Peso atomico" << endl;
			cout << "4. Densidade" << endl;
			cout << "5. Temperatura de fusão" << endl;
			cout << "6. Temperatura de ebulição" << endl;
			cout << "7. Abundância na terra" << endl;
			cout << "8. Se a carta é um SuperTrunfo" << endl;
			cout << "Opção: ";
			cin >> choose;
			cinVerificador();
			switch(choose)
			{
			case 1:
				cout << "Entre com o nome do elemento: ";
				cin.ignore();
				cin.getline(cartas[atomicNumber - 1].element, 30);
				break;
			case 2:
				cin.ignore();
				cout << "Entre com o símbolo do elemento: ";
				cin.getline(cartas[atomicNumber - 1].symbol, 30);
				break;
			case 3:
				do
				{
					cout << "Entre com o peso atômico (> 0): ";
					cin >> cartas[atomicNumber - 1].atomicWeight;
					cinVerificador();
					if(cartas[atomicNumber - 1].atomicWeight < 0)
					{
						cout << "Peso atomico incorreto! Tente novamente!" << endl;
					}
				}
				while(!(cartas[atomicNumber - 1].atomicWeight > 0));
				break;
			case 4:
				do
				{
					cout << "Entre com a densidade (> 0): ";
					cin >> cartas[atomicNumber - 1].density;
					cinVerificador();
					if(cartas[atomicNumber - 1].density < 0)
					{
						cout << "Densidade incorreta! Tente novamente!" << endl;
					}
				}
				while(!(cartas[atomicNumber - 1].density > 0));
				break;
			case 5:
				do
				{
					cout << "Entre com a temperatura de fusão em K (> 0): ";
					cin >> cartas[atomicNumber - 1].melt;
					cinVerificador();
					if(cartas[atomicNumber - 1].melt < 0)
					{
						cout << "Temperatura incorreta! Tente novamente!" << endl;
					}
				}
				while(!(cartas[atomicNumber - 1].melt > 0));
				break;
			case 6:
				do
				{
					cout << "Entre com a temperatura de ebulição em K (> 0): ";
					cin >> cartas[atomicNumber - 1].boil;
					cinVerificador();
					if(cartas[atomicNumber - 1].boil < 0)
					{
						cout << "Temperatura incorreta! Tente novamente!" << endl;
					}
				}
				while(!(cartas[atomicNumber - 1].boil > 0));
				break;
			case 7:
				do
				{
					cout << "Entre com a abundância do elemento na terra (=> 0): ";
					cin >> cartas[atomicNumber - 1].abundance;
					cinVerificador();
					if(cartas[atomicNumber - 1].abundance < 0)
					{
						cout << "Valor de abundância incorreta! Tente novamente!" << endl;
					}
				}
				while(cartas[atomicNumber - 1].abundance < 0);
				break;
			case 8:
				do
				{
					cout << "Esta carta é um SuperTrunfo? (1-sim | 2-não): ";
					cin >> choose;
					cinVerificador();
					if(choose == 1)
					{
						cartas[atomicNumber - 1].superTrunfo = true;
					}
					else if(choose == 2)
					{
						cartas[atomicNumber - 1].superTrunfo = false;
					}
					else if(choose < 1 || choose > 2)
					{
						cout << "Opção incorreta! Tente novamente!" << endl;
					}
				}
				while (!(choose == 1 || choose == 2));
				break;
			default:
				cout << "Opção incorreta! Tente novamente!" << endl;
				break;
			}
		}
		while(!(choose > 0 && choose < 8));
		system("cls");
		cout << "Edição da carta concluída!" << endl;
		cartas[atomicNumber - 1].reveal();
		system("pause");
		menu();
		break;
	default:
		break;
	}
}
void searchCard()
{
	int atomicNumber;

	do
	{
		system("cls");
		cout << "Entre com o número atomico da carta (1 até 120): ";
		cin >> atomicNumber;
		cinVerificador();
		if(atomicNumber < 1 || atomicNumber > 120)
		{
			cout << "Número atomico inválido! Tente novamente!" << endl;
			system("pause");
		}
	}
	while(!(atomicNumber > 0 && atomicNumber <= 120));

	if(cartas[atomicNumber - 1].active)
	{
		cartas[atomicNumber - 1].reveal();
	}
	else
	{
		cout << "Carta não cadastrada" << endl;
	}

	system("pause");
	menu();

}
void listAll()
{
	int totCards = 0;
	for (int i = 1; i <= 120; i++)
	{
		if(cartas[i - 1].active)
		{
			totCards++;
			cartas[i - 1].reveal();
		}
	}
	if(totCards == 0)
	{
		cout << "Não existem cartas cadastradas!" << endl;
	}
	else
	{
		cout << "Total de cartas no Deck: " << totCards << endl;
	}
	system("pause");
	menu();
}
void delCard()
{
	int choose;
	int atomicNumber;

	do
	{
		system("cls");
		cout << "Entre com o número atomico da carta (1 até 120): ";
		cin >> atomicNumber;
		cinVerificador();
		if(atomicNumber < 1 || atomicNumber > 120)
		{
			cout << "Número atomico inválido! Tente novamente!" << endl;
			system("pause");
		}
	}
	while(!(atomicNumber > 0 && atomicNumber <= 120));

	if(cartas[atomicNumber - 1].active)
	{
		cartas[atomicNumber - 1].reveal();
	}
	else
	{
		system("cls");
		cout << "Carta não cadastrada" << endl;
		system("pause");
		menu();
	}

	do
	{
		cout << "Tem certeza que deseja excluir esta carta? (1-sim | 2-não): ";
		cin >> choose;
		cinVerificador();
		if(choose == 1)
		{
			cartas[atomicNumber - 1].build("", "", 0, 0, 0, 0, 0, 0, false, false);
		}
		else if(choose == 2)
		{
			menu();
		}
		else if(choose < 1 || choose > 2)
		{
			cout << "Opção incorreta! Tente novamente!" << endl;
		}
	}
	while (!(choose == 1 || choose == 2));
	system("cls");
	cout << "Carta excluída com sucesso" << endl;
	system("pause");
	menu();
}
void padrao()
{
	def.open("def.txt", ios::in | ios::binary);
	if(!def.is_open())
	{
		system("cls");
		cout << "Impossível abrir o arquivo! Arquivo inexistente ou danificado!" << endl;
		system("pause");
	}

	def.seekg(0, def.beg);
	while(def.read((char *) &cartas, sizeof(cartas)))
	{
	}

	def.clear();
	def.close();
	system("cls");
	cout << "Cartas padrão carregadas!" << endl;
	system("pause");
	menu();
}
void limpar()
{
	for(int i = 1; i <= 120; i++)
	{
		cartas[i - 1].build("", "", 0, 0, 0, 0, 0, 0, false, false);
	}
	system("cls");
	cout << "Todas as cartas foram excluídas!" << endl;
	system("pause");
	menu();
}
void saveDeck()
{
	int choose;
	do
	{
		system("cls");
		cout << "Salvar Deck atual?" << endl;
		cout << "0. Voltar para o menu" << endl;
		cout << "1. Slot 1" << endl;
		cout << "2. Slot 2" << endl;
		cout << "3. Slot 3" << endl;
		cout << "Opção: ";
		cin >> choose;
		cinVerificador();

		switch(choose)
		{
		case 0:
			menu();
			break;
		case 1:
			slot1.open("slot1.txt", ios::in | ios::out | ios::binary);
			if (!slot1.is_open())
			{
				slot1.open("slot1.txt", ios::in | ios::out | ios::trunc | ios::binary);
			}
			else
			{
				do
				{
					system("cls");
					cout << "Slot já usado! Deseja substituir? (1-sim | 2-não): ";
					cin >> choose;
					cinVerificador();
					switch(choose)
					{
					case 1:
						slot1.close();
						slot1.open("slot1.txt", ios::in | ios::out | ios::trunc | ios::binary);
						break;
					case 2:
						slot1.close();
						system("cls");
						cout << "O Deck não foi salvo" << endl;
						system("pause");
						menu();
						break;
					default:
						system("cls");
						cout << "Opção Invalida!" << endl;
						system("pause");
						choose = 9;
						break;
					}
				}
				while(!(choose == 1 || choose == 2));

			}
			slot1.seekp(0, slot1.beg);
			slot1.write((char *) &cartas, sizeof(cartas));

			slot1.close();
			system("cls");
			cout << "Deck salvo com sucesso no slot 01!" << endl;
			system("pause");
			menu();
			break;
		case 2:
			slot2.open("slot2.txt", ios::in | ios::out | ios::binary);
			if (!slot2.is_open())
			{
				slot2.open("slot2.txt", ios::in | ios::out | ios::trunc | ios::binary);
			}
			else
			{
				do
				{
					system("cls");
					cout << "Slot já usado! Deseja substituir? (1-sim | 2-não): ";
					cin >> choose;
					cinVerificador();
					switch(choose)
					{
					case 1:
						slot2.close();
						slot2.open("slot2.txt", ios::in | ios::out | ios::trunc | ios::binary);
						break;
					case 2:
						slot2.close();
						system("cls");
						cout << "O Deck não foi salvo" << endl;
						system("pause");
						menu();
						break;
					default:
						system("cls");
						cout << "Opção Invalida!" << endl;
						system("pause");
						choose = 9;
						break;
					}
				}
				while(!(choose == 1 || choose == 2));

			}
			slot2.seekp(0, slot2.beg);
			slot2.write((char *) &cartas, sizeof(cartas));

			slot2.close();
			system("cls");
			cout << "Deck salvo com sucesso no slot 02!" << endl;
			system("pause");
			menu();
			break;
		case 3:
			slot3.open("slot3.txt", ios::in | ios::out | ios::binary);
			if (!slot3.is_open())
			{
				slot3.open("slot3.txt", ios::in | ios::out | ios::trunc | ios::binary);
			}
			else
			{
				do
				{
					system("cls");
					cout << "Slot já usado! Deseja substituir? (1-sim | 2-não): ";
					cin >> choose;
					cinVerificador();
					switch(choose)
					{
					case 1:
						slot3.close();
						slot3.open("slot3.txt", ios::in | ios::out | ios::trunc | ios::binary);
						break;
					case 2:
						slot3.close();
						system("cls");
						cout << "O Deck não foi salvo" << endl;
						system("pause");
						menu();
						break;
					default:
						system("cls");
						cout << "Opção Invalida!" << endl;
						system("pause");
						choose = 9;
						break;
					}
				}
				while(!(choose == 1 || choose == 2));

			}
			slot3.seekp(0, slot3.beg);
			slot3.write((char *) &cartas, sizeof(cartas));

			slot3.close();
			system("cls");
			cout << "Deck salvo com sucesso no slot 03!" << endl;
			system("pause");
			menu();
			break;
		default:
			cout << "Opção inválida!" << endl;
			system("pause");
			break;
		}
	}
	while(!(choose == 0 || choose == 1 || choose == 2 || choose == 3));
}
void loadDeck()
{
	int choose;
	do
	{
		system("cls");
		cout << "Carregar Deck salvo?" << endl;
		cout << "0. Voltar para o menu" << endl;
		cout << "1. Slot 1" << endl;
		cout << "2. Slot 2" << endl;
		cout << "3. Slot 3" << endl;
		cout << "4. Carregar Deck padrão" << endl;
		cout << "Opção: ";
		cin >> choose;
		cinVerificador();

		switch(choose)
		{
		case 0:
			menu();
			break;
		case 1:
			slot1.open("slot1.txt", ios::in | ios::out | ios::binary);
			if (!slot1.is_open())
			{
				system("cls");
				cout << "Não existe Deck salvo neste slot!" << endl;
				system("pause");
				menu();
			}
			else
			{
				slot1.seekg(0, slot1.beg);
				while(slot1.read((char *) &cartas, sizeof(cartas)))
				{
				}
				slot1.clear();
			}
			slot1.close();
			system("cls");
			cout << "Deck carregado com sucesso!" << endl;
			system("pause");
			menu();
			break;
		case 2:
			slot2.open("slot2.txt", ios::in | ios::out | ios::binary);
			if (!slot2.is_open())
			{
				system("cls");
				cout << "Não existe Deck salvo neste slot!" << endl;
				system("pause");
				menu();
			}
			else
			{
				slot2.seekg(0, slot2.beg);
				while(slot2.read((char *) &cartas, sizeof(cartas)))
				{
				}
				slot2.clear();
			}
			slot2.close();
			system("cls");
			cout << "Deck carregado com sucesso!" << endl;
			system("pause");
			menu();
			break;
		case 3:
			slot3.open("slot3.txt", ios::in | ios::out | ios::binary);
			if (!slot3.is_open())
			{
				system("cls");
				cout << "Não existe Deck salvo neste slot!" << endl;
				system("pause");
				menu();
			}
			else
			{
				slot3.seekg(0, slot3.beg);
				while(slot3.read((char *) &cartas, sizeof(cartas)))
				{
				}
				slot3.clear();
			}
			slot3.close();
			system("cls");
			cout << "Deck carregado com sucesso!" << endl;
			system("pause");
			menu();
			break;
		case 4:
			padrao();
			break;
		default:
			cout << "Opção inválida!" << endl;
			system("pause");
			break;
		}
	}
	while(!(choose == 0 || choose == 1 || choose == 2 || choose == 3 || choose == 4));
}
void play()
{

	srand(time(0));


	Carta shuttleDeck[120];
	Carta deckP1[60];
	Carta deckP2[60];

	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int choose = 0;
	int scoreP1 = 0;
	int scoreP2 = 0;
	double p1aux = 0;
	double p2aux = 0;
	bool p1ST = false;
	bool p2ST = false;
	string atrib[6] = {"Peso atomico", "Densidade", "Temperatura de fusão", "Temperatura de ebulição", "Abundância na terra"};

	for(i = 0; i < 120; i++)
	{
		if(cartas[i].active)
		{
			shuttleDeck[j] = cartas[i];
			j++;
		};
	}

	for(i = 0; i < j; i++)
	{
		int index = rand() % j;

		Carta temp = shuttleDeck[i];
		shuttleDeck[i] = shuttleDeck[index];
		shuttleDeck[index] = temp;
	}

	for(i = 0; i < j; i++)
	{
		if(i % 2 == 0)
		{
			deckP1[k] = shuttleDeck[i];
			k++;
		}
		else
		{
			deckP2[l] = shuttleDeck[i];
			l++;
		}
	}

	if ((k < 1 && l < 1) || k == 0 || l == 0)
	{
		system("cls");
		cout << "Cartas insuficientes para jogar!" << endl;
		system("pause");
		menu();
	}

	if(k > l)
	{
		i = k - abs(k - l) - 1;
	}
	else if(k < l)
	{
		i = l - abs(k - 1) - 1;
	}
	else
	{
		i = k - 1;
	}

	system("cls");
	cout << endl;
	cout << "+--------------------+" << endl;
	cout << "|                    |" << endl;
	cout << "|                    |" << endl;
	cout << "|                    |" << endl;
	cout << "|    Embaralhando    |" << endl;
	cout << "|                    |" << endl;
	cout << "|                    |" << endl;
	cout << "|                    |" << endl;
	cout << "+--------------------+" << endl;
	cout << "|*** SUPER TRUNFO ***|" << endl;
	cout << "+--------------------+" << endl;
	cout << "|                    |" << endl;
	cout << "|                    |" << endl;
	cout << "|                    |" << endl;
	cout << "|    Distribuindo    |" << endl;
	cout << "|                    |" << endl;
	cout << "|                    |" << endl;
	cout << "|                    |" << endl;
	cout << "+--------------------+" << endl;
	cout << endl;
	system("pause");

	do
	{
		do
		{
			system("cls");
			cout << "Player 1, certifique-se que o seu oponete não está olhando!" << endl;
			cout << "Digite 1553 para continuar: ";
    		cin >> choose;
			cinVerificador();
			if(choose != 1553)
			{
				cout << "Opção Inválida!" << endl;
			}
		}
		while(!(choose == 1553));
		system("cls");
		cout << "Player 1, esta é sua carta:" << endl;
		deckP1[i].reveal();
		do
		{
			cout << "Escolha um dos atributos:" << endl;
			cout << endl;
			cout << "1. Peso atomico" << endl;
			cout << "2. Densidade" << endl;
			cout << "3. Temperatura de fusão" << endl;
			cout << "4. Temperatura de ebulição" << endl;
			cout << "5. Abundância na terra" << endl;
			cout << endl;
			cout << "Opção: ";
			cin >> choose;
			cinVerificador();
			p1aux = 0;
			p1ST = deckP1[i].superTrunfo;
			switch(choose)
			{
			case 1:
				p1aux = deckP1[i].atomicWeight;
				p2aux = deckP2[i].atomicWeight;
				break;
			case 2:
				p1aux = deckP1[i].density;
				p2aux = deckP2[i].density;
				break;
			case 3:
				p1aux = deckP1[i].melt;
				p2aux = deckP2[i].melt;
				break;
			case 4:
				p1aux = deckP1[i].boil;
				p2aux = deckP2[i].boil;
				break;
			case 5:
				p1aux = deckP1[i].abundance;
				p2aux = deckP2[i].abundance;
				break;
			default:
				cout << "Opção incorreta! Tente novamente!" << endl;
				choose = 9;
				system("cls");
				cout << "Player 1, esta é sua carta:" << endl;
				deckP1[i].reveal();
				break;
			}
		}
		while(!(choose > 0 && choose <= 5));

		system("cls");
		cout << "Player 1, chame o Player 2" << endl;
		system("pause");

		p2ST = deckP2[i].superTrunfo;

		if(p1ST == true && p2ST == false)
		{
			scoreP1++;
			system("cls");
			cout << "Player 1 ganha! Ninguém bate um SuperTrunfo" << endl;
			cout << "--- Player 1 ---" << endl;
			deckP1[i].reveal();
			cout << "--- Player 2 ---" << endl;
			deckP2[i].reveal();
			system("pause");
		}
		else if(p1ST == false && p2ST == true)
		{
			scoreP2++;
			system("cls");
			cout << "Player 2 ganha! Ninguém bate um SuperTrunfo" << endl;
			cout << "--- Player 2 ---" << endl;
			deckP2[i].reveal();
			cout << "--- Player 1 ---" << endl;
			deckP1[i].reveal();
			system("pause");
		}
		else if(p1ST && p2ST)
		{
			system("cls");
			cout << "Ninguém pontuou nesta rodada! 2 SuperTrunfos, qual a probabilidade?" << endl;
			cout << "--- Player 1 ---" << endl;
			deckP1[i].reveal();
			cout << "--- Player 2 ---" << endl;
			deckP2[i].reveal();
			system("pause");
		}
		else
		{
			if (p1aux > p2aux)
			{
				scoreP1++;
				system("cls");
				cout << "Player 1 ganha!" << endl;
				cout << atrib[choose - 1] << ": " << p1aux << endl;
				cout << "--- Player 1 ---" << endl;
				deckP1[i].reveal();
				cout << "--- Player 2 ---" << endl;
				deckP2[i].reveal();
				system("pause");
			}
			else if(p1aux < p2aux)
			{
				scoreP2++;
				system("cls");
				cout << "Player 2 ganha!" << endl;
				cout << atrib[choose - 1] << ": " << p2aux << endl;
				cout << "--- Player 2 ---" << endl;
				deckP2[i].reveal();
				cout << "--- Player 1 ---" << endl;
				deckP1[i].reveal();
				system("pause");
			}
			else if(p1aux == p2aux)
			{
				system("cls");
				cout << "Ninguém pontuou nesta rodada!" << endl;
				system("pause");
			}
		}

		i--;
		system("cls");
		cout << "+--------------------+" << endl;
		cout << "|*** SUPER TRUNFO ***|" << endl;
		cout << "+--------------------+" << endl;
		cout << "|    Placar atual    |" << endl;
		cout << "|                    |" << endl;
		cout << "+----P1: " << scoreP1 << endl;
		cout << "+----P2: " << scoreP2 << endl;
		cout << "|                    |" << endl;
		cout << "+--------------------+" << endl;
		system("pause");
		if(i < 0)
		{
			system("cls");
			cout << "Acabaram todas as cartas!" << endl;
			system("pause");
			menu();
		}

		do
		{
			system("cls");
			cout << "Agora é a vez do Player 2!" << endl;
			cout << "Player 2, certifique-se que o seu oponete não está olhando!" << endl;
			cout << "Digite 4453 para continuar: ";
			cin >> choose;
			cinVerificador();
			if(choose != 4453)
			{
				cout << "Opção Inválida!" << endl;
			}
		}
		while(!(choose == 4453));
		system("cls");
		cout << "Player 2, esta é sua carta:" << endl;
		deckP2[i].reveal();
		do
		{
			cout << "Escolha um dos atributos:" << endl;
			cout << endl;
			cout << "1. Peso atomico" << endl;
			cout << "2. Densidade" << endl;
			cout << "3. Temperatura de fusão" << endl;
			cout << "4. Temperatura de ebulição" << endl;
			cout << "5. Abundância na terra" << endl;
			cout << endl;
			cout << "Opção: ";
			cin >> choose;
			cinVerificador();
			p2aux = 0;
			p2ST = deckP2[i].superTrunfo;
			switch(choose)
			{
			case 1:
				p1aux = deckP1[i].atomicWeight;
				p2aux = deckP2[i].atomicWeight;
				break;
			case 2:
				p1aux = deckP1[i].density;
				p2aux = deckP2[i].density;
				break;
			case 3:
				p1aux = deckP1[i].melt;
				p2aux = deckP2[i].melt;
				break;
			case 4:
				p1aux = deckP1[i].boil;
				p2aux = deckP2[i].boil;
				break;
			case 5:
				p1aux = deckP1[i].abundance;
				p2aux = deckP2[i].abundance;
				break;
			default:
				cout << "Opção incorreta! Tente novamente!" << endl;
				choose = 9;
				system("cls");
				cout << "Player 2, esta é sua carta:" << endl;
				deckP2[i].reveal();
				break;
			}
		}
		while(!(choose > 0 && choose <= 5));

		system("cls");
		cout << "Player 2, chame o Player 1" << endl;
		system("pause");

		p1ST = deckP1[i].superTrunfo;

		if(p2ST == true && p1ST == false)
		{
			scoreP2++;
			system("cls");
			cout << "Player 2 ganha! Ninguém bate um SuperTrunfo" << endl;
			cout << "--- Player 2 ---" << endl;
			deckP2[i].reveal();
			cout << "--- Player 1 ---" << endl;
			deckP1[i].reveal();
			system("pause");
		}
		else if(p2ST == false && p1ST == true)
		{
			scoreP1++;
			system("cls");
			cout << "Player 1 ganha! Ninguém bate um SuperTrunfo" << endl;
			cout << "--- Player 1 ---" << endl;
			deckP1[i].reveal();
			cout << "--- Player 2 ---" << endl;
			deckP2[i].reveal();
			system("pause");
		}
		else if(p2ST && p1ST)
		{
			system("cls");
			cout << "Ninguém pontuou nesta rodada! 2 SuperTrunfos, qual a probabilidade?" << endl;
			cout << "--- Player 2 ---" << endl;
			deckP2[i].reveal();
			cout << "--- Player 1 ---" << endl;
			deckP1[i].reveal();
			system("pause");
		}
		else
		{
			if (p2aux > p1aux)
			{
				scoreP2++;
				system("cls");
				cout << "Player 2 ganha!" << endl;
				cout << atrib[choose - 1] << ": " << p2aux << endl;
				cout << "--- Player 2 ---" << endl;
				deckP2[i].reveal();
				cout << "--- Player 1 ---" << endl;
				deckP1[i].reveal();
				system("pause");
			}
			else if(p2aux < p1aux)
			{
				scoreP1++;
				system("cls");
				cout << "Player 1 ganha!" << endl;
				cout << atrib[choose - 1] << ": " << p1aux << endl;
				cout << "--- Player 1 ---" << endl;
				deckP1[i].reveal();
				cout << "--- Player 2 ---" << endl;
				deckP2[i].reveal();
				system("pause");
			}
			else if(p2aux == p1aux)
			{
				system("cls");
				cout << "Ninguém pontuou nesta rodada!" << endl;
				system("pause");
			}
		}

		i--;

		do
		{
			system("cls");
			cout << "+--------------------+" << endl;
			cout << "|*** SUPER TRUNFO ***|" << endl;
			cout << "+--------------------+" << endl;
			cout << "|    Placar atual    |" << endl;
			cout << "|                    |" << endl;
			cout << "+----P1: " << scoreP1 << endl;
			cout << "+----P2: " << scoreP2 << endl;
			cout << "|                    |" << endl;
			cout << "+--------------------+" << endl;
			cout << "Jogar mais uma? (1-sim | 2-não)" << endl;
			cout << "Opção: ";
			cin >> choose;
			cinVerificador();

			switch(choose)
			{
			case 1:
				system("cls");
				cout << "Pegando outra carta!" << endl;
				system("pause");
				break;
			case 2:
				menu();
				break;
			default:
				system("cls");
				cout << "Opção inválida!" << endl;
				system("pause");
				break;
			}
		}
		while(!(choose == 1));
		if(i == 0)
		{
			system("cls");
			cout << "Acabaram todas as cartas!" << endl;
			cout << "Reembaralhando e zerando o contador!" << endl;
			system("pause");
			menu();
		}
	}
	while(1);
}
void menu()
{
	int menuOp = 0;
	do
	{
		system("cls");
		cout << "+----------------------------------------------------------------+" << endl;
		cout << "|                                                                |" << endl;
		cout << "|                       SUPER TRUNFO QUIMICA                     |" << endl;
		cout << "|                                                                |" << endl;
		cout << "+----------------------------------------------------------------+" << endl;
		cout << "|                              MENU                              |" << endl;
		cout << "+----------------------------------------------------------------+" << endl;
		cout << "| Selecione a opção desejada                                     |" << endl;
		cout << "|  1.  Jogar                                                     |" << endl;
		cout << "|  2.  Adicionar/Editar carta                                    |" << endl;
		cout << "|  3.  Excluir carta                                             |" << endl;
		cout << "|  4.  Listar todas as cartas                                    |" << endl;
		cout << "|  5.  Pesquisar carta                                           |" << endl;
		cout << "|  6.  Carregar deck                                             |" << endl;
		cout << "|  7.  Salvar deck                                               |" << endl;
		cout << "|  8.  Excluir deck atual                                        |" << endl;
		cout << "|  9.  Sair do programa                                          |" << endl;
		cout << "+----------------------------------------------------------------+" << endl;
		cout << "Opção: ";
		cin >> menuOp;

		cinVerificador();

		switch(menuOp)
		{
		case 1:
			play();
			break;
		case 2:
			addEditCard();
			break;
		case 3:
			delCard();
			break;
		case 4:
			listAll();
			break;
		case 5:
			searchCard();
			break;
		case 6:
			loadDeck();
			break;
		case 7:
			saveDeck();
			break;
		case 8:
			limpar();
			break;
		case 9:
			cout << "\nTchau!\n";
			exit(EXIT_SUCCESS);
			break;
		default:
			cout << "Opção inválida! Tente novamente" << endl;
			system("pause");
			break;
		}
	}
	while (!(menuOp == 1 || menuOp == 2 || menuOp == 3 || menuOp == 4 || menuOp == 5 || menuOp == 6 || menuOp == 7 || menuOp == 8 || menuOp == 9 || menuOp == 10));
}

int main()
{
	setlocale(LC_ALL, "Portuguese");

	menu();
	return 0;
}