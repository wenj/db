pf_module.o: pf/pf_buffermgr.cc pf/pf_error.cc pf/pf_filehandle.cc utils/statistics.cc \
			 pf/pf_hashtable.cc pf/pf_manager.cc pf/pf_pagehandle.cc pf/pf_statistics.cc pf/pf_test1.cc
	g++ -c pf/pf_buffermgr.cc pf/pf_error.cc pf/pf_filehandle.cc \
			 pf/pf_hashtable.cc pf/pf_manager.cc pf/pf_pagehandle.cc pf/pf_statistics.cc pf/pf_test1.cc
			 
main: pf_buffermgr.o pf_error.o pf_filehandle.o pf_hashtable.o pf_manager.o pf_pagehandle.o pf_statistics.o pf_test1.o statistics.o
	g++ -o main pf_buffermgr.o pf_error.o pf_filehandle.o pf_hashtable.o pf_manager.o pf_pagehandle.o pf_statistics.o pf_test1.o statistics.o
