#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



void char_freq(); 
void sortfunc();
void logfinder(int *chars_used);

struct huffman
{
	char tegn;
	int key;
	int freq;
};

struct huffman tree_node[256];
struct huffman sorted_tree_node[256];

void main()
{
    char_freq();
	sortfunc();
}

void char_freq() 
{
	
    int i = 0, j = 0, k = 0, l = 0;
    char char_read;
    int chars_used = 0;

	FILE *msg;
    msg = fopen("msg.txt", "r");

//finder antallet af tegn i filen og tegnenes frekvens
   	while(1) 
	{	
    	char_read = getc(msg);
		tree_node[char_read].tegn = char_read;
		tree_node[char_read].key = char_read;
        if (tree_node[char_read].freq == 0)
        {
            chars_used++;
        }
		tree_node[char_read].freq++;	
    	if(feof(msg)) 
		{
        	break;
        }	
	}
    fclose(msg); 
    printf("DIFFERENT CHARS USED: %d\n", chars_used);
    logfinder(&chars_used);  
}

void sortfunc()
{
//så får vi sgu brugt farmand runes frække sorteringsalgoritme fra eksamensopgave 3 til at sortere efter frekvens

	int i = 0, k = 0, l = 0;

    while (l < 256)
    {
        while (i < 256)
        {
            if (tree_node[l].freq > tree_node[i].freq)
            {
                k++;
                i++;
            }
            else if (tree_node[l].freq == tree_node[i].freq && tree_node[l].key > tree_node[i].key)
            {
                k++;
                i++;
            }
            else
            {  
                i++;        
            }
        } 

        sorted_tree_node[k] = tree_node[l]; 
        k = 0;
        l++;
        i = 0;
    }	
}

void logfinder(int *chars_used)
{
    int j = 2;
    int fixed_length = 1;
    while (j < *chars_used)
    {
        j*=2;
        fixed_length++;
    }
    printf ("AMOUNT OF BITS NEEDED TO REPRESENT ALL THE NUMBERS: %d", fixed_length);
}





