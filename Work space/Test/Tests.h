#pragma once

// Before including standard headers, remove any macro definitions
#undef snprintf
// Include standard headers
#include <stdio.h>

/* Includes to use CUnit Framework */
#include <CUnit.h>	   // ASSERT macros for use in test cases, and includes other framework headers.
#include <Automated.h> // Automated interface with xml output.
#include <Basic.h>     // Basic interface with non-interactive output to stdout.
#include <Console.h>   // Interactive console interface.

/* this is our software under test */
#include "../App/App.h"

#include "../DB/DB_Manager.h"
/* Prototype Function to Run the Tests */
void Main_Test_Runner(void);

#define FIRST_USER_IN_DB 0
#define SEC_USER_IN_DB 1

#define CHANGE_PASS_SUCCESS 1
#define CHANGE_PASS_MISMATCH 0
#define UNCORRECT_CURRENT_PASS 2
#define INVALID_PASS 3

#define STANDARD 1
#define AUTOSAR 2
#define ARM 3
#define RTOS 4
#define TESTING 5
#define EMBLINUX 6


extern unsigned int Expected_MAXUSER;
extern unsigned int TestedMaxUser;
extern unsigned char ChangePass_state;
unsigned char See_Ifo_state;
extern unsigned char num_of_courses_user1;
extern unsigned int num_of_users_DB;
extern unsigned int num_of_courses_DB;
extern unsigned int num_of_trials;
extern unsigned int num_of_users_firstCourse;
extern unsigned char Login_num_of_trials;