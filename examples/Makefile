#
# Makefile:

ifneq ($V,1)
Q ?= @
endif

#DEBUG	= -g -O0
DEBUG	= -O3
CFLAGS	= $(DEBUG) -Wall  -Winline -pipe

LDLIBS    = -lpi-i2c

###############################################################################ˆ˙

SRC	=	DS3231.c \
		testMCP23017.c \
		egpio.c \
		bench-egpio.c


OBJ	=	$(SRC:.c=.o)

BINS	=	$(SRC:.c=)
# BINS	=	$(SRC:.c=.cpp=)

all:	$(BINS)

DS3231: DS3231.c
	$(CC) $(CFLAGS) $@.c $(LDLIBS) -o $@

testMCP23017: testMCP23017.c
	$(CC) $(CFLAGS) $@.c $(LDLIBS) -o $@

egpio: egpio.c
	$(CC) $(CFLAGS) $@.c $(LDLIBS) -o $@

bench-egpio: bench-egpio.c
	$(CC) $(CFLAGS) $@.c $(LDLIBS) -o $@

.c.o:
	$Q echo [CC] $<
	$Q $(CC) -c $(CFLAGS) $< -o $@

# .cpp.o:
# 	$Q echo [CC] $<
# 	$Q $(CC) -c $(CFLAGS) $< -o $@

clean:
	$Q echo "[Clean]"
	$Q rm -f *.o *~ core tags $(BINS)
