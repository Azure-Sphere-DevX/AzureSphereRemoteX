#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
// #include "spi.h"


typedef enum __attribute__((packed))
{
    GPIO_OpenAsOutput_c,
    GPIO_OpenAsInput_c,
    GPIO_SetValue_c,
    GPIO_GetValue_c,
    I2CMaster_Open_c,
    I2CMaster_SetBusSpeed_c,
    I2CMaster_SetTimeout_c,
    I2CMaster_Write_c,
    I2CMaster_WriteThenRead_c,
    I2CMaster_Read_c,
    I2CMaster_SetDefaultTargetAddress_c,
    SPIMaster_Open_c,
    PWM_Open_c,
    PWM_Apply_c
} SOCKET_CMD;

typedef struct __attribute__((packed))
{
    SOCKET_CMD cmd;
    int gpioId;
    uint8_t outputMode;
    uint8_t initialValue;
    int returns;
    int err_no;
} GPIO_OpenAsOutput_t;

typedef struct __attribute__((packed))
{
    SOCKET_CMD cmd;
    int gpioId;
    int returns;
    int err_no;
} GPIO_OpenAsInput_t;

typedef struct __attribute__((packed))
{
    SOCKET_CMD cmd;
    int gpioFd;
    uint8_t value;
    int returns;
    int err_no;
} GPIO_SetValue_t;

typedef struct __attribute__((packed))
{
    SOCKET_CMD cmd;
    int gpioFd;
    uint8_t outValue;
    int returns;
    int err_no;
} GPIO_GetValue_t;

typedef struct __attribute__((packed))
{
    SOCKET_CMD cmd;
    int I2C_InterfaceId;
    int returns;
    int err_no;
} I2CMaster_Open_t;

typedef struct __attribute__((packed))
{
    SOCKET_CMD cmd;
    int fd;
    uint32_t speedInHz;
    int returns;
    int err_no;
} I2CMaster_SetBusSpeed_t;

typedef struct __attribute__((packed))
{
    SOCKET_CMD cmd;
    int fd;
    uint32_t timeoutInMs;
    int returns;
    int err_no;
} I2CMaster_SetTimeout_t;

typedef struct __attribute__((packed))
{
    SOCKET_CMD cmd;
    int fd;
    unsigned char address;
    unsigned char data[32];
    unsigned int length;
    int returns;
    int err_no;
} I2CMaster_Write_t;

typedef struct __attribute__((packed))
{
    SOCKET_CMD cmd;
    int fd;
    unsigned char address;
    unsigned int lenWriteData;
    unsigned int lenReadData;
    int returns;
    int err_no;
    unsigned char data[32];
} I2CMaster_WriteThenRead_t;

typedef struct __attribute__((packed))
{
    SOCKET_CMD cmd;
    int fd;
    unsigned char address;
    unsigned int maxLength;
    int returns;
    int err_no;
    unsigned char data[32];
} I2CMaster_Read_t;

typedef struct __attribute__((packed))
{
    SOCKET_CMD cmd;
    int fd;
    unsigned char address;
    int returns;
    int err_no;
} I2CMaster_SetDefaultTargetAddress_t;

typedef struct __attribute__((packed))
{
    SOCKET_CMD cmd;
    int interfaceId;
    int chipSelectId;
    unsigned char csPolarity;
    int returns;
    int err_no;
} SPIMaster_Open_t;

typedef struct __attribute__((packed))
{
    SOCKET_CMD cmd;
    unsigned int pwm;
    int returns;
    int err_no;
} PWM_Open_t;

typedef struct __attribute__((packed))
{
    SOCKET_CMD cmd;
    int pwmFd;
    uint32_t pwmChannel;
    unsigned int period_nsec;
    unsigned int dutyCycle_nsec;
    uint32_t polarity;
    bool enabled;
    int returns;
    int err_no;
} PWM_Apply_t;
