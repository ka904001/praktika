#include "lib.h"
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
void base::input_n() {
  cout << "Введите количество пар значений" << endl;
  cin >> size;
  data[0] = new double[size];
  data[1] = new double[size];
  data[2] = new double[size];
  cout << "Введите " << size
       << " пар элементов через пробел (число исходов i-го типа, значение "
          "исхода i-го типа)"
       << endl;
  for (int i = 1; i <= size; i++) {
    cout << "Введите " << i << " пару элементов ";
    cin >> data[i - 1][0] >> data[i - 1][1];
  }
}
void base::input_p() {
  cout << "Введите количество пар значений" << endl;
  cin >> size;
  data[0] = new double[size];
  data[1] = new double[size];
  data[2] = new double[size];
  cout << "Введите " << size
       << " пар элементов через пробел (вероятность исхода i-го типа, значение "
          "исхода i-го типа)"
       << endl;
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
void base::da_count_out() {
  dis = 0.0;
  double cl = 0.0;
  int n = 0;
  ma_count();
  fstream file("output.txt", ios::out);
  for (int i = 0; i < size; i++) {
    data[2][i] = data[0][i] * (data[1][i] - averege) * (data[1][i] - averege);
    for (int j = 0; j < 3; j++) {
      cout.width(15);
      cout << data[j][i];
      if (j == 2)
        cout << endl;
      file.width(15);
      file << data[j][i];
      if (j == 2)
        file << endl;
    }
    dis += data[2][i];
    n += data[0][i];
  }
  dis /= n;
  cout << "Дисперсия для данного множества: D^2 = " << dis << endl;
  cout << "Среднеквадратическое отклонение: sqrt(D^2) = " << sqrt(dis);
  file << "Дисперсия для данного множества: D^2 = " << dis << endl;
  file << "Среднеквадратическое отклонение: sqrt(D^2) = " << sqrt(dis);
  file.close();
}
void base::de_count_out() {
  dis = 0.0;
  double cl = 0.0;
  me_count();
  fstream file("output.txt", ios::out);
  for (int i = 0; i < size; i++) {
    data[2][i] = data[0][i] * (data[1][i] - averege) * (data[1][i] - averege);
    for (int j = 0; j < 3; j++) {
      cout.width(15);
      cout << data[j][i];
      if (j == 2)
        cout << endl;
      file.width(15);
      file << data[j][i];
      if (j == 2)
        file << endl;
    }
    dis += data[2][i];
  }
  cout << "Дисперсия для данного множества: D^2 = " << dis << endl;
  cout << "Среднеквадратическое отклонение: sqrt(D^2) = " << sqrt(dis);
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
    cout << "Вводятся количество исходов и соответсвующее значение (0) или"
         << endl
         << "вероятность исхода и его значение (1)?" << endl;
    cin >> choice;
    if (choice) {
      input_p();
    } else {
      input_n();
    }
  }
}
void application::exec() {
  cout << "Хотите посчитать для количества исходов или их вероятностей (0 и 1 "
          "соотвественно)"
       << endl;
  cin >> choice;
  if (choice) {
    de_count_out();
  } else {
    da_count_out();
  }
}
