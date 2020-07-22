/*
Задание №2
Создайте класс Passport (паспорт), который будет содержать паспортную информацию о гражданине Украины.
С помощью механизма наследования, реализуйте класс ForeignPassport (загран.паспорт) производный от Passport.
Напомним, что заграничный паспорт содержит помимо паспортных данных, также данные о визах, номер заграничного паспорта.
*/
#include <iostream>
#include <windows.h>
using namespace std;

class Passport {
	char* SERIES_AND_NUMBER;
	char* FIO;
	char* DATE_OF_BIRTH;
	char* PLACE_OF_BIRTH;
public:
	Passport() : SERIES_AND_NUMBER(nullptr), FIO(nullptr), DATE_OF_BIRTH(nullptr), PLACE_OF_BIRTH(nullptr) {}
	Passport(const char* series_and_number, const char* fio, const char* date_of_birth, const char* place_of_birth) {
		SERIES_AND_NUMBER = _strdup(series_and_number);
		FIO = _strdup(fio);
		DATE_OF_BIRTH = _strdup(date_of_birth);
		PLACE_OF_BIRTH = _strdup(place_of_birth);
	}
	void Print() {
		cout << "Серія та номер паспорту : " << SERIES_AND_NUMBER << endl;
		cout << "Прізвище, імя, по батькові : " << FIO << endl;
		cout << "Дата народження : " << DATE_OF_BIRTH << endl;
		cout << "Місце народження : " << PLACE_OF_BIRTH << endl;
	}
	~Passport() { delete[]SERIES_AND_NUMBER;  delete[]FIO; delete[]DATE_OF_BIRTH;  delete[]PLACE_OF_BIRTH; }
};

class ForeignPassport : public Passport {
	//Напомним, что заграничный паспорт содержит помимо паспортных данных, также данные о визах, номер заграничного паспорта.
	char* CITIZENSHIP;
	char* SEX;
	char* VALID_UNTIL;
	char* SERIES_AND_NUMBER_FOREIGN;
	char* VISA_DATA;
public:
	ForeignPassport() : Passport(), CITIZENSHIP(nullptr), SEX(nullptr), VALID_UNTIL(nullptr), SERIES_AND_NUMBER_FOREIGN(nullptr),
		VISA_DATA(nullptr) {}
	ForeignPassport(const char* series_and_number, const char* fio, const char* date_of_birth, const char* place_of_birth,
		const char* citizenship, const char* sex, const char* valid_until, const char* series_and_number_foreign, const char* visa_data)
		: Passport(series_and_number, fio, date_of_birth, place_of_birth) {
		CITIZENSHIP = _strdup(citizenship);
		SEX = _strdup(sex);
		VALID_UNTIL = _strdup(valid_until);
		SERIES_AND_NUMBER_FOREIGN = _strdup(series_and_number_foreign);
		VISA_DATA = _strdup(visa_data);
	}
	void Print() {
		Passport::Print();
		cout << "Громадянтсво : " << CITIZENSHIP << endl;
		cout << "Стать : " << SEX << endl;
		cout << "Дійсний до : " << VALID_UNTIL << endl;
		cout << "Серія та номер закордонного паспорту : " << SERIES_AND_NUMBER_FOREIGN << endl;
		cout << "Відомості про візи : " << VISA_DATA << endl;
	}
	~ForeignPassport() { delete[]CITIZENSHIP; delete[]SEX; delete[]VALID_UNTIL; delete[]SERIES_AND_NUMBER_FOREIGN; delete[]VISA_DATA; }
};

int main()
{
	setlocale(LC_ALL, ""); //працює тільки з потоком виведення
	SetConsoleCP(1251); //встановлює потрібну кодову таблицю, на потік введення
	SetConsoleOutputCP(1251); //встановлює потрібну кодову таблицю, на потік виводу.
	cout << "\tПаспорт громадянина України" << endl;
	Passport B("ВМ123456", "Іванова Іванна Іванівна", "08.12.1983", "Україна, м. Житомир");
	B.Print();
	cout << "\n\tЗакордонний паспорт громадянина України" << '\n';
	ForeignPassport A("ВМ123456", "Іванова Іванна Іванівна / Ivanova Ivanna Ivanivna", "08.12.1983",
		"Україна, м. Житомир / Ukraine, Zhytomyr", "Громадянство України / Citizen of Ukraine", "Жіноча / Female",
		"01.01.2025", "FB678954", "United Kingdom (01.06.2020 - 01.11.2020)");
	A.Print();
}
