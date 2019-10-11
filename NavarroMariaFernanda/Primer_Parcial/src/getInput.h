
#ifndef GETINPUT_H_INCLUDED
#define GETINPUT_H_INCLUDED


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
			  int   retries);

#endif //  GETINPUT_H_INCLUDED
