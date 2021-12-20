// Gcode Block test by Bui Viet Hoang

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSZ_ITOA  12
float gx= 0, gy= 0, gz= 0, ga= 0, gf= 0;


short _read_number_f(char* pdst, char* psrc, short ifrom, short maxlen)
{
	short i= ifrom;

	while(psrc[i])
	{
		if(psrc[i] != '-' && psrc[i] != '.' && psrc[i] != ',' && (psrc[i] < '0' || psrc[i] > '9' || (i-ifrom >= maxlen)))
		{
			if(pdst)
			{
				pdst[i-ifrom]= 0;
			}
			break;
		}
		else
		{
			if(pdst)
			{
				pdst[i-ifrom]= psrc[i];
			}
			i++;
		}
	}

	return(i);
}

void update_xyzaf(char* gblock)
{
	int i, len;
	char bufa[BUFSZ_ITOA];

	len= strlen(gblock);

	for(i= 0; i < len; i++)
	{
		switch(gblock[i])
		{
			case 'X':
			{
				i= _read_number_f(bufa, gblock, i+1, BUFSZ_ITOA)-1;
				gx= atof(bufa);
				break;
			}
			case 'Y':
			{
				i= _read_number_f(bufa, gblock, i+1, BUFSZ_ITOA)-1;
				gy= atof(bufa);
				break;
			}
			case 'Z':
			{
				i= _read_number_f(bufa, gblock, i+1, BUFSZ_ITOA)-1;
				gz= atof(bufa);
				break;
			}
			case 'A':
			{
				i= _read_number_f(bufa, gblock, i+1, BUFSZ_ITOA)-1;
				ga= atof(bufa);
				break;
			}
			case 'F':
			{
				i= _read_number_f(bufa, gblock, i+1, BUFSZ_ITOA)-1;
				gf= atof(bufa);
				break;
			}
			default:
			{
				break;
			}
		}
	}
}

int main()
{
	char* block= "G00X-7Y10Z20.5A.45F10.5";
	update_xyzaf(block);
	printf("X=%8.4f Y=%8.4f Z=%8.4f A=%8.4f F=%8.4f", gx, gy, gz, ga, gf);
	return 0;
}
