#include <memory>


class Meal {
public:
  virtual void eat() = 0;
  virtual std::shared_ptr<Meal> Clone() const = 0;
  virtual ~Meal();
};


class Spagetti : public Meal {
public:
  Spagetti(const Spagetti&);
  void eat();
  std::shared_ptr<Spagetti> Clone() const {
    return std::make_shared<Spagetti>(*this);
  }
};


class Icecream : public Meal {
public:
  Icecream(const Icecream&);
  void eat();
  std::shared_ptr<Icecream> Clone() const {
    return std::make_shared<Icecream>(*this);
  }
};