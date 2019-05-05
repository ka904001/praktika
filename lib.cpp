#include "lib.h"
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
void base::input() {
  cout << "Введите количество пар значений" << endl;
  cin >> size;
  data[0] = new double[size];
  data[1] = new double[size];
  data[2] = new double[size];
  cout << "Введите " << size << " пар элементов через пробел" << endl;
  for (int i = 1; i <= size; i++) {
    cout << "Введите " << i << " пару элементов ";
    cin >> data[i - 1][0] >> data[i - 1][1];
  }
}
void base::finput() {
  fstream file("input.txt", ios::in);
  file >> size;
  data[0] = new double[size];
  data[1] = new double[size];
  data[2] = new double[size];
  for (int i = 0; i < size; i++) {
    file >> data[0][i] >> data[1][i];
  }
  file.close();
}
void base::ma_count() {
  averege = 0.0;
  int n = 0;
  for (int i = 0; i < size; i++) {
    averege += data[0][i] * data[1][i];
    n += (int)data[0][i];
  }
  averege /= n;
}
void base::me_count() {
  averege = 0.0;
  for (int i = 0; i < size; i++) {
    averege += data[0][i] * data[1][i];
  }
}
void base::da_count() {
  dis = 0.0;
  int n = 0;
  ma_count();
  for (int i = 0; i < size; i++) {
    data[2][i] = data[0][i] * (data[1][i] - averege) * (data[1][i] - averege);
    dis += data[2][i];
    n += data[0][i];
  }
  dis /= n;
}
void base::de_count() {
  dis = 0.0;
  me_count();
  for (int i = 0; i < size; i++) {
    data[2][i] = data[0][i] * (data[1][i] - averege) * (data[1][i] - averege);
    dis += data[2][i];
  }
}
void base::output() {
  fstream file("output.txt", ios::out);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < 3; j++) {
      cout.width(15);
      cout << data[j][i];
      file.width(15);
      file << data[j][i];
      if (j == 2) {
        file << endl;
        cout << endl;
      }
    }
  }
  cout << "Математическое ожидание для данного множества: M(X) = " << averege
       << endl;
  cout << "Дисперсия для данного множества: D^2 = " << dis << endl;
  cout << "Среднеквадратическое отклонение: sqrt(D^2) = " << sqrt(dis);
  file << "Математическое ожидание для данного множества: M(X) = " << averege
       << endl;
  file << "Дисперсия для данного множества: D^2 = " << dis << endl;
  file << "Среднеквадратическое отклонение: sqrt(D^2) = " << sqrt(dis);
  file.close();
}
void application::init() {
  cout << "Хотите вводить данные вручную или из файла (0 и 1, соответственно)"
       << endl;
  int ch;
  cin >> ch;
  if (ch) {
    finput();
  } else {
    input();
  }
}
void application::exec() {
  cout << "Хотите посчитать для количества исходов или их вероятностей (0 и 1 "
          "соотвественно)"
       << endl;
  cin >> choice;
  if (choice) {
    de_count();
  } else {
    da_count();
  }
  output();
}
