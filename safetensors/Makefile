ROOT_DIR := ..
INC_DIR  := $(ROOT_DIR)/include
CXXFLAGS := -std=c++20 -I$(INC_DIR) 

ckpt_reader: ckpt_reader.o
	$(CXX) $(CXXFLAGS) -o $@ $^