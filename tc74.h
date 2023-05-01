// @File		TC74.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		01/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef TC74_H_
#define TC74_H_

#include "wire.h"

// SLAVE, MASTER ADDRESS
#define TC74_SLA_W					0x9A
#define TC74_SLA_R					0x9B

// ADDRESS MAP
#define TC74_RTR					0x00
#define TC74_RWCR					0x01
#define TC74_NORMAL					0x04
#define TC74_STANDBYL				0x80

void TC74_Command(char cmd, char data)
{
    Wire_Start();
    Wire_Write(TC74_SLA_W);
    Wire_Write(cmd);
    Wire_Write(data);
    Wire_Stop();
}

char TC74_Read_Temp(char data)
{
    Wire_Start();
    Wire_Write(TC74_SLA_W);
    Wire_Write(data);
    Wire_Start();
    Wire_Write(TC74_SLA_R);
    char temp = Wire_Nack();
    Wire_Stop();

    return temp;
}

#endif
