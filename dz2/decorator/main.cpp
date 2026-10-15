#include <functional>
#include <iostream>
#include <string>

using TextFunction = std::function<std::string(const std::string&)>;
using Decorator = std::function<TextFunction(const TextFunction&)>;

std::string PlainText(const std::string& text) {
  return text;
}

TextFunction BracketsDecorator(const TextFunction& component) {
  return [component](const std::string& text) {
    return "[" + component(text) + "]";
  };
}

TextFunction StarsDecorator(const TextFunction& component) {
  return [component](const std::string& text) {
    return "*" + component(text) + "*";
  };
}

TextFunction QuotesDecorator(const TextFunction& component) {
  return [component](const std::string& text) {
    return "\"" + component(text) + "\"";
  };
}

int main() {
  std::string text{};
  std::getline(std::cin, text);

  int count{};
  std::cin >> count;

  TextFunction component{PlainText};

  for (int i{}; i < count; ++i) {
    std::string decorator_name{};
    std::cin >> decorator_name;

    Decorator decorator;

    if (decorator_name == "brackets") {
      decorator = BracketsDecorator;
    } else if (decorator_name == "stars") {
      decorator = StarsDecorator;
    } else if (decorator_name == "quotes") {
      decorator = QuotesDecorator;
    } else {
      std::cout << "error\n";
      return 0;
    }

    component = decorator(component);
  }

  std::cout << component(text) << '\n';
}