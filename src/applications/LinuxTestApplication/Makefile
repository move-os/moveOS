################################################################################
# Project: moveOS Test Application for Linux
# 
# Makefile:
#     Purpose:
#         Building the main library as linkable binary and building the project
#     by linking with the built library.
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
################################################################################

GCC    = gcc
GXX    = g++
LDGCC  = g++
LD     = $(LDGCC)





#######################################
# Paths
##################################
THIS_DIR              = $(PWD)

MOVEOS_MAKEFILE_DIR = $(THIS_DIR)/../../../
MOVEOS_INC_DIR      = $(MOVEOS_MAKEFILE_DIR)/src/moveOS/inc
MOVEOS_LIB_DIR      = $(MOVEOS_MAKEFILE_DIR)/build/moveOS
MOVEOS_LIB_FILE     = $(MOVEOS_LIB_DIR)/moveOS-Lib





################################################################################
# Building the application
###########################################################################
application: 
	@if [ ! -f $(MOVEOS_LIB_FILE) ]; then cd $(MOVEOS_MAKEFILE_DIR); make; cd $(THIS_DIR); fi
	@$(GXX) -c LinuxApp.cpp -I$(MOVEOS_INC_DIR) -o app.o
	@$(GXX) app.o $(MOVEOS_LIB_FILE) -o app
	@rm app.o
	@echo Application built





################################################################################
# Cleaning-up
###########################################################################
clean:
	@rm -f app.o
	@rm -f app
	@echo Project cleaned





################################################################################
#                            ----------------------                            #
################################################################################


