#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED


typedef struct{
int idCliente;
int idPedido;
float cantRecoleccion;
float HDPE;
float LDPE;
float PP;
int estado;
int isEmpty;
}Pedidos;

/** \brief  Shows the menuPedido at screen.
 *   Don't receive or return anything
*/
void subMenuPedido();

/** \brief  Shows the subMenuChangePedido at screen.
 *   Don't receive or return anything
*/
void subMenuChangePedido(void);

/** \brief  Starts all elements of list  with isEmpty == TRUE.
 * To indicate that all position at list are empty.
* \param pedido list Pedidos*
* \param size int
* \return ret int (-1) if an error and (0) if OK.
*/
int initPedido(Pedidos* pedido,int size);
/** \brief Prints the content of elements of the index position received  of list
* \param pedido list Pedidos*
* \param size int
* \param position int
* \return ret int (-1) if an error and (0) if OK.
*/
int printPositionPedido(Pedidos* pedido,int size,int position);

/** \brief Add the values received in the first empty position of list
 *  Increased automatically counterClient
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
* \param *pedidoCount int
* \param *pedidosPendientes int
 */
int addPedido(Pedidos* pedido,Clients* client,int cant,int size,int *pedidoCount);
/** \brief  Search for free space in the  list
* and returns the index position empty at list
* \param pedido list Pedidos*
 * \param size int
 * \param *freePosition int
 * \return ret int (-1) if an error and (0) if find an empty index position.
*/
int searchFreeSpacePedido(Pedidos* pedido,int size,int *freePosition);
/** \brief  Shows the options of menuPedidos at screen.
 *
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
* \param *pedidoCount int
* \param  clientCount int
* \param *pedidosPendientes int
*/
int cargaPedido(Pedidos* pedido,Clients* client,int cant, int size,int *pedidoCount);
/** \brief Changes the data of pedido by idPedido
* \param pedido list Pedidos*
 * \param size int
 \param pedidoCount int
 * \return ret int (-1) if an error and (0) if OK.
*/
int changeByIdPedido(Pedidos* pedido, int size,int *pedidoCount);
/** \brief Remove pedido by id pedido. Logic drop: rewrite isEmpty == TRUE
* \param pedido list Pedidos*
 * \param size int
 * \param *pedidoCount int
 * \return ret int (-1) if an error and (0) if OK.
*/
int removeByIdPedido(Pedidos* pedido,int size,int *pedidoCount);

/** \brief Search pedido by id pedido and returns the index position at list
 * \param pedido list Pedidos*
 * \param size int
 * \param *position int
 * \return ret int (-1) if an error and (0) if find the Id search at list
*/
int findByIdPedido(Pedidos* pedido,int size,int *position);
/** \brief Prints the content of elements at list with isEmpty == FALSE.
* \param pedido list pedidos*
* \param size int
* \return ret int (-1) if an error and (0) if OK.
*/
int printPedido(Pedidos* pedido,int size);
/** \brief Processes the total amount and divides it by types of plastic and waste
* \param pedido list Pedidos*
* \param size int
* \param pedidoCount int
* \param *pedidosCompletados int
* \return ret int (-1) if an error and (0) if OK.
*/
int procesarResiduos(Pedidos* pedido,int size,int pedidoCount);
/** \brief Informs if list is empty or not
* \param pedido list pedidos*
* \param size int
 * \param pedidoCount int
* \return ret int (-1) if an error and (0) if OK.
*/
int loadedOrder(Pedidos* pedido,int size,int pedidoCount);

#endif //  PEDIDOS_H_INCLUDED
