#include <iostream>
#include <stdlib.h>
using namespace std;
int count(char* c, char x);
float change_dot(char* ch);

void main()
{
	char input[9000];
	int change_num[10] = { 0 };
	int j = 0;
	char* num;
	float number = 0;

	cout << "이 프로그램은 pound와 feet를 kilogram과 meter로 변환합니다." << endl;
	cout << "변환을 1개 하려면 'p/f:'로 동시변환을 하려면 '(p/f: )'형태로 입력하세요." << endl;
	cout << "최대 5개까지 입력가능합니다." << endl;
	cin >> input;

	/*char* num;
	num = input;
	float number = change_dot(num);
	cout << "" << number << endl;*/


	if (input[0] == 'p')
	{//pound
		cout << " " << input << " -> kilogram: ";

			char* num;
			num = &input[2];
			float number = change_dot(num);
			float outKilogram = number / 2.205f;

			cout << "" << outKilogram << endl;
	}
	

	if (input[0] == 'f')
	{//feet
		cout << "f: " << input << "-> meter: ";
		
			char* num;
			num = &input[2];
			float number = change_dot(num);
			float outMeter = number / 3.281f;

			cout << "" << outMeter << endl;
	}
	
	int w = 0;
	w = count(input, ' )');
	if (w > 5)
	{
		cout << "5개까지 입력가능합니다." << endl;
		exit(1);
	}
	else if (input[0] == '(')
	{
		cout << " " << input << "->";
		//cout << "1";
		float PtoKilogram[10] = { 0 };
		float FtoMeter[10] = { 0 };
		//char output[5];
		for (int i = 1; ; i++)
		{
			if (input[i] == '\0')
				break;

			if (input[i] == 'p')
			{
				//cout << "2";
				for(i = i+2;;i++)
				{
					//cout << "3";
					if (input[i] >= '0' && input[i] <= '9')
					{
						//cout << "4";
						change_num[j] = change_num[j] * 10;
						change_num[j] += input[i] - '0';
					}
					else
					{
						//cout << "5";
						//cout << change_num[j] << endl;
						PtoKilogram[j] = (float)change_num[j] / 2.205;
						cout << "(kilogram: " << PtoKilogram[j] << ")";
						j++;
						break;
					}
				}
			}
			else if (input[i] == 'f')
			{
				for (i = i + 2; ; i++)
				{
					if (input[i] >= '0' && input[i] <= '9')
					{
						change_num[j] = change_num[j] * 10;
						change_num[j] += input[i] - '0';
					}
					else
					{
						//cout << change_num[j] << endl;
						FtoMeter[j] = (float)change_num[j] / 3.281;
						cout << "(meter: " << FtoMeter[j] << ")";
						j++;
						break;
					}
				}
			}
		}
	}
	cin.get();
}

int count(char* c, char x)
{
	int i, count;
	count = 0;
	for (i = 0; c[i] != NULL; i++)
	{
		if (c[i] == x)
			count++;
		else
			continue;
	}
	return count;
}
float change_dot(char* ch)
{

	float num1;

	num1 = atof(ch);

	return num1;
}