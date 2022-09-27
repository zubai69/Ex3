#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <experimental/filesystem>
#include <Windows.h>

void zaem() {
	double m, S, n, p;
	std::cout << "Введите сумму:" << std::endl;
	std::cin >> S;
	std::cout << "Введите процент:" << std::endl;
	std::cin >> p;
	std::cout << "Введите количество лет:" << std::endl;
	std::cin >> n;
	double r = p / 100;
	if (r == 0) {
		m = S / (12 * n);
	}
	else {
		m = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));
	}
	std::cout << "Месячная выплата равна: " << m << std::endl;
}

void ssuda()
{
	double m, S, n, p;
	std::cout << "Введите сумму:" << std::endl;
	std::cin >> S;
	std::cout << "Введите месячную выплату:" << std::endl;
	std::cin >> m;
	std::cout << "Введите количество лет:" << std::endl;
	std::cin >> n;
	double mm = S / (12 * n);
	double min = abs(m-mm);
	double pp = 0;
	p = 0;
	bool T = true;
	while (p <= 101) {
		double mmm = 0;
		double i = 1;
		int ii = 0;
		while (ii < n) {
			i *= (1 + (p / 100));
			ii += 1;
		}
		mmm = S * i * (p / 100) / (12 * (i - 1));
		if (abs(mmm - m) < min) {
			min = abs(mmm - m);
			pp = p;
		}
		p += 0.001;
	}
	if (pp <= 100) {
		std::cout << "Процент равен: " << round(pp*1000)/1000 << std::endl;
	}
	else {
		std::cout << "Процент не может быть найден" << std::endl;
	}
	
}

void copyfile() {
	std::ofstream f1;
	std::string filename = "zubai.txt";
	std::string str = new char[10000];
	f1.open(filename);
	std::getline(std::cin, str);
	f1 << str;
	f1.close();
	std::ifstream f2;
	f2.open(filename);
	std::string s;
	std::getline(f2, s);
	std::cout << s << std::endl;;
	f2.close();
}

void filt() {
	std::ifstream f;
	f.open("zubai.txt");
	std::string str;
	std::getline(f, str);
	std::string i = "";
	str += " ";
	for (char x : str) {
		if ((x <= '9') && (x >= '0')) {
			i += x;
		}
		else {
			if (i != "") {
				std::cout << std::stoi(i) << " ";
			}
			i = "";
		}
	}
	f.close();
}

void sortirovka() {
	std::string str;
	std::cout << "Введите символы: ";
	std::cin >> str;
	std::vector <char> mass;
	mass.reserve(30);
	int i = 0;
	for (char s : str) {
		if (i < 30) {
			mass.push_back(s);
			i += 1;
		}
		else {
			break;
		}
	}
	for (int i = 0; i < mass.size()-1; i++) {
		for (int ii = 0; ii < mass.size()-1; ii++) {
			if (mass[ii] > mass[ii + 1]) {
				char a = mass[ii];
				mass[ii] = mass[ii + 1];
				mass[ii + 1] = a;
			}
		}
	}
	for (char i : mass) {
		std::cout << i;
	}
	std::cout << std::endl;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	return 0;
}