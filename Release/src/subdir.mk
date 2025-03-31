################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Game.cpp \
../src/Music.cpp \
../src/Sprite.cpp \
../src/State.cpp \
../src/main.cpp 

CPP_DEPS += \
./src/Game.d \
./src/Music.d \
./src/Sprite.d \
./src/State.d \
./src/main.d 

OBJS += \
./src/Game.o \
./src/Music.o \
./src/Sprite.o \
./src/State.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -Dmain=SDL_main -I"C:\SDL2-2.30.12\include\SDL2" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Game.d ./src/Game.o ./src/Music.d ./src/Music.o ./src/Sprite.d ./src/Sprite.o ./src/State.d ./src/State.o ./src/main.d ./src/main.o

.PHONY: clean-src

