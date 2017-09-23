#include "PieceCod.h"

int my_rand() {
    return (rand() % 101 - 50);
}


void CreateData(std::ostream& stream, std::true_type) {
    for(int i = 0; i < 100; ++i)
        stream << my_rand() << std::endl;
}
