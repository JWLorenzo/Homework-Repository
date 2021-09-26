//Jacob Lorenzo

/*the code has an odd bug where when you insert the 8th element, it turns it into a 4
tried fixing it, but it refuses to go away no matter what I do, it's weird though because when I manually
push values to the stack, the bug disappears, to show I at least have something to submit, I set the cap to 7 elements*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int Stack[100];
int *SP = Stack;
int *InitSP = Stack;
int InputVal, PushVal, CheckStackVal;


void
Push (int **SP, int val)
{
  (*SP)--;
  **(SP) = val;//one of my attempts at trying to fix the bug
  **(SP) = val;
  **(SP) = val;
}


int
Pop (int **SP)
{
  int tempint = **(SP);
  **(SP) = '\0';
  (*SP)++;
  return tempint;
}


int
NumberElements (int *SP, int *InitSP)
{
  return InitSP - SP;
}

void
PrintStack (int *SP)
{
  int numels = NumberElements (SP, InitSP);

  int i;

  if (numels == 0)
    {
      printf ("The stack is empty\n");
    }
  else
    {

      for (i = 0; i < numels; i++)
	{
	  printf ("Stack element[%d] is %d\n", numels - i-1, *(SP + i));
	}
    }
  printf ("\n");
  
}


int
Instack (int *SP, int val)
{
  int numels = NumberElements (SP, InitSP);

  int i;

  for (i = 0; i < numels; i++)
    {

      if (*(SP + i) == val)
	{
	  return 1;
	}
      return 0;
    }

}

void
Peek (int *SP)
{
  if (NumberElements (SP, InitSP) == 0)
    {
      printf ("The stack is empty\n");
    }
  else
    {
      printf ("Peek value: %d\n", *(SP));
    }
  printf ("\n");
}


int
SizeofStack ()
{
  return NumberElements (SP, InitSP);
}

void
Checknegative1 (int InputVal)
{
  if (InputVal == -1)
    {
      PrintStack (SP);
      exit (0);
    }
}

void
Check0 (int InputVal)
{
  if (InputVal == 0)
    {
      if (NumberElements (SP, InitSP) == 7)
	{
	  printf ("Cannot push because it would cause overflow(bugs)\n");
	}
      else
	{
	  printf ("Please enter an integer to push: ");
	  scanf ("%i", &PushVal);
	  Push (&SP, PushVal);
	}
      printf ("\n");
    }
  InputVal = '\0';
}

void
Check1 (int InputVal)
{
  if (InputVal == 1)
    {
      if (NumberElements (SP, InitSP) == 0)
	{
	  printf ("Cannot pop because it would cause underflow\n");
	}
      else
	{
	 printf("popped value: %d", Pop (&SP));
	}
    }
  printf ("\n");
  InputVal = '\0';
}

void
Check2 (int InputVal)
{
  if (InputVal == 2)
    {
      printf
	("Please enter a valid integer to check if it's in the stack:\n");
      scanf ("%d", &CheckStackVal);
      printf
	("Instack result:\n1 = in\n0 = not in\nresult: %d\n",
	 Instack (SP, CheckStackVal));
    }
  printf ("\n");
  InputVal = '\0';
}

void
Check3 (int InputVal)
{
  if (InputVal == 3)
    {
      printf ("The size of the stack is %d\n", SizeofStack ());
    }
  printf ("\n");
  InputVal = '\0';
}

void
Check4 (int InputVal)
{
  if (InputVal == 4)
    {
      PrintStack (SP);
    }
  InputVal = '\0';
}

void
Check5 (int InputVal)
{
  if (InputVal == 5)
    {
      Peek (SP);
    }
  InputVal = '\0';
}


int
main ()
{
  /*
     //This works fine
     Push (&SP,1);
     Push (&SP,2);
     Push (&SP,3);
     Push (&SP,4);
     Push (&SP,5);
     Push (&SP,6);
     Push (&SP,7);
     Push (&SP,8);
     Push (&SP,9);
     Push (&SP,10);
     Push (&SP,11);
     Push (&SP,12);
     PrintStack (SP);
   */
 //this is a buggy mess, literally everything else works except this one bug that replaces a value
  while (1)
    {
      for (;;)
	{
	  printf
	    ("Choose one of the presented options:\n 0: push\n 1: pop\n 2: instack\n 3: sizeofstack\n 4: printstack\n 5: peek\n -1: quit: ");

	  scanf ("%d", &InputVal);

	  if (InputVal == -1 || InputVal == 0 || InputVal == 1
	      || InputVal == 2 || InputVal == 3 || InputVal == 4
	      || InputVal == 5)
	    {
	      break;
	    }
	  printf ("Invalid selection, choose again.\n");
	}

      if (InputVal == -1)
	{
	  Checknegative1 (InputVal);
	}
      else
	{
	  if (InputVal == 0)
	    {
	      Check0 (InputVal);
	    }
	  else
	    {
	      if (InputVal == 1)
		{
		  Check1 (InputVal);

		}
	      else
		{
		  if (InputVal == 2)
		    {
		      Check2 (InputVal);

		    }
		  else
		    {


		      if (InputVal == 3)
			{
			  Check3 (InputVal);

			}
		      else
			{


			  if (InputVal == 4)
			    {
			      Check4 (InputVal);

			    }
			  else
			    {
			      if (InputVal == 5)
				{
				  Check5 (InputVal);

				}

			    }


			}


		    }

		}
	    }

	}
    }

}

