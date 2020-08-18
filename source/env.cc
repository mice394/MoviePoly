#include "academic.h"
#include "env.h"
#include <string>
using namespace std;

Env::Env() {
    setName("ENV");
    setSetProperties(properties);
}

Env::~Env() {}
