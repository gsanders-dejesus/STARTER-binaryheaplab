CXX = g++
CXXFLAGS = -Wall -std=c++17

examheap: examheap.cpp heap.cpp
	$(CXX) $(CXXFLAGS) examheap.cpp heap.cpp -o examheap

clean:
	rm -f examheap
