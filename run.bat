g++ -c pf/pf_buffermgr.cc pf/pf_error.cc pf/pf_filehandle.cc pf/pf_hashtable.cc pf/pf_manager.cc pf/pf_pagehandle.cc pf/pf_statistics.cc utils/statistics.cc rm/rm_filehandle.cc rm/rm_manager.cc rm/rm_record.cc rm/rm_rid.cc rm/rm_filescan.cc rm/rm_manager.cc rm/rm_test.cc rm/rm_error.cc -DPF_STATS
g++ -o main pf_buffermgr.o pf_error.o pf_filehandle.o pf_hashtable.o pf_manager.o pf_pagehandle.o pf_statistics.o rm_test.o statistics.o rm_filehandle.o rm_filescan.o rm_manager.o rm_record.o rm_rid.o rm_error.o