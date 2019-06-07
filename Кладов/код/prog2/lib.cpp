#include "lib.h"
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
void application::init() {
  cout << "Готов ли файл input.txt к обработке? Если нет введите 0, если да, "
          "то 1"
       << endl;
  int choice;
  cin >> choice;
  if (choice) {
    input();
  } else {
    ready = 0;
    return;
  }
}
void application::exec() {
  if (ready) {
    count();
    output();
  }
}
void data_base::input() {
  fstream file;
  file.open("input.txt", ios::in);
  file >> n;
  p_double = new double *[2];
  p_double[0] = new double[n];
  p_double[1] = new double[n];
  for (int i = 0; i < n; i++) {
    file >> p_double[0][i] >> p_double[1][i];
  }
  file.close();
}
void data_base::count() {
  double summ = 0.0;
  for (int i = 0; i < n; i++) {
    aver_a += p_double[0][i];
    aver_b += p_double[1][i];
  }
  aver_a /= n;
  aver_b /= n;
  double a, b;
  for (int i = 0; i < n; i++) {
    a = p_double[0][i] - aver_a;
    b = p_double[1][i] - aver_b;
    summ += a * b;
    adis += a * a;
    bdis += b * b;
  }
  adis = sqrt(adis / (n - 1));
  bdis = sqrt(bdis / (n - 1));
  summ = summ / (n - 1);
  corel = summ / (adis * bdis);
}
void data_base::output() {
  fstream file;
  file.open("output.txt", ios::out);
  for (int i = 0; i < n; i++) {
    file.width(15);
    file << p_double[0][i];
    file.width(15);
    file << p_double[1][i] << endl;
  }
  file << "Среднеквадратическое отклонение для первой величины: " << adis
       << endl;
  file << "Среднее для первой величины: " << aver_a << endl;
  file << "Среднеквадратическое отклонение для второй величины: " << bdis
       << endl;
  file << "Среднее для второй величины: " << aver_b << endl;
  file << "Коэффициент корреляции: " << corel << endl;
  file.close();
  delete[] p_double[0];
  delete[] p_double[1];
  delete[] p_double;
}
