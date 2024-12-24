#include <iostream>
#include <vector>

class ILayer {
public:
  ILayer() {
    std::cout << "LAYER CONSTRUCTOR CALLED\n";
  }
  ILayer(const ILayer& layer) = default;
  virtual ~ILayer() {};

public:
  virtual void forward() = 0;
};

class Dense : public ILayer {
public:
  Dense() {
    std::cout << "DENSE CONSTRUCTOR CALLED\n";
  }
  Dense(const Dense& dense) = default;

public:
  void forward() override {
    std::cout << "DENSE FORWARD\n";
  };
};

class Convolutional : public ILayer {
public:
  Convolutional() {
    std::cout << "CONVOLUTIONAL CONSTRUCTOR CALLED\n";
  }
  Convolutional(const Convolutional& dense) = default;

public:
  void forward() override {
    std::cout << "CONVOLUTIONAL FORWARD\n";
  };
};

class Reccurent : public ILayer {
public:
  Reccurent() {
    std::cout << "RECCURENT CONSTRUCTOR CALLED\n";
  }
  Reccurent(const Reccurent& dense) = default;

public:
  void forward() override {
    std::cout << "RECCURENT FORWARD\n";
  };
};

enum LAYER_TYPE {
  DENSE,
  CONV,
  REC
};

ILayer* makeLayerFactory(LAYER_TYPE type) {
  switch (type) {
  case DENSE: return new Dense();
  case CONV:  return new Convolutional();
  case REC:   return new Reccurent();
  default:    break;
  }
}

class net {
public:
  std::vector<ILayer*> _layers;

public:
  net() = default;
  net(const net& nn) = default;

public:
  void addLayer(LAYER_TYPE type) {
    _layers.emplace_back(makeLayerFactory(type));
  }

  void forward() {
    for (const auto& layer : _layers) {
      layer->forward();
    }
  }

  ~net() {
    for (const auto& layer : _layers) {
      delete layer;
    }
  }
};

int main() {
  net* model {new net()};

  model->addLayer(CONV);
  model->addLayer(CONV);
  model->addLayer(DENSE);

  model->forward();

  delete model;

  return 0;
}