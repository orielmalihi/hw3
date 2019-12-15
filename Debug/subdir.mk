################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main1.c \
../main2.c \
../sorting.c \
../strings.c 

O_SRCS += \
../main1.o \
../main2.o \
../sorting.o \
../strings.o 

OBJS += \
./main1.o \
./main2.o \
./sorting.o \
./strings.o 

C_DEPS += \
./main1.d \
./main2.d \
./sorting.d \
./strings.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


