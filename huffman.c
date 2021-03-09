#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void char_freq(); 

struct huffman
{
	char tegn;
	int key;
	int freq;
};

void main()
{
    char_freq();
}

void char_freq() 
{
	
    int i = 0, j = 0, k = 0, l = 0;
	char char_read;
	int char_read_value = 0;
	int file_length = 0;
	int freq_array[256] = {0};
	int chars_used = 0;
    
	FILE *msg;
    msg = fopen("msg.txt", "r");

	//finder antallet af tegn i filen og tegnenes frekvens
   	while(1) 
	{	
    	char_read = getc(msg);
		char_read_value = char_read;
		freq_array[char_read_value]++;
		file_length++;	
    	if(feof(msg)) 
		{
        	break;
        }	
	}
    fclose(msg);   
//t�ller antallet af forskellige tegn brugt
	for (i = 0; i < 256; i++)
	{
		if(freq_array[i] > 0)
		{
			chars_used++;
		}
	}

	struct huffman tree_node[chars_used];
	struct huffman sorted_tree_node[chars_used];
	
	for (i = 0; i < 256; i++)
	{
		if(freq_array[i] > 0)
		{
			tree_node[j].key = i;
			tree_node[j].freq = freq_array[i];
			tree_node[j].tegn = tree_node[j].key;
			j++;
		}
	}

//så får vi sgu brugt farmand runes frække sorteringsalgoritme til at sortere efter frekvens

	i = 0;
	k = 0;
	l = 0;
    while (l < chars_used)
    {
        while (i < chars_used)
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





    i = 0;
	for (k = 0; k < chars_used; k++)
	{
		printf(":%c: %d: :%d:\n", sorted_tree_node[k].tegn, sorted_tree_node[k].key, sorted_tree_node[k].freq);	
	}



}





