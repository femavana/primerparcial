################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Primer_Parcial.c \
../src/clientes.c \
../src/getInput.c \
../src/informes.c \
../src/pedidos.c \
../src/proceso.c 

OBJS += \
./src/Primer_Parcial.o \
./src/clientes.o \
./src/getInput.o \
./src/informes.o \
./src/pedidos.o \
./src/proceso.o 

C_DEPS += \
./src/Primer_Parcial.d \
./src/clientes.d \
./src/getInput.d \
./src/informes.d \
./src/pedidos.d \
./src/proceso.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


