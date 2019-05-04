#ifndef LIB_H
#define LIB_H

class base {
public:
  void input_n();
  void input_p();
  void finput();
  void me_count();
  void ma_count();
  void de_count_out();
  void da_count_out();
  bool choice;

private:
  double *data[3];
  int size;
  double averege;
  double dis;
};

class application : public base {
public:
  void init();
  void exec();
};

#endif
