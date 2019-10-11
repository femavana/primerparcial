/*
 * arrayEmployees.h
 *
 *  Created on:  sep. 2019
 *      Author: Navarro María Fernanda
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define CANT 51

typedef struct{
int id;
char name[CANT];
char lastName[CANT];
float salary;
int sector;
int isEmpty;
}Employee;

/** \brief  Shows the menu at screen.
 *   Don't receive or return anything
*/
void menu();

/** \brief  Shows the subMenuChange at screen.
 *   Don't receive or return anything
*/
void subMenuChange();

/** \brief  Shows the subMenuInfo at screen.
 *   Don't receive or return anything
*/
void subMenuInfo();

/** \brief  Starts all elements of list Employee* with isEmpty == TRUE.
 * To indicate that all position at list are empty.
* \param personalData list Employee*
* \param size int
* \return ret int (-1) if an error and (0) if OK.
*/
int initEmployees(Employee* personalData,int size);

/** \brief Prints the content of elements at list Employee* with isEmpty == FALSE.
* \param personalData list Employee*
* \param size int
* \return ret int (-1) if an error and (0) if OK.
*/
int printEmployees(Employee* personalData,int size);

/** \brief Add the values received in the first empty position of list Employee*
 *  increased automatically counterId
 * \param personalData list Employee*
 * \param size int
 * \param *counterId int
 * \return ret int (-1) if an error and (0) if OK.
*/
int addEmployees(Employee* personalData,int size,int *counterId);

/** \brief  Search for free space in the Employee list *
* and returns the index position empty at list Employee*.
 * \param personalData list Employee*
 * \param size int
 * \param *freePosition int
 * \return ret int (-1) if an error and (0) if find an empty index position.
*/
int searchFreeSpace(Employee* personalData,int size,int *freePosition);

/** \brief Remove an employee by ID. Logic drop: rewrite isEmpty == TRUE
 * \param personalData list Employee*
 * \param size int
 * \param counterId int
 * \return ret int (-1) if an error and (0) if OK.
*/
int removeEmployee(Employee* personalData,int size,int *counterId);

/** \brief Search employee by Id and returns the index position at list Employee*.
 * \param size int
 * \param *position int
 * \return ret int (-1) if an error and (0) if find the Id search at list Employee*
*/
int findEmployeeById(Employee* personalData,int size,int *position);

/** \brief Search employee by name and returns the index position at list Employee*.
 * \param size int
 * \param *position int
 * \return ret int (-1) if an error and (0) if find the name search at list Employee*
*/
int searchEmployeeByName(Employee* personalData,int size,int *position);

/** \brief Changes the data of an employee by ID.
 * It allows changing all the elements of the employee.
 * \param personalData list Employee*
 * \param size int
 * \param counterId int
 * \return ret int (-1) if an error and (0) if OK.
*/
int changeEmployee(Employee* personalData, int size,int counterId);

/** \brief Prints the content of elements of the index position received  of list Employee*
* \param personalData list Employee*
* \param size int
* \param *position int
* \return ret int (-1) if an error and (0) if OK.
*/
int printPositionEmployees(Employee* personalData,int size,int position);

/** \brief Prints the results of options of subMenuInfo
* \param personalData list Employee*
* \param size int
* \param counterId int
* \return ret int (-1) if an error and (0) if OK.
*/
int reportEmployee(Employee* personalData, int size,int counterId);

/** \brief Sort elements of list Employee* in descending order
* \param personalData list Employee*
* \param size int
* \return ret int (-1) if an error and (0) if OK.
*/
int sortEmployee(Employee* personalData, int size);

/** \brief Informs if list Employee* is empty or not
* \param personalData list Employee*
* \param size int
* \param counterId int
* \return ret int (-1) if an error and (0) if OK.
*/
int loadedEmployee(Employee* personalData,int size,int counterId);

/** \brief Sort average of the salaries at  list Employee*
* \param personalData list Employee*
* \param size int
* \param counterId int
* \param *average int
* \return ret int (-1) if an error and (0) if OK.
*/
int averageSalaryEmployee(Employee* personalData,int size,int counterId,int *average);

/** \brief Sort total employees exceeding the average salary
* \param personalData list Employee*
* \param size int
* \param average int
* \return ret int (-1) if an error and (0) if OK.
*/
int sortSalaryEmployee(Employee* personalData,int size,int average);

#endif /* ARRAYEMPLOYEES_H_ */
