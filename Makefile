CC = g++
CFLAGS = -g -Wall -Werror -std=c++11

# all: first second

all: first

first: first.o bulk_send_service_installer.o bulk_send_service.o packet_sink_service_installer.o packet_sink_service.o echo_service_installer.o echo_service.o host.o link_installer.o link.o manual_router.o message_service_installer.o message_service.o node.o router.o service_installer.o simulator.o object.o
	$(CC) $(CFLAGS) -o first first.o bulk_send_service_installer.o bulk_send_service.o packet_sink_service_installer.o packet_sink_service.o echo_service_installer.o echo_service.o host.o link_installer.o link.o manual_router.o message_service_installer.o message_service.o node.o router.o service_installer.o simulator.o object.o

first.o: scenarios/first.cpp 
	$(CC) $(CFLAGS) -c scenarios/first.cpp 

# second.o: scenarios/second.cpp 
# 	$(CC) $(CFLAGS) -c scenarios/second.cpp 

bulk_send_service_installer.o: bulk_send_service_installer.cpp bulk_send_service_installer.h
	$(CC) $(CFLAGS) -c bulk_send_service_installer.cpp -o bulk_send_service_installer.o

bulk_send_service.o: bulk_send_service.cpp bulk_send_service.h
	$(CC) $(CFLAGS) -c bulk_send_service.cpp -o bulk_send_service.o

packet_sink_service_installer.o: packet_sink_service_installer.cpp packet_sink_service_installer.h
	$(CC) $(CFLAGS) -c packet_sink_service_installer.cpp -o packet_sink_service_installer.o

packet_sink_service.o: packet_sink_service.cpp packet_sink_service.h
	$(CC) $(CFLAGS) -c packet_sink_service.cpp -o packet_sink_service.o

echo_service_installer.o: echo_service_installer.cpp echo_service_installer.h
	$(CC) $(CFLAGS) -c echo_service_installer.cpp

echo_service.o: echo_service.cpp echo_service.h
	$(CC) $(CFLAGS) -c echo_service.cpp

host.o: host.cpp host.h
	$(CC) $(CFLAGS) -c host.cpp

link_installer.o: link_installer.cpp link_installer.h
	$(CC) $(CFLAGS) -c link_installer.cpp

link.o: link.cpp link.h
	$(CC) $(CFLAGS) -c link.cpp

manual_router.o: manual_router.cpp manual_router.h
	$(CC) $(CFLAGS) -c manual_router.cpp

message_service_installer.o: message_service_installer.cpp message_service_installer.h
	$(CC) $(CFLAGS) -c message_service_installer.cpp

message_service.o: message_service.cpp message_service.h
	$(CC) $(CFLAGS) -c message_service.cpp

node.o: node.cpp node.h
	$(CC) $(CFLAGS) -c node.cpp

router.o: router.cpp router.h
	$(CC) $(CFLAGS) -c router.cpp

service_installer.o: service_installer.cpp service_installer.h
	$(CC) $(CFLAGS) -c service_installer.cpp

simulator.o: simulator.cpp simulator.h
	$(CC) $(CFLAGS) -c simulator.cpp

object.o: object.cpp object.h
	$(CC) $(CFLAGS) -c object.cpp

clean:
	del /Q *.o first.exe
# clean:
# 	del /Q *.o first.exe second.exe