#pragma once
#include <string>
using namespace std;

#include "Aleatorizador.h"
#include "Agente.h"
#include "ClienteBarbero.h"

class Santa
{
public:
    
    enum Estado {
        durmiendo,
        atendiendoduende,
        preparandotrineo
    };
    
    Santa();
    Santa(Santa::Estado ne);
    virtual ~Santa();
    
    virtual int estado();
    virtual void actuar();
    virtual string estadoString();
    
private:
    Estado e;
    shared_ptr< Elfos > elfosXatender_ptr;
    shared_ptr< Renos > Renosencabaña_ptr;
};


Santa::~Santa()
{
}

int Santa::estado()
{
    return e;
}

void Santa::actuar()
{
    switch (e)
    {
        case durmiendo:
        {
            if (Renos::Renosencabaña.size() == 9) {
# pragma omp critical
                {
                    clienteXatender_ptr = ClienteBarbero::clientesEsperando.front();
                    ClienteBarbero& clienteXatender = *clienteXatender_ptr;
                    ClienteBarbero::msjsClientes[clienteXatender.obtId()] = ClienteBarbero::siendoAtendido;
                    ClienteBarbero::clientesEsperando.pop(); // pasa al siguiente cliente sac·ndolo de la cola
                }
                e = cortando;
            }elseif(Elfos:ElfosesRenosencabaña.size() == 9)
            break;
        }
        case atendiendoduende:
        {
            if (clienteXatender_ptr->obtDC() == 0)    // ya termino con el cliente
                e = esperando;
            break;
        }
        case preparandotrineo:
    }
}

string Barbero::estadoString()
{
    string rsl = "";
    switch (e)
    {
        case esperando:
        {
            rsl = "esperando";
            break;
        }
        case cortando:
        {
            rsl = "cortando";
            break;
        }
        case destruido:
        {
            rsl = "destruido";
            break;
        }
    }
    return rsl;
}
