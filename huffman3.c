#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



void char_freq(); 
void sortfunc();
void codebuilder();


struct huffman
{
	char tegn;
	int key;
	int freq;
    int code[256];
    int counter;
};

struct huffman2
{
	int freq;
    int code[256];
};

struct huffman tree_node[256];
struct huffman sorted_tree_node[256];
struct huffman2 combined_tree_node;

void main()
{
    int i = 0, j = 0, k = 0;

    for (i = 0; i < 256; i++)
    {
        for (j = 0; j < 256; j++)
        {
            tree_node[i].code[j] = -1;
            tree_node[i].code[j] = -1;            
        } 
    }

    for (i = 0; i < 256; i++)
    {
        for (j = 0; j < 256; j++)
        {
            sorted_tree_node[i].code[j] = -1;
            sorted_tree_node[i].code[j] = -1;
        } 
    }
    char_freq();
	sortfunc();
    codebuilder();
}

void char_freq() 
{
	
    int i = 0, j = 0, k = 0, l = 0;
    char char_read;

	FILE *msg;
    msg = fopen("msg.txt", "r");

//finder antallet af tegn i filen og tegnenes frekvens
   	while(1) 
	{	
    	char_read = getc(msg);
		tree_node[char_read].tegn = char_read;
		tree_node[char_read].key = char_read;
        tree_node[char_read].code[0] = char_read;
		tree_node[char_read].freq++;
    	if(feof(msg)) 
		{
        	break;
        }	
	}
    fclose(msg);   
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



void codebuilder()
{
    int i = 0, j = 0, k = 0, first, second, counter;

    while (sorted_tree_node[i].freq < 1)
    {
        i++;
    }

    for (i = i; i < 255; i++)
    {
        j = 0;
        while(sorted_tree_node[i+1].code[j] >= 0)
        {
            first = sorted_tree_node[i+1].code[j];
            counter = tree_node[first].counter;
            tree_node[first].code[counter] = 1;
            tree_node[first].counter++;
            j++;
            second++;
        }

        j = 0;
        while(sorted_tree_node[i].code[j] >= 0)
        {
            first = sorted_tree_node[i].code[j];
            counter = tree_node[first].counter;
            tree_node[first].code[counter] = 0;
            tree_node[first].counter++;
            j++;
            sorted_tree_node[i+1].code[second] = first;
            second++;
        }
    }   
    sortfunc();
    i = 0;

    while (sorted_tree_node[i].freq < 1)
    {
        i++;
    }

    for (i = i; i < 256; i++)
    {
		printf(":%c: %d: :%d: ", sorted_tree_node[i].tegn, sorted_tree_node[i].key, sorted_tree_node[i].freq);	
        for (j = 0;  sorted_tree_node[i].code[j] >= 0; j++)
        {
            printf("%d",sorted_tree_node[i].code[j]);
        }
        printf("\n");
    }
    
     
}





