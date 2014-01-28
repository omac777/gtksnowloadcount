all: gtksnowloadcount  

gtksnowloadcount:
	g++ -std=gnu++11  -c gtksnowloadcountassistant.cc `pkg-config gtkmm-3.0 --cflags --libs` -lboost_system -lboost_filesystem -lboost_serialization -lboost_iostreams -lboost_date_time
	g++ -std=gnu++11  -c gtksnowloadcountmain.cc `pkg-config gtkmm-3.0 --cflags --libs` -lboost_system -lboost_filesystem -lboost_serialization -lboost_iostreams -lboost_date_time
	g++ -std=gnu++11  -c snldb.cc `pkg-config gtkmm-3.0 --cflags --libs` -lboost_system -lboost_filesystem -lboost_serialization -lboost_iostreams -lboost_date_time
	g++ -std=gnu++11  gtksnowloadcountassistant.o gtksnowloadcountmain.o snldb.o -o gtksnowloadcount `pkg-config gtkmm-3.0 --cflags --libs` -lboost_system -lboost_filesystem -lboost_serialization -lboost_iostreams -lboost_date_time

