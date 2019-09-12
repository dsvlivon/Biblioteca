/*
 * validations.h
 *
 *  Created on: 11 sep. 2019
 *      Author: Daniel
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

int getInt(int *result, char *msg, char *msgFail, int minus, int maximus, int try);
float getFloat(float *result, char *msg, char *msgFail, float minus, float maximus, int try);
char getChar(char *resultChar, char *msgChar, char *msgFailChar, char minus, char maximus, int try);
