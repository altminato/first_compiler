typedef struct _nodo Nodo;
struct _nodo
{
	int valor;
	Nodo* next;
};

typedef struct _lista Lista;
struct _lista
{
	Nodo* nodoInicial;
	void (*add)(Lista* lista, int valor);
	int (*getAt)();
	int (*imprimir)(Lista* lista);
};

Nodo* crearNodo()
{
	return ((Nodo*)malloc(sizeof(Nodo)));
}

Lista* crearLista(void * agregar, void* imprimir, void* get)
{
	Lista* lista=((Lista*)malloc(sizeof(Lista)));
	lista->nodoInicial=NULL;
	lista->add=agregar;
	lista->imprimir=imprimir;
	lista->getAt=get;	
	return lista;
}

void agregarValor(int valor, Nodo* nodo)
{
	if(nodo->next==NULL)
	{
		nodo->next=crearNodo();
		nodo->next->next=NULL;
		nodo->next->valor=valor;
	}else
	{
		agregarValor(valor, nodo->next);
	}
}


void agregarValorLista(Lista* lista, int valor)
{
	if(lista->nodoInicial==NULL)
	{
		lista->nodoInicial=crearNodo();
		lista->nodoInicial->next=NULL;
		lista->nodoInicial->valor=valor;
	}
	else
	{
		agregarValor(valor, lista->nodoInicial );
	}
}

int getValorLista(Lista* lista, int posicion)
{
	if(lista->nodoInicial != NULL)
	{
		return get(lista->nodoInicial, posicion,0);
	}else
	{
		return NOT_FOUND;
	}
}

int get(Nodo* nodo, int posicion, int conteo)
{
	if(nodo != NULL)
	{
		if(posicion==conteo)
		{
			return nodo->valor;
		}else{
			return get(nodo->next, posicion, conteo+1);
		}
	}else{
		return NOT_FOUND;
	}
}

void imprimirLista(Lista* lista)
{
	if(lista->nodoInicial == NULL)
	{
		printf("Lista vacia\n");
		
	}else{
		imprimir(lista->nodoInicial);
	}
}
int imprimir(Nodo* nodo)
{
	if(nodo != NULL)
	{
		printf("%d,",nodo->valor);
		return imprimir(nodo->next);
	}else{
	return 0;
	}
}