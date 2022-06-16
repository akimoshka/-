#include <iostream> 
#include <string> 
#include <iomanip>
#include <fstream>

using namespace std;

bool is_letter(char a) {
	string alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	bool flag = 0;
	for (int i = 0; i < alphabet.size(); i++)
	{
		if (alphabet[i] == a)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1) return true;
	else return false;
}

int main() {

	setlocale(LC_ALL, "Russian");

	string alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	string key = "вектор";
	bool ans_1;

	cout << "\t\tМЕНЮ\n\n";
	cout << "\t1 - расшивровать текст в файле лаба2.txt\n";
	cout << "\t0 - закрыть программу\n\n";
	cout << "\t\tВведите здесь - ";
	cin >> ans_1;

	if (ans_1 == 1)
	{
		system("cls");

		ifstream file("лаба2.txt");

		if (!file)
		{
			cout << "Файл не открыт!\n";
		}
		else
		{
			string txt, txt_decode;
			char sym;
			int num_sym_code = 0, num_sym_key = 0, num_sym_message;
			int kol = 0;
			while (getline(file, txt))
			{
				for (int i = 0; i < txt.length(); i++) // идем по всем символам каждой строчки зашифровонного сообщения
				{

					if (is_letter(txt[i]))
					{

						for (int j = 0; j < alphabet.length(); j++) // находим цифру зашифровонного символа в русском алфавите
						{
							if (alphabet[j] == txt[i])
							{
								num_sym_code = j;

								break;
							}
						}
						for (int j = 0; j < alphabet.length(); j++) // находим цифру символа ключа в русском алфавите
						{
							if (alphabet[j] == key[kol % key.length()])
							{
								num_sym_key = j;

								break;
							}
						}
						num_sym_message = num_sym_code - num_sym_key; // номер символа расшифрованного сообщения

						if (num_sym_message < 0) // номер символа расшифрованного сообщения может быть отрицательным
						{
							num_sym_message += alphabet.length(); // из-за этого надо прибавить кол-во букв в русском алф.
						}
						sym = alphabet[num_sym_message % alphabet.length()]; // символ расшифрованного сообщения

						txt_decode += sym;

						kol++; // расшифрововать надо только буквы. поэтому создаем переменную kol с помощью которой и будем сравнивать ключ с зашифрованным сообщением
					}
					else
					{
						txt_decode += txt[i];
					}

				}

				txt_decode += '\n';

			}


			int ans_2;
			cout << "1 - Показать расшифрованное сообщение на экране\n0 - Записать расшифрованное сообщение в файл\n\tВведите здесь - ";
			cin >> ans_2;

			if (ans_2 == 1)
			{
				bool ans_3;
				system("cls");
				cout << txt_decode << endl;

				cout << "Хочешь ли ты ещё записать сообщение в файл?\n1 - да\n0 - нет\n\tВведите здесь - ";
				cin >> ans_3;

				if (ans_3 == 1)
				{
					string dir;

					system("cls");

					cout << "Введите директорию файла - ";

					cin >> dir;
					ofstream out;
					out.open(dir);
					if (!out.is_open())
					{
						cout << "Ошибка открытия файла!\n";
					}
					else
					{
						out << txt_decode;
						cout << "\nУспешно!!!\n\n";
					}

					cout << "Пока!!!!!\n";
					out.close();

				}
				else
				{
					system("cls");
					cout << "Пока!!!!!\n";
				}
			}
			else if (ans_2 == 0)
			{
				bool ans_3;
				string dir;

				system("cls");

				cout << "Введите директорию файла - ";
				cin >> dir;
				ofstream out;
				out.open(dir);
				if (!out.is_open())
				{
					cout << "Ошибка открытия файла!\n";
				}
				else
				{
					out << txt_decode;
					cout << "\nУспешно!!!\n\n";
				}

				cout << "Хочешь ли ты ещё записать сообщение в консоль?\n1 - да\n0 - нет\n\tВведите здесь - ";
				cin >> ans_3;

				if (ans_3 == 1)
				{
					system("cls");
					cout << txt_decode << endl;
					cout << "Пока!!!!!\n";
				}
				else 
				{
					system("cls");
					cout << "Пока!!!!!\n";
				}
				out.close();
			}
		}
		
		file.close();
	}
	return 0;
}