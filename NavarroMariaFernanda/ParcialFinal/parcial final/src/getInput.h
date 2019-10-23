#ifndef GETINPUT_H_INCLUDED
#define GETINPUT_H_INCLUDED

//GETS
/** \brief  Solicita un numero decimal al usuario y lo valida
     * \param *pResultado Puntero del numero ingresado
     * \param *mensaje  Puntero del mensaje a ser mostrado
     * \param *msjError Puntero del mensaje a ser mostrado en caso de error
     * \param minimo Limite minimo a validar
     * \param maximo Limite maximo a validar
     * \param reintentos Cantidad de intentos en caso de error
     * \return Devuelve 0 si carga el numero decimal y sino -1
     */
int getFloat(float *pResultado,
			 char* mensaje,
			 char* msjError,
			 int minimo,
			 int maximo,
			 int reintentos);

/**  \brief  Solicita un numero al usuario y lo valida
     * \param *pResultado Puntero del numero ingresado
     * \param *mensaje  Puntero del mensaje a ser mostrado
     * \param *msjError Puntero del mensaje a ser mostrado en caso de error
     * \param minimo Limite minimo a validar
     * \param maximo Limite maximo a validar
     * \param reintentos Cantidad de intentos en caso de error
     * \return Devuelve 0 si carga el numero y sino -1
     */
int getInt(	int *pResultado,
			char* mensaje,
			char* mensajeError,
			int minimo,
			int maximo,
			int reintentos);
/**  \brief  Solicita una letra al usuario y la valida dentro de los parametros min y max determinados
     * \param input letra ingresado
     * \param *message  Puntero del mensaje a ser mostrado
     * \param *msgError Puntero del mensaje a ser mostrado en caso de error
     * \param minSize minimo a validar
     * \param maxSize maximo a validar
     * \param retries Cantidad de intentos en caso de error
     * \return Devuelve 0 si carga el char y sino -1
     */
int getSeguir(char *input,
		      char* message,
		      char* msgError,
		      int minSize,
		      int maxSize,
		      int retries);
/**  \brief  Solicita una letra al usuario y la valida que sea una letra
     * \param input letra ingresado
     * \param *message  Puntero del mensaje a ser mostrado
     * \param *msgError Puntero del mensaje a ser mostrado en caso de error
     * \param retries Cantidad de intentos en caso de error
     * \return Devuelve 0 si carga el char y sino -1
     */
int getLetter(char *input,
		      char* message,
		      char* msgError,
		      int retries);
/** \brief Solicita un string al usuario y valida que este dentro de los limites del array
    * \param *input Puntero del string ingresado
    * \param *message  Puntero del mensaje a ser mostrado
    * \param *msgError Puntero del mensaje a ser mostrado en caso de error
    * \param minSize Limite minimo a validar
    * \param maxSize Limite maximo a validar
    * \param reintentos Cantidad de intentos en caso de error
    * \return Devuelve 0 si carga el string y sino -1
    */
int getString(char* input,
		      char* message,
			  char* msgError,
			  int   minSize,
			  int   maxSize,
			  int* retries);
/** \brief Solicita un string al usuario y valida que sean solo letras
    * \param *input Puntero del string ingresado
    * \param *message  Puntero del mensaje a ser mostrado
    * \param *msgError Puntero del mensaje a ser mostrado en caso de error
    * \param minSize Limite minimo a validar
    * \param maxSize Limite maximo a validar
    * \param reintentos Cantidad de intentos en caso de error
    * \return Devuelve 0 si carga el string y sino -1
    */
int getName(char* input,
		      char* message,
		      char* msgError,
		      int minSize,
		      int maxSize,
		      int retries);
/** \brief Solicita un string al usuario y valida que sean solo numeros y dos guiones
    * \param *input Puntero del string ingresado
    * \param *message  Puntero del mensaje a ser mostrado
    * \param *msgError Puntero del mensaje a ser mostrado en caso de error
    * \param minSize Limite minimo a validar
    * \param maxSize Limite maximo a validar
    * \param reintentos Cantidad de intentos en caso de error
    * \return Devuelve 0 si carga el string con numeros y dos guiones sino -1
    */
int getCUIT(char* input,
		       char* message,
		       char* msgError,
		       int minSize,
		       int maxSize,
		       int retries);
/** \brief Solicita un string al usuario y valida que solo sean letras y numeros
    * \param *input Puntero del string ingresado
    * \param *message  Puntero del mensaje a ser mostrado
    * \param *msgError Puntero del mensaje a ser mostrado en caso de error
    * \param minSize Limite minimo a validar
    * \param maxSize Limite maximo a validar
    * \param reintentos Cantidad de intentos en caso de error
    * \return Devuelve 0 si carga el string y sino -1
    */
int getAlfanumerico(char *input,
	      char* message,
	      char* msgError,
	      int minSize,
	      int maxSize,
	      int retries);
/** \brief Solicita un string al usuario y valida que sean solo espacios y letras
    * \param *input Puntero del string ingresado
    * \param *message  Puntero del mensaje a ser mostrado
    * \param *msgError Puntero del mensaje a ser mostrado en caso de error
    * \param minSize Limite minimo a validar
    * \param maxSize Limite maximo a validar
    * \param reintentos Cantidad de intentos en caso de error
    * \return Devuelve 0 si carga el string y sino -1
    */
int getTexto(char* input,
		      char* message,
		      char* msgError,
		      int minSize,
		      int maxSize,
		      int retries);
//validations

/** \brief Recibe un auxiliar string y valida que sean solo letras
    * \param aux string  recibido
    * \return Devuelve 1 si contiene solo espacio y letras y sino 0
    */
int isValidStrChar(char* aux);
/** \brief Recibe un auxiliar string de numeros y valida que sean solo numeros y dos guiones
    * \param aux string  recibido
    * \return Devuelve 1 si contiene solo numeros y dos guiones sino 0
    */
int isValidCUIT(char* aux);
/** \brief Recibe un auxiliar string  y valida que sean solo letras y numeros
    * \param aux string  recibido
    * \return Devuelve 1 si contiene solo espcio,letras y numeros y sino 0
    */
int isValidAlphanumeric(char* aux);
/** \brief Recibe un auxiliar string  y valida que sean solo letras y espacios
    * \param aux string  recibido
    * \return Devuelve 1 si contiene solo espacio y letras y sino 0
    */
int isValidTexto(char* auxiliar);
//SYSTEM
/**
 * \brief Limpia la pantalla
 * \param -
 * \return No recibe ni retorna nada
 *
 */
void clearScreen(void);

#endif //  GETINPUT_H_INCLUDED
