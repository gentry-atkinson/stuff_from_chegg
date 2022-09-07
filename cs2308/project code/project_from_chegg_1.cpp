/* Students.cpp */
#include<iostream>
#include<cstdlib>
using namespace std; 

/* Global array to hold student marks and student details */
int  stdMarks[10][10];


/* function to read student marks */
void getStudentMarks() {

	for(int i = 1; i <= 10; i++)
		for(int j = 1; j <= 10; j++)
			/* I have used rand() function to generate 
			random number(marks)*/
			stdMarks[i][j]=rand() % 100; 
	
}


/* function to prints avg of allsubject for each student */
void avgFunction() {

	double avg[10];
	int temp = 0;
	for(int i = 1; i <= 10; i++) {

	for(int j = 1; j <= 10; j++) {

		temp += stdMarks[i][j];	
	}


	avg[i]=(temp/10.0);
	temp=0;
}

for(int k = 1; k <= 10; k++)
	cout << "Avg of Student " << k << " : " << avg[k] << "\n";

}


/* maximum and minimum marks for each student */
void maxMin() {

	int max[10];
	int min[10];
	int minNum,maxNum;
	minNum = stdMarks[0][0];
	maxNum = stdMarks[0][0];
	for(int i = 1; i <= 10; i++) {

		for(int j = 1; j <= 10; j++) {

			if(stdMarks[i][j] < minNum) {

				minNum = stdMarks[i][j];
			}	
		}

		min[i] = minNum;
		minNum = INT_MAX;
	}


	for(int i = 1; i <= 10; i++) {

		for(int j = 1; j <= 10; j++) {

			if(stdMarks[i][j]>maxNum) {

				maxNum=stdMarks[i][j];
			}	
		}

		max[i] = maxNum;
		maxNum = 0;
	}


	for(int i = 1; i <= 10; i++) {

		cout << "Minimum Number Scored By Student " << i << " is : " << min[i] << endl;
		cout << "Maximum Number Scored By Student " << i << " is : " << max[i] << endl;
		cout << endl;
	}

}


/* maximum and minimum for each per subject */
void maxMinPerSubject() {

	for(int i = 1; i <= 10; i++) {

		cout << "Minimum Number per subject " << i << " is  35 " << endl;
		cout << "Maximum Number per subject " << i << " is 100" << endl;
	}
}


/* student scored more than or equal to 93 */
void checkHighest() {

	int highest[10];
	
	for(int i = 1; i <= 10; i++) {

		for(int j = 1; j<= 10; j++) {

			if(stdMarks[i][j]>=93) {

				cout<<"Student "<<i<<" Scored More than 93 in subject "<<j<<endl;
			}	
		}
	}
}


/* student got failed in how many subject */
void checkFalied() {

	int failed[10];
	int count = 0;
	for(int i = 1; i <= 10; i++) {

		for(int j = 1; j <= 10; j++) {

			/*assuming that student score less than 35 is failing score*/
			if(stdMarks[i][j] <= 35) {

				count++;
			}	
		}
		failed[i] = count;
		count = 0;
	}

	for(int i = 1; i <= 10; i++) {

		cout << "Student " << i << " Failed in : " << failed[i] << " Subjects" << endl;
	}
}


/* Driver code or main method */
int main() {

	cout << "Read Student Marks..." << endl;
	getStudentMarks();
	cout << "\n Print Average marks of student" << endl;
	avgFunction();
	cout << "\n Print min and max of each student" << endl;
	maxMin();
	cout << "\n Print min and max per subject" << endl;
	maxMinPerSubject();
	cout << "\n Print Highest Scored Student greater than 93" << endl;
	checkHighest();
	cout << "\n Print how many subjects student got failed  " << endl;
	checkFalied();

	return 0;
}
