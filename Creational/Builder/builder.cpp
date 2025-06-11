#include <iostream>
#include <vector>
#include <string>

class Menu {
private:
  size_t                   _width   {};
  size_t                   _height  {};
  std::string              _id      {};
  std::string              _title   {};
  std::vector<std::string> _options {};

private:
  Menu(std::string id)
  : _id(id)
  {}

public:
  static Menu create(std::string id) { return Menu(id); }
  void show() const { std::cout << _id << ' ' << "Called\n"; }

  Menu& title(std::string title) { _title = title; return *this; }
  Menu& addOption(std::string option) { _options.emplace_back(option); return *this; }
  Menu& height(size_t height) { _height = height; return *this; }
  Menu& width(size_t width) { _width = width; return *this; }
};