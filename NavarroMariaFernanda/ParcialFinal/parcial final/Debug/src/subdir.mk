################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/clientes.c \
../src/getInput.c \
../src/harcodeo.c \
../src/informes.c \
../src/parcial\ final.c \
../src/pedidos.c 

OBJS += \
./src/clientes.o \
./src/getInput.o \
./src/harcodeo.o \
./src/informes.o \
./src/parcial\ final.o \
./src/pedidos.o 

C_DEPS += \
./src/clientes.d \
./src/getInput.d \
./src/harcodeo.d \
./src/informes.d \
./src/parcial\ final.d \
./src/pedidos.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/parcial\ final.o: ../src/parcial\ final.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/parcial final.d" -MT"src/parcial\ final.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


