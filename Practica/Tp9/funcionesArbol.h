// LIBRERIAS
    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
    #include <stdlib.h>

// TIPO DE DATOS PERSONALIZADOS || ESTRUCTURA DE ARBOL

    typedef int t_num;
    typedef struct nodo_arbol {
        t_num numero;
        struct nodo_arbol * hijo_izq;
        struct nodo_arbol * hijo_der;
    }t_arbol;

// PROTOTIPOS
    void crearArbolVacio( t_arbol ** );
    bool arbolVacio( t_arbol *);
    t_num datoRaiz(t_arbol *);
    void insertarElemento( t_arbol **, t_num);
    void eliminarElemento( t_arbol **, int );
    void recorrerEnPreorden( t_arbol * );
    void recorrerEnPostorden( t_arbol * );
    void recorrerEnInorden( t_arbol * );
    bool buscarElemento( t_arbol *, int );
    int cantidadNodos( t_arbol * );
    t_arbol * buscarMin( t_arbol * );


// DESPLIEGUE Y DESARROLLO DE FUNCIONES 

    void crearArbolVacio( t_arbol ** p_arbol ) {
        *p_arbol = NULL;
        printf("Arbol vacio creado!\n");
    }

    bool arbolVacio( t_arbol * p_arbol ) {
        return p_arbol == NULL;
    }

    void insertarElemento( t_arbol ** p_arbol, t_num p_numero ) {
        if( arbolVacio(*p_arbol)){
            (*p_arbol) = (t_arbol*) malloc(sizeof(t_arbol));
            if(*p_arbol != NULL) {
                (*p_arbol)->numero = p_numero;
                (*p_arbol)->hijo_der = NULL;
                (*p_arbol)->hijo_izq = NULL;
            } else {
                printf("No hay memoria disponible!\n");
            }						
        } else {
            if( p_numero<(*p_arbol)->numero) {
                // el dato que quiero insertar es menor que el nodo actual
                insertarElemento(&((*p_arbol)->hijo_izq), p_numero);
            } else {
                // el dato que quiero insertar es mayor que el nodo actual
                if( p_numero > (*p_arbol)->numero) {
                    insertarElemento(  &((*p_arbol)->hijo_der), p_numero);	
                    // el dato que quiero insertar es igual que el nodo actual
                }  else {
                    printf("Valor duplicado, no es posible insertar!\n");
                }
            }
        }
    }

    void recorrerEnPreorden( t_arbol * p_arbol ) {
        if( p_arbol != NULL ) {
            printf("%d\n", p_arbol->numero);
            recorrerEnPreorden( p_arbol->hijo_izq );
            recorrerEnPreorden( p_arbol->hijo_der );
        }
    }

    void recorrerEnPostorden( t_arbol * p_arbol ) {
        if( p_arbol != NULL ) {
            recorrerEnPostorden( p_arbol->hijo_izq );
            recorrerEnPostorden( p_arbol->hijo_der );
            printf("%d\n", p_arbol->numero);
        }
    }

    void recorrerEnInorden( t_arbol * p_arbol ) {
        if( p_arbol != NULL ) {
            recorrerEnInorden( p_arbol->hijo_izq );
            printf("%d\n", p_arbol->numero);
            recorrerEnInorden( p_arbol->hijo_der);	
        }
    }

    bool buscarElemento( t_arbol * p_arbol, int p_numero ) {
        if( arbolVacio(p_arbol)) {
            return false;
        } else {
            if( p_numero < p_arbol->numero ) {
                buscarElemento( p_arbol->hijo_izq,  p_numero);
            } else {
                if( p_numero > p_arbol->numero ) {
                    buscarElemento( p_arbol->hijo_der,  p_numero);
                } else {
                    // Se encontró un nodo con el código igual al código buscado
                    return true;
                }
            }
        }
    }

    t_num datoRaiz(t_arbol * p_arbol) {
        return p_arbol->numero;	
    }

    int cantidadNodos( t_arbol * p_arbol ) {
        // siguiendo el recorrido en preorden
        if( p_arbol != NULL) {
            return 1 + cantidadNodos( p_arbol->hijo_izq) + cantidadNodos( p_arbol->hijo_der);
        }	
    }

    t_arbol * buscarMin( t_arbol * p_arbol ) {
        if( arbolVacio(p_arbol)) {
            return NULL;
        } else {
            if( !arbolVacio(p_arbol->hijo_izq)) {
                return buscarMin( p_arbol->hijo_izq );
            }else {
                return p_arbol;
            }
        }
    }

    void eliminarElemento( t_arbol ** p_arbol, int p_numero ) {
        t_arbol * aux;
        
        if( arbolVacio(*p_arbol)) {
            // No existe el nodo que se quiere eliminar
            printf("No existe el elemento que se desea eliminar\n");		
        } else {		
            if( p_numero < (*p_arbol)->numero ) {
                eliminarElemento( &((*p_arbol)->hijo_izq) , p_numero);
            } else {
                if( p_numero > (*p_arbol)->numero ) {
                    eliminarElemento( &((*p_arbol)->hijo_der) , p_numero);
                } else {
                    // Se encontró el nodo que se desea eliminar
                    if( (*p_arbol)->hijo_izq == NULL) {
                        aux = *p_arbol;
                        *p_arbol = (*p_arbol)->hijo_der;
                        free(aux);
                    } else {
                        if( (*p_arbol)->hijo_der == NULL) {
                            aux = *p_arbol;
                            *p_arbol = (*p_arbol)->hijo_izq;
                            free(aux);
                        } else {
                            // significa que el nodo por eliminar tiene 2 hijos
                            aux = buscarMin( (*p_arbol)->hijo_der  );
                            (*p_arbol)->numero = aux->numero;
                            eliminarElemento( &((*p_arbol)->hijo_der) , (*p_arbol)->numero);
                        } 										
                    }
                }
            }
            
        } 
        
    }
