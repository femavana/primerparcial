/*
 * getInput.h
 *
 * Created on:  sep. 2019
 *      Author: Navarro María Fernanda
 */

#ifndef GETINPUT_H_
#define GETINPUT_H_

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
/**  \brief  Solicita una letra al usuario y la valida
     * \param *pResultado Puntero del numero ingresado
     * \param *mensaje  Puntero del mensaje a ser mostrado
     * \param *msjError Puntero del mensaje a ser mostrado en caso de error
     * \param minimo Limite minimo a validar
     * \param maximo Limite maximo a validar
     * \param reintentos Cantidad de intentos en caso de error
     * \return Devuelve 0 si carga el char y sino -1
     */
int getChar( char *pResultado,
			 char* mensaje,
			 char* msjError,
			 char minimo,
			 char maximo,
			 int reintentos);
/** \brief Solicita un string al usuario y valida que sean solo caracteres
    * \param *input Puntero del caracter ingresado
    * \param *message  Puntero del mensaje a ser mostrado
    * \param *msgError Puntero del mensaje a ser mostrado en caso de error
    * \param minSize Limite minimo a validar
    * \param maxSize Limite maximo a validar
    * \param reintentos Cantidad de intentos en caso de error
    * \return Devuelve 0 si carga el string y sino -1
    */
int getStrChar(char* input,
		      char* message,
		      char* msgError,
		      int minSize,
		      int maxSize,
		      int retries);
/** \brief Recibe un auxiliar string de numeros y valida que sean solo numeros
    * \param aux string  recibido
    * \return Devuelve 0 si son solo numeros y sino -1
    */
int onlyNumbersStr(char* aux);
/** \brief Recibe un auxiliar string de caracteres y valida que sean solo letras
    * \param aux string  recibido
    * \return Devuelve 0 si son solo letras y sino -1
    */
int onlyText(char* aux);


#endif /* GETINPUT_H_ */
