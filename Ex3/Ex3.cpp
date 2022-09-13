#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <experimental/filesystem>

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
	double x = S / (12 * m);
	double min = abs(n-x);
	double pp = 0;
	p = 0;
	while (p <= 100) {
		double xx = 0;
		double i = 1;
		int ii = 0;
		while (ii < n) {
			i *= (1 + (p / 100));
			ii += 1;
		}
		xx = (i - 1) / (i * (p / 100));
		if (abs(xx - x) < min) {
			min = abs(x - xx);
			pp = p;
		}
		p += 0.001;
	}
	std::cout << "Процент равен: " << pp << std::endl;
}

void copyfile() {
	std::ofstream f1;
	std::string filename = "zubai.txt";
	f1.open(filename);
	std::string full_path = std::experimental::filesystem::canonical(filename).generic_string();
	std::cout << full_path << std::endl;
	f1.close();
}

void filt() {
	std::ofstream f;
	f.open("zubai.txt");
	std::cout << "Введите строку: " << std::endl;
	std::string strr;
	f << strr;
	f.close();

	std::ifstream ff;
	ff.open("zubai.txt");
	std::string str;
	std::getline(ff, str);
	for (char x : str) {
		if ((x <= '9') && (x >= '0')) {
			std::cout << x << std::endl;
		}
	}
	ff.close();
}

void sortirovka() {
	std::string str;
	int len;
	std::cout << "Введите символы: ";
	std::cin >> str;
	len = str.length();
	std::vector <char> mass;
	mass.reserve(str.length());
	for (char s : str) {
		mass.push_back(s);
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
	setlocale(LC_ALL, "");
	copyfile();
	return 0;
}