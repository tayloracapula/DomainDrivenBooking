PROJECT_NAME := leaveBookingServer

SRCDIR := src
BUILDDIR := build
OBJDIR := $(BUILDDIR)/obj
BINDIR := $(BUILDDIR)/bin

TEST_SRCDIR := tests
TEST_BUILDDIR := $(BUILDDIR)/tests
TEST_BINDIR := $(TEST_BUILDDIR)/bin

# Build configuration (overridable through command line)
CXX_STANDARD ?= c++20
OPTIMISATION ?= 2
DEBUG ?= 0
STATIC ?= 0
VERBOSE ?= 0

SOURCES := $(shell find $(SRCDIR) -name '*.cpp')
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

TEST_SOURCES := $(shell find $(TEST_SRCDIR) -name '*.cpp')
TEST_OBJECTS := $(patsubst $(TEST_SRCDIR)/%.cpp,$(TEST_BUILDDIR)/%.o,$(TEST_SOURCES))
TEST_TARGET := $(TEST_BINDIR)/tests

# Compiler configuration (overridable through command line)
CXX ?= g++
MINGW_CXX ?= x86_64-w64-mingw32-g++

# Build flags 
BASE_CXXFLAGS := -Wall -Wextra -std=$(CXX_STANDARD)
OPT_FLAGS := -O$(OPTIMISATION)
DEPFLAGS := -MMD -MP

ifeq ($(DEBUG),1)
	CXXFLAGS := $(BASE_CXXFLAGS) -g -DDEBUG
else
	CXXFLAGS := $(BASE_CXXFLAGS) $(OPT_FLAGS)
endif

ifeq ($(STATIC),1)
	LDFLAGS += -static
endif

ifeq ($(VERBOSE),1)
	Q :=
else
	Q := @
endif

INCLUDES ?= -I./include -I/usr/include/jsoncpp
LIBS ?= -ldrogon -ltrantor -ljsoncpp -lpthread -lssl -lcrypto -luuid -lz

WIN_LDFLAGS := -static
WIN_LIBS := -lm

LINUX_TARGET := $(BINDIR)/$(PROJECT_NAME)
WINDOWS_TARGET := $(BINDIR)/$(PROJECT_NAME).exe

# Default target
.PHONY: all
all: linux

# Linux build
.PHONY: linux
linux: $(LINUX_TARGET)

$(LINUX_TARGET): $(OBJECTS) | $(BINDIR)
	$(Q)$(CXX) $(OBJECTS) -o $@ $(LDFLAGS) $(LIBS)
	@echo "Linux build complete: $@"

# Windows cross compile
.PHONY: windows
windows: $(WINDOWS_TARGET)

$(WINDOWS_TARGET): CXX := $(MINGW_CXX)
$(WINDOWS_TARGET): LDFLAGS := $(WIN_LDFLAGS)
$(WINDOWS_TARGET): LIBS := $(WIN_LIBS)
$(WINDOWS_TARGET): $(OBJECTS) | $(BINDIR)
	$(Q)$(MINGW_CXX) $(OBJECTS) -o $@ $(WIN_LDFLAGS) $(WIN_LIBS)
	@echo "Windows build complete: $@"

# Debug build 
.PHONY: debug
debug:
	$(MAKE) DEBUG=1

# Object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	mkdir -p $(dir $@)
	$(Q)$(CXX) $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiled: $<"

# Create directories
$(OBJDIR):
	$(Q)mkdir -p $(OBJDIR)

$(BINDIR):
	$(Q)mkdir -p $(BINDIR)

# Build both platforms
.PHONY: both
both: linux windows

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)
	rm -f $(LINUX_TARGET)
	rm -f $(WINDOWS_TARGET)
	@echo "Build artifacts removed"


.PHONY: check
check:
	@echo "Checking for required tools..."
	@command -v $(CXX) >/dev/null 2>&1 || { echo "$(CXX) not found!"; exit 1; }
	@command -v $(MINGW_CXX) >/dev/null 2>&1 || { echo "MinGW not found! Install with: sudo apt install g++-mingw-w64"; exit 1; }
	@echo "All tools available!"

# Show current configuration
.PHONY: config
config:
	@echo "Build Configuration:"
	@echo "  PROJECT_NAME: $(PROJECT_NAME)"
	@echo "  VERSION: $(VERSION)"
	@echo "  CXX_STANDARD: $(CXX_STANDARD)"
	@echo "  OPTIMIZATION: $(OPTIMIZATION)"
	@echo "  DEBUG: $(DEBUG)"
	@echo "  STATIC: $(STATIC)"
	@echo "  VERBOSE: $(VERBOSE)"
	@echo "  CXX: $(CXX)"
	@echo "  CXXFLAGS: $(CXXFLAGS)"
	@echo "  INCLUDES: $(INCLUDES)"
	@echo "  LIBS: $(LIBS)"

.PHONY: test
test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJECTS) | $(TEST_BINDIR)
	$(Q)$(CXX) $(TEST_OBJECTS) -o $@ $(LDFLAGS)

$(TEST_BUILDDIR)/%.o: $(TEST_SRCDIR)/%.cpp
	mkdir -p $(dir $@)
	$(Q)$(CXX) $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) -I./tests/include -c $< -o $@

$(TEST_BUILDDIR):
	$(Q)mkdir -p $(TEST_BUILDDIR)

$(TEST_BINDIR):
	$(Q)mkdir -p $(TEST_BINDIR)

DEPS := $(OBJECTS:.o=.d)
TEST_DEPS := $(TEST_OBJECTS:.o=.d)

-include $(DEPS)
-include $(TEST_DEPS)
