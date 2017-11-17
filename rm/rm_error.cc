#include <cerrno>
#include <cstdio>
#include <iostream>
#include "rm.h"

using namespace std;

static char *RM_WarnMsg[] = {
  (char*)"reach the end of file"
};

static char *RM_ErrorMsg[] = {
  (char*)"no record",
  (char*)"file not exist",
  (char*)"rid not exist",
  (char*)"slot number not exist",
  (char*)"record not exist",
  (char*)"scan has opened",
  (char*)"scan not open",
  (char*)"scan invalid",
  (char*)"unknown error",
  (char*)"size too big",
  (char*)"size invalid",
};

void RM_PrintError(RC rc)
{
  // Check the return code is within proper limits
  if (rc >= START_RM_WARN && rc <= END_RM_WARN)
    // Print warning
    cerr << "RM warning: " << RM_WarnMsg[rc - START_RM_WARN] << "\n";
  // Error codes are negative, so invert everything
  else if (-rc >= -START_RM_ERR && -rc < -END_RM_ERR)
    // Print error
    cerr << "RM error: " << RM_ErrorMsg[-rc + START_RM_ERR] << "\n";
  else if (rc >= START_PF_WARN && rc <= PF_LASTWARN)
    // Print warning
    cerr << "PF warning: " << rc << "\n";
  // Error codes are negative, so invert everything
  else if (-rc >= -START_PF_ERR && -rc < -PF_LASTERROR)
    // Print error
    cerr << "PF error: " << rc << "\n";
  else if (rc == PF_UNIX)
#ifdef PC
      cerr << "OS error\n";
#else
      cerr << "???" << "\n";
#endif
  else if (rc == 0)
    cerr << "PF_PrintError called with return code of 0\n";
  else
    cerr << "PF error: " << rc << " is out of bounds\n";
}