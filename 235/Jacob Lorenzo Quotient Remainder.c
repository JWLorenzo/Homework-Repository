//Jacob Lorenzo 3/2/2021
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main ()
{
//declaration of variables
  char bufferx[100], buffery[100];
  int quotient, base, index = 0;
  int remain[100];
  char HexChar[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
  };
  //while loop to keep repeating the program until the condition is met
  while (1)
    {
      //while loop for variable conditioning
      while (1)
	{
	  //input
	  printf ("Please enter a nonnegative number in base 10: ");
	  scanf ("%s", bufferx);
	  quotient = atoi (bufferx);
	  if (quotient <= 0)
	    {
	      if (quotient == -1)
		{
		  printf ("Goodbye");
		  exit (0);
		}
	      else
		{
		  printf ("Please enter a valid number\n");
		}
	    }
	  else
	    {
	      break;
	    }
	}

      while (1)
	{
	  //conditioning for the bases as well
	  printf ("Please enter base(2,3,4,8,16): ");
	  scanf ("%s", buffery);
	  base = atoi (buffery);
	  if ((base == 2) || (base == 3) || (base == 4) || (base == 8)
	      || (base == 16))
	    {
	      break;
	    }
	  else
	    {
	      base = 0;
	      printf ("Please enter a valid base\n");
	    }
	}
      //case switch to determine what occurs for different bases
      switch (base)
	{
	case 2:
	case 3:
	case 4:
	case 8:
	  //calculations
	  while (quotient != 0)
	    {
	      remain[index] = quotient % base;
	      quotient /= base;
	      index++;

	    }
	  //inverter
	  index--;
	  for (; index >= 0; index--)
	    {
	      printf ("%d", remain[index]);
	    }
	case 16:
	  //calculations
	  while (quotient != 0)
	    {
	      remain[index] = quotient % base;
	      quotient /= base;
	      index++;

	    }
	  //inverter and hex correlation
	  index--;
	  for (; index >= 0; index--)
	    {
	      if (remain[index] <= 9)
		{
		  printf ("%d", remain[index]);
		}
	      else
		{
		  printf ("%c", HexChar[remain[index]]);
		}
	    }

	default:
	  break;
	}
      //clear indexes and the remain array
      index = 0;
      printf ("\n");
      memset (remain, '\0', sizeof remain);
    }
}
