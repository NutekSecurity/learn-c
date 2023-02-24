CC = cc
CFLAGS = -std=c11 -Wall -Wextra -Werror 
CURLCFLAGS = `curl-config --cflags`
CURLFLAGS = `curl-config --libs`
JSONCFLAGS = `pkg-config --cflags json-c`
JSONFLAGS = `pkg-config --libs json-c`

SRC = curl.c
CURL = curl
UNITY_SRC = ../unity/unity.c

TEST = test
DEBUG = debug
.PHONY: all clean

# create curl library
all: $(SRC)
	$(CC) $(CFLAGS) $(CURLCFLAGS) $(JSONCFLAGS) -fPIC -shared $^ -o $(CURL) $(CURLFLAGS) $(JSONFLAGS)

# create test executable in debug mode
$(DEBUG): $(TEST).c $(UNITY_SRC)
	$(CC) $(CFLAGS) -I../unity $(CURLCFLAGS) $(JSONCFLAGS) -g $^ -o $@ $(CURLFLAGS) $(JSONFLAGS)

# run test executable
$(TEST): $(TEST).c $(UNITY_SRC)
	$(CC) $(CFLAGS) -I../unity $(CURLCFLAGS) $(JSONCFLAGS) $^ -o $@ $(CURLFLAGS) $(JSONFLAGS)
	./$(TEST)

# clean up
clean:
	rm -f *.o
	rm -f $(TEST)
	rm -rf *.dSYM
	rm -f $(DEBUG)
	rm -f $(CURL)


