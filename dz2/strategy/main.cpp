#include <functional>
#include <iomanip>
#include <iostream>

using PriceStrategy = std::function<double(double)>;

double NoDiscount(double price) {
  return price;
}

double StudentDiscount(double price) {
  return price * 0.9;
}

double SaleDiscount(double price) {
  return price * 0.8;
}

double CalculatePrice(double price, const PriceStrategy& strategy) {
  return strategy(price);
}

int main() {
  double price{};
  int type{};

  std::cin >> price >> type;

  PriceStrategy strategy{NoDiscount};

  if (type == 0) {
    strategy = NoDiscount;
  } else if (type == 1) {
    strategy = StudentDiscount;
  } else if (type == 2) {
    strategy = SaleDiscount;
  } else {
    std::cout << "error\n";
    return 0;
  }

  std::cout << std::fixed << std::setprecision(2)
            << CalculatePrice(price, strategy) << '\n';
}
