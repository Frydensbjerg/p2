#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



void char_freq(); 
void sortfunc();
void nodebuilder();

struct huffman
{
	char tegn;
	int key;
	int freq;
    int code[256];
    int counter;
};



struct huffman tree_node[256];
struct huffman sorted_tree_node[256];
struct huffman combined_tree_node[256];

void main()
{
    char_freq();
	sortfunc();
    nodebuilder();
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

void nodebuilder()
{
    int i = 0, j = 0, k = 0, counter;

    while (sorted_tree_node[i].freq == 0)
    {
        i++;
    }

    for (i = i; i < 256; i++)
    {
        if (sorted_tree_node[i].code[0] == 0 && sorted_tree_node[i+1].code[0] == 0)
        {
            tree_node[sorted_tree_node[i].key].code[tree_node[i].counter] = 0;
            tree_node[sorted_tree_node[i].key].counter++;
            tree_node[sorted_tree_node[i+1].key].code[tree_node[i+1].counter] = 1;
            tree_node[sorted_tree_node[i+1].key].counter++;
            combined_tree_node[j].freq = sorted_tree_node[i].freq + sorted_tree_node[i+1].freq;
            combined_tree_node[j].code[j] = sorted_tree_node[i].key;
            combined_tree_node[j].code[j+1] = sorted_tree_node[i+1].key;
            sorted_tree_node[i+1] = combined_tree_node[j];
            sortfunc();
        }
        else if(sorted_tree_node[i].code[j] != 0 && sorted_tree_node[i+1].code[j] == 0)
        {
            for (k = 0; sorted_tree_node[i].code[k] > 0; k++)
            {
                tree_node[sorted_tree_node[i].code[0]].code[tree_node[sorted_tree_node[i].code[0]].counter] = 0;
                tree_node[sorted_tree_node[i].code[0]].counter++;
            }
            tree_node[sorted_tree_node[i+1].key].code[tree_node[i+1].counter] = 1;
            tree_node[sorted_tree_node[i+1].key].counter++;
            
            for (k = 0; sorted_tree_node[i].code[k] > 0; k++)
            {
                combined_tree_node[j].freq = sorted_tree_node[i].freq + sorted_tree_node[i+1].freq;

            }
        }
    }
}





