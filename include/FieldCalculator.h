#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

/**
 * @brief Считывает введенное значение
 * @return Возвращает ощибку если число меньше либо равно 0, иначе возвращает введеное число
 */
int pInput(void);

/**
 * @brief Проверяет введеное значение на неотрицательность
 * @param value введеное значение
 * @return Возвращает ошибку если введеное значение меньше либо равно 0
 */
void checkValue(int value);

/**
 * @brief Проверяет, является ли введеное значение простым числом
 * @param p порядок поля
 * @return Возвращает ошибку если введеное число не простое
 */
void checkPrime(const int p);

/**
 * @brief Считывает введеное значение
 * @return Возвраащает введеное значение
 */
int Input(void);

/**
 * @brief Вычисляет значение дроби в поле z(p)
 * @param a Числитель дроби
 * @param b Знаменатель дроби
 * @param p Порядок поля
 * @return Возвращает значение дроби в поле z(p)
 */
int getX(const int a, const int b, const int p);

/**
 * @brief Вычисляет элемент в поле z(p)
 * @param number Исходное число
 * @param p Порядок поля
 * @return Возвращает значение элемента в поле z(p)
 */
int getElementInField(const int number,const int p);

/**
 * @param fraction дробь
 * @param integer целое
 */
enum{
    fraction,
    integer
};