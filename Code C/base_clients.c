//BASE_CLIENT.C
#include "base_clients.h"

unsigned int id_client ;

int authentifier(unsigned int num_carte)
{
 int i;
 unsigned int carte_client[20] = {10, 15, 16, 19, 20, 25, 26, 29, 30, 37} ;


	for(i=0;i<10;i++)
	{
		if(carte_client[i] == num_carte) {
	 	id_client = num_carte ;
	 	return 1 ;
	 	}

	}
return 0 ;
}