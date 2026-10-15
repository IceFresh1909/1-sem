#include <functional>
#include <iostream>
#include <string>

using TextFunction = std::function<std::string(const std::string&)>;

std::string PlainText(const std::string& text) {
  return text;
}

TextFunction AddBrackets(TextFunction text_function) {
  return [text_function](const std::string& text) {
    return "[" + text_function(text) + "]";
  };
}

TextFunction AddStars(TextFunction text_function) {
  return [text_function](const std::string& text) {
    return "*" + text_function(text) + "*";
  };
}

TextFunction AddQuotes(TextFunction text_function) {
  return [text_function](const std::string& text) {
    return "\"" + text_function(text) + "\"";
  };
}

int main() {
  std::string text{};
  std::getline(std::cin, text);

  int count{};
  std::cin >> count;

  TextFunction text_function{PlainText};

  for (int i{}; i < count; ++i) {
    std::string decorator{};
    std::cin >> decorator;

    if (decorator == "brackets") {
      text_function = AddBrackets(text_function);
    } else if (decorator == "stars") {
      text_function = AddStars(text_function);
    } else if (decorator == "quotes") {
      text_function = AddQuotes(text_function);
    } else {
      std::cout << "error\n";
      return 0;
    }
  }

  std::cout << text_function(text) << '\n';
}
