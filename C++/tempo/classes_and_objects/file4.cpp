#include <iostream>

class Sort{
public:
  virtual void processData() final {
    readData();
    sortData();
    writeData();
  }
private:
  virtual void readData(){}
  virtual void sortData()= 0;
  virtual void writeData(){}
};


class QuickSort: public Sort{
private:
  void readData() override {
    std::cout << "readData" << std::endl;
  }
  void sortData() override {
    std::cout <<  "sortData" << std::endl;
  }
  void writeData() override {
    std::cout << "writeData" << std::endl;
  }
};

class BubbleSort: public Sort{
private:

  void sortData() override {
    std::cout <<  "sortData" << std::endl;
  }

};


int main(){

  std::cout << std::endl;

  Sort* sort = new QuickSort;
  sort->processData();

  std::cout << std::endl;

}