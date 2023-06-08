#include "strGenerate.h"
#include "Levenshtein.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
//
#define LEN_S1 300
#define LEN_S2 200
#define K (1./20.)
#define LEN_PREFIX_S1 (int)(LEN_S1 * (double)K)
#define LEN_PREFIX_S2 (int)(LEN_S2 * (double)K)

int main()
{
	srand((unsigned)time(NULL));
	setlocale(0, "ru");
	char* S1, *S2;
	S1 = strGenerate::strGenerate(LEN_S1);
	S2 = strGenerate::strGenerate(LEN_S2);

	cout << "-----------------------������ 1-----------------------" <<endl<< S1 << endl;
	cout << "-----------------------������ 2-----------------------" <<endl<< S2 << endl;

	clock_t t1 = 0, t2 = 0, t3, t4;
	
	std::cout << std::endl<<endl;
	cout << "������1: " << prefix(S1, LEN_PREFIX_S1) << endl;
	cout << "������2: " << prefix(S2, LEN_PREFIX_S2) << endl;
	cout << endl;
	std::cout << std::endl << "-- ���������� ����������� -----" << std::endl;
	std::cout << std::endl << "--����� --- �������� -- ���.�������. ---"
		<< std::endl;
	int lev = 0, lev_r = 0;
	int sum = 0, sum_r = 0;
	
	for (int i = 0; i < std::min(LEN_PREFIX_S1, LEN_PREFIX_S2); i++)
	{
		
		t1 = clock(); lev = levenshtein_r(i, prefix(S1, LEN_PREFIX_S1), i, prefix(S2, LEN_PREFIX_S2)); t2 = clock();
		t3 = clock(); lev_r = levenshtein(i, prefix(S1, LEN_PREFIX_S1), i, prefix(S2, LEN_PREFIX_S2)); t4 = clock();
		std::cout << std::right << std::setw(2) << i << "/" << std::setw(2) << i
			<< "        " << std::left << std::setw(10) << (t2 - t1)
			<< "   " << std::setw(10) << (t4 - t3) << std::endl;
		sum_r += t2 - t1;
		sum += t4 - t3;
	}
	cout << lev << endl << lev_r << endl;
	cout << sum_r << "\t" << sum << endl;
	system("pause");
	return 0;
}








// - main  
// -- ���������� ����� LCS 



//#include <iostream>
//#include "LCH.h"
//int main()
//{
//    srand((unsigned)time(NULL));
//        	setlocale(0, "ru");
//        	char* S1, *S2;
//        	S1 = strGenerate::strGenerate(LEN_S1);
//        	S2 = strGenerate::strGenerate(LEN_S2);
//        
//        	cout << "-----------------------������ 1-----------------------" <<endl<< S1 << endl;
//        	cout << "-----------------------������ 2-----------------------" <<endl<< S2 << endl;
//        
//        std::cout << std::endl << "-- ���������� ����� LCS ��� X � Y(������������ ���������������� )\n";
//        cout << "������1: " << prefix(S1, LEN_PREFIX_S1) << endl;
//        cout << "������2: " << prefix(S2, LEN_PREFIX_S2) << endl;
//        clock_t t1 = 0, t2 = 0;
//        t1 = clock();
//        char z[100];
//    int s = lcsd(  
//         prefix(S1, LEN_PREFIX_S1),       
//         prefix(S2, LEN_PREFIX_S2),
//        z
//    );
//    t2 = clock();
//       std::cout << std::endl << "-- ����� LCS: " << s << std::endl;
//        cout << "�����: " << t2 - t1 << endl;
//    system("pause");
//    return 0;
//}



//#include <iostream>
//#include "LCS.h"
//int main()
//{
//
//    srand((unsigned)time(NULL));
//    	setlocale(0, "ru");
//    	char* S1, *S2;
//    	S1 = strGenerate::strGenerate(LEN_S1);
//    	S2 = strGenerate::strGenerate(LEN_S2);
//    
//    	cout << "-----------------------������ 1-----------------------" <<endl<< S1 << endl;
//    	cout << "-----------------------������ 2-----------------------" <<endl<< S2 << endl;
//    
//    std::cout << std::endl << "-- ���������� ����� LCS ��� X � Y(��������)\n";
//    cout << "������1: " << prefix(S1, LEN_PREFIX_S1) << endl;
//    cout << "������2: " << prefix(S2, LEN_PREFIX_S2) << endl;
//    clock_t t1 = 0, t2 = 0;
//    t1 = clock();
//    int s = lcs(
//       LEN_PREFIX_S1,  // �����   ������������������  X   
//        prefix(S1, LEN_PREFIX_S1),       // ������������������ X
//        LEN_PREFIX_S2 - 1,  // �����   ������������������  Y
//        prefix(S2, LEN_PREFIX_S2)       // ������������������ Y
//    );
//    t2 = clock();
//    std::cout << std::endl << "-- ����� LCS: " << s << std::endl;
//    cout << "�����: " << t2 - t1 << endl;
//    system("pause");
//    return 0;
//}