#include "Tests.h"

/* Test Code to test the Sign Up */
static struct User_Input_Type Test1_User =
{
	{
	-1, // this is to indecate user hasn't assigned ID 
	"Mahmoud",
	26,
	23,
	10,
	1998,
	Male,
	Masters_Student
	},
	{
		{
			"EdgesAcademy",
			"Edges123"
		},
	"Edges123"
	}
};

/* Test Code to test the Sign Up */
static struct User_Input_Type Test2_User =
{
	{
	-1, // this is to indecate user hasn't assigned ID 
	"Reda",
	53,
	31,
	12,
	1970,
	Female,
	PHD_Holder
	},
	{
		{
			"AdminUser1",
			"Edges_123_$$"
		},
	"Edges_123_$$"
	}
};

static struct User_Input_Type Test3_User =
{
	{
	-1, // this is to indecate user hasn't assigned ID 
	"Ashoush",
	23,
	20,
	6,
	2001,
	Female,
	Graduate
	},
	{
		{
			"EdgesAcademy",
			"Edges_123_"
		},
	"Edges_123_"
	}
};



static struct LoginCredentials_Type  testUser1 = 
{
	"AdminUser1",
	"Edges_123"
};

/**************************************** Admin/User Register new acc Test cases *******************************************/
/* init function for Test Suite 1*/
static unsigned char test1_Register_start(void)
{
	unsigned char RET = Add_Account(&Test1_User);
	Test1_User.PersonalInfo_Form.id = current_user_test-1;
	DBM_PrintUsers();
	return !RET;
}

/* Closure Function For Test Suite 1*/
static unsigned char test1_Register_end(void)
{
	unsigned char RET = Delete_Account(current_user_test-1);
	DBM_PrintUsers();
	return !RET;
}

/* init function for Test Suite 2*/
static unsigned char test2_Register_start(void)
{
	unsigned char RET = Add_Account(&Test2_User);
	Test2_User.PersonalInfo_Form.id = current_user_test - 1;
	DBM_PrintUsers();
	return !RET;
}

/* Closure Function For Test Suite 1*/
static unsigned char test2_Register_end(void)
{
	unsigned char RET = Delete_Account(current_user_test - 1);
	DBM_PrintUsers();
	return !RET;
}

/************************************************************************************
* Test ID                : TestCase 1
* Description            : Testing the Add Account Functionality
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Ahmed
*                          Age                          -> 26
*                          DOB_day                      -> 01
*                          DOB_Month                    -> 02
*                          DOB_Year                     -> 1999
*                          Educational_Status           -> Masters_Student
*                          Gender                       -> Male
*                          UserName                     -> EdgesAcademy
*                          Password                     -> Edges123
*                          Password Recheck             -> Edges123
* Test Expected output   : The DB should be updated with the previous inputs correctly
* Reason                 : All inputs are in correct format
*************************************************************************************/
static void TestCase1(void)
{
	unsigned int Test_id = Test1_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test1_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test1_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test1_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test1_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test1_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test1_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test1_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test1_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test1_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test1_User.PersonalInfo_Form.id);
}


/************************************************************************************
* Test ID                : TestCase 2
* Description            : Testing the Add Account Functionality
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 31
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges123
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : Password inputs mismatch so the suite willn't initiallize 
*************************************************************************************/
static void TestCase2(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}


/***************************************** Name ***************************************************/

/************************************************************************************
* Test ID                : TestCase_Register_negative_name
* Description            : Testing the Add Account Functionality -> Numeric input for the name field
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> 226
*                          Age                          -> 54
*                          DOB_day                      -> 31
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : Name include numeric data which is not accepted
*************************************************************************************/
static void TestCase_Register_negative_name(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/*************************************************************************************************************/

/******************************************** Age *****************************************************/

/************************************************************************************
* Test ID                : TestCase_Register_zero_age
* Description            : Testing the Add Account Functionality -> if the zero aged accepted or not
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 0
*                          DOB_day                      -> 31
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : Age zero is unaccepted
*************************************************************************************/
static void TestCase_Register_zero_age(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}


/************************************************************************************
* Test ID                : TestCase_Register_unsuitable_age
* Description            : Testing the Add Account Functionality -> check if the age calculated from the input DOB and match the given age
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 22
*                          DOB_day                      -> 31
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : calculated age and given age not matched
*************************************************************************************/
static void TestCase_Register_unsuitable_age(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase_Register_0Age_suitableYear
* Description            : Testing the Add Account Functionality -> check if the age calculated from the input DOB and match the given age
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 0
*                          DOB_day                      -> 2
*                          DOB_Month                    -> 10
*                          DOB_Year                     -> 2024
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : Age is zero 
*************************************************************************************/
static void TestCase_Register_0Age_suitableYear(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}
/*************************************************************************************************************/

/******************************************** DOB ****************************************************/

/************************************************************************************
* Test ID                : TestCase_Register_incorrect_day_zero
* Description            : Testing the Add Account Functionality -> zero input for the day field
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 0
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : there is no day zero
*************************************************************************************/
static void TestCase_Register_incorrect_day_zero(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}


/************************************************************************************
* Test ID                : TestCase_Register_incorrect_day
* Description            : Testing the Add Account Functionality ->input large than 31
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : there is no day large than 31
*************************************************************************************/
static void TestCase_Register_incorrect_day(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase_Register_incorrect_month_zero
* Description            : Testing the Add Account Functionality -> if the month zero accepted or not
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 0
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : No month zero
*************************************************************************************/
static void TestCase_Register_incorrect_month_zero(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}


/************************************************************************************
* Test ID                : TestCase_Register_incorrect_month
* Description            : Testing the Add Account Functionality -> if any num large than 12 accepted or not 
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 13
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : number of months 12 only
*************************************************************************************/
static void TestCase_Register_incorrect_month(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}



/************************************************************************************
* Test ID                : TestCase_Register_incorrect_year_zero
* Description            : Testing the Add Account Functionality -> if the zero year accepted or not
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 0
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : year 0 is not logical
*************************************************************************************/
static void TestCase_Register_incorrect_year_zero(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}


/************************************************************************************
* Test ID                : TestCase_Register_incorrect_year
* Description            : Testing the Add Account Functionality -> years above 2024
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 2025
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : years in the future not accepted
*************************************************************************************/
static void TestCase_Register_incorrect_year(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/*************************************************************************************************************/

/********************************************** ED Status *************************************************/

/************************************************************************************
* Test ID                : TestCase_Register_EDstatus_zero
* Description            : Testing the Add Account Functionality -> zero (unprovided in the list)
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : No choice zero in the provided list
*************************************************************************************/
static void TestCase_Register_EDstatus_zero(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase_Register_EDstatus_age_invalid
* Description            : unsuitable age for a specific Educational status
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 1
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 2023
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : age compared to the given age is not logical
*************************************************************************************/
static void TestCase_Register_EDstatus_age_invalid(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

static void TestCase_Register_EDstatus_string(void) {
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
}

/*************************************************************************************************************/

/******************************************** Gender **************************************************/

/************************************************************************************
* Test ID                : TestCase_Register_gender_zero
* Description            : Test if the zero accepted whatever its not in the list
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> 0
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : not provided in the list
*************************************************************************************/
static void TestCase_Register_gender_zero(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase_Register_gender_invalid
* Description            : If a number larger than 2 is accepted or not
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> 3
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : There is 2 choices only
*************************************************************************************/
static void TestCase_Register_gender_invalid(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}


/********************************************* User Name ***************************************************/

/************************************************************************************
* Test ID                : TestCase_Register_UN_8char
* Description            : check the boundary (8) of the number of char in the user name
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> 3
*                          UserName                     -> EdgesAca
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : inputs match with the specification 
*************************************************************************************/
static void TestCase_Register_UN_8char(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}


/************************************************************************************
* Test ID                : TestCase_Register_UN_7char
* Description            : check if a number of char in the username less than 8 is accepted or not
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> 3
*                          UserName                     -> EdgesAc
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : username must contain at leat 8 char
*************************************************************************************/
static void TestCase_Register_UN_7char(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase_Register_space
* Description            : check if the spaces accepted in the username or not
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> 3
*                          UserName                     -> E dgesAc
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : space isnt allowed in the username
*************************************************************************************/
static void TestCase_Register_UN_space(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase_Register_UN_32char
* Description            : check if number of char is larger than the upper boundary (32)
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> 3
*                          UserName                     -> EdgesAcademy11111111111111111111
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : number of char allowed is between 8 : 32
*************************************************************************************/
static void TestCase_Register_UN_32char(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase_Register_UN_33char
* Description            : check if number of char is larger than the upper boundary (32)
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> 3
*                          UserName                     -> EdgesAcademy111111111111111111111
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : number of char allowed is between 8 : 32
*************************************************************************************/
static void TestCase_Register_UN_33char(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase_Register_repetitiveUN
* Description            : check if number of char is larger than the upper boundary (32)
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> 3
*                          UserName                     -> AdminUser1
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : number of char allowed is between 8 : 32
*************************************************************************************/
static void TestCase_Register_repeatitiveUN(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}
/*************************************************************************************************************/

/********************************************* Password ***************************************************/


/************************************************************************************
* Test ID                : TestCase_Register_pass_8char
* Description            : check the lowest boundary of num of char in the pass
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> female
*                          UserName                     -> EdgesAcademy
*                          Password                     -> Edges_12
*                          Password Recheck             -> Edges_12
* Test Expected output   : The DB should be updated with the previous inputs
* Reason                 : correct inputs
*************************************************************************************/
static void TestCase_Register_pass_8char(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase_Register_pass_7char
* Description            : test if number of char less than 8 is allowed or not
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> female
*                          UserName                     -> EdgesAcademy
*                          Password                     -> Edges_1
*                          Password Recheck             -> Edges_1
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : number of char allowed is between 8 : 32
*************************************************************************************/
static void TestCase_Register_pass_7char(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase_Register_pass_space
* Description            : check if the pass contained spaces accepted or not
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> 3
*                          UserName                     -> E dgesAc
*                          Password                     -> Edges_1 2
*                          Password Recheck             -> Edges_1 2
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : spaces is not allowed in the pass
*************************************************************************************/
static void TestCase_Register_pass_space(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase_Register_pass_32char
* Description            : check the upper boundary of the num of char in the pass
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> female
*                          UserName                     -> EdgesAcademy
*                          Password                     -> EdgesAcademy11111111111111111111
*                          Password Recheck             -> EdgesAcademy11111111111111111111
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : number of char allowed is between 8 : 32
*************************************************************************************/
static void TestCase_Register_pass_32char(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase_Register_pass_33char
* Description            : check the upper boundary of the num of char in the pass
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> female
*                          UserName                     -> EdgesAcademy
*                          Password                     -> EdgesAcademy111111111111111111111
*                          Password Recheck             -> EdgesAcademy111111111111111111111
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : number of char allowed is between 8 : 32
*************************************************************************************/
static void TestCase_Register_pass_33char(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase_Register_invalid_reenter_pass
* Description            : unsuitable age for a specific Educational status
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 32
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> 3
*                          UserName                     -> EdgesAcademy
*                          Password                     -> Edges_123_$$
*                          Password Recheck             -> Edges_123_$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : Name include numeric data which is not accepted
*************************************************************************************/
static void TestCase_Register_invalid_reenter_pass(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}
/*************************************************************************************************************/

/********************************************** End of Admin / User Register new Acc *********************************************/

/********************************************** Admin Delete user *********************************************/
static unsigned char test1_Admin_DeleteUser_start(void)
{
	unsigned char RET=Add_Account(&Test1_User);
	Test1_User.PersonalInfo_Form.id = current_user_test - 1;
	return !RET;
}

 //Closure Function For Test Suite 
static unsigned char test1_Admin_DeleteUser_end(void)
{
	printf("End of Admin delete account suit");
	return 0;
}

/************************************************************************************
* Test ID                : TestCase_Admin_DeleteUser
* Description            : Test the module of Delete account
* Pre-requisits          : There is a User Assigned to DB 
* Test inputs            : User ID from the DB
* Test Expected output   : Current user ID while be = to the expected current user after delete the Test1_User
*************************************************************************************/
static void TestCase_Admin_DeleteUser(void) {
	unsigned int Test_id = Test1_User.PersonalInfo_Form.id;
	unsigned int expedcted_currentUser_id = Test_id;
	Delete_Account(Test_id);
	CU_ASSERT_EQUAL(expedcted_currentUser_id, (current_user_test));
}
/********************************************** End of Admin Delete user *********************************************/

/********************************************** Admin Print All users *********************************************/
static unsigned char Test_Admin_PrintAll_start(void)
{
	DBM_PrintUsers();
	return 0;
}

static unsigned char Test_Admin_PrintAll_end(void)
{
	return 0;
}

/************************************************************************************
* Test ID                : TestCase_Admin_PrintAll_numOfUsers
* Description            : Test the module of Print all users
* Pre-requisits          : There is a Users Assigned to DB
* Test inputs            : Number of actual number of users in DB
* Test Expected output   : Users info
*************************************************************************************/
static void TestCase_Admin_PrintAll_numOfUsers(void) {
	unsigned int Actual_NumOfUsers = num_of_users_DB;
	unsigned int Expected_NumOfUsers = 3;
	printf("Actual_NumOfUsers= %d   Expected_NumOfUsers= %d", Actual_NumOfUsers, Expected_NumOfUsers);
	CU_ASSERT_EQUAL(Actual_NumOfUsers, Expected_NumOfUsers);
}
/********************************************** End of Admin Print All users *********************************************/

/********************************************** Admin check available courses *********************************************/
static unsigned char Test_Admin_availableCourses_start(void) {
	DBM_CheckReservations();
	return 0;
}

static unsigned char Test_Admin_availableCourses_end(void) {
	return 0;
}

/************************************************************************************
* Test ID                : TestCase_Admin_availableCourses
* Description            : Test the module of check available courses
* Pre-requisits          : There is a courses in the DB
* Test inputs            : Number of actual number of courses in DB
* Test Expected output   : available courses = 6
*************************************************************************************/
static void TestCase_Admin_availableCourses(void) {
	unsigned int Actual_numOfCourses = num_of_courses_DB;
	unsigned int Expected_numOfCourses = 6;
	CU_ASSERT_EQUAL(Actual_numOfCourses, Expected_numOfCourses);
}
/****************************************** End of Admin check available courses *****************************************/

/*************************************************** User Login *********************************************************/

static unsigned char Test_User_Login_start(void) {
	printf("Test suite for login started");
	return 0;
}

static unsigned char Test_User_Login_end(void) {
	printf("Test suite for login ended");
	return 0;
}

/************************************************************************************
* Test ID                : TestCase_User_Login_Successfully
* Description            : Test functionality of login successfully
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            : User name : AdminUser1
*						   Password  : Edges123
* Test Expected output   : Login Successfully
*************************************************************************************/
static void TestCase_User_Login_Successfully(void)
{
	unsigned int Test_id = FIRST_USER_IN_DB;
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, testUser1.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, testUser1.Password);
}

/************************************************************************************
* Test ID                : TestCase_User_Wrong_US
* Description            : Test functionality of login 
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            : User name : adminUser1
*						   Password  : Edges123
* Test Expected output   : Login failed
*************************************************************************************/
static void TestCase_User_Wrong_US(void)
{
	unsigned int Test_id = FIRST_USER_IN_DB;
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, testUser1.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, testUser1.Password);
}

/************************************************************************************
* Test ID                : TestCase_User_Wrong_Pass
* Description            : Test functionality of login
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            : User name : AdminUser1
*						   Password  : E dges12
* Test Expected output   : Login failed
*************************************************************************************/
static void TestCase_User_Wrong_Pass(void)
{
	unsigned int Test_id = FIRST_USER_IN_DB;
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, testUser1.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, testUser1.Password);
}

static void TestCase_UserLogin_trials(void) {
	Customer_Runner();
	unsigned char Actual_trials = Login_num_of_trials;
	unsigned char Expected_trials = 3;
	CU_ASSERT_EQUAL(Actual_trials, Expected_trials);
}
/******************************************** End of User Login *******************************************/

/******************************************** User change pass *******************************************/

static unsigned char Test_User_ChangePass_start(void)
{
	Customer_Runner();	
	printf("Test suite for login started");
	return 0;
}

static unsigned char Test_User_ChangePass_end(void)
{
	printf("Test suite for Change Pass ended");
	return 0;
}

/************************************************************************************
* Test ID                : TestCase_ChangePass_successfully
* Description            : Test functionality of change password
* Pre-requisits          : There is a User Assigned to DB , login
* Test inputs            : User name        : AdminUser1
*						   Password         : Edges123
*						   new password     : Testing123
*						   reenter password : Testing123
* Test Expected output   : Password change successfully
*************************************************************************************/
static void TestCase_ChangePass_successfully(void)
{
	unsigned char Actual_ChangePass_state = ChangePass_state;
	unsigned char Expected_ChangePass_state = CHANGE_PASS_SUCCESS;
	CU_ASSERT_EQUAL(Actual_ChangePass_state, Expected_ChangePass_state);
}

/************************************************************************************
* Test ID                : TestCase_ChangePass_mismatch
* Description            : Test functionality of change password (mismatched passwords)
* Pre-requisits          : There is a User Assigned to DB , login
* Test inputs            : User name        : AdminUser1
*						   Password         : Edges123
*						   new password     : Testing123
*						   reenter password : 3Testing12
* Test Expected output   : Password change faild
*************************************************************************************/
static void TestCase_ChangePass_mismatch(void)
{
	unsigned char Actual_ChangePass_state = ChangePass_state;
	unsigned char Expected_ChangePass_state = CHANGE_PASS_MISMATCH;
	CU_ASSERT_EQUAL(Actual_ChangePass_state, Expected_ChangePass_state);
}

/************************************************************************************
* Test ID                : TestCase_ChangePass_invalid_pass
* Description            : Test functionality of change password (invalid pass)
* Pre-requisits          : There is a User Assigned to DB , login
* Test inputs            : User name        : AdminUser1
*						   Password         : Edges123
*						   new password     : 1 2
*						   reenter password : 1 2
* Test Expected output   : Password change faild
*************************************************************************************/
static void TestCase_ChangePass_invalid_pass(void)
{
	unsigned char Actual_ChangePass_state = ChangePass_state;
	unsigned char Expected_ChangePass_state = INVALID_PASS;
	CU_ASSERT_EQUAL(Actual_ChangePass_state, Expected_ChangePass_state);
}

/************************************************************************************
* Test ID                : TestCase_ChangePass_invalid_pass
* Description            : Test functionality of change password (invalid pass)
* Pre-requisits          : There is a User Assigned to DB , login
* Test inputs            : User name        : AdminUser1
*						   Password         : Edge123
*						   new password     : 12345678
*						   reenter password : 12345678
* Test Expected output   : Password change faild
*************************************************************************************/
static void TestCase_ChangePass_Wrong_CurrentPass(void)
{
	unsigned char Actual_ChangePass_state = ChangePass_state;
	unsigned char Expected_ChangePass_state = UNCORRECT_CURRENT_PASS;
	CU_ASSERT_EQUAL(Actual_ChangePass_state, Expected_ChangePass_state);
}
/******************************************** End of User change pass *******************************************/
static unsigned char Test_User_see_info_start(void) {
	Customer_Runner();
	return 0;
}

static unsigned char Test_User_see_info_end(void) {
	return 0;
}

/************************************************************************************
* Test ID                : TestCase_SeeInfo_input_i
* Description            : Test functionality of See Info
* Pre-requisits          : There is a User Assigned to DB , login
* Test inputs            : User name        : AdminUser1
*						   Password         : Edge123
*						   from the list    : i
* Test Expected output   : see info of the user
*************************************************************************************/
static void TestCase_SeeInfo_input_i(void) {
	unsigned char Actual_see_info_state = See_Ifo_state;
	unsigned char Expected_see_info_state = 1;
	CU_ASSERT_EQUAL(Actual_see_info_state, Expected_see_info_state);
}

/************************************************************************************
* Test ID                : TestCase_SeeInfo_input_I
* Description            : Test functionality of See Info
* Pre-requisits          : There is a User Assigned to DB , login
* Test inputs            : User name        : AdminUser1
*						   Password         : Edge123
*						   from the list    : I
* Test Expected output   : see info of the user
*************************************************************************************/
static void TestCase_SeeInfo_input_I(void) {
	unsigned char Actual_see_info_state = See_Ifo_state;
	unsigned char Expected_see_info_state = 1;
	CU_ASSERT_EQUAL(Actual_see_info_state, Expected_see_info_state);
}
/******************************************** End of User See Info *******************************************/

/******************************************** User Reverse Course ********************************************/
static unsigned char Test_User_ReverseCourse_start(void) {
	return 0;
}

static unsigned char Test_User_ReverseCourse_end(void) {
	return 0;
}

/************************************************************************************
* Test ID                : TestCase_ReverseCourse_Enrolled
* Description            : Test functionality of Reverse course enrolled successfully
* Pre-requisits          : There is a User Assigned to DB 
* Test inputs            : Course Id  : STANDARD (1)
*						   Student Id : FIRST_USER_IN_DB (0)
* Test Expected output   : Enrolled
*************************************************************************************/
static void TestCase_ReverseCourse_Enrolled(void) {
	unsigned char Actual_Reverse_state = AddStudentToCourse(STANDARD, FIRST_USER_IN_DB); 
	unsigned char Expected_Reverse_state = Enrolled;
	CU_ASSERT_EQUAL(Actual_Reverse_state, Expected_Reverse_state);
}

/************************************************************************************
* Test ID                : TestCase_ReverseCourse_AlreadyEnrolled
* Description            : Test functionality of Reverse course already enrolled 
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            : Course Id  : TESTING (1)
*						   Student Id : FIRST_USER_IN_DB (0)
* Test Expected output   : Already Enrolled
*************************************************************************************/
static void TestCase_ReverseCourse_AlreadyEnrolled(void) {
	unsigned char Actual_Reverse_state = AddStudentToCourse(TESTING, FIRST_USER_IN_DB); 
	unsigned char Expected_Reverse_state = AlreadyEnrolled;
	CU_ASSERT_EQUAL(Actual_Reverse_state, Expected_Reverse_state);
}

/************************************************************************************
* Test ID                : TestCase_ReverseCourse_Failed
* Description            : Test functionality of Reverse course failed
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            : Course Id  :  0
*						   Student Id : FIRST_USER_IN_DB (0)
* Test Expected output   : Already Enrolled
*************************************************************************************/
static void TestCase_ReverseCourse_Failed(void) {
	unsigned char Actual_Reverse_state = (0, FIRST_USER_IN_DB);
	unsigned char Expected_Reverse_state = 3; //failed 
	printf("Actual_Reverse_state = %d    ", Actual_Reverse_state);
	printf("Expected_Reverse_state = %d", Expected_Reverse_state);
	CU_ASSERT_EQUAL(Actual_Reverse_state, Expected_Reverse_state);
}

/************************************************************************************
* Test ID                : TestCase_ReverseCourse_CapCopm
* Description            : Test functionality of Reverse course capacity compelete
* Pre-requisits          : There is a User Assigned to DB , add 3 users for the database 
						   and reverse the same course (total users 6)
* Test inputs            : Course Id  : TESTING (5)
*						   Student Id : 5
* Test Expected output   : Capacity completed
*************************************************************************************/
static void TestCase_ReverseCourse_CapCopm(void) {
	 Add_Account(&Test1_User);
	 AddStudentToCourse(TESTING, 3);
	 Add_Account(&Test2_User);
	 AddStudentToCourse(TESTING, 4);
	 Add_Account(&Test3_User);
	 unsigned char Actual_Reverse_state= AddStudentToCourse(TESTING, 5);
	 unsigned char Expected_Reverse_state = CapacityCompleted; 
	 CU_ASSERT_EQUAL(Actual_Reverse_state, Expected_Reverse_state);
}
/******************************************** End of User reverse course *******************************************/

/********************************************** User show course *********************************************/
static unsigned char Test_User_ShowCourses_start(void) {
	return 0;
}

static unsigned char Test_User_ShowCourses_end(void) {
	return 0;
}

/************************************************************************************
* Test ID                : TestCase_User_ShowCourse
* Description            : Test functionality of show enrolled courses
* Pre-requisits          : There is a User Assigned to DB 
* Test inputs            : User ID = 0
* Test Expected output   : number of enrolled courses =2 
*************************************************************************************/
static void TestCase_User_ShowCourse(void) {
	ShowStudentCourses(FIRST_USER_IN_DB);
	unsigned char Actual_numOfCourses = num_of_courses_user1;
	unsigned char Expected_numOfCourses = 2;
	CU_ASSERT_EQUAL(Actual_numOfCourses, Expected_numOfCourses);
}

/************************************************************************************
* Test ID                : TestCase_User_ShowCourse
* Description            : Test functionality of show enrolled courses
* Pre-requisits          : There is a User Assigned to DB , enroll new course
* Test inputs            : User ID = 0
* Test Expected output   : number of enrolled courses =3
*************************************************************************************/
static void TestCase_User_ShowCourse_AfterAddedNew(void) {
	AddStudentToCourse(STANDARD, FIRST_USER_IN_DB);
	ShowStudentCourses(FIRST_USER_IN_DB);
	unsigned char Actual_numOfCourses = num_of_courses_user1;
	unsigned char Expected_numOfCourses = 3;
	CU_ASSERT_EQUAL(Actual_numOfCourses, Expected_numOfCourses);
}

/************************************************************************************
* Test ID                : TestCase_User_ShowCourse
* Description            : Test functionality of show enrolled courses
* Pre-requisits          : There is a User Assigned to DB , enroll already enrolled new course
* Test inputs            : User ID = 0
* Test Expected output   : number of enrolled courses =2
*************************************************************************************/
static void TestCase_User_ShowCourse_AfterAddedNew_AE(void) {
	AddStudentToCourse(TESTING, FIRST_USER_IN_DB);
	ShowStudentCourses(FIRST_USER_IN_DB);
	unsigned char Actual_numOfCourses = num_of_courses_user1;
	unsigned char Expected_numOfCourses = 2;
	CU_ASSERT_EQUAL(Actual_numOfCourses, Expected_numOfCourses);
}
/********************************************** End of User show course *********************************************/


/*************************************************** Admin token ***************************************************/
static unsigned char Test_AdminToken_start(void) {
	return 0;
}

static unsigned char Test_AdminToken_end(void) {
	return 0;
}

/************************************************************************************
* Test ID                : TestCase_AdminToken_numOfTrials
* Description            : Test functionality of Trials for admin login
* Test inputs            : 3 times uncorrect admin token 
* Test Expected output   : Login Failed
*************************************************************************************/
static void TestCase_AdminToken_numOfTrials(void) {
	unsigned char Admin_verify_State = Verify_Admin();
	unsigned char Actual_numOfTrials = num_of_trials;
	unsigned char Expected_numOfTrials = 3;
	unsigned char Expected_verifyState = FALSE;
	CU_ASSERT_EQUAL(Actual_numOfTrials, Expected_numOfTrials);
	CU_ASSERT_EQUAL(Admin_verify_State, Expected_verifyState);
}

/************************************************************************************
* Test ID                : TestCase_AdminToken_sucess1trial
* Description            : Test functionality of Trials for admin login
* Test inputs            : 1 time uncorrect admin token then correct token
* Test Expected output   : Login success
*************************************************************************************/
static void TestCase_AdminToken_sucess1trial(void) {
	unsigned char Admin_verify_State = Verify_Admin();
	unsigned char Actual_numOfTrials = num_of_trials;
	unsigned char Expected_numOfTrials = 1;
	unsigned char Expected_verifyState = TRUE;
	CU_ASSERT_EQUAL(Actual_numOfTrials, Expected_numOfTrials);
	CU_ASSERT_EQUAL(Admin_verify_State, Expected_verifyState);

}

/************************************************************************************
* Test ID                : TestCase_AdminToken_sucess2trial
* Description            : Test functionality of Trials for admin login
* Test inputs            : 2 times uncorrect admin token then correct token
* Test Expected output   : Login success
*************************************************************************************/
static void TestCase_AdminToken_sucess2trial(void) {
	unsigned char Admin_verify_State = Verify_Admin();
	unsigned char Actual_numOfTrials = num_of_trials;
	unsigned char Expected_numOfTrials = 2;
	unsigned char Expected_verifyState = TRUE;
	CU_ASSERT_EQUAL(Actual_numOfTrials, Expected_numOfTrials);
	CU_ASSERT_EQUAL(Admin_verify_State, Expected_verifyState);
}
/************************************************* End of Admin token *************************************************/




void Main_Test_Runner(void)
{
	/* initialize the Registry */
	CU_initialize_registry();

	/**************************************** Admin / User Register new acc *******************************************/
	//Adding Test Suite to the Registry 
	CU_pSuite Register_suite_positive = CU_add_suite(" Register Create Valid Account", test1_Register_start, test1_Register_end);
	CU_pSuite Register_suite_negative = CU_add_suite(" Register Create InValid Account", test2_Register_start, test2_Register_end);
	//Adding Test Cases to the Test Suite
	CU_add_test(Register_suite_positive, " Register Create Valid Account", TestCase1);
	 //this suite is expected to fail and not to run due to to the invalid creation of the account 
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase2);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_negative_name);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_zero_age);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_unsuitable_age);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_0Age_suitableYear);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_incorrect_day_zero);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_incorrect_day);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_incorrect_month_zero);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_incorrect_month);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_incorrect_year_zero);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_incorrect_year);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_EDstatus_zero);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_EDstatus_string);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_EDstatus_age_invalid);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_gender_zero);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_gender_invalid);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_UN_8char);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_UN_7char);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_UN_space);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_UN_32char);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_UN_33char);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_pass_8char);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_pass_7char);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_pass_space);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_pass_32char);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_pass_33char);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_invalid_reenter_pass);
	CU_add_test(Register_suite_negative, " Register Create InValid Account", TestCase_Register_repeatitiveUN);
	
	/*************************************************************************************************************/

	/**************************************** Admin Delete User **********************************************/
	CU_pSuite Admin_DeleteUser_suite = CU_add_suite("Admin Delete Account Suite", test1_Admin_DeleteUser_start, test1_Admin_DeleteUser_end);
	CU_add_test(Admin_DeleteUser_suite, "Admin delete account", TestCase_Admin_DeleteUser);
	/*************************************************************************************************************/

	/***************************************** Admin Print all users **********************************************/
	CU_pSuite Admin_PrintAll_suite = CU_add_suite("Admin Print all users", Test_Admin_PrintAll_start, Test_Admin_PrintAll_end);
	CU_add_test(Admin_PrintAll_suite, "Admin Print all users", TestCase_Admin_PrintAll_numOfUsers);
	/*************************************************************************************************************/

	/*************************************** Admin Show available courses ********************************************/
	CU_pSuite Admin_AvailableCourses_suite = CU_add_suite("Admin show available courses", Test_Admin_availableCourses_start, Test_Admin_availableCourses_end);
	CU_add_test(Admin_AvailableCourses_suite, "Admin show available courses", TestCase_Admin_availableCourses);
	/****************************************************************************************************************/

	/**************************************** User Login *************************************************/
	CU_pSuite User_login_suite = CU_add_suite("User Login", Test_User_Login_start, Test_User_Login_end);
	CU_add_test(User_login_suite, "Login successfully", TestCase_User_Login_Successfully);
	CU_add_test(User_login_suite, "Login wrong username", TestCase_User_Wrong_US);
	CU_add_test(User_login_suite, "Login wrong pass", TestCase_User_Wrong_Pass);
	CU_add_test(User_login_suite, "Login wrong pass", TestCase_UserLogin_trials);
	

	/*************************************************************************************************************/

	/**************************************** User change pass *************************************************/
	CU_pSuite User_changePass_suite = CU_add_suite("User change pass", Test_User_ChangePass_start, Test_User_ChangePass_end);
	CU_add_test(User_changePass_suite, "Pass changed successfully", TestCase_ChangePass_successfully);
	CU_add_test(User_changePass_suite, "new reenter is mismatched  ", TestCase_ChangePass_mismatch);
	CU_add_test(User_changePass_suite, "Invalid Pass ", TestCase_ChangePass_invalid_pass);
	CU_add_test(User_changePass_suite, "uncorrect current Pass  ", TestCase_ChangePass_Wrong_CurrentPass);
	/***********************************************************************************************************/

	/***************************************** User see info ***************************************************/
	CU_pSuite User_seeInfo_suite = CU_add_suite("User See info", Test_User_see_info_start, Test_User_see_info_end);
	CU_add_test(User_seeInfo_suite, "User see info", TestCase_SeeInfo_input_i);
	CU_add_test(User_seeInfo_suite, "User see info", TestCase_SeeInfo_input_I);
	/***********************************************************************************************************/

	/*************************************** User Reverse Course *************************************************/
	CU_pSuite User_ReverseCourse_suite = CU_add_suite("User Reverse Course", Test_User_ReverseCourse_start, Test_User_ReverseCourse_end);
	CU_add_test(User_ReverseCourse_suite, "User Reverse Course", TestCase_ReverseCourse_Enrolled );
	CU_add_test(User_ReverseCourse_suite, "User Reverse Course", TestCase_ReverseCourse_AlreadyEnrolled);
	CU_add_test(User_ReverseCourse_suite, "User Reverse Course", TestCase_ReverseCourse_Failed);
	CU_add_test(User_ReverseCourse_suite, "User Reverse Course", TestCase_ReverseCourse_CapCopm);
	/**************************************************************************************************************/

	/*************************************** User show Reversed Courses *************************************************/
	CU_pSuite User_ShowCourses_suite = CU_add_suite("User show Reversed Courses", Test_User_ShowCourses_start, Test_User_ShowCourses_end);
	CU_add_test(User_ShowCourses_suite, "User show Reversed Courses", TestCase_User_ShowCourse );
	CU_add_test(User_ShowCourses_suite, "User show Reversed Courses", TestCase_User_ShowCourse_AfterAddedNew);
	CU_add_test(User_ShowCourses_suite, "User show Reversed Courses", TestCase_User_ShowCourse_AfterAddedNew_AE);
	/**************************************************************************************************************/
	
	/********************************************** Admin token *********************************************/
	CU_pSuite Admin_Token_suite = CU_add_suite(" verify admin token", Test_AdminToken_start, Test_AdminToken_end);
	CU_add_test(Admin_Token_suite, "verify admin token number of trials", TestCase_AdminToken_numOfTrials);
	CU_add_test(Admin_Token_suite, "verify admin token number of trials", TestCase_AdminToken_sucess1trial);
	CU_add_test(Admin_Token_suite, "verify admin token number of trials", TestCase_AdminToken_sucess2trial);
	/**************************************************************************************************************/




	/* Running the Test Suite through Basic Console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	//CU_basic_run_tests();

	/* Running the Test Suite through Console interactive */
	  CU_console_run_tests();

	/* Clear the registry after test finished */
	CU_cleanup_registry();
}
