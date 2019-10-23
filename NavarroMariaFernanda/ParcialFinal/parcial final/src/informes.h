#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

/** \brief Lista los pedidos completados por cliente
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
*/
int orderListProcessed(Pedidos* pedido,Clients* client,int cant,int size);
/** \brief Lista los pedidos pendientes por cliente
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
*/
int orderListPending(Pedidos* pedido,Clients* client,int cant,int size);
/** \brief Lista los clientes y muestra la cantidad de pedidos pendientes que tiene cada uno
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
*/
int listClients(Pedidos* pedido,Clients* client,int cant,int size);
/** \brief Muestra la cantidad de clientes que reciclaron mas de 1000Kg
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
*/
int kilosRecicladosMayorA(Pedidos* pedido,Clients* client,int cant,int size);
/** \brief Muestra la cantidad de clientes que reciclaron menos de 100Kg
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
*/
int kilosRecicladosMenorA(Pedidos* pedido,Clients* client,int cant,int size);
/** \brief Carga las operaciones del MenuInformes
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
*/
int cargaInformes(Pedidos* pedido,Clients* client,int cant,int size);
/** \brief Muestra el menu de Informes
* \return No recibe ni devuelve nada
*/
void subMenuInformes(void);
/** \brief Recibe una localidad y muestra el numero de pedidos pendientes en dicha localidad
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
*/
int listPendingByLocation(Pedidos* pedido,Clients* client,int cant,int size);
/** \brief Muestra el cliente con mas pedidos
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
*/
int clientsMostOrders(Pedidos* pedido,Clients* client,int cant,int size);
/** \brief Muestra el cliente con mas pedidos pendientes
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
*/
int clientsMostOrdersPending(Pedidos* pedido,Clients* client,int cant,int size);
/** \brief Muestra el cliente con mas pedidos completados
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
*/
int clientsMostOrdersProcesed(Pedidos* pedido,Clients* client,int cant,int size);
/** \brief Muestra el cliente con mas kilos procesados
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
*/
int clientsMostRecicled(Pedidos* pedido,Clients* client,int cant,int size);
/** \brief Muestra el cliente con menos kilos procesados
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
*/
int clientsLessRecicled(Pedidos* pedido,Clients* client,int cant,int size);
/** \brief Recibe un tipo de plastico y cuit y muestra la cantidad de kilos reciclados
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
*/
int kilosRecicladoByTipoPlastico(Pedidos* pedido,Clients* client,int cant,int size);
/** \brief Lista los pedidos completados y muestra el porcentaje de reciclado de cada uno
 * \param pedido list pedidos*
* \param client list Clients*
* \param cant int size for client
* \param size int size for pedido
*/
int orderProcessedListByCriteria(Pedidos* pedido,Clients* client,int cant,int size);



#endif //  INFORMES_H_INCLUDED

