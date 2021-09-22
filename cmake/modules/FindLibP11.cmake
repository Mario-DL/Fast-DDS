# Find libp11 
#
#  LIBP11_INCLUDE_DIR
#  LIBP11_LIBRARIES
#  LIBP11_FOUND

IF (LIBP11_INCLUDE_DIR)
  SET(LIBP11_FIND_QUIETLY TRUE)
ENDIF (LIBP11_INCLUDE_DIR)

FIND_PATH(LIBP11_INCLUDE_DIR libp11.h)

SET(LIBP11_NAMES p11 libp11)
FIND_LIBRARY(LIBP11_LIBRARY NAMES ${LIBP11_NAMES} )

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LibP11 DEFAULT_MSG LIBP11_LIBRARY LIBP11_INCLUDE_DIR)

IF(LIBP11_FOUND)
  SET( LIBP11_LIBRARIES ${LIBP11_LIBRARY} )
ELSE(LIBP11_FOUND)
  SET( LIBP11_LIBRARIES )
ENDIF(LIBP11_FOUND)

MARK_AS_ADVANCED( LIBP11_LIBRARY LIBP11_INCLUDE_DIR )

MESSAGE(${LIBP11_FOUND})
MESSAGE(${LIBP11_INCLUDE_DIR})
MESSAGE(${LIBP11_LIBRARIES})
