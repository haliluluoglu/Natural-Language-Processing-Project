#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#define MAX 1000
#define LOG_DIR_word "C:\\Users\\NidaBil\\Desktop\\HOMEWORK\\BBG2\\bonusOdev\\kelimeler.txt"
#define LOG_DIR_input "C:\\Users\\NidaBil\\Desktop\\HOMEWORK\\BBG2\\bonusOdev\\a.txt"
#define LOG_DIR_output "C:\\Users\\NidaBil\\Desktop\\HOMEWORK\\BBG2\\bonusOdev\\b.txt"

/*~HALÝL ÝBRAHÝM ULUOÐLU~*/

/*INITILAZING*/
void outputString(char []);
int findString(char []);
int searching(char [],char []);

/*void MaximizeOutputWindow(void)
{
	HWND consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow,SW_MAXIMIZE);
}*/ //For Debugging with big screen
FILE *ptr_file_word;
FILE *ptr_file_input;
FILE *ptr_file_output;
main()
{
	//1
	setlocale(LC_ALL, "Turkish");
	
	char string[MAX];
	//2
	ptr_file_input = fopen(LOG_DIR_input,"r");
	fscanf(ptr_file_input,"%s" ,&string);	
	fclose(ptr_file_input);
	
	//MaximizeOutputWindow();
	findString(string);
	//3
	ptr_file_output = fopen(LOG_DIR_output,"aw");
	fputs("\n",ptr_file_output);
	fclose(ptr_file_output);
}
//1.Fonksiyon
void outputString(char outputString[])
{
	ptr_file_output = fopen(LOG_DIR_output,"aw");
	fprintf(ptr_file_output,"%s ",outputString);
	fclose(ptr_file_output);
	printf("DOSYAYA YAZMA ÝÞLEMÝ BAÞARILI :)\n");
}
//2.Fonksiyon
int findString(char string[])
{
	char temp[MAX];
	int indis = 0,length,length2 = 0;

	length = strlen(string);
	while(indis<=length)
	{
		strncpy(temp,string,indis);
		temp[indis] = '\0';
		length2 = searching(string,temp);
		indis++;
		if(length2 > 0)
		{
			string += length2;
			indis = 0;
		}
	}
	outputString(temp);
	return 1;
}
//3.Fonksiyon
int searching(char string[],char temp[])
{
	int length2;
	char fileString[MAX],firstString[MAX];
	
	ptr_file_word = fopen(LOG_DIR_word,"r");
	while(!feof(ptr_file_word))
	{
		fscanf(ptr_file_word,"%s" ,&fileString);
		if(strcmp(temp,fileString) == 0)
		{
			length2 = strlen(temp);
			strcpy(firstString,temp);
			outputString(firstString);
			return length2;
		}
	}
	fclose(ptr_file_word);
	return 0;
}
