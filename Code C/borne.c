//BORNE.C
#include <stdio.h>
#include <memoire_borne.h>
#include <donnees_borne.h>

#include "lecteurcarte.h"
#include "base_clients.h"

int main()
{

    lecteurcarte_initialiser();

    while (1)
    {
        lecteurcarte_lire_carte();
    }

}
