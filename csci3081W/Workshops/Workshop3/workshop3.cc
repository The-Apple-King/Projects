#include <iostream>

class Duck {
 protected:
  float cost;
  float tax;

 public:
  float getCost() { return cost; };
  float getTotlaCost() { return (cost + tax); };
  float getTax() { return tax; };
};

class Mallard : public Duck {
 public:
  Mallard();
  ~Mallard();
};

Mallard::Mallard() { cost = 12.61; }

class WoodDuck : public Duck {
 public:
  WoodDuck();
  ~WoodDuck();
};

WoodDuck::WoodDuck() { cost = 150.00; }

class Rubber : public Duck {
 public:
  Rubber();
  ~Rubber();
};

Rubber::Rubber() { cost = .01; }

class MNMallard : public Mallard {
 public:
  MNMallard() { this->tax = .06875; };
};

class MNWoodDuck : public WoodDuck {
 public:
  MNWoodDuck() { this->tax = .06875; };
};

class MNRubber : public Rubber {
 public:
  MNRubber() { this->tax = .06875; };
};

class CAMallard : public Mallard {
 public:
  CAMallard() { this->tax = .0725; };
};

class CAWoodDuck : public WoodDuck {
 public:
  CAWoodDuck() { this->tax = .0725; };
};

class CARubber : public Rubber {
 public:
  CARubber() { this->tax = .0725; };
};

class NYMallard : public Mallard {
 public:
  NYMallard() { this->tax = .045; };
};

class NYWoodDuck : public WoodDuck {
 public:
  NYWoodDuck() { this->tax = .045; };
};

class NYRubber : public Rubber {
 public:
  NYRubber() { this->tax = .045; };
};

class Ifactory {
 public:
  virtual Mallard* createMallard() = 0;
  virtual WoodDuck* createWoodDuck() = 0;
  virtual Rubber* createRubberDuck() = 0;
};

class MNFactory : public Ifactory {
 public:
  Mallard* createMallard() { return new MNMallard(); };
  WoodDuck* createWoodDuck() { return new MNWoodDuck(); };
  Rubber* createRubberDuck() { return new MNRubber(); };
};

class CAFactory : public Ifactory {
 public:
  Mallard* createMallard() { return new CAMallard(); };
  WoodDuck* createWoodDuck() { return new CAWoodDuck(); };
  Rubber* createRubberDuck() { return new CARubber(); };
};

class NYFactory : public Ifactory {
 public:
  Mallard* createMallard() { return new NYMallard(); };
  WoodDuck* createWoodDuck() { return new NYWoodDuck(); };
  Rubber* createRubberDuck() { return new NYRubber(); };
};

class facade {
 private:
  MNFactory* mnf;
  CAFactory* caf;
  NYFactory* nyf;
  std::string state;
  std::string type;

 public:
  facade();
  ~facade();
  void run();
  Duck* createDuck();
  void query();
};

facade::facade() {
  mnf = new MNFactory();
  caf = new CAFactory();
  nyf = new NYFactory();
}

facade::~facade() {
  delete mnf;
  delete caf;
  delete nyf;
  delete state;
  delete type;
}

void facade::run() {
  query();
  Duck* Duck = createDuck();
  std::cout << "the cost of a " << state << " " << type << " is "
       << Duck->getTotlaCost();
}

Duck* facade::createDuck() {
  Ifactory curFactory = nullptr;
  switch (state) {
    case "Minnesota":
      curFactory = mnf;
      break;

    case "California":
      curFactory = caf;
      break;

    case "New York":
      curFactory = nyf;
      break;

    default:
        std::cout << "invalid state";
      break;
  }

  switch (type)
  {
  case "Mallard":
    return curFactory->createMallard();
    break;

    case "WoodDuck":
    return curFactory->createWoodDuck();
    break;

    case "RubberDuck":
    return curFactory->createRubberDuck();
    break;
  
  default:
  std::cout << "invalid type";
    break;
  }
}

void facade::query() {
    std::string state;
    std::string type;
    std::cout << "enter the state";
    std::cin >> state;
    while (state != "Minnesota" || state != "California" || state != "New York")
    {
        std::cout << "please enter a valid state";
        std::cin >> state;
    }
    std::cout << "enter the type";
    std::cin >> type;
    while (type != "Mallard" || type != "WoodDuck" || type != "Rubber")
    {
        std::cout << "please enter a valid type";
        std::cin >> type;
    }
    
    
    
}

int main() {
  facade* f = new facade();
  f->run();
  delete f;
}
