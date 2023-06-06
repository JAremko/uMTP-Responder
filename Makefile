CC:=/home/jare/Desktop/zara/zara_buildroot2/prebuilts/toolchains/mips-gcc720-glibc229/bin/mips-linux-gnu-gcc

override CFLAGS += -I./inc -lpthread -Wall -O3

sources := $(wildcard src/*.c)
objects := $(sources:src/%.c=obj/%.o)

ops_sources := $(wildcard src/mtp_operations/*.c)
ops_objects := $(ops_sources:src/mtp_operations/%.c=obj/%.o)

all: umtprd

umtprd: $(objects) $(ops_objects)
	${CC} -o $@    $^ $(LDFLAGS) -lpthread

$(objects): obj/%.o: src/%.c | output_dir
	${CC} -o $@ $^ -c $(CPPFLAGS) $(CFLAGS)

$(ops_objects): obj/%.o: src/mtp_operations/%.c | output_dir
	${CC} -o $@ $^ -c $(CPPFLAGS) $(CFLAGS)

output_dir:
	@mkdir -p obj

clean:
	rm -Rf  *.o  .*.o  .*.o.* *.ko  .*.ko  *.mod.* .*.mod.* .*.cmd umtprd obj
