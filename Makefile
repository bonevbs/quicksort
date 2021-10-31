# ------------------------------------------------------------
# Components of the main library
# ------------------------------------------------------------

CORE =
	
SOURCES_CORE := \
	$(CORE)

EXTRA_HEADERS = src/quicksort.cpp

HEADERS_CORE := $(SOURCES_CORE:.cpp=.hpp) $(EXTRA_HEADERS)

OBJECTS_CORE := $(SOURCES_CORE:.cpp=.o)

DEPENDENCIES_CORE := $(SOURCES_CORE:.cpp=.d)

# ------------------------------------------------------------
# Test programs
# ------------------------------------------------------------

SOURCES_TESTS := \
	src/tests.cpp

OBJECTS_TESTS := \
	$(SOURCES_TESTS:.cpp=.o)

DEPENDENCIES_TESTS := \
	$(SOURCES_TESTS:.cpp=.d)

PROGRAMS_TESTS := \
	$(SOURCES_TESTS:.cpp=)

	
# ------------------------------------------------------------
# All files
# ------------------------------------------------------------

SOURCES := \
	$(SOURCES_CORE) \
	$(SOURCES_TESTS)

HEADERS := \
	$(HEADERS_CORE)

OBJECTS := \
	$(OBJECTS_CORE) \
	$(OBJECTS_TESTS)

DEPENDENCIES := \
	$(DEPENDENCIES_CORE) \
	$(DEPENDENCIES_TESTS)

PROGRAMS := \
	$(PROGRAMS_TESTS)

# ------------------------------------------------------------
# Standard target
# ------------------------------------------------------------

all: $(PROGRAMS_TESTS) # $(PROGRAMS_EXAMPLES)

# ------------------------------------------------------------
# Build configuration
# ------------------------------------------------------------

CC = gcc-11
CFLAGS = -std=c++11 -fPIC -fopenmp -Wall -Wextra
LDFLAGS = -Wl,-L,.,-lstdc++
RM = rm
AR = gcc-ar-11
ARFLAGS = rcs

# ------------------------------------------------------------
# Rules for test programs
# ------------------------------------------------------------

$(PROGRAMS_TESTS): %: %.o
	echo Building $@
	$(CC) $(LDFLAGS) $< -o $@

$(OBJECTS_TESTS): %.o: %.cpp
	echo Building $@
	$(CC) $(CFLAGS) -I src -c $< -o $@

-include $(DEPENDENCIES_TESTS)
$(OBJECTS_TESTS): Makefile

# ------------------------------------------------------------
# Rules for the main library
# ------------------------------------------------------------

# quicksort.a: $(OBJECTS_CORE)
# 	echo Building $@
# 	$(AR) $(ARFLAGS) $@ $(OBJECTS_CORE)

# $(OBJECTS_CORE): %.o: %.cpp
# 	echo Compiling $<
# 	$(CC) -MT $@ -MM $< > $(<:%.cpp=%.d)
# 	$(CC) $(CFLAGS) -I src -c $< -o $@

-include $(DEPENDENCIES_CORE)
$(OBJECTS_CORE): Makefile

# ------------------------------------------------------------
# Useful additions
# ------------------------------------------------------------

.PHONY: clean programs

clean:
	$(RM) -f $(OBJECTS) $(DEPENDENCIES) $(PROGRAMS)