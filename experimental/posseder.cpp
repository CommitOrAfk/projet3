/*
 * File:   posseder.cpp
 * Author: jordan
 *
 * Created on 20 février 2015, 15:53
 */

#include "posseder.h"

posseder::posseder()
{


}

posseder::posseder(const posseder& orig) {
}

posseder::~posseder() {
}

void posseder::SaisirClient()
{
    C[0].Saisir(cin);
}
