LIB_NAME := libfp.a
TEST_NAME := tests

CXX := c++

CXXFLAGS := -Wall -Werror -Wextra -std=c++98 -MMD -g3

SOURCES_DIR := src/
BUILD_DIR := build/
INCLUDES_DIR := includes/

OBJ := $(BUILD_DIR)FileParser.o \
	$(BUILD_DIR)Object.o \
	$(BUILD_DIR)Module.o \
	$(BUILD_DIR)Variable.o \

TEST_OBJ := $(BUILD_DIR)tests/test.o

INCLUDES := -I$(INCLUDES_DIR)

DEPS := ${OBJ:.o=.d} ${MAIN_OBJ:.o=.d} ${TEST_OBJ:.o=.d}

#############################################################################

$(LIB_NAME): $(OBJ)
	ar -rc $(LIB_NAME) $(OBJ)

$(TEST_NAME): $(LIB_NAME) $(TEST_OBJ)
	$(CXX) $(TEST_OBJ) -o $(TEST_NAME) -L. -lfp

test: $(TEST_NAME)
	valgrind ./$(TEST_NAME)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)
	mkdir $(BUILD_DIR)tests

$(BUILD_DIR)%.o: $(SOURCES_DIR)%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

all: $(LIB_NAME)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(LIB_NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test

-include $(DEPS)