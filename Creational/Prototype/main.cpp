#include "prototype.cpp"
#include <memory>

int main(int argc, char** argv) {
  std::shared_ptr<Spagetti> spagetti = std::make_shared<Spagetti>();
  std::shared_ptr<Spagetti> spagetti2 = spagetti->Clone();

  return 0;
}