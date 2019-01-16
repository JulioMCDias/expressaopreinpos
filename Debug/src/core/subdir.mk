################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/core/Convert.c \
../src/core/FuncoesPilha.c \
../src/core/Saidas.c \
../src/core/ValidaExpressao.c 

OBJS += \
./src/core/Convert.o \
./src/core/FuncoesPilha.o \
./src/core/Saidas.o \
./src/core/ValidaExpressao.o 

C_DEPS += \
./src/core/Convert.d \
./src/core/FuncoesPilha.d \
./src/core/Saidas.d \
./src/core/ValidaExpressao.d 


# Each subdirectory must supply rules for building sources it contributes
src/core/%.o: ../src/core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


