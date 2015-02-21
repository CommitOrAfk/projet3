/*
 * File:   posseder.h
 * Author: jordan
 *
 * Created on 20 février 2015, 15:52
 */
#include "client.h"
#include "compte.h"
#ifndef POSSEDER_H
#define	POSSEDER_H

class posseder {
    public:

    Client *C;
    Compte *compte;
public:
    posseder();
    posseder(const posseder& orig);
    virtual ~posseder();
    void SaisirClient();
private:

};

#endif	/* POSSEDER_H */

