/// <summary>
/// small main program to test matrix class
/// yay matrices
/// </summary>
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
/// <summary>
/// @author Dylan Curran
/// @Login: C00217112
/// @date : 18/02/2017 - 22/02/2107
/// time roughly spent on project: 10 hours 
/// known bugs: No known errors at this time
/// </summary>

#include "MyVector3D.h"
#include "MyMatrix3.h"
#include <SFML\Graphics.hpp>
#include <string.h>

void testConstructors();	// I used this function to test the constructors for this matrix project
void testOperators();		// I used this function for performing operation with one or more matrices over multiple tests


int main()
{
	testConstructors();		// this calls the constructor function in the main
	testOperators();		// this calls the operator function in the main
	std::system("pause");	// this keeps the window on the screen
	return EXIT_SUCCESS;
}

void testConstructors()
{
	MyMatrix3 matrixA{};		// this declares the matrix A
	
	//this is the code for the default constructor
	std::cout << "______________DEFAULT CONSTRUCTOR__________________" << std::endl;
	std::cout << matrixA.toString() << std::endl;										// this converts the matrix to a string and displays it
	std::cout << " [ 0, 0, 0 ] [ 0, 0, 0 ] [ 0, 0, 0 ] " << std::endl;					// this is the expected result
	std::cout << "___________________________________________________" << std::endl;
	

	// this is the code for a matrix constructor for a matrix with 9 doubles
	std::cout << "______________9 DOUBLES CONSTRUCTOR________________" << std::endl;
	matrixA = MyMatrix3{ 1.1,2.2,3.3,-4.4,5.5,6.6,7.7,8.8,9.9 };							// this initialises the matrix with 9 doubles
	std::cout << matrixA.toString() << std::endl;											// this converts the matrix to a string and displays it
	std::cout << " [ 1.1, 2.2, 3.3 ] [ -4.4, 5.5, 6.6 ] [ 7.7, 8.8, 9.9 ] " << std::endl;	// this is the expected result
	std::cout << "___________________________________________________" << std::endl;

	// this is a matrix constructor with 3 rows
	// btw my duck told me to name these vectors like this
	std::cout << "_______________3 ROW CONSTRUCTOR___________________" << std::endl;
	MyVector3D GeorgeVector(1, -2, 4.5);							// this is the first vector row
	MyVector3D theVector(2, 0, -3.5);								// this is the second vector row
	MyVector3D Duckvector(3, -4, 2);								// this is the third vector row
	matrixA = MyMatrix3{GeorgeVector,  theVector , Duckvector };	// this puts it as a matrix
	std::cout << "[1, -2, 4.5] [2, 0, 3.5] [3, -4, 2] " << std::endl;	// this is the expected result
	std::cout << matrixA.toString() << std::endl;						// this converts the matrix to a string and displays it
	std::cout << "___________________________________________________" << std::endl;
	
	}

void testOperators()
{
	MyMatrix3 matrixA{};		// this declares a matrix
	MyMatrix3 matrixB{};		// this declares another matrix
	MyVector3D vectorA{};		// this declares a vector
	MyVector3D vectorB{};		// this declares another vector
	// this operator adds two matrices
	std::cout << "________________PLUS OPERATOR______________________" << std::endl;
	matrixA = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };			// this initialises matrixA
	matrixB = MyMatrix3{ 7,6,5,4,3,6,5,4,3 };			// this initialises matrixB
	std::cout << matrixA.toString() << std::endl;		// this converts matrixA to a string and displays it
	std::cout << matrixB.toString() << std::endl;		// this converts matrixB to a string and displays it
	matrixA = matrixA.operator+(MyMatrix3(matrixB));	// this adds the matrices and assigns the answer to matrixA
	std::cout << "the result should be [8,8,8] [8,8,12] [12,12,12]" << std::endl;	// this is the expected result
	std::cout << matrixA.toString() << std::endl;	//this converts the matrix to a string and displays it
	std::cout << "___________________________________________________" << std::endl;

	// this operator subtracts two matrices
	std::cout << "_______________MINUS OPERATOR______________________" << std::endl;
	matrixA = MyMatrix3{ 9,9,9,9,9,9,9,9,9 };			// this initialises matrixA
	matrixB = MyMatrix3{ 8,7,6,5,4,3,2,1,0 };			// this initialises matrixB
	std::cout << matrixA.toString() << std::endl;		// this converts matrixA to a string and displays it
	std::cout << matrixB.toString() << std::endl;		// this converts matrixB to a string and displays it
	matrixA = matrixA.operator-(MyMatrix3(matrixB));	// this subtracts matrixB from matrixA and assigns it to matrix A
	std::cout << "the result should be [1,2,3] [4,5,6] [7,8,9]" << std::endl;	// this is the expected answer
	std::cout << matrixA.toString() << std::endl;		// this converts matrixA to string and displays it
	std::cout << "____________________________________________________" << std::endl;

	// this operator multiplies two matrices by each other
	std::cout << "______________MATRIX BY MATRIX OPERATOR_____________" << std::endl;
	matrixA = MyMatrix3{ 4,5,2,3,6,1,4,3,2 };			// this initialises matrixA
	matrixB = MyMatrix3{ 2,3,2,3,2,3,2,3,2 };			// this initialises matrixB
	std::cout << matrixA.toString() << std::endl;		// this converts matrixA to a string and displays it
	std::cout << matrixB.toString() << std::endl;		// this converts matrixB to a string and displays it
	matrixA = matrixA.operator*(MyMatrix3(matrixB));	// this multiplies the matrices by each other and assins it to matrixA
	std::cout << "the result should be [27,28,27] [26,24,26] [21,24,21]" << std::endl;	// this is the expected answer
	std::cout << matrixA.toString() << std::endl;		// this converts matrixA to a string and displays it
	std::cout << "____________________________________________________" << std::endl;

	// this operator multiplies a matrix by a vector
	std::cout << "_____________MATRIX BY VECTOR_______________________" << std::endl;
	matrixA = MyMatrix3{ 2,3,4,5,6,7,8,9,1 };		// this initialises matrixA
	vectorA = MyVector3D{ 2,3,5 };					// this initialises vectorA
	std::cout << matrixA.toString() << std::endl;	// this converts matrixA to a string and displays it
	std::cout << vectorA.toString() << std::endl;	// this converts matrixB to a string and displays it
	vectorA = matrixA.operator*(MyVector3D(vectorA)); // this multiplies the matrix by the vector and assigns the answer to vectorA
	std::cout << "the result should be [33,63,48]" << std::endl;	// this is the expected result
	std::cout << vectorA.toString() << std::endl;	// this converts vectorA to a string and displays it
	std::cout << "____________________________________________________" << std::endl;

	// this operator scales a matrix up by a multiplier
	std::cout << "_________________MATRIX BY SCALAR___________________" << std::endl;
	matrixA = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };		// this initialises matrixA
	double scalar = 2;								// this is the scalar
	std::cout << matrixA.toString() << std::endl;	// this converts matrixA to a string and displays it
	std::cout << scalar << std::endl;				// this shows the scalar used
	matrixA = matrixA.operator*(scalar);			// this scales the matrix and  assigns it to matrixA
	std::cout << "the result should be [2,4,6] [8,10,12] [14,16,18]" << std::endl;	// this is the expected answer
	std::cout << matrixA.toString() << std::endl;	// this converts matrixA to a string and displays it
	std::cout << "_____________________________________________________" << std::endl;

	// this transposes a matrix which flips the matrix form bottom to top and from left to right
	std::cout << "_________________MATRIX TRANSPOSE____________________" << std::endl;
	matrixA = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };		// this initialises matrixA
	std::cout << matrixA.toString() << std::endl;	// this converts matrixA
	matrixA = matrixA.transpose();					// this performs the transpose operator
	std::cout << "result should be [9,8,7] [6,5,4] [3,2,1]" << std::endl;	// this is the expected result
	std::cout << matrixA.toString() << std::endl;	// this converts matrixA to a string and displays it
	std::cout << "_____________________________________________________" << std::endl;

	// this operator finds the multiplier for the inverse of a matrix
	std::cout << "________________DETERMINANT OPERATOR________________" << std::endl;
	matrixA = MyMatrix3{ 1,12,32,7,9,2,12,6,4 };	// this initialises matrixA
	std::cout << matrixA.toString() << std::endl;	// this converts matrixA to a string and displays it
	double determinant = 0;							// this declares the determinant variable
	determinant = matrixA.determinant();			// this calls the determinant operator and assigns it to the variable determinant@gmail.com
	std::cout << "the result should be  -2136 unless changed" << std::endl;	// this is what the result should be
	std::cout << determinant << std::endl;			// this outputs the determinant to the screen
	std::cout << "_____________________________________________________" << std::endl;

	std::cout << "_________________INVERSE OPERATOR____________________" << std::endl;
	// using determinant from determinant operator in this calculation
	matrixA = MyMatrix3{ 3,-1,1,-15,6,-5,5,-2,2 };
	std::cout << matrixA.toString() << std::endl;
	matrixA = matrixA.inverse();
	std::cout << "the result should be [2, 0, -1] [5, 1, 0] [0, 1, 3]" << std::endl;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "_____________________________________________________" << std::endl;

	std::cout << "__________________ROW CHECKER________________________" << std::endl;
	matrixA = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };
	double valueIn;
	std::cout << "please input one value one the machine to check that row (options are 1, 2 or 3)" << std::endl;
	std::cin >> valueIn;
	std::cout << std::endl;
	vectorA = MyVector3D{ 1,1,1 };
	vectorA = matrixA.row(valueIn);
	std::cout << vectorA.toString() << std::endl;


	std::cout << "__________________COLUMN CHECKER________________________" << std::endl;
	matrixA = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };
	std::cout << "please input one value one the machine to check that row (options are 1, 2 or 3)" << std::endl;
	std::cin >> valueIn;
	std::cout << std::endl;
	vectorA = MyVector3D{ 1,1,1 };
	vectorA = matrixA.column(valueIn);
	std::cout << vectorA.toString() << std::endl;


	std::cout << "__________________ EQUALS CHECKER___________________" << std::endl;
	bool check = true;
	matrixA = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };
	matrixB = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };
	std::cout << matrixA.toString() << std::endl;
	std::cout << matrixB.toString() << std::endl;
	check = matrixA.operator==(matrixB);
	if (check)
	{
		std::cout << "they are equal" << std::endl;
	}
	else
	{
		std::cout << "they are not equal" << std::endl;
	}
	std::cout << "____________________________________________________" << std::endl;

	std::cout << "_______________NOT EQUALS CHECKER___________________" << std::endl;
	check = true;
	matrixA = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };
	matrixB = MyMatrix3{ 1,2,3,4,5,66,7,8,9 };
	std::cout << matrixA.toString() << std::endl;
	std::cout << matrixB.toString() << std::endl;
	check = matrixA.operator!=(matrixB);
	if (check)
	{
		std::cout << "they are not equal" << std::endl;
	}
	else
	{
		std::cout << "they are equal" << std::endl;
	}
	std::cout << "____________________________________________________" << std::endl;
	// this operator rotates the point about the x axis
	std::cout << "___________________ROTATION X_______________________" << std::endl;
	std::cout << "please input a value between 0 and 360" << std::endl;
	std::cin >> valueIn;
	matrixA = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };
	matrixB = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };
	std::cout << std::endl;
	std::cout << matrixA.toString() << std::endl;
	matrixB = matrixA.rotationX(valueIn);
	matrixA = matrixA * matrixB;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "____________________________________________________" << std::endl;

	std::cout << "___________________ROTATION Y_______________________" << std::endl;
	std::cout << "please input a value between 0 and 360" << std::endl;
	std::cin >> valueIn;
	matrixA = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };
	matrixB = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };
	std::cout << std::endl;
	std::cout << matrixA.toString() << std::endl;
	matrixB = matrixA.rotationY(valueIn);
	matrixA = matrixA * matrixB;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "____________________________________________________" << std::endl;

	std::cout << "___________________ROTATION Z_______________________" << std::endl;
	std::cout << "please input a value between 0 and 360" << std::endl;
	std::cin >> valueIn;
	matrixA = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };
	matrixB = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };
	std::cout << std::endl;
	std::cout << matrixA.toString() << std::endl;
	matrixB = matrixA.rotationZ(valueIn);
	matrixA = matrixA * matrixB;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "____________________________________________________" << std::endl;

	std::cout << "___________________2D TRANSLATIION__________________" << std::endl;
	vectorA = MyVector3D{ 1,2,1 };
	vectorB = MyVector3D{ 3,4,1 };
	
	std::cout << matrixA.toString() << std::endl;
	std::cout << vectorA.toString() << std::endl;
	std::cout << vectorB.toString() << std::endl;
	//vectorA = (matrixA.translation(vectorA) * vectorB);
	std::cout << (matrixA.translation(vectorA) * (vectorB)).toString() << std::endl;
	std::cout << "The expected result is [4,6,1]" << std::endl;
	std::cout << "____________________________________________________" << std::endl;

	std::cout << "___________________SCALAR FACTOR____________________" << std::endl;
	std::cout << "please put in a value to scale the matrix by" << std::endl;
	std::cin >> valueIn;
	matrixA = MyMatrix3{ 1,2,3,4,5,6,7,8,9 };
	std::cout << matrixA.toString() << std::endl;
	matrixB = matrixA.scale(valueIn);
	matrixA = matrixA * matrixB;
	std::cout << matrixA.toString() << std::endl;
	std::cout << "___________________________________________________" << std::endl;
}	
