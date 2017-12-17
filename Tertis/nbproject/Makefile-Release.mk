#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Main.o \
	${OBJECTDIR}/al_backend_init.o \
	${OBJECTDIR}/al_events.o \
	${OBJECTDIR}/front_allegro.o \
	${OBJECTDIR}/front_init_allegro.o \
	${OBJECTDIR}/front_init_pi.o \
	${OBJECTDIR}/front_pi.o \
	${OBJECTDIR}/game_start.o \
	${OBJECTDIR}/matrix_manipulation.o \
	${OBJECTDIR}/matrix_validation.o \
	${OBJECTDIR}/misc_functions.o \
	${OBJECTDIR}/scored.o \
	${OBJECTDIR}/states_allegro.o \
	${OBJECTDIR}/states_pi.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tetris

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tetris: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tetris ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Main.o: Main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Main.o Main.c

${OBJECTDIR}/al_backend_init.o: al_backend_init.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/al_backend_init.o al_backend_init.c

${OBJECTDIR}/al_events.o: al_events.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/al_events.o al_events.c

${OBJECTDIR}/front_allegro.o: front_allegro.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/front_allegro.o front_allegro.c

${OBJECTDIR}/front_init_allegro.o: front_init_allegro.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/front_init_allegro.o front_init_allegro.c

${OBJECTDIR}/front_init_pi.o: front_init_pi.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/front_init_pi.o front_init_pi.c

${OBJECTDIR}/front_pi.o: front_pi.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/front_pi.o front_pi.c

${OBJECTDIR}/game_start.o: game_start.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/game_start.o game_start.c

${OBJECTDIR}/matrix_manipulation.o: matrix_manipulation.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/matrix_manipulation.o matrix_manipulation.c

${OBJECTDIR}/matrix_validation.o: matrix_validation.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/matrix_validation.o matrix_validation.c

${OBJECTDIR}/misc_functions.o: misc_functions.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/misc_functions.o misc_functions.c

${OBJECTDIR}/scored.o: scored.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/scored.o scored.c

${OBJECTDIR}/states_allegro.o: states_allegro.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/states_allegro.o states_allegro.c

${OBJECTDIR}/states_pi.o: states_pi.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/states_pi.o states_pi.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
