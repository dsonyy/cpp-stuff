// error.h -- list of error codes
#pragma once
#include <string>

#define error_code	unsigned int

#define NO_ERRORS				0x0

// ----------------------------------------------------------------------------
// error codes caused by player


// the entity with you are working has too few items to complete given operation
#define ERROR_TOO_FEW_RESOURCES			0x1 

// the entity with you are working has too much items to complete given operation
#define ERROR_TOO_MANY_RESOURCES		0x2

// the entity with you are working can't recognize given item
#define ERROR_UNKNOWN_RESOURCE			0x4



// ----------------------------------------------------------------------------
// error codes caused by program
