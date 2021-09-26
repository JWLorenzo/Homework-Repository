#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


//Creator: Jacob Lorenzo
//COS 235
//4/7/21
int
ISSET (unsigned int BitSet, int BitPos)
{

  if (BitSet & (1 << BitPos))
    {
      return (1);
    }
  else
    {
      return (0);
    }

}

int
ADDBIT (unsigned int BitSet, int BitPos)
{
  printf ("Old Bitset:%p\n", BitSet);
  BitSet |= 1UL << BitPos;
  printf ("New Bitset:%p\n", BitSet);

}

int
DELBIT (unsigned int BitSet, int BitPos)
{
  printf ("Old Bitset:%p\n", BitSet);
  BitSet &= ~(1UL << BitPos);
  printf ("New Bitset:%p\n", BitSet);
}

int
PRINTBIT (unsigned char *BitSet)
{
  const char binary[16][5] =
    { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000",
"1001", "1010", "1011", "1100", "1101", "1110", "1111" };
  const char *digits = "0123456789abcdef";

  char buffer2[100];
  buffer2[0] = '\0';
  int p = 0;

  while (BitSet[p])
    {
      const char *v = strchr (digits, tolower (BitSet[p++]));
      if (v)
	{
	  strcat (buffer2, binary[v - digits]);
	}
    }
  p = 4 * p;
  int r = p;
  while (p != 0)
    {
      printf ("The Bit in Position %i is %c\n", r - p, buffer2[p - 1]);
      p--;
    }
}

int
main ()
{
  char FuncInput[100], buffer[100];
  int FuncInputATOI, PlaceHolderInt, i = 0;
  unsigned int HexInput;
  const char *validNumber = NULL;
  while (1)
    {
      while (1)
	{
	  printf
	    ("Please enter function (1 = IS, 2 = ADD, 3 = DEL, 4 = PRINT, or -1 to quit): ");
	  scanf ("%s", FuncInput);
	  FuncInputATOI = atoi (FuncInput);
	  if (FuncInputATOI == 1 || FuncInputATOI == 2 || FuncInputATOI == 3
	      || FuncInputATOI == 4)
	    {
	      break;
	    }
	  else
	    {
	      if (FuncInputATOI == -1)
		{
		  exit (0);
		}
	      else
		{
		  printf ("Please enter a valid input\n");
		}
	    }
	}
      printf ("Please enter a BitSet (0x...): ");
      scanf("%x", &HexInput);
	  sprintf (buffer, "%x", HexInput);
	  while ((getchar()) != '\n');
      printf ("Bitset:%p\n", HexInput);
      switch (FuncInputATOI)
	{
	case 1:
	  printf ("Please enter bit to check: ");
	  scanf ("%i", &PlaceHolderInt);
	  printf ("Result of if bit is set(1 is set, 0 isn't set):%i\n",
		  ISSET (HexInput, PlaceHolderInt));
	  break;
	case 2:
	  printf ("Please enter bit to change: ");
	  scanf ("%i", &PlaceHolderInt);
	  ADDBIT (HexInput, PlaceHolderInt);
	  break;
	case 3:
	  printf ("Please enter bit to delete: ");
	  scanf ("%i", &PlaceHolderInt);
	  DELBIT (HexInput, PlaceHolderInt);
	  break;
	case 4:
	  PRINTBIT (buffer);
	  break;
	default:
	  printf ("casedefault\n");
	  break;
	}
    }

}
