#ifndef LIB_H
#define LIB_H
class data_base {
private:
  double **p_double;
  double adis, bdis, corel;
  double aver_a = 0.0, aver_b = 0.0;
  int n;

public:
  bool ready = true;
  void input();
  void count();
  void output();
};
class application : public data_base {
public:
  void init();
  void exec();
};
#endif
