
#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED


typedef struct{
int idCliente;
int idPedido;
int cantRecoleccion;
int estado;
int isEmpty;
}Pedidos;

/** \brief  Shows the menuPedido at screen.
 *   Don't receive or return anything
*/
void subMenuPedido();

/** \brief  Shows the options of menuPedidos at screen.
 *   Don't receive or return anything
 * \param pedido list pedidos*
* \param size int
*/
int cargaPedido(Pedidos* pedido,Clients* client,int cant, int size,int* pedidoCount);

/** \brief  Shows the subMenuChange at screen.
 *   Don't receive or return anything
*/
void subMenuChangePedido(void);

/** \brief  Starts all elements of list  with isEmpty == TRUE.
 * To indicate that all position at list are empty.
* \param client list Clients*
* \param size int
* \return ret int (-1) if an error and (0) if OK.
*/
int initPedido(Pedidos* pedido,int size);

/** \brief Prints the content of elements at list with isEmpty == FALSE.
* \param pedido list pedidos*
* \param size int
* \return ret int (-1) if an error and (0) if OK.
*/
int printPedido(Pedidos* pedido,int size);

/** \brief Add the values received in the first empty position of list
 *  increased automatically counterClient
* \param client list Clients*
 * \param size int
 * \param *clientCount int
 * \return ret int (-1) if an error and (0) if OK.
*/
int addPedido(Pedidos* pedido,Clients* client,int cant,int size,int *pedidoCount);

/** \brief  Search for free space in the  list
* and returns the index position empty at list
* \param client list Clients*
 * \param size int
 * \param *freePosition int
 * \return ret int (-1) if an error and (0) if find an empty index position.
*/
int searchFreeSpacePedido(Pedidos* pedido,int size,int *freePosition);

/** \brief Remove an client by codeClient. Logic drop: rewrite isEmpty == TRUE
* \param client list Clients*
 * \param size int
 * \param clientCount int
 * \return ret int (-1) if an error and (0) if OK.
*/
int removeByIdPedido(Pedidos* pedido,int size,int *clientCount);

/** \brief Search client by codeClient and returns the index position at list
 * \param client list Clients*
 * \param size int
 * \param *position int
 * \return ret int (-1) if an error and (0) if find the Id search at list
*/
int findByIdPedido(Pedidos* pedido,int size,int *position);

/** \brief Changes the data of an client by codeClient
 * It allows changing all the elements of the list
* \param client list Clients*
 * \param size int
 * \param counterClient int
 * \return ret int (-1) if an error and (0) if OK.
*/
int changeByIdPedido(Pedidos* pedido, int size);

/** \brief Prints the content of elements of the index position received  of list
* \param client list Clients*
* \param size int
* \param *position int
* \return ret int (-1) if an error and (0) if OK.
*/
int printPositionPedido(Pedidos* pedido,int size,int position);


#endif //  PEDIDOS_H_INCLUDED
