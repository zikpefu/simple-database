/*
Zachary Ikpefua
ECE 2220
Project 2
Semester Spring 2018
Purpose:	Write a I/O program so that a user can enter in information

Estimates: I thought that this code would take a day to complete,
however this took about a week

Known Bugs:
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void printMenu();
int verifyStateSelection(char [] , char [50][4]);
int verifyFirstname(char []);
int verifyMiddlename(char);
int verifyLastname(char []);
int verifyAge(int);
int verifyGender(char); //Look here
int verifySuffix(char []);
int verifyClass(int);
int verifyGPA(float);
int verifyParking(double);
int verifyTwitter(char []);


#define NAME_LIMIT 33
int main(void){
	//Input initialization
//	const int NAME_LIMIT = 33;
	char fname[NAME_LIMIT] = "";// Unknown Value
	char mname = '\t';
	char lname[NAME_LIMIT] = "";//Unknown Value
	char suffix[5] = "";
	char sex = '\t'; //Initalized to this because user cannot see this
	char state[3] = "";
	char twitter[NAME_LIMIT] = ""; //Unknown Name
	char club_entry[4][NAME_LIMIT] = {""};
	int class = -1;
	int age = 100;
	char ukn[]= "Not-Named";
	char handle[2] = "@";

	float gpa = -1;
	double pbill = -1;

	//Program variables
	int x = 0;
	int c = 0;
	int userInput = 0;
	int clubLoop = 0;
	int clubAns = 1;
	int stateLoop = 0;
	int fnameLoop = 0;
	int mnameLoop = 0;
	int ageLoop = 0;
	int genderLoop = 0;
	int suffixLoop = 0;
	int classLoop = 0;
	int gradeLoop = 0;
	int cDisplay = 0;
	int lnameLoop = 0;
	int pbillLoop = 0;
	int tweetLoop = 0;
	char cIdentify[35] = "";
	int clearClub = 0;
	char stateList[50][4] = {
		{"AL"},{"AK"},{"AZ"},{"AR"},{"CA"},{"CO"},{"CT"},{"DE"},{"FL"},{"GA"},{"HI"},{"ID"},
		{"IL"},{"IN"},{"IA"},{"KS"},{"KY"},{"LA"},{"ME"},{"MD"},{"MA"},{"MI"},{"MN"},{"MS"},
		{"MO"},{"MT"},{"NE"},{"NV"},{"NH"},{"NJ"},{"NM"},{"NY"},{"NC"},{"ND"},{"OH"},{"OK"},
		{"OR"},{"PA"},{"RI"},{"SC"},{"SD"},{"TN"},{"TX"},{"UT"},{"VT"},{"VA"},{"WA"},{"WV"},
		{"WI"},{"WY"}			};

	fprintf(stdout,"\nWelcome to the Clemson University Student Database!\n\n");
	while(x == 0){
		printMenu();
		fscanf(stdin,"%d",&userInput);
		switch(userInput){

			case 1: 			//Case 1 Name
				fnameLoop = 0;
				do {
				fprintf(stdout,"Enter the first name: ");
				getchar();//Dummy character
				fscanf(stdin,"%s",fname);
				freopen("/dev/tty","rw",stdin);//Frees up buffer
				fnameLoop = verifyFirstname(fname); //Loop will stop if return value is 1
				}while (fnameLoop == 0);


				do {
					mnameLoop = 0;
					fprintf(stdout,"Enter the middle character: ");
					freopen("/dev/tty","rw",stdin);
					mname = getchar(); //Getting rid of the dummy character

					freopen("/dev/tty","rw",stdin);
					mnameLoop = verifyMiddlename(mname);
				} while(mnameLoop == 0);

				if (mnameLoop == 2){
					fprintf(stdout,"Capitalizing...\n");
					mname -= 32;
				}
				if(mnameLoop == 3){
					mname = '\t';
				}
				lnameLoop = 0;
				do {
					fprintf(stdout,"Enter the last name: ");//same as first name
					getchar();
					fscanf(stdin,"%s",lname);
					freopen("/dev/tty","rw",stdin);
					lnameLoop = verifyLastname(lname);
				}while (lnameLoop == 0);
				fprintf(stdout,"\nThank you for the information\n\n");
				break;

			case 2: //Case 2, Age
				ageLoop = 0;
				do {
					fprintf(stdout,"Enter you age: ");
					fscanf(stdin,"%d",&age);
					getchar();
					ageLoop = verifyAge(age);
					}while(ageLoop == 0);
				fprintf(stdout,"\nThank you for the information\n\n");
				
				break;
			case 3: //Case 3, Gender and Suffix
				do {
					freopen("/dev/tty","rw",stdin);
					fprintf(stdout,"Enter your sex: ");
					sex = getchar();
					freopen("/dev/tty","rw",stdin);
					genderLoop = verifyGender(sex);
					} while(genderLoop == 0);

				do {
					fprintf(stdout,"Enter your suffix or type [QUIT] to cancel: ");
					fscanf(stdin,"%s",suffix);
					suffixLoop = verifySuffix(suffix);
					} while(suffixLoop == 0);

					if(strcmp(suffix,"QUIT") == 0){
						strcpy(suffix,"");
					}

					fprintf(stdout,"\nThank you for the information\n\n");
					break;
			case 4: //Case 4, CLass identification
				do {
					classLoop = 0;
					class = -1;
					fprintf(stdout,"Enter a number beween 1 and 4 for your class level: ");
					fscanf(stdin,"%d",&class);
					freopen("/dev/tty","rw",stdin);
					classLoop = verifyClass(class);
				} while(classLoop == 0);

				if(class == 1){
				strcpy(cIdentify,"Freshman");
			}
				else if(class == 2){
				strcpy(cIdentify, "Sophomore");
			}
				else if(class == 3){
				strcpy(cIdentify,"Junior");
			}
				else{
				strcpy(cIdentify,"Senior");
			}
				fprintf(stdout,"\nThank you for the information.\n\n");
				break;
			case 5: //Case 5, State name
				stateLoop = 0;
				do{
				fprintf(stdout,"Type the state code from the list:\n");
				fprintf(stdout,"Alabama - AL\t\tMontana - MT\nAlaska - AK\t\tNebraska - NE\n");
				fprintf(stdout,"Arizona - AZ\t\tNevada - NE\nArkansas - AR\t\tNew Hampshire - NH\n");
				fprintf(stdout,"California - CA\t\tNew Jersey - NJ\nColorado - CO\t\tNew Mexico - NM\n");
				fprintf(stdout,"Connecticut - CT\tNew York - NY\nDelaware - DE\t\tNorth Carolina - NC\n");
				fprintf(stdout,"Flordia - FL\t\tNorth Dakota - ND\nGeorgia - GA\t\tOhio - OH\n");
				fprintf(stdout,"Hawaii - HI\t\tOklahoma - OK\nIdaho - ID\t\tOregon - OR\n");
				fprintf(stdout,"Illinois - IL\t\tPennsylvania - PA\nIndiana - IN\t\tPhode Island - RI\n");
				fprintf(stdout,"Iowa - IA\t\tSout Carolina - SC\nKansas - KS\t\tSouth Dakota - SD\n");
				fprintf(stdout,"Kentucky - KY\t\tTennessee - TN\nLouisiana - LA\t\tTexas - TX\n");
				fprintf(stdout,"Maine - ME\t\tUtah - UT\nMaryland - MD\t\tVermont - VT\n");
				fprintf(stdout,"Massachusetts - MA\tVirginia - VA\nMichigan - MI\t\tWashington - WA\n");
				fprintf(stdout,"Minnesota - MN\t\tWest Virginia - WV\nMississippi - MS\tWisconsin - WI\n");
				fprintf(stdout,"Missouri - MO\t\tWyoming - WY\n");
				fscanf(stdin,"%s",state);
				stateLoop = verifyStateSelection(state,stateList);
				}while(stateLoop == 0);
				fprintf(stdout,"\nThank you for the information\n\n");
				break;

			case 6: //Case 6, Grades
				do {
					gpa = -1;//Set GPA = -1 so when char is entered it takes -1
					fprintf(stdout,"Enter the GPA associated with the stduent: ");
					fscanf(stdin,"%f",&gpa);
					freopen("/dev/tty","rw",stdin);
					gradeLoop = verifyGPA(gpa);

				} while(gradeLoop == 0);
				fprintf(stdout,"\nThank you for your information.\n\n");
				break;
		
			case 8: //Case 8, Parking Bill amount
				do {
					pbill = -1; //Same as grade, must set equal to -1 to prevent infinite loop
					fprintf(stdout,"Enter a parking bill amount: ");
					fscanf(stdin,"%lf",&pbill);
					freopen("/dev/tty","rw",stdin);
					pbillLoop = verifyParking(pbill);
					} while(pbillLoop == 0);
			
				fprintf(stdout,"\nThank you for the information.\n\n");
				break;
			
			case 9: //Case 9, Organizations
				do{ //Asks the user how many clubs they have
				fprintf(stdout,"How many clubs do you have?: ");
				fscanf(stdin,"%d",&clubAns);
				if(clubAns > 5 || clubAns < 0){
					fprintf(stdout,"\aInvalid Amount: Please enter a number betwen 0 and 5\n");
				}
			}while (clubAns > 5 || clubAns < 0);
				//if statement for more than 5 clubs

				fprintf(stdout,"\nEnter your %d club[s] each ending with a newline:",clubAns);
				c = 0;
			for(clubLoop = 0; clubLoop < clubAns; clubLoop++){ //Loop to input each word into character array club_entry
					do {
						if(c == 0){
						getchar();
						}
						fprintf(stdout,"\nEnter Club %d: ",clubLoop +1);
						scanf("%s",club_entry[clubLoop]);
						freopen("/dev/tty","rw",stdin);
						++c;
					} while ((club_entry[clubLoop][0] == '\n')); //returns 1 because it doesnt equal
				}
				if(clubAns == 0){
					clubAns = 1;
				}
				fprintf(stdout,"\nThank you for the information.\n\n");
				break;
		
			case 7://Case 7, Twitter
				strcpy(handle, "@");
				do {
					fprintf(stdout,"Enter your twitter handle without the \"@\" sign: ");
					scanf("%s",twitter);
					freopen("/dev/tty","rw",stdin);
					tweetLoop = verifyTwitter(twitter);
					} while(tweetLoop == 0);
				strcat(handle, twitter); //Combine the @ sign to correct handle
				fprintf(stdout,"Thank you for the information.\n\n");
				break;

			case 10: //Case 10, Display data

				cDisplay = 0;
				fprintf(stdout,"\nDisplaying Information: If a \'?\' is present, ");
				fprintf(stdout,"there was no input availiable from the option!\n\n");

			fprintf(stdout,"/********************************************************************/\n");
			//Check each input so program can say 'Unknwon Value', etc
				if(strcmp(suffix, "") == 0){
					strcpy(suffix,ukn);
				}
				if(strcmp(fname, "") == 0){
					strcpy(fname,ukn);
				}
				if(mname == '\t'){
					mname = '?';
				}
				if(strcmp(lname,"")== 0){
					strcpy(lname,ukn);
				}
				if(handle[1] == '\0'){
					strcpy(handle, ukn);
				}
				if(sex == '\t'){
					sex = '?';
				}
				if(strcmp(state,"")== 0){
					strcpy(state,ukn);
				}
				fprintf(stdout,"FULL NAME: %s %s %c %s\n",suffix,fname,mname,lname);
				if(age == 100){
					fprintf(stdout,"AGE: Unknown Value\n");
				}
				else {
					fprintf(stdout,"AGE: %d\n",age);
				}

				if(sex == 'M'){
					fprintf(stdout,"GENDER: Male\n");
				}
				else if(sex == 'F'){
					fprintf(stdout,"GENDER: Female\n");
				}
				else {
					fprintf(stdout,"GENDER: %c\n",sex);
				}
				if(strcmp(cIdentify,"") == 0){
				fprintf(stdout,"CLASS: Unknown\n");
				}
				else {
				fprintf(stdout,"CLASS: %s\n",cIdentify);
				}

				fprintf(stdout,"STATE: %s\n",state);
				if(gpa == -1){
					fprintf(stdout,"GPA: Unknown Value\n");
				}
				else {
					fprintf(stdout,"GPA: %.2f\n",gpa);
				}
				fprintf(stdout,"TWITTER: %s\n",handle);
				if(pbill == -1){
				fprintf(stdout,"PARKING BILL: Unknown Value\n");
			}
				else {
					fprintf(stdout,"PARKING BILL: $%.2lf\n",pbill);
				}
				fprintf(stdout,"CLUBS: ");
				for(cDisplay = 0; cDisplay < clubAns; cDisplay++){
					if(cDisplay == clubAns - 1){
						fprintf(stdout,"%s",club_entry[cDisplay]); //Dosent print out comma for last entry
						if(strcmp(club_entry[cDisplay],"") == 0){
							fprintf(stdout,"None");//If there is no entry, print None
						}
					}
					else{
						fprintf(stdout,"%s, ",club_entry[cDisplay]);
						if(strcmp(club_entry[cDisplay], "") == 0){
							fprintf(stdout,"None, "); //Print commas to sepearte each club
						}
					}
				}
				fprintf(stdout,"\n/********************************************************************/");
				fprintf(stdout,"\n\nAll information Displayed\n\n");
			break;
			
			case 11: //Case 11, Clear all data
				
				strcpy(suffix,"");
				strcpy(fname, "");
				strcpy(state, "");
				strcpy(handle, "@\0");
				handle[0] = '\0';
				strcpy(twitter,"");
				strcpy(lname,"");
				strcpy(cIdentify,"");
				class = -1;
				age = 100;
				gpa = -1;
				pbill = -1;
				sex = '\t';
				mname = '\t';
				for(clearClub = 0; clearClub < clubAns; clearClub++){ //Clearing the entire char array
					strcpy(club_entry[clearClub], "");
				}
				cDisplay = 0;
				clubAns = 1;
				fprintf(stdout,"\a\nAll data cleared!\n\n");
				break;
				
			default:
				fprintf(stdout,"\a\n\nThank you for using the system!\n\n"); //If user enters anything other than 1 - 11
				return 0;
		}
	}
	return 0;
}

/*
FUNCTION:		printMenu()
INPUTS:			none
OUTPUTS:		none-is void
PURPOSE:		To show a menu that gives the user a list of options to select
*/

void printMenu(){
	fprintf(stdout,"1: Enter Name\t\t\t7: Enter Twitter Account\n");
	fprintf(stdout,"2: Enter Age\t\t\t8: Enter Parking Bill\n");
	fprintf(stdout,"3: Enter Sex\t\t\t9: Enter Clubs\n");
	fprintf(stdout,"4: Enter Class\t\t\t10: Display Data\n");
	fprintf(stdout,"5: Enter State\t\t\t11: Clear all Data\n");
	fprintf(stdout,"6: Enter GPA\t\t\t0: Quit\n");
}




//Fix verifyFirstname and copy to last

/*
FUNCTION:		verifyFirstname
INPUTS:			fname
OUTPUTS:		0 if invalid; 1 if valid
PURPOSE:		To verify if the first name has only chars
*/


int verifyFirstname(char input[]){
	int f = 0;
	int check = 0;

	for(f = 0; f < (unsigned)strlen(input) ;f++){
		if((input[f] <= 'z' && input[f] >= 'a') || (input[f] >= 'A' && input[f] <= 'Z')){
			check++;
		}
		if(check == (unsigned)strlen(input)){
		return 1;
		}
	}

	fprintf(stdout,"\aPlease enter only characters for the first name\n");
	return 0;
}

/*
FUNCTION:		verifyMiddlename
INPUTS:			mname
OUTPUTS:		0 if invalid; 1 if valid; 2 if lowercase; 3 if user rejected
PURPOSE:		To verify if the character input is valid;
*/

int verifyMiddlename(char input){
//	int m = 0;
	char noInputAns = '\t';

	if(input == '\n'){
		fprintf(stdout,"Would you like to enter a middle inital? [Y/N]: ");
		noInputAns = getchar();
		if(noInputAns == 'Y'){
			return 0;
		}
		else if(noInputAns == 'N'){
			fprintf(stdout,"\nContinuing to Last name...\n");
			return 3;
		}
	}

	else if(input >= 'A' && input <= 'Z'){
		return 1;
	}

	else if(input >= 'a' && input <= 'z'){
		return 2;
	}
	else {
		fprintf(stdout,"\aInvalid Choice: Please enter a single character for the inital\n");
		return 0;
	}
	return 0;
}

/*
FUNCTION:		verifylastname
INPUTS:			lname
OUTPUTS:		0 if invalid 1 if valid
PURPOSE:		To verify if the last name has a valid input
*/

int verifyLastname(char input[]){
	int l = 0;
	int check = 0;

	for(l = 0; l < (unsigned)strlen(input) ;l++){
		if((input[l] <= 'z' && input[l] >= 'a') || (input[l] >= 'A' && input[l] <= 'Z')){
			check++;
		}
		if(check == (unsigned)strlen(input)){
		return 1;
		}
	}

	fprintf(stdout,"\aPlease enter only characters for the last name\n");
	return 0;
}


/*
FUNCTION:		verifyGender
INPUTS:			gender
OUTPUTS:		0 if invalid 1 if valid
PURPOSE:		To verify the gender character output
*/


int verifyGender(char gender){
	if (gender == 'M'|| gender == 'F') {
		return 1;
	}
	else{
		fprintf(stdout,"\aInvalid Input: Please enter a [M] for male or [F] for female.\n");
		return 0;
	}
}

/*
FUNCTION:		verifyAge
INPUTS:			age
OUTPUTS:		0 if invalid 1 if valid
PURPOSE:		To verify if the age is betwwen 1 and 99
*/

int verifyAge(int num){
	if(num < 1 ||  num > 99){
		fprintf(stdout,"\aInvalid number: Age has to be between 1 and 99.\n");
	}
	else if (num >= 1 && num <= 99){
		return 1;
	}
	else {
		fprintf(stdout,"\aInvalid Input: Please enter a number between 1 and 99.\n");
	}


	return 0;
}

/*
FUNCTION:		verifyStateSelection
INPUTS:			state (input), state abreviation list (statesList)
OUTPUTS:		0 if invalid 1 if valid
PURPOSE:		To compare and verify that the state is on the list
*/

int verifyStateSelection(char input [],char states[50][4]){
	int s = 0;

	for(s = 0; s < 50; s++){
		if(strcmp(&states[s][0], input) == 0){
			return 1;
		}
	}
	fprintf(stdout,"\aInvalid Choice: Please choose what is on the list.\n");
	return 0;
}

/*
FUNCTION:		verifySuffix
INPUTS:			suffix
OUTPUTS:		0 if invalid 1 if valid
PURPOSE:		To verify if the suffix is valid and adjust the suffix if needed
*/

int verifySuffix(char sfx []){
	
	if(strcmp(sfx,"Mr") == 0 || strcmp(sfx,"Mrs") == 0 || strcmp(sfx,"Ms") == 0){
		fprintf(stdout,"\nAdding a period...\n");
		strcat(sfx,".");
		return 1;
	}
	else if(strcmp(sfx,"Mr.")== 0 || strcmp(sfx,"Mrs.") == 0 || strcmp(sfx,"Ms.")== 0){
		return 1;
	}
	else if(strcmp(sfx, "QUIT") == 0){
		fprintf(stdout,"Continuing...\n");
		return 1;
	}
	
	else {
		fprintf(stdout,"\aInvaid Choice: Please enter a valid suffix");
		fprintf(stdout," make sure the \"M\" is capitalized:\n[Mr.] [Mrs.] [Ms.]\n");
		return 0;
	}
	return 0;
}

/*
FUNCTION:		verifyClass
INPUTS:			class
OUTPUTS:		0 if invalid 1 if valid
PURPOSE:		To verify and visually show the user there input
*/

int verifyClass(int input){
	if(input == 1){
		fprintf(stdout,"\nYou have chosen a 1 for \'Freshman\'\n");
		return 1;
	}
	else if(input == 2){
		fprintf(stdout,"\nYou have chosen a 2 for \'Sophomore\'\n");
		return 1;
	}
	else if(input == 3){
		fprintf(stdout,"\nYou have chosen a 3 for \'Junior\'\n");
		return 1;
	}
	else if(input == 4){
		fprintf(stdout,"\nYou have chosen a 4 for \'Senior\'\n");
		return 1;
	}
	else{
		fprintf(stdout,"\a\nInvalid Choice: Please enter a number between 1 and 4.\n");
		return 0;
	}
}

/*
FUNCTION:		verifyGPA
INPUTS:			gpa
OUTPUTS:		0 if invalid 1 if valid
PURPOSE:		To verify if the gpa float is in the range of 0 and 4
*/

int verifyGPA(float grade){
	if(grade >= 0.00 && grade <= 4.00){
		return 1;
	}
	else {
		fprintf(stdout,"\aInvalid Entry: Enter a decimal between 0 and 4\n");
		return 0;
	}
}

/*
FUNCTION:		verifyParking
INPUTS:			pbill
OUTPUTS:		0 if invalid 1 if valid
PURPOSE:		To verify if the parking bill amount is a valid amount
*/
int verifyParking(double bill){
	if(bill >= 0.0 && bill <= 1.0E100){
		return 1;
	}
	else {
		fprintf(stdout,"\aInvalid Entry: Enter a decial between 0 and 1.0x10^(100)\n");
		return 0;
	}
}
/*
FUNCTION:		verifyTwitter
INPUTS:			twitter
OUTPUTS:		0 if invalid 1 if valid
PURPOSE:		To verify if the twitter handle has an @ sign
*/

int verifyTwitter(char thandle[]){
	int atCheck = 0;
	for(atCheck = 0; atCheck < (unsigned)strlen(thandle); atCheck++){
		if(thandle[atCheck] == '@'){
			fprintf(stdout,"\aThe \'@\' sign cannot be used. Please try again.\n");
			return 0;
		}
	}
	return 1;
}
