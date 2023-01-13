################################################################################
# Project: moveOS
# 
# Makefile:
#     Purpose:
#         Building the main library as linkable binary
#     
#     Author:     usama
#     Created On: 13 January, 2023
# 
# 
# Edited
# -------------------------------------------------------------------------
# On                  | By                    | Remarks
# -------------------------------------------------------------------------
#                     |                       |
#                     |                       |
#                     |                       |
#                     |                       |
#                     |                       |
#                     |                       |
#                     |                       |
#                     |                       |
#                     |                       |
#                     |                       |
################################################################################

GCC    = gcc
GXX    = g++
LDGCC  = g++
LD     = $(LDGCC)





#######################################
# Paths
##################################
OUTPUT_LIB_NAME = moveOS-Lib

ROOT_DIR              = $(PWD)/src/moveOS
INC_ROOT_DIR          = $(ROOT_DIR)/inc
INC_INTERNAL_ROOT_DIR = $(ROOT_DIR)/src/_internal_inc
SRC_ROOT_DIR          = $(ROOT_DIR)/src
BUILD_ROOT_DIR        = $(PWD)/build/moveOS

MOVEOS_BASE_DIR                        = base
MOVEOS_KERNEL_DIR                      = kernel
MOVEOS_UTILITIES_DIR                   = utilities
MOVEOS_UTILITIES_CONFIG_DIR            = $(MOVEOS_UTILITIES_DIR)/config
MOVEOS_UTILITIES_STATEMACHINE_DIR      = $(MOVEOS_UTILITIES_DIR)/statemachine
MOVEOS_UTILITIES_VARS_DIR              = $(MOVEOS_UTILITIES_DIR)/vars


MOVEOS_SRCS_DIRS = .                                       \
                $(MOVEOS_BASE_DIR)                         \
                $(MOVEOS_KERNEL_DIR)                       \
                $(MOVEOS_UTILITIES_DIR)                    \
                $(MOVEOS_UTILITIES_CONFIG_DIR)             \
                $(MOVEOS_UTILITIES_STATEMACHINE_DIR)       \
                $(MOVEOS_UTILITIES_VARS_DIR)


INCLUDE_DIRS := $(foreach dir, $(MOVEOS_SRCS_DIRS), -I$(SRC_ROOT_DIR)/$(dir))  \
                -I$(ROOT_DIR)                                                  \
                -I$(INC_ROOT_DIR)                                              \
				-I$(INC_INTERNAL_ROOT_DIR)





#######################################
# Creating output directories
##################################
$(shell [ -d $(BUILD_ROOT_DIR) ] || mkdir -p $(BUILD_ROOT_DIR))
$(foreach dir, $(MOVEOS_SRCS_DIRS), $(shell [ -d $(BUILD_ROOT_DIR)/$(dir) ] || mkdir -p $(BUILD_ROOT_DIR)/$(dir)))





#######################################
# Enlisting the object files
##################################
SRCS_C   = $(foreach dir, $(MOVEOS_SRCS_DIRS), $(shell ls $(SRC_ROOT_DIR)/$(dir)/*.c   2>/dev/null | sed s,.*/,$(dir)/,))
SRCS_CPP = $(foreach dir, $(MOVEOS_SRCS_DIRS), $(shell ls $(SRC_ROOT_DIR)/$(dir)/*.cpp 2>/dev/null | sed s,.*/,$(dir)/,))

OBJS_C   := $(foreach file, $(SRCS_C:c=o),     $(BUILD_ROOT_DIR)/$(file))
OBJS_CPP := $(foreach file, $(SRCS_CPP:cpp=O), $(BUILD_ROOT_DIR)/$(file))

MOVEOS_OBJECTS = $(OBJS_C) $(OBJS_CPP)





################################################################################
# Compilation flags
###########################################################################
COMPILATION_C_FLAGS          = -fPIC -Wall -DLINUX_TARGET $(INCLUDE_DIRS)
COMPILATION_CPP_FLAGS        = -fPIC -Wall -DLINUX_TARGET -std=c++11 $(INCLUDE_DIRS) -lpthread


default: library

#######################################
# Rules for ".c"
##################################
$(BUILD_ROOT_DIR)/%.o: $(SRC_ROOT_DIR)/%.c
	@echo [Compiling] $<
	@$(GCC) -c $(COMPILATION_C_FLAGS) $< -o $@


$(BUILD_ROOT_DIR)/$(MOVEOS_BASE_DIR)/%.o: $(SRC_ROOT_DIR)/$(MOVEOS_BASE_DIR)/%.c
	@echo [Compiling] $<
	@$(GCC) -c $(COMPILATION_C_FLAGS) $< -o $@


$(BUILD_ROOT_DIR)/$(MOVEOS_KERNEL_DIR)/%.o: $(SRC_ROOT_DIR)/$(MOVEOS_KERNEL_DIR)/%.c
	@echo [Compiling] $<
	@$(GCC) -c $(COMPILATION_C_FLAGS) $< -o $@


$(BUILD_ROOT_DIR)/$(MOVEOS_UTILITIES_DIR)/%.o: $(SRC_ROOT_DIR)/$(MOVEOS_UTILITIES_DIR)/%.c
	@echo [Compiling] $<
	@$(GCC) -c $(COMPILATION_C_FLAGS) $< -o $@

$(BUILD_ROOT_DIR)/$(MOVEOS_UTILITIES_CONFIG_DIR)/%.o: $(SRC_ROOT_DIR)/$(MOVEOS_UTILITIES_CONFIG_DIR)/%.c
	@echo [Compiling] $<
	@$(GCC) -c $(COMPILATION_C_FLAGS) $< -o $@

$(BUILD_ROOT_DIR)/$(MOVEOS_UTILITIES_STATEMACHINE_DIR)/%.o: $(SRC_ROOT_DIR)/$(MOVEOS_UTILITIES_STATEMACHINE_DIR)/%.c
	@echo [Compiling] $<
	@$(GCC) -c $(COMPILATION_C_FLAGS) $< -o $@

$(BUILD_ROOT_DIR)/$(MOVEOS_UTILITIES_VARS_DIR)/%.o: $(SRC_ROOT_DIR)/$(MOVEOS_UTILITIES_VARS_DIR)/%.c
	@echo [Compiling] $<
	@$(GCC) -c $(COMPILATION_C_FLAGS) $< -o $@





#######################################
# Rules for ".cpp"
##################################
$(BUILD_ROOT_DIR)/%.O: $(SRC_ROOT_DIR)/%.cpp
	@echo [Compiling] $<
	@$(GXX) -c $(COMPILATION_CPP_FLAGS) $< -o $@


$(BUILD_ROOT_DIR)/$(MOVEOS_BASE_DIR)/%.O: $(SRC_ROOT_DIR)/$(MOVEOS_BASE_DIR)/%.cpp
	@echo [Compiling] $<
	@$(GXX) -c $(COMPILATION_CPP_FLAGS) $< -o $@


$(BUILD_ROOT_DIR)/$(MOVEOS_KERNEL_DIR)/%.O: $(SRC_ROOT_DIR)/$(MOVEOS_KERNEL_DIR)/%.cpp
	@echo [Compiling] $<
	@$(GXX) -c $(COMPILATION_CPP_FLAGS) $< -o $@


$(BUILD_ROOT_DIR)/$(MOVEOS_UTILITIES_DIR)/%.O: $(SRC_ROOT_DIR)/$(MOVEOS_UTILITIES_DIR)/%.cpp
	@echo [Compiling] $<
	@$(GXX) -c $(COMPILATION_CPP_FLAGS) $< -o $@

$(BUILD_ROOT_DIR)/$(MOVEOS_UTILITIES_CONFIG_DIR)/%.O: $(SRC_ROOT_DIR)/$(MOVEOS_UTILITIES_CONFIG_DIR)/%.cpp
	@echo [Compiling] $<
	@$(GXX) -c $(COMPILATION_CPP_FLAGS) $< -o $@

$(BUILD_ROOT_DIR)/$(MOVEOS_UTILITIES_STATEMACHINE_DIR)/%.O: $(SRC_ROOT_DIR)/$(MOVEOS_UTILITIES_STATEMACHINE_DIR)/%.cpp
	@echo [Compiling] $<
	@$(GXX) -c $(COMPILATION_CPP_FLAGS) $< -o $@

$(BUILD_ROOT_DIR)/$(MOVEOS_UTILITIES_VARS_DIR)/%.O: $(SRC_ROOT_DIR)/$(MOVEOS_UTILITIES_VARS_DIR)/%.cpp
	@echo [Compiling] $<
	@$(GXX) -c $(COMPILATION_CPP_FLAGS) $< -o $@





################################################################################
# Building the library
###########################################################################
library: $(MOVEOS_OBJECTS)
	@$(GXX) -shared -o $(BUILD_ROOT_DIR)/$(OUTPUT_LIB_NAME) $(MOVEOS_OBJECTS) $(COMPILATION_CPP_FLAGS)
	@echo ""
	@echo ""
	@echo "*****************************************************************"
	@echo "*** moveOS built successfully"
	@echo "*****************************************************************"
	@echo "**********************************************************"




################################################################################
# Cleaning-up
###########################################################################
clean:
	$(foreach dir, $(MOVEOS_SRCS_DIRS), $(shell rm -f $(BUILD_ROOT_DIR)/$(dir)/*.o 2> /dev/null))
	$(foreach dir, $(MOVEOS_SRCS_DIRS), $(shell rm -f $(BUILD_ROOT_DIR)/$(dir)/*.O 2> /dev/null))
	@rm -f $(BUILD_ROOT_DIR)/$(OUTPUT_LIB_NAME)
	@echo Project cleaned ...




################################################################################
#                            ----------------------                            #
################################################################################


