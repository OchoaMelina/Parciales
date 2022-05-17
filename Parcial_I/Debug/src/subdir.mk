################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Parcial_I.c \
../src/Productos.c \
../src/Tracking.c \
../src/Usuario.c \
../src/input.c 

OBJS += \
./src/Parcial_I.o \
./src/Productos.o \
./src/Tracking.o \
./src/Usuario.o \
./src/input.o 

C_DEPS += \
./src/Parcial_I.d \
./src/Productos.d \
./src/Tracking.d \
./src/Usuario.d \
./src/input.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


