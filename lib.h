#ifndef LIB_H
#define LIB_H

class base {
public:
  void input();
  void finput();
  void me_count();
  void ma_count();
  void de_count();
  void da_count();
  void output();

private:
  double *data[3];
  int size;
  double average;
  double dis;
};

class application : public base {
public:
  void init();
  void exec();

private:
  bool choice;
};

#endif
