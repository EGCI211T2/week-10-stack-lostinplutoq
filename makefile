
CC = g++
CFLAGS = -I.
DEPS = node.h queue.h

# เป้าหมายหลักคือสร้างไฟล์ queue
all: queue

# วิธีสร้างไฟล์ queue จาก main.cpp
queue: main.cpp $(DEPS)
	$(CC) main.cpp -o queue

# คำสั่งรันเทส (ตามโจทย์ของคุณ)
run: queue
	./queue 1 2 3 2 x 3 2 x

clean:
	rm -f queue